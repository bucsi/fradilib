#include <stdio.h>      // printf
#include <stdlib.h>     // malloc, exit
#include <unistd.h>     // pipe, write, read
#include <string.h>     //strlen

#include "cso.h"

int* cso_letrehoz(){
    int* cso = (int*)malloc(2*sizeof(int));
    if(pipe(cso) == -1){
        printf("Hiba a csovezetek letrehozaskor\n");
        exit(EXIT_FAILURE);
    }
    return cso;
}

void cso_ir(int descriptor[2], const char message[1024]){
    close(descriptor[0]);
    write(descriptor[1], message, strlen(message)+1);
    close(descriptor[1]);
}

void cso_olvas(int descriptor[2], char buffer[1024]){
    close(descriptor[1]);
    read(descriptor[0], buffer, 1024);
    close(descriptor[0]);
}

void cso_torol(int descriptor[2]){
    free(descriptor);
    descriptor = NULL;
}