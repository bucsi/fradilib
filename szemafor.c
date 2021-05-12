#include <fcntl.h>     // szemaforkreálás opciók
#include <semaphore.h> // szemaforkezelés
#include <stdio.h>     // perror
#include <stdlib.h>    // exit

#include "szemafor.h"

sem_t *szemafor_letrehozas(char *nev) {
    sem_t *semid = sem_open(nev, O_CREAT, S_IRUSR | S_IWUSR, 0);
    if (semid == SEM_FAILED) {
        perror("sem_open");
    }
    return semid;
}

void szemafor_mehet(sem_t *szemafor) { sem_post(szemafor); }

void szemafor_var(sem_t *szemafor) { sem_wait(szemafor); }

void szemafor_torles(char *nev) { sem_unlink(nev); }