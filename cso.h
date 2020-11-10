#include <stdio.h>      // printf
#include <stdlib.h>     // malloc, exit
#include <unistd.h>     // pipe, write, read
#include <string.h>     //strlen

/**
 * Létrehoz egy csővezetéket.
 * @returns A csővezeték leírója, int* - egy 2 hosszú tömb.
 */
int* cso_letrehoz(){
    int* cso = malloc(2*sizeof(int));
    if(pipe(cso) == -1){
        printf("Hiba a csovezetek letrehozaskor\n");
        exit(EXIT_FAILURE);
    }
    return cso;
}

/**
 * Üzenet küldése egy csővezetéken keresztül
 * @param descriptor a csővezeték leíróra (int[2])
 * @param message az üzenet karaktertömbként - nincs limitáció a méretére, óvatosan!
 */
void cso_ir(int descriptor[2], const char message[1024]){
    close(descriptor[0]);
    write(descriptor[1], message, strlen(message)+1);
    close(descriptor[1]);
}

/**
 * Üzenet fogadása egy csővezetékből
 * @param descriptor a csővezeték leírója (int[2])
 * @param buffer az üzenet fogadására szolgáló buffer (char[100])
*/
void cso_olvas(int descriptor[2], char buffer[1024]){
    close(descriptor[1]);
    read(descriptor[0], buffer, 1024);
    close(descriptor[0]);
}