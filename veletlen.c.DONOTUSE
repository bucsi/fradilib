#include <sys/random.h>

#include "veletlen.h"

int veletlen_kozott(int also, int felso) {
    unsigned int veletlen;
    getrandom(&veletlen, sizeof(unsigned int), 0);
    return veletlen % (felso - also) + also;
}