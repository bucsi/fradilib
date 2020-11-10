#include <stdio.h>      // printf
#include <unistd.h>     // getpid
#include <signal.h>     // SIGRTMIN

/**
 * Egyszerű signal handler függvény
 * @returns A konzolon kijelzi, hogy melyik folyamat hányas signalt kapott.
*/
void handler(int sign){
    printf("%d folyamat %d jelzést kapott.\n",getpid(), sign);
}

/**
 * Egyszerű példa a signalokkal való információ-közvetítésre.
*/
void numOverSignal(int signal){
    signal = signal - SIGRTMIN;
    if(signal == 0){
        // SIGRTMIN jelentése: nincs készleten a könyv
        printf("%d: Kár, hogy nincs.\n",getpid());
    }else{
        // SIGRTMIN+1 jelentése: készleten van a könyv
        printf("%d: Köszönöm, kérek egyet!\n",getpid()); 
    }
}

