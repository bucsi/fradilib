#ifndef SZEMAFOR_H
#define SZEMAFOR_H

#include <semaphore.h> // szemaforkezelés

/**
 * Szemafor létrehozása egyszerűen.
 * @param nev a szemafor neve, pl. "/gyerek1szemafor"
 * @returns a szemafor, melyre a sem_post() és sem_wait() meghívható.
 */
sem_t *szemafor_letrehozas(char *nev);

/**
 * A szemaforral továbbindít egy várakozó programot.
 */
void szemafor_mehet(sem_t *szemafor);

/**
 * Megállítja a programot, amíg a szemafor nem vált.
 */
void szemafor_var(sem_t *szemafor);

/**
 * Törli a szemafort.
 */
void szemafor_torles(char *nev);

#endif