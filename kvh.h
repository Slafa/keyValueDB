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
    struct NODE *pnNodes; //pekere til undernoder(kataloger)
} NODE;
        void setInt();
        int getInt(char*);
        void setString();
        char* getString();
        int getType(char*);
        struct NODE createNode(char *name);
        void setupNodes(char **pArr, int size, NODE *root );

#define foreach(item, array) \
    for(int keep = 1, \
            count = 0,\
            size = sizeof (array) / sizeof *(array); \
        keep && count != size; \
        keep = !keep, count++) \
      for(item = (array) + count; keep; keep = !keep)




#endif //EXAMEN_KVH_H




