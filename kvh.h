//
// Created by glenn on 26.10.17.
//

#ifndef EXAMEN_KVH_H
#define EXAMEN_KVH_H
#define MAX_NODE 10


typedef unsigned long ULONG;
typedef enum {
    false,
    true
} bool;

typedef enum {
    intValue = 1,
    stringValue = 2,
    folder = 3,
    nodeDontExist = -1,
    wrongType = -2
} nodeType;


typedef struct NODE {
    char *pszName; //this node name.
    ULONG ulIntVal; //if this node value is an int
    char *pszString; //if this node value is a string
    int pnNodeCounter; //hold number of indexes in pnNodes, if -1 pnNodes == NULL
    struct NODE *pnNodes; //pointer to subnodes(catalogs)
} NODE;

NODE * root;

void setInt(ULONG intValue, NODE *this);

void *getInt(char *stringValue);

void setString(char *stringValue, NODE *this);

void *getString(char *stringValue);

struct NODE * createNode(char *name);

void setupNodes(char **pArr, int size, NODE *root);

void printAllNodes(NODE *this, char *folderName);

nodeType getType(char *keyValue);

NODE *getNode(char *keyValue, NODE *root);

void test();

void printResult(char *keyValue);

void * getValue(char* keyValue);

bool delete(char * keyValue);

void deleteSubNodes(NODE *this, char *folderName);

void bubbleSort(NODE * node);

void swap(NODE *a, NODE *b);


#endif //EXAMEN_KVH_H




