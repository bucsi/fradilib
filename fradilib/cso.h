#ifndef CSO_H
#define CSO_H

/**
 * Létrehoz egy csővezetéket.
 * @returns A csővezeték leírója, int* - egy 2 hosszú tömb.
 */
int* cso_letrehoz();

/**
 * Üzenet küldése egy csővezetéken keresztül
 * @param descriptor a csővezeték leíróra (int[2])
 * @param message az üzenet karaktertömbként - nincs limitáció a méretére, óvatosan!
 */
void cso_ir(int descriptor[2], const char message[1024]);

/**
 * Üzenet fogadása egy csővezetékből
 * @param descriptor a csővezeték leírója (int[2])
 * @param buffer az üzenet fogadására szolgáló buffer (char[100])
*/
void cso_olvas(int descriptor[2], char buffer[1024]);

/**
 * Egy csővezeték törlése
 * @param descriptor a csővezeték leírója (int[2])
*/
void cso_torol(int descriptor[2]);

#endif