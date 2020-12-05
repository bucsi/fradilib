#ifndef SZEMAFOR_H
#define SZEMAFOR_H

#include <semaphore.h>  // szemaforkezelés

/**
 * Szemafor létrehozása egyszerűen.
 * @param nev a szemafor neve, pl. "/gyerek1szemafor"
 * @param szemafor_ertek a szemafor kezdőértéke, általában 0.
 * @returns a szemafor, melyre a sem_post() és sem_wait() meghívható.
*/
sem_t* szemafor_letrehozas(char*nev,int szemafor_ertek);

/**
 * A szemaforral továbbindít egy várakozó programot.
*/
void szemafor_mehet(sem_t* szemafor);

/**
 * Megállítja a programot, amíg a szemafor nem vált.
*/
void szemafor_var(sem_t* szemafor);

/**
 * Törli a szemafort.
*/
void szemafor_torles(char* nev);

#endif