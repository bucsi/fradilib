#include <stdlib.h>     // exit
#include <stdio.h>      // perror
#include <semaphore.h>  // szemaforkezelés
#include <fcntl.h>      // szemaforkreálás opciók

#include "szemafor.h"

sem_t* szemafor_letrehozas(char*nev,int szemafor_ertek){
    sem_t *semid=sem_open(nev,O_CREAT,S_IRUSR|S_IWUSR,szemafor_ertek );
	if (semid==SEM_FAILED){
        perror("sem_open");
    }  
    return semid;
}

void szemafor_mehet(sem_t* szemafor){
    sem_post(szemafor);
}

void szemafor_var(sem_t* szemafor){
    sem_wait(szemafor);
}

void szemafor_torles(char* nev){
    sem_unlink(nev);
}