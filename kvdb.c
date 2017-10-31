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
            //word = malloc(sizeof(pArr[i]));
            //printf("%d testtezt : ", sizeof(&pArr[i]));

            char *deli = ". ";
            word = strtok(pArr[i], deli);
            temp = word;
            while (strcmp(word, "=") != 0) {
                if (root->pnNodes == NULL) {
                    root->pnNodes = malloc(sizeof(NODE));
                    root->pnNodes[0] = createNode(temp);
                    lastNode = &root->pnNodes[0];
                } else {
                    bool nameExist = false;

                    foreach(NODE *node, lastNode->pnNodes) {
                            if (strcmp(node->pszName, temp) == 0) {
                                nameExist = true;
                                lastNode = node;
                            }
                        }
                    if (nameExist == false) {
                        lastNode->pnNodes = malloc(sizeof(NODE));
                        lastNode->pnNodes[0] = createNode(temp);
                        lastNode = &lastNode->pnNodes[0];
                    }//todo fix if node exist
                    //printf("\n\nnodeName : \n%s\n", lastNode->pnNodes[0].pszName);
                    word = strtok(NULL, deli);
                    temp = word;
                }
            }
            //puts(word);
            word = strtok(NULL,"\0");
            //puts(word);
            //char *buffer = malloc(sizeof(char));
//printf("grr  %c", word[0]);
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






