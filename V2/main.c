#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "imports.h"
#include "funcoes.h" 
#include "lista.h"     
    
int main(int argc, char const *argv[])
{   
    char **dicionario; 
    int nDicionario = 0;   
    dicionario = importDicionario("arquivos/sort_dict.txt", &nDicionario);
    ordena(dicionario, 0, nDicionario); 
    struct node *l = lista();  
    if (strcmp(argv[1], "1") == 0) {   
        for (size_t i = 2; i < argc; i++)  
        { 
            char *str = correcao(dicionario, nDicionario, argv[i]);
            add(l, str);   
        }
    } else if (strcmp(argv[1], "2") == 0) {
        char **palavras;
        int *n = 0;
        palavras = lerArquivo(argv[2], &n); 
        for (size_t i = 0; i < n; i++)
        { 
            char *str = correcao(dicionario, nDicionario, palavras[i]);
            add(l, str);    
        } 
    } else {
        printf("Comando inválido.\n");
    }
    imprimeLista(l);
}      
    