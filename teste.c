#include <stdio.h>
#include "algoritmos.h"

int main(int argc, char const *argv[])
{
    int a = levenshtein("espasso", 7, "espaço", 6);
    int b = levenshtein("ossapse", 7, "oçapse", 6);
    printf("a - %d\nb - %d\n", a, b);
    return 0;
}
