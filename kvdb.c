#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kvh.h"

NODE root;

int main(int argc, char *fileAdress[]) {


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

    root = createNode("root");
    //root.pszName = "root";
    printf("\n\ntest : %d \n%s\n", lineCounter, root.pszName);
    //printf("\n\ntest : %d \n", (int) (sizeof(&lines) / sizeof(char)));

    setupNodes(lines, lineCounter, &root);
    puts("\n");
    //puts(root.pszName);

    printAllNodes(&root, root.pszName);
    puts("");
    printf("%d\n", getType("config.update.interval"));
    printf("%d\n", getType("config.update"));
    printf("%d\n", getType("config.update.server1"));
    printf("%d\n", getType("strings.no.header"));
    printf("%d\n", getType("strins.no.header"));

    puts("\n\n");
    printf("%s", (char *) getString("config.update.interval"));
    return 0;
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


            while (strcmp(word, "=") != 0) {
                nodeExist = false;
                if (lastNode->pnNodeCounter == -1) {
                    lastNode->pnNodes = calloc(1, sizeof(NODE));
                    lastNode->pnNodes[0] = createNode(temp);
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
                        // printf("\nfør : %d", lastNode->pnNodeCounter);
                        lastNode->pnNodes[++lastNode->pnNodeCounter] = createNode(temp);
                        //printf("\netter : %d", lastNode->pnNodeCounter);

                        //printf("DETTE ER NAVNET : %s",);
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
                printf("\nSTRING VALUE - %s : %s", lastNode->pszName, lastNode->pszString);

            } else {
                ULONG intValue = (ULONG) atoi(word);
                setInt(intValue, lastNode);
                printf("\nNUM VALUE - %s : %lu", lastNode->pszName, lastNode->ulIntVal);
            }
        }
    }
}


struct NODE createNode(char *name) {
    NODE new;
    new.pszName = strdup(name);
    new.pnNodes = NULL;
    new.pszString = NULL;
    new.pnNodeCounter = -1;
    return new;
}

void printAllNodes(NODE *this, char *folderName) {

    char *pfolderName;
    pfolderName = malloc(sizeof(char) * strlen(folderName));

    if (this->pnNodeCounter != -1) {

        for (int i = 0; i <= this->pnNodeCounter; i++) {

            pfolderName = realloc(pfolderName,
                                  sizeof(char) * (strlen(folderName) + strlen(this->pnNodes[i].pszName) + 2));
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

nodeType getType(char *keyValue) {

    char keyValDup[strlen(keyValue + 1)];
    char *delimeter = ". ";
    char *word;
    int counter = 0;
    bool nodeExist = false;
    NODE thisNode = root;


    strcpy(keyValDup, keyValue);
    word = strtok(keyValDup, delimeter);

    while (word != NULL) {
        nodeExist = false;
        if (thisNode.pnNodeCounter != -1) {
            for (int i = 0; i <= thisNode.pnNodeCounter; ++i) {
                if (strcmp(thisNode.pnNodes[i].pszName, word) == 0) {
                    thisNode = thisNode.pnNodes[i];
                    nodeExist = true;
                    continue;
                }
            }
        }
        counter++;
        word = strtok(NULL, delimeter);

    }
    if (nodeExist != true) {
        printf("%s", "ERROR = ");
        return nodeDontExist;

    } else if (thisNode.pnNodeCounter > -1) {
        printf("%s", "FOLDER = ");
        return folder;

    } else if (thisNode.pszString != NULL) {
        printf("%s", "STRING = ");
        return stringValue;

    } else {
        printf("%s", "INT = ");
        return intValue;
    }

}

void setInt(ULONG intValue, NODE *this) {
    this->ulIntVal = intValue;
}

void setString(char *stringValue, NODE *this) {
    this->pszString = malloc(sizeof(stringValue));
    this->pszString = stringValue;
}

void* getString (char* keyValue){
    nodeType type=  getType(keyValue);

    if (type == intValue){
        return (void *) wrongType;
    }else if (type == nodeDontExist){
        return (void *) nodeDontExist;
    }else {
        return getNode(keyValue,root).pszString;
    }
}

NODE getNode(char* keyValue, NODE root){
    char keyValDup[strlen(keyValue + 1)];
    char *delimeter = ". ";
    char *word;
    int counter = 0;
    NODE thisNode = root;

    strcpy(keyValDup, keyValue);
    word = strtok(keyValDup, delimeter);

    while (word != NULL) {
        if (thisNode.pnNodeCounter != -1) {
            for (int i = 0; i <= thisNode.pnNodeCounter; ++i) {
                if (strcmp(thisNode.pnNodes[i].pszName, word) == 0) {
                    thisNode = thisNode.pnNodes[i];
                    continue;
                }
            }
        }
        counter++;
        word = strtok(NULL, delimeter);
    }
    return thisNode;
}






