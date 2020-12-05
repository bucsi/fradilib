#ifndef OSZTMEM_H
#define OSZTMEM_H

/**
 * Létrehoz egy 1024 méretű osztott memóriát.
 * @param kulcs A <sys/types.h> :: ftok(argv[0], 1) által létrehozott kulcs.
 * @returns char*, amely az osztott memóriára mutat.
*/
char* memoria_letrehoz(key_t kulcs);

/**
 * Bezárja, "elengedi" az osztott memóriát.
 * @param memoria A memória címe
*/
void memoria_elenged(char* memoria);

/**
 * A paraméterként kapott stringet beírja a memóriába, majd bezárja azt.
 * @param memoria A memória címe
 * @param adat Az írandó string (max 1024 hosszú)
*/
void memoria_ir(char* memoria, const char adat[1024]);

#endif