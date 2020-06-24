#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    
    int dif = 0;
    int ig = 0;
    int tam = 7;
    char array[7] = "saldade";
    char palavra[7] = "saudade";
    char invertida1[7] = "edadlas";
    char invertida2[7] = "edaduas";
    for (size_t j = 1; j < tam; j++)
    {   
        if (strncmp(array, palavra, j) != 0) {
            dif ++;
        }     

        if (strncmp(invertida1, invertida2, j) == 0) {
            ig ++;
        }
    }

    printf("%d %d\n", dif, ig);
}
