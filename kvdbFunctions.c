//
// Created by glenn on 10.11.17.
//

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "kvh.h"


void start() {
    char *lines = "----------------------------------------------------------------------------\n";


    puts("Printer ut alle nodene for å sjekke at de er der, og er sortert alfabetisk.\n");
    printAllNodes(root, root->pszName);

    puts(lines);
    puts("\nforsøker å slette strings.no noden.");
    delete("strings.no");

    puts("printer ut alle nodene for å sjekke at strings.no er borte\n");
    printAllNodes(root, root->pszName);
    puts(lines);

    puts("\nforsøker å slette strings.en noden");
    delete("strings.en");

    puts("printer ut alle nodene for å sjekke at strings også ble borte\n");
    printAllNodes(root, root->pszName);
    puts(lines);

    puts("\nforsøker å endre config.loglevel til 200, i tillegg til å lage noen nye");

    setValue((ULONG) 200, "config.loglevel", NULL);
    setValue("opp", "strings.no.button_up", NULL);
    setInt((ULONG) 9000, "config.test.9000", NULL);
    setString("up", "strings.en.button_up", NULL);
    setString("ned", "strings.no.button_down", NULL);
    setString("down", "strings.en.button_down", NULL);
    setString("left", "strings.en.button_left", NULL);
    setString("right", "strings.en.button_right", NULL);
    setString("hoyre", "strings.no.button_right", NULL);
    puts("\nhenter nodene for å sjekke endringene\n");
    printAllNodes(root, root->pszName);
    puts(lines);

    puts("tester enumerate på strings.en\n");
    enumerate("strings.en", printAllNodes);
    puts(lines);

    puts("tester get value på config.update.timeout, og config.update.server1 ");
    printf("%lu\n", getValue("config.update.timeout", 1));
    puts(getValue("config.update.server1", ""));
    puts(lines);

    puts("tester getText på button_left på norsk og engelsk + button down på norsk");
    puts(getText("button_left", "no"));
    puts(getText("button_left", "en"));
    puts(getText("button_down", "no"));
    puts(lines);

    puts("tester getType på forskjellige nøkkelverdier\n");
    printf("%d\n", getType("config.update.interval"));
    printf("%d\n", getType("config.update"));
    printf("%d\n", getType("config.update.server1"));
    printf("%d\n", getType("strings.no.header"));
    printf("%d\n", getType("strins.no.header"));
}


void buildKVDB(char *fileName) {
    int lineCounter = 0;
    FILE *pfile = fopen(fileName, "r");

    if (pfile == 0) {
        fprintf(stderr, "failed to open file\n");
        exit(1);
    }

    int check;
    ///counting number of lines
    while (!feof(pfile)) {
        check = fgetc(pfile);
        if (check == '\n')
            lineCounter++;
    }

    int length = 0;
    int counter = 0;
    int lineLength[lineCounter];
    rewind(pfile);

    ///counting line length and put it into an array
    do {
        check = fgetc(pfile);

        if (check == '\n') {
            lineLength[counter] = ++length;
            counter++;
            length = 0;
        } else {
            length++;

        }
    } while (!feof(pfile));

    rewind(pfile);
    char *lines[lineCounter];

    for (int i = 0; i < lineCounter; i++) {
        lines[i] = malloc((size_t) lineLength[i]);
        fgets(lines[i], sizeof(lines[i]) * lineLength[i], pfile);
    }

    fclose(pfile);
    setupNodes(lines, lineCounter, root);

    for (int j = 0; j < lineCounter; ++j) {
        free(lines[j]);
    }
}

void freeNode(NODE *node) {
    free(node->pszString);
    free(node->pnNodes);
    free(node->pszName);
    node->pnNodeCounter = -2;
}

bool delete(char *keyValue) {
    if (getType(keyValue) == nodeDontExist) {
        return false;
    }
    char *temp = malloc(strlen(keyValue) + 1);
    char *word;
    char *path = calloc(1, strlen(keyValue) + 1);
    char *delim = ".";
    char *save;
    int nodeArrSize = 0;
    NODE **nodeArr = malloc(sizeof(nodeArr) * ++nodeArrSize);

    nodeArr[nodeArrSize - 1] = root;


    strcpy(temp, keyValue);
    word = strtok_r(temp, delim, &save);

    while (word != NULL) {

        strcat(path, word);
        nodeArr = realloc(nodeArr, sizeof(*nodeArr) * ++nodeArrSize);

        nodeArr[nodeArrSize - 1] = getNode(path, root);
        strcat(path, ".");
        word = strtok_r(NULL, delim, &save);
    }


    for (int i = nodeArrSize - 1; i > 0; i--) {
        if (i == nodeArrSize - 1 || nodeArr[i]->pnNodeCounter == -1) {
            deleteSubNodes(nodeArr[i]);
            sortNode(nodeArr[i - 1]);
            freeNode(&nodeArr[i - 1]->pnNodes[nodeArr[i - 1]->pnNodeCounter]);
            nodeArr[i - 1]->pnNodes = realloc(nodeArr[i - 1]->pnNodes, sizeof(NODE) * nodeArr[i - 1]->pnNodeCounter--);
        }

    }

    free(nodeArr);
    return true;
}


void swap(NODE *a, NODE *b) {
    NODE temp = *a;
    *a = *b;
    *b = temp;
}

void sortNode(NODE *node) {

    if (node->pnNodeCounter == -1) {
        return;
    }

    int n = node->pnNodeCounter + 1;
    NODE *array = node->pnNodes;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < (n - i); ++j) {
            char *name1 = array[j].pszName;
            char *name2 = array[j + 1].pszName;
            if (name1 == NULL || (name2 != NULL && strcmp(name1, name2) > 0)) {
                swap(&array[j], &array[j + 1]);

            }
        }
    }
}

void printResult(char *keyValue) {

    nodeType type = getType(keyValue);

    if (type == nodeDontExist) {
        printf("\nNode dosnt exist");
    } else if (type == wrongType) {
        printf("\nwrong data type");
    } else if ((type == stringValue)) {
        printf("\n%s", (char *) getValue(keyValue, ""));
    } else {
        printf("\n%lu", (unsigned long) getValue(keyValue, 1));
    }
}


void setupNodes(char **pArr, int size, NODE *root) {
    if (pArr != NULL) {
        char *word;
        char *temp;
        NODE *lastNode;
        NODE *nodesToSort = calloc(1, sizeof(NODE));
        bool nodeExist;
        for (int i = 0; i < size; ++i) {
            int sortArrSize = 0;
            lastNode = root;
            char *deli = ". ";
            word = strtok(pArr[i], deli);
            temp = word;
            //sortNode(lastNode);
            while (strcmp(word, "=") != 0) {
                nodeExist = false;

                if (lastNode->pnNodeCounter == -1) {
                    lastNode->pnNodes = calloc(1, sizeof(NODE));
                    lastNode->pnNodes[0] = *createNode(temp);
                    lastNode->pnNodeCounter++;
                    lastNode = &lastNode->pnNodes[lastNode->pnNodeCounter];
                } else {


                    ///set last node to the current if it exist
                    for (int j = 0; j <= lastNode->pnNodeCounter; j++) {

                        if (strcmp(lastNode->pnNodes[j].pszName, temp) == 0) {
                            lastNode = &lastNode->pnNodes[j];

                            nodeExist = true;
                            continue;
                        }
                    }

                    ///increase the size of node array, place a new node into it,
                    ///and set last node pointer to the new node.
                    if (nodeExist == false) {
                        nodesToSort = realloc(nodesToSort, sizeof(NODE) * (++sortArrSize + 1));
                        lastNode->pnNodes = realloc(lastNode->pnNodes, sizeof(NODE) * (lastNode->pnNodeCounter + 2));
                        lastNode->pnNodes[++lastNode->pnNodeCounter] = *createNode(temp);
                        nodesToSort[sortArrSize - 1] = *lastNode;
                        lastNode = &lastNode->pnNodes[lastNode->pnNodeCounter];

                    }

                }
                word = strtok(NULL, deli);
                temp = word;
            }

            word = strtok(NULL, "\0");
            ///sets the value of the node if its the last one
            if (word[0] == '"') {
                temp = strtok(word, "\"");
                setValue(temp, NULL, lastNode);

            } else {
                ULONG intValue = (ULONG) atoi(word);
                setValue(intValue, NULL, lastNode);
            }
            for (int k = 0; k < sortArrSize; ++k) {
                sortNode(&nodesToSort[k]);

            }

        }
        free(nodesToSort);
    }
}


