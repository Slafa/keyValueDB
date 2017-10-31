#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kvh.h"


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

    NODE root = createNode("root");
    //root.pszName = "root";
    printf("\n\ntest : %d \n%s\n", lineCounter, root.pszName);
    //printf("\n\ntest : %d \n", (int) (sizeof(&lines) / sizeof(char)));

    setupNodes(lines, lineCounter, &root);
    return 0;
}

void setupNodes(char **pArr, int size, NODE *root) {
    if (pArr != NULL) {
        char *word;
        char *temp;
        NODE *lastNode;
        for (int i = 0; i < size; ++i) {
            lastNode = root;
            char *deli = ". ";
            word = strtok(pArr[i], deli);
            temp = word;
            int pnNodesSize;

            while (strcmp(word, "=") != 0) {
                if (root->pnNodes == NULL) {
                    root->pnNodes = malloc(sizeof(NODE));
                    root->pnNodes[0] = createNode(temp);
                    lastNode = &root->pnNodes[0];
                } else {
                    bool nameExist = false;
                    pnNodesSize = 0;

                    foreach(NODE *node, lastNode->pnNodes) {
                            //set last node to the current if it exist
                            if (strcmp(node->pszName, temp) == 0) {
                                nameExist = true;
                                lastNode = node;
                            }
                            pnNodesSize++;
                        }

                    //create a new node if not exist and set the last node to the new one
                    if (nameExist == false) {
                            lastNode->pnNodes = malloc(sizeof(lastNode->pnNodes)+sizeof(NODE));
                            lastNode->pnNodes[pnNodesSize] = createNode(temp);
                            lastNode = &lastNode->pnNodes[pnNodesSize];
                    }
                    word = strtok(NULL, deli);
                    temp = word;
                }
            }
            word = strtok(NULL,"\0");
            //sets the value of the node if its the last one
            if(word[0] == '"'){
                temp = strtok(word,"\"");
                lastNode->pszString = malloc(sizeof(temp));
                lastNode->pszString = temp;
                printf("\nSTRING VALUE - %s : %s",lastNode->pszName,lastNode->pszString);

            } else{
                lastNode->ulIntVal = (ULONG) atoi(word);
                printf("\nNUM VALUE - %s : %lu",lastNode->pszName,lastNode->ulIntVal);
            }
        }
    }
}


struct NODE createNode(char *name) {
    NODE new;
    new.pszName = strdup(name);
    new.pnNodes = NULL;
    new.pszString = NULL;
    return new;
}






