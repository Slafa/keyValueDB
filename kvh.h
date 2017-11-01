//
// Created by glenn on 26.10.17.
//

#ifndef EXAMEN_KVH_H
#define EXAMEN_KVH_H
#define MAX_NODE 10

        typedef unsigned long ULONG;
        typedef enum { false, true } bool;

typedef struct NODE{
    char *pszName; //this node name.
    ULONG ulIntVal; //if this node value is an int
    char *pszString; //if this node value is a string
    int pnNodeCounter; //hold number of indexes in pnNodes, if -1 pnNodes == NULL
    struct NODE *pnNodes; //pointer to subnodes(catalogs)
} NODE;
        void setInt();
        int getInt(char*);
        void setString();
        char* getString();
        int getType(char*);
        struct NODE createNode(char *name);
        void setupNodes(char **pArr, int size, NODE *root );
        void printAllNodes(NODE * this, char *folderName);





#endif //EXAMEN_KVH_H




