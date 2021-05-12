#include <signal.h> // SIGRTMIN
#include <stdio.h>  // printf
#include <unistd.h> // getpid

#include "szignal.h"

// Ez a függvény a leginkábbb "haszontalan" a gyűjteményben, de volt már problémám a paraméterek
// sorrendjének elfelejtésével, a dokumentációs komment remélhetőleg segít.
int szignalkuldes(pid_t kinek, int mit) { return kill(kinek, mit); }

void handler(int sign) { printf("%d folyamat %d jelzést kapott.\n", getpid(), sign); }

void numberSignal(int signal) {
    signal = signal - SIGRTMIN;
    printf("%d folyamat jelzésen keresztül ezt a számot kapta: %d", getpid(), signal);
    return signal;
}

void numOverSignal(int signal) {
    signal = signal - SIGRTMIN;
    if (signal == 0) {
        // SIGRTMIN jelentése: nincs készleten a könyv
        printf("%d: Kár, hogy nincs.\n", getpid());
    } else {
        // SIGRTMIN+1 jelentése: készleten van a könyv
        printf("%d: Köszönöm, kérek egyet!\n", getpid());
    }
}