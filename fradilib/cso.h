#ifndef CSO_H
#define CSO_H

#define cso_ir csobe_string
#define cso_olvas csobol_string

/**
 * Létrehoz egy csővezetéket.
 * @returns A csővezeték leírója, int* - egy 2 hosszú tömb.
 */
int *cso_letrehoz();

/**
 * Üzenet küldése egy csővezetéken keresztül
 * @param descriptor a csővezeték leíróra (int[2])
 * @param message az üzenet karaktertömbként - nincs limitáció a méretére,
 * óvatosan!
 */
void csobe_string(int descriptor[2], const char *message);

/**
 * Tetszőleges adat írása egy csővezetékbe
 * @param descriptor
 * @param data az írandó adatra mutató pointer
 * @param memsize az írandó adat mérete byteokban (sizeof eredménye)
 */
void csobe_adat(int descriptor[2], const void *data, size_t memsize);

/**
 * Üzenet fogadása egy csővezetékből
 * @param descriptor a csővezeték leírója (int[2])
 * @param buffer az üzenet fogadására szolgáló buffer (char[100])
 */
void csobol_string(int descriptor[2], char buffer[1024]);

/**
 * Tetszőleges adat olvasása egy csővezetékből
 * @param descriptor
 * @param data ide fogja olvasni az adatokat
 * @param memsize maximum enyni byte-ot olvas (sizeof eredménye)
 */
void csobol_adat(int descriptor[2], void *data, size_t memsize);

/**
 * Egy csővezeték törlése
 * @param descriptor a csővezeték leírója (int[2])
 */
void cso_torol(int descriptor[2]);

#endif