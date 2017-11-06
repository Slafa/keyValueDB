//
// Created by slafa on 26.10.17.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kvh.h"


int main(int argc, char *fileAdress[]) {
    root = createNode("root");


    int lineCounter = 0;
    FILE *pfile = fopen(fileAdress[1], "r");

    if (pfile == 0) {
        fprintf(stderr, "failed to open file\n");
        exit(1);
    }

    int check;
    //counting number of lines
    while (!feof(pfile)) {
        check = fgetc(pfile);
        if (check == '\n')
            lineCounter++;
    }

    int length = 0;
    int counter = 0;
    int lineLength[lineCounter];
    rewind(pfile);

    //counting line length and put it into an array
    do {
        check = fgetc(pfile);
        if (check == '\n') {
            //lineLength[counter] = (int) malloc(sizeof(int) * lineCounter);
            lineLength[counter] = ++length;
            printf("\n%d + %d", lineLength[counter], counter);
            counter++;
            length = 0;
        } else {
            length++;
        }
    } while (!feof(pfile));

    rewind(pfile);

    char *lines[lineCounter];
    printf("\nthis -> %d\n", lineCounter);
    //int i = 0;
    printf("hooooooorrreeeeeeeee      %d", counter);
    for (int i = 0; i < lineCounter; i++) {
        lines[i] = malloc((size_t) lineLength[i]);
        fgets(lines[i], sizeof(lines[i]) * lineLength[i], pfile);
        printf("\n%s", lines[i]);
    }
    fclose(pfile);

    //root.pszName = "root";
    printf("\n\ntest : %d \n%s\n", lineCounter, root->pszName);
    //printf("\n\ntest : %d \n", (int) (sizeof(&lines) / sizeof(char)));

    setupNodes(lines, lineCounter, root);
    puts("\n");
    //puts(root.pszName);




    test();


    return 0;
}

void test() {

    printAllNodes(root, root->pszName);

    /*puts("");
    printf("%d\n", getType("config.update.interval"));
    printf("%d\n", getType("config.update"));
    printf("%d\n", getType("config.update.server1"));
    printf("%d\n", getType("strings.no.header"));
    printf("%d\n", getType("strins.no.header"));

    puts("\n\n");
    //printf("%s", (char *) getString("config.update.interval"));


    setString("hest",getNode("strings.no.header",&root));*/
    //setInt(4 ,getNode("config.update.interval",&root));

    puts("\n\n");
    //printResult(stringValue, getString("strings.no.header"));
    //printResult("strings.no.heade");
    //printResult(stringValue, getString("strings.no.header"));

    //printResult(intValue, getInt("strings.no.header"));
    //printResult(intValue, getInt("config.update.interval"));
    //printf("%lu", (ULONG) getInt("config.update.interval"));
    //printResult("strings.no.header");

    //printAllNodes(&root, root.pszName);

    delete("strings.no");
    puts("\n");
    printAllNodes(root, root->pszName);
    puts("\n");
delete("strings.en");
    printAllNodes(root, root->pszName);

    //printAllNodes(getNode("strings.no", root), getNode("strings.no", root)->pszName);
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
    NODE *nodeArr = malloc(sizeof(nodeArr) * nodeArrSize);

    strcpy(temp, keyValue);
    word = strtok_r(temp, delim, &save);

    while (word != NULL) {

        strcat(path, word);
        nodeArr = realloc(nodeArr, sizeof(*nodeArr) * ++nodeArrSize);

        nodeArr[nodeArrSize - 1] = *getNode(path, root);
        strcat(path, ".");
        word = strtok_r(NULL, delim, &save);


    }
    puts(nodeArr[nodeArrSize - 1].pszName);

    printf("\n%d", nodeArrSize);
    puts("\n\n");
    deleteSubNodes(&nodeArr[nodeArrSize-1],nodeArr[nodeArrSize-1].pszName);


    for (int i = (nodeArrSize - 1); i >= 0; i--) {
        if (nodeArr[i].pnNodeCounter == -1) {
            deleteSubNodes(&nodeArr[i], nodeArr[i].pszName);
        }
        NODE *tempNP = NULL;
        int tempNPSize = -1;
        printf("\nrunde nr :%d", i);
        for (int j = 0; j < nodeArrSize; ++j) {
            if (nodeArr[i].pnNodeCounter == -1)deleteSubNodes(&nodeArr[i],nodeArr[i].pszName);
            if (nodeArr[i].pnNodes[j].pnNodeCounter != -2) {
                if (tempNPSize == -1) {
                    tempNP = malloc(sizeof(*tempNP) * (++tempNPSize+1));
                } else {
                    tempNP = realloc(tempNP, sizeof(*tempNP) * (++tempNPSize + 1));

                }
                //freeNode(nodeArr[i].pnNodes);
                    tempNP[tempNPSize] = nodeArr[i].pnNodes[j];
                }
            }
        nodeArr[i].pnNodeCounter = tempNPSize;
            nodeArr[i].pnNodes = tempNP;


            /*if (nodeArr[i].pnNodes[j].pnNodeCounter == -1) {
                printf("\npeker som skal slettes = %d", nodeArr[i].pnNodes[j].pnNodeCounter);
                //free(&nodeArr[i].pnNodes[j]);
                nodeArr[i].pnNodeCounter--;
                if(nodeArr[i].pnNodeCounter == -1){
                    freeNode(&nodeArr[i]);

                }*/

            //nodeArr[i].pnNodes = realloc(nodeArr[i].pnNodes,
            //                              sizeof(NODE) * nodeArr[i].pnNodeCounter + 1);
            //free(&nodeArr[i-1].pnNodes[i]);
            // printf("nå skal den være borte : %s", nodeArr[i].pnNodes[j].pszName);

        }
    }

    //bubbleSort(&nodeArr[i-1]);

    //strcpy(nodeName,nodeArr[i].pszName);
    //printf("horrreeeeeercdcdd    %s",nodeName);

//free(&nodeArr[nodeArrSize-2]);



void swap(NODE *a, NODE *b) {
    NODE temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(NODE *node) {

    if (node->pnNodeCounter == -1) {
        return;
    }

    int n = node->pnNodeCounter + 1;
    NODE *array = node->pnNodes;
    for (int i = 1; i < n; ++i)
        for (int j = 0; j < (n - i); ++j) {

            if (strcmp(array[j].pszName, array[j + 1].pszName) > 0) {
                swap(&array[j], &array[j + 1]);
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
        printf("\n%s", (char *) getValue(keyValue));
    } else {
        printf("\n%lu", (unsigned long) getValue(keyValue));
    }
}


void setupNodes(char **pArr, int size, NODE *root) {
    if (pArr != NULL) {
        char *word;
        char *temp;
        NODE *lastNode;
        bool nodeExist;
        for (int i = 0; i < size; ++i) {
            lastNode = root;
            char *deli = ". ";
            word = strtok(pArr[i], deli);
            temp = word;
            bubbleSort(lastNode);

            while (strcmp(word, "=") != 0) {
                nodeExist = false;
                if (lastNode->pnNodeCounter == -1) {
                    NODE *nodeToSort = lastNode;
                    lastNode->pnNodes = calloc(1, sizeof(NODE));
                    lastNode->pnNodes[0] = *createNode(temp);
                    lastNode->pnNodeCounter++;
                    lastNode = &lastNode->pnNodes[lastNode->pnNodeCounter];
                } else {


                    //set last node to the current if it exist
                    for (int j = 0; j <= lastNode->pnNodeCounter; j++) {

                        if (strcmp(lastNode->pnNodes[j].pszName, temp) == 0) {
                            lastNode = &lastNode->pnNodes[j];

                            nodeExist = true;
                            continue;
                        }
                    }

                    //increase the size of node array, place a new node into it,
                    //and set last node to the new node.
                    if (nodeExist == false) {
                        lastNode->pnNodes = realloc(lastNode->pnNodes, sizeof(NODE) * (lastNode->pnNodeCounter + 2));
                        lastNode->pnNodes[++lastNode->pnNodeCounter] = *createNode(temp);
                        lastNode = &lastNode->pnNodes[lastNode->pnNodeCounter];

                    }

                }
                word = strtok(NULL, deli);
                temp = word;
            }

            word = strtok(NULL, "\0");
            //sets the value of the node if its the last one
            if (word[0] == '"') {
                temp = strtok(word, "\"");
                setString(temp, lastNode);

            } else {
                ULONG intValue = (ULONG) atoi(word);
                setInt(intValue, lastNode);
            }
            bubbleSort(lastNode);

        }

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

}

void deleteSubNodes(NODE *this, char *folderName) {

    puts(this->pszName);

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
            deleteSubNodes(&this->pnNodes[i], pfolderName);
        }

    } else {
        for (int i = 0; i <= this->pnNodeCounter; ++i) {
            free(&this->pnNodes[i]);
        }
        freeNode(this);

    }

}







