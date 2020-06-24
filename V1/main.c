#include "algoritmos.h"
#include "imports.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NONE "\033[0m"
#define BOLD "\033[1m"
#define MAGENTA "\033[35m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"

void correcao(char **palavras, char **dicionario, int nDicionario, int nPalavras);
int buscaMenorDistancia(char *array[], int inicio, int fim, char palavra[], int menor);
void buscaMenorDistanciaIterativa(char *array[], int inicio, int fim, char palavra[], int indices[]);
int comparaBuscas(char *array[], int inicio, int fim, char palavra[], int menor);

int main (int argc, char **argv) {  

    //Importa arquivo com dicionário de palavras
    int nDicionario = 0;
    char **dicionario = NULL;
    if (!(dicionario = importaDicionario ("./arquivos/dicionario.txt", &nDicionario))) {
        fprintf (stderr, "erro: importaDicionario retornou NULL.\n");
        return 1;
    }

    //Ordena as palavras do dicionário
    ordena(dicionario, 0, nDicionario);

    //Carrega linhas do arquivo a ser avaliado
    int nPalavras = 0;
    char **palavras = NULL;

    if (!(palavras = pegaLinhas("./arquivos/arquivo.txt", &nPalavras))) {
        fprintf (stderr, "erro: arquivo vazio.\n");
        return 1;
    }

    //Sujestões de correção das palavras
    correcao(palavras, dicionario, nDicionario, nPalavras);  
    
    for (size_t i = 0; i < nPalavras; i++)
    {
        printf("%s ", palavras[i]);
    }

    printf("\n");

    return 0;
}
 
void correcao(char **palavras, char **dicionario, int nDicionario, int nPalavras) {
    int opcao = 0;
    for (size_t i = 0; i < nPalavras; i++)
    {     
        int indice_busca = busca(dicionario, palavras[i], 0, nDicionario);
        if (indice_busca == -1) {
            
            int indices[3] = {0};
            buscaMenorDistanciaIterativa(dicionario, 0, nDicionario, palavras[i], indices);

            printf("\n%s%sA palavra %s%s%s pode estar escrita incorretamente, as opções de substituição são:%s\n", BOLD, MAGENTA, YELLOW, palavras[i], MAGENTA, NONE);
            printf("%s%s1. %s\n2. %s\n3. %s%s\n", BOLD, GREEN, dicionario[indices[0]], dicionario[indices[1]], dicionario[indices[2]], NONE);
            printf("%sDigite o número da palavra a ser usada ou 0 para permanecer com a palavra %s.%s\n", YELLOW, palavras[i], NONE);
               
            printf("%s-> %s", BOLD, NONE);
            scanf("%d", &opcao);
            while (opcao > 3 || opcao < 0) {
                printf("Valor inválido\nDigite o número da palavra a ser usada ou 0 para permanecer com a palavra.\n");
                printf("%s-> %s", BOLD, NONE);
                scanf("%d", &opcao);
            }
            if (opcao == 1) {
                palavras[i] = dicionario[indices[0]];
            } else if (opcao == 2) {
                palavras[i] = dicionario[indices[1]]; 
            } else if (opcao == 3) {
                palavras[i] = dicionario[indices[2]];
            }
        }   
    }
}

int buscaMenorDistancia(char *array[], int inicio, int fim, char palavra[], int menor) {
    if (inicio < fim) {

        int meio = (inicio + fim) / 2;

        if (menor == -1) {
            menor = meio;
        }

        int distanciaMenor = levenshtein(palavra, strlen(palavra), array[menor], strlen(array[menor]));
        int distanciaMeio = levenshtein(palavra, strlen(palavra), array[meio], strlen(array[meio]));

        if (distanciaMenor == 1) {
            return menor;
        }

        if (distanciaMeio < distanciaMenor) {
            menor = meio;
        }
        
        if (strcmp(palavra, array[meio]) > 0) {
            buscaMenorDistancia(array, meio + 1, fim, palavra, menor);
        } else {
            buscaMenorDistancia(array, inicio, meio, palavra, menor);
        }
        
    } else {
        return menor;
    }
}

void buscaMenorDistanciaIterativa(char *array[], int inicio, int fim, char palavra[], int indices[]) {
    int menor = -1;
    for (size_t i = inicio + 1; i < fim; i++)
    {
        int dist = levenshtein(array[i], strlen(array[i]), palavra, strlen(palavra));

        if (dist == 1) {
            indices[0] = i - 1;
            indices[1] = i;
            indices[2] = i + 1;
            menor = dist;
            break;
        }
        
        if (menor == -1 || menor > dist) {
            indices[0] = i - 1;
            indices[1] = i;
            indices[2] = i + 1;
            menor = dist;
        }
    }
}