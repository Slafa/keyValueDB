//
// Created by glenn on 26.10.17.
//

#ifndef EXAMEN_KVH_H
#define EXAMEN_KVH_H
#define getType(a)                              \
                    _Generic((a),               \
                    NODE*: getTypeNode,         \
                    char*: getTypeString)(a)
///params (b) = any int value if expected int or any string value for string.
#define getValue(a,b)                           \
                    _Generic((b),               \
                    char*: getString,           \
                    int: getInt)(a,b)

#define setValue(a)(b)(c)                           \
                    _Generic((a),               \
                    char*: setString,           \
                    int: setInt)(a,b,c)


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

typedef void (*callBack) (NODE *, char *);

NODE *root;

nodeType setInt(ULONG intValue, char *keyValue, NODE * this);

void setString(char *stringValue, NODE *this);

struct NODE *createNode(char *name);

void setupNodes(char **pArr, int size, NODE *root);

void printAllNodes(NODE *this, char *folderName);

ULONG getInt(char * keyValue, int nodeType);

char * getString(char * keyValue, char * nodeType);

NODE *getNode(char *keyValue, NODE *root);

void test();

bool delete(char *keyValue);

void deleteSubNodes(NODE *this);

void sortNode(NODE *node);

void swap(NODE *a, NODE *b);

void buildKVDB(char *fileName);

nodeType getTypeNode(NODE *thisNode);

nodeType getTypeString(char *keyValue);

char *getText(char *value, char *language);

NODE *findValue(char *valueName, char *language, NODE *this);

void enumerate(char * keyName, callBack callBackFunk);




#endif //EXAMEN_KVH_H




