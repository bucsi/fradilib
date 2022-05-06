#ifndef SZIGNAL_H
#define SZIGNAL_H
#include <unistd.h> //pid_t

/**
 * Wrapper a kill() függvény köré, a cél processnek küld egy jelzést.
 * @param kinek A jelzés címzettjének process ID-je
 * @param mit Az elküldendő jelzés
 * @returns 0, ha sikeres volt a jelzésküldés, -1, ha hiba történt
 */
int szignalkuldes(pid_t kinek, int mit);

/**
 * Egyszerű signal handler függvény
 * @returns A konzolon kijelzi, hogy melyik folyamat hányas signalt kapott.
 */
void handler(int sign);

/**
 * Szám fogadása signalon keresztül. Az érkező számot kiírja a konzolra, valamint
 * @returns a signalon érkező szám
 */
int numberSignal(int signal);

/**
 * Egyszerű példa a signalokkal való információ-közvetítésre.
 */
void numOverSignal(int signal);

#endif