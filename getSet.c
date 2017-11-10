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

void setInt(ULONG intValue, NODE *this) {
    this->ulIntVal = intValue;
}

void setString(char *stringValue, NODE *this) {
    if (this->pszString == NULL) {
        this->pszString = malloc(strlen(stringValue)+1);
    }else{
        this->pszString = realloc(this->pszString,strlen(stringValue) + 1);

    }
    strcpy(this->pszString, stringValue);
}

char * getText(char * value, char * language){
NODE * node = findValue(value, language,root);
    if(node != NULL){
        return node->pszString;
    }else{
        return NULL;
    }
}

char * getString (char * keyValue){
    nodeType type=  getType(keyValue);

    if (type == stringValue){
        return getNode(keyValue,root)->pszString;
    }
    return NULL;
}

ULONG getInt(char * keyValue){

    nodeType type=  getType(keyValue);
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


