#include <stdlib.h>     // exit
#include <stdio.h>      // perror
#include <semaphore.h>  // szemaforkezelés
#include <fcntl.h>      // szemaforkreálás opciók


/**
 * Szemafor létrehozása egyszerűen.
 * @param nev a szemafor neve, pl. "/gyerek1szemafor"
 * @param szemafor_ertek a szemafor kezdőértéke, általában 0.
 * @returns a szemafor, melyre a sem_post() és sem_wait() meghívható.
*/
sem_t* szemafor_letrehozas(char*nev,int szemafor_ertek){
    sem_t *semid=sem_open(nev,O_CREAT,S_IRUSR|S_IWUSR,szemafor_ertek );
	if (semid==SEM_FAILED){
        perror("sem_open");
    }  
    return semid;
}

/**
 * A szemaforral továbbindít egy várakozó programot.
*/
void szemafor_mehet(sem_t* szemafor){
    sem_post(szemafor);
}

/**
 * Megállítja a programot, amíg a szemafor nem vált.
*/
void szemafor_var(sem_t* szemafor){
    sem_wait(szemafor);
}

/**
 * Törli a szemafort.
*/
void szemafor_torles(char* nev){
    sem_unlink(nev);
}