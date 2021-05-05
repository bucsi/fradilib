#ifndef VELETLEN_H
#define VELETLEN_H

/**Előállít egy véletlen egész számot két határérték között.
 * CSAK LINUX 3.17, VAGY ÚJABB KERNELEN MŰKÖDIK!
 * @param also az alsó határ (inkluzív)
 * @param felso a felső határ (exkluzív)
 */
int veletlen_kozott(int also, int felso);

#endif