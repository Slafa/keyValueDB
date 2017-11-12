//
// Created by slafa on 26.10.17.
//


#include <stdio.h>
#include "kvh.h"


int main(int argc, char *fileAdress[]) {

    if (argc != 2) {
        puts("run file with arguments (filename.txt)");
        return 1;
    }
    root = createNode("root");

    puts("Attempting to build nodes from file\n");
    buildKVDB(fileAdress[1]);

    start();


    return 0;
}








