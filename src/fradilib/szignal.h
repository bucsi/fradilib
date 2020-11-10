#ifndef SZIGNAL_H
#define SZIGNAL_H

/**
 * Egyszerű signal handler függvény
 * @returns A konzolon kijelzi, hogy melyik folyamat hányas signalt kapott.
*/
void handler(int sign);

/**
 * Egyszerű példa a signalokkal való információ-közvetítésre.
*/
void numOverSignal(int signal);

#endif