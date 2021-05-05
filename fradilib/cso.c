#include <stdio.h>  // printf
#include <stdlib.h> // malloc, exit
#include <string.h> //strlen
#include <unistd.h> // pipe, write, read

#include "cso.h"

cso *cso_letrehoz() {
    int *uj_cso = (int *)malloc(2 * sizeof(int));
    if (pipe(uj_cso) == -1) {
        printf("Hiba a csovezetek letrehozaskor\n");
        exit(EXIT_FAILURE);
    }
    return uj_cso;
}

void csobe_string(cso descriptor, const char *message) {
    write(descriptor[1], message, strlen(message) + 1);
}

void csobe_adat(cso descriptor, const void *data, size_t memsize) {
    write(descriptor[1], data, memsize);
}

void csobol_string(cso descriptor, char *buffer) { read(descriptor[0], buffer, 1024); }

void csobol_adat(cso descriptor, void *data, size_t memsize) { read(descriptor[0], data, memsize); }

void cso_torol(cso descriptor) {
    free(descriptor);
    descriptor = NULL;
}