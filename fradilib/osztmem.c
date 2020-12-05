#include <string.h>       // strcpy
#include <sys/types.h>  // key_t
#include <stddef.h>     // NULL
#include <sys/shm.h>    // osztott memória
#include <sys/stat.h>   // osztott memória opciók

#include "osztmem.h"

char* memoria_letrehoz(key_t kulcs){
    int sh_mem_id = shmget(kulcs,1024,IPC_CREAT|S_IRUSR|S_IWUSR);
    return shmat(sh_mem_id,NULL,0);
}

void memoria_elenged(char* memoria){
    shmdt(memoria);
}

void memoria_ir(char* memoria, const char adat[1024]){
    strcpy(memoria, adat);
    memoria_elenged(memoria); // ez egy általam meghatározott default. Ha több dolgot is szeretnél az osztott memóriába írni, kommenteld ki, és a programból hívd meg a memoria_elenged függvényt!
}