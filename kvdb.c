//
// Created by slafa on 26.10.17.
//

#include <stdio.h>
#include <stdlib.h>
#include "kvh.h"




int main(int argc, char *fileAdress[]) {

    if (argc <2){
        return 1;
    }
    root = createNode("root");

    buildKVDB(fileAdress[1]);

    test();


    return 0;
}








