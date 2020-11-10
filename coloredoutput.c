#include <stdio.h>

#define red "\033[0;31m"
#define green "\033[0;32m"
#define reset "\033[0m"

int main(){
    printf("%sPiros%s\n", red, reset);
    printf("%sFehér%s\n", reset, reset);
    printf("%sZöld%s\n", green, reset);
}