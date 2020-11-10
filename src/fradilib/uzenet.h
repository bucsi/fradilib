#ifndef UZENET_H
#define UZENET_H

#include <sys/types.h>
/**
 * üzenet struktúra az üzenetsorokhoz.
*/
struct uzenet { 
    long mtype;
    char mtext [ 1024 ]; 
};


/**
 * Létrehozza az üzenetsort.
 * @param kulcs a <sys/types.h>::ftok(argv[0], 1) által létrehozott kulcs.
 * @returns az üzenetsor, int-ként.
*/
int uzenetsor_letrehoz(key_t kulcs);
/**
 * Üzenet küldése egy üzenetsoron keresztül
 * @param uzenetsor az üzenetsor
 * @param message az üzenet karaktertömbként (1024 hosszú)
*/
void uzenet_kuld(int uzenetsor, const char message[1024]);

/**
 * Üzenet fogadása egy üzenetsorról
 * @param uzenetsor az üzenetsor
 * @returns az üzenet a konzolra kerül kiírásra
 */
void uzenet_fogad(int uzenetsor);

#endif