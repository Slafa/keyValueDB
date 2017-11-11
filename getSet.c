//
// Created by slafa on 02.11.17.
//

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "kvh.h"

nodeType getTypeString(char *keyValue) {

    char keyValDup[strlen(keyValue + 1)];
    char *delimeter = ". ";
    char *word;
    int counter = 0;
    NODE *thisNode = root;


    strcpy(keyValDup, keyValue);
    word = strtok(keyValDup, delimeter);

    while (word != NULL) {
        if (thisNode->pnNodeCounter != -1) {
            for (int i = 0; i <= thisNode->pnNodeCounter; ++i) {
                if (strcmp(thisNode->pnNodes[i].pszName, word) == 0) {
                    thisNode = &thisNode->pnNodes[i];
                    continue;
                }
            }
            if (strcmp(thisNode->pszName,word) != 0 ){
                return nodeDontExist;
            }
        }
        counter++;
        word = strtok(NULL, delimeter);

    }
    return getType(thisNode);
}

nodeType getTypeNode(NODE * thisNode){
         if (thisNode == NULL) {
        return nodeDontExist;

    } else if (thisNode->pnNodeCounter > -1) {
        return folder;

    } else if (thisNode->pszString != NULL) {
        return stringValue;

    } else {
        return intValue;
    }
}

nodeType setInt(ULONG intValue, char *keyValue, NODE * this) {

    NODE *node;
    if (this == NULL){
        node = getNode(keyValue, root);
    }else{
        node = this;
    }

    if(node == NULL){
        char * nodeToCreate = {keyValue};
        setupNodes(&nodeToCreate,1,root);
        node = getNode(keyValue, root);
    }
    else if(getType(node) == stringValue){
        return wrongType;
    }
    node->ulIntVal = intValue;
}

nodeType setString(char *value, char * keyValue, NODE *this) {

    NODE *node;
    if (this == NULL){
        node = getNode(keyValue, root);
    }else{
        node = this;
    }

    if(node == NULL){
        char val[strlen(keyValue)+ strlen(value)+6];
        strcat(val,keyValue);
        strcat(val," = \"");
        strcat(val,value);
        strcat(val,"\"");
        puts(val);
        char * nodeToCreate = {val};
        setupNodes(&nodeToCreate,1,root);
        node = getNode(keyValue, root);
    }
    else if(this == NULL && getType(node) != stringValue){
        return wrongType;
    }


    if (node->pszString == NULL) {
        node->pszString = malloc(strlen(value)+1);
    }else{
        node->pszString = realloc(node->pszString,strlen(value) + 1);

    }
    strcpy(node->pszString, value);
}

char * getText(char * value, char * language){
NODE * node = findValue(value, language,root);
    if(node != NULL){
        return node->pszString;
    }else{
        return NULL;
    }
}
///param (blank) =  any string value
char * getString (char * keyValue, char * blank){
    nodeType type = getType(keyValue);

    if (type == stringValue){
        return getNode(keyValue,root)->pszString;
    }
    return NULL;
}
///param (blank) =  any int value
ULONG getInt(char * keyValue, int blank){

    nodeType type = getType(keyValue);
    if (type == intValue){
        return getNode(keyValue, root)->ulIntVal;
    }
}

 /*void * getValue(*char keyValue){
    nodeType type = getType(keyValue);
    if(type == stringValue){
        return getString(keyValue);
    }else if(type == intValue){
        return getInt(keyValue);
    } else return (void *) type;
}*/

NODE *getNode(char* keyValue, NODE * root){
    if(getType(keyValue) == nodeDontExist ){
        return NULL;
    }
    char keyValDup[strlen(keyValue + 1)];
    char *delimeter = ". ";
    char *word;
    int counter = 0;
    NODE * thisNode = root;

    strcpy(keyValDup, keyValue);
    word = strtok(keyValDup, delimeter);

    while (word != NULL) {
        if (thisNode->pnNodeCounter != -1) {
            for (int i = 0; i <= thisNode->pnNodeCounter; ++i) {
                if (strcmp(thisNode->pnNodes[i].pszName, word) == 0) {
                    thisNode = &thisNode->pnNodes[i];
                    continue;
                }
            }
        }
        counter++;
        word = strtok(NULL, delimeter);
    }
    return thisNode;
}

///var litt usikker på hva som skulle være poenget med denne funksjonen og hvordan den skulle virke.
///valgte derfor å printe ut alle undernodene og verdien.
void enumerate(char * keyName, callBack callbackFunc){
    char * fullPath = calloc(1, sizeof(char) * strlen(keyName+1));
    strcpy(fullPath,keyName);

    if(fullPath != NULL && fullPath[strlen(fullPath)-1] =='*') {
        fullPath[strlen(fullPath)-1] = '\0';
        if(fullPath[strlen(fullPath)-1] =='.'){
            fullPath[strlen(fullPath)-1] = '\0';
        }else{
            return;
        }
    }

    NODE * node = getNode(fullPath,root);
    if (node != NULL) {
        for (int i = 0; i <= node->pnNodeCounter; ++i) {

            callbackFunc(&node->pnNodes[i],node->pnNodes[i].pszName);
        }
    }
}