struct NODE *createNode(char *name) {
    NODE *new = calloc(1, sizeof(NODE));
    new->pszName = strdup(name);
    new->pnNodes = NULL;
    new->pszString = NULL;
    new->pnNodeCounter = -1;
    return new;
}

void printAllNodes(NODE *this, char *folderName) {

    char *pfolderName;
    pfolderName = malloc(sizeof(char) * strlen(folderName));

    if (this->pnNodeCounter != -1) {

        for (int i = 0; i <= this->pnNodeCounter; i++) {

            pfolderName = realloc(pfolderName,
                                  sizeof(char) * (strlen(folderName) +
                                                  strlen(this->pnNodes[i].pszName) + 2));
            strcpy(pfolderName, folderName);
            strcat(pfolderName, ".");
            strcat(pfolderName, this->pnNodes[i].pszName);
            printAllNodes(&this->pnNodes[i], pfolderName);
        }

    } else {
        if (this->pszString != NULL) {
            printf("%s = %s\n", folderName, this->pszString);
        } else {
            printf("%s = %lu\n", folderName, this->ulIntVal);
        }

    }
    free(pfolderName);
}

void deleteSubNodes(NODE *this) {


    if (this->pnNodeCounter != -1) {
        int times = this->pnNodeCounter;
        for (int i = 0; i <= times; i++) {
            deleteSubNodes(&this->pnNodes[i]);
            freeNode(&this->pnNodes[i]);
        }
    }
    this->pszName = NULL;
}

NODE *findValue(char *valueName, char *language, NODE *this) {

    for (int i = 0; i <= this->pnNodeCounter; i++) {
        for (int j = 0; j <= this->pnNodes[i].pnNodeCounter; j++) {


            if (strcmp(this->pnNodes[i].pnNodes[j].pszName, language) == 0) {

                /// return if language node contain the value
                for (int k = 0; k <= this->pnNodes[i].pnNodes[j].pnNodeCounter; k++) {

                    if (strcmp(this->pnNodes[i].pnNodes[j].pnNodes[k].pszName, valueName) == 0) {
                        return &this->pnNodes[i].pnNodes[j].pnNodes[k];
                    }

                }

                /// if no value was found, check the other language
                char *otherLanguage;
                if (strcmp(language, "no") == 0) {
                    otherLanguage = "en";
                } else {
                    otherLanguage = "no";
                }
                for (int k = 0; k <= this->pnNodes[i].pnNodeCounter; k++) {
                    for (int l = 0; l <= this->pnNodes[i].pnNodes[k].pnNodeCounter; l++) {

                        if (strcmp(this->pnNodes[i].pnNodes[k].pszName, otherLanguage) == 0) {
                            if (strcmp(this->pnNodes[i].pnNodes[k].pnNodes[l].pszName, valueName) == 0) {
                                return &this->pnNodes[i].pnNodes[k].pnNodes[l];
                            }
                        }
                    }
                }
            }

            NODE *node = findValue(valueName, language, &this->pnNodes[i]);
            if (node != NULL && strcmp(node->pszName, valueName) == 0) {
                return node;
            }
        }
    }

    return NULL;
}
