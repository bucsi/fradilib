#include <stdio.h>
#include <stdlib.h>

#include "veletlen.h"

int veletlen_kozott(int also, int felso) {
    FILE* fp = fopen("/dev/urandom", "rb");
    int n;
    fread(&n, sizeof(int), 1, fp);
    fclose(fp);
    return abs(n % (felso - also) + also);
}