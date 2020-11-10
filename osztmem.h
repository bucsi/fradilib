#include <sys/types.h>  // key_t
#include <stddef.h>     // NULL
#include <sys/shm.h>    // osztott memória
#include <sys/stat.h> // osztott memória opciók

/**
 * Létrehoz egy 1024 méretű osztott memóriát.
 * @param kulcs A <sys/types.h> :: ftok(argv[0], 1) által létrehozott kulcs.
 * @returns char*, amely az osztott memóriára mutat.
*/
char* memoria_letrehoz(key_t kulcs){
    int sh_mem_id = shmget(kulcs,1024,IPC_CREAT|S_IRUSR|S_IWUSR);
    return shmat(sh_mem_id,NULL,0);
}

/**
 * Bezárja, "elengedi" az osztott memóriát.
 * @param memoria A memória címe
*/
void memoria_elenged(char* memoria){
    shmdt(memoria);
}

/**
 * A paraméterként kapott stringet beírja a memóriába, majd bezárja azt.
 * @param memoria A memória címe
 * @param adat Az írandó string (max 1024 hosszú)
*/
void memoria_ir(char* memoria, const char adat[1024]){
    strcpy(memoria, adat);
    memoria_elenged(memoria); // ez egy általam meghatározott default. Ha több dolgot is szeretnél az osztott memóriába írni, kommenteld ki, és a programból hívd meg a memoria_elenged függvényt!
}
