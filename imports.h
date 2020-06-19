
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define comprimentoDaLista 256
#define comprimentoDasPalavras 46

char **importaDicionario (char *fileName, int *n);
void liberaArray (char** palavras, int linhas);
char **pegaLinhas (char *fileName, int *n);
void limpaPalavra(char *palavra);

char **importaDicionario (char *fileName, int *n) {

    FILE *file = fopen (fileName, "r");

    if (!file) { /* valida a abertura do arquivo */
        fprintf (stderr, "erro: abertura do arquivo falhou.\n");
        return 1;
    }
    
    char **palavras = NULL;
    char buf[comprimentoDasPalavras + 1] = {0};
    int maxlen = comprimentoDaLista > 0 ? comprimentoDaLista : 1;

    if (!(palavras = calloc (maxlen, sizeof *palavras))) {
        fprintf (stderr, "importaDicionario() erro: memória virtual exaurida.\n");
        return NULL;
    }

    while (fgets (buf, comprimentoDasPalavras + 1, file)) {

        size_t wordlen = strlen (buf);  

        if (buf[wordlen - 1] == '\n')  
            buf[--wordlen] = 0;

        palavras[(*n)++] = strdup (buf);   

        if (*n == maxlen) { 
            void *tmp = realloc (palavras, maxlen * 2 * sizeof *palavras);
            if (!tmp) {
                fprintf (stderr, "importaDicionario() realloc: memória exaurida.\n");
                return palavras;
            }
            palavras = tmp;
            memset (palavras + maxlen, 0, maxlen * sizeof *palavras);
            maxlen *= 2;
        }
    }

    fclose(file);
    return palavras;
}

char **pegaLinhas (char *fileName, int *n) {
    char **palavras = NULL;
    FILE *arq = NULL;
    char buf[BUFSIZ] = {0};
    int maxlen = comprimentoDaLista > 0 ? comprimentoDaLista : 1;

    arq = fopen(fileName, "r");

    if (!(palavras = calloc (maxlen, sizeof *palavras))) {
        fprintf (stderr, "pegaPalavras() erro: memória virtual exaurida.\n");
        return NULL;
    }

    while(fgets(buf, BUFSIZ, arq) != NULL) {
        char *token = strtok(strdup(buf), " ");

        while (token != NULL) {
            
            limpaPalavra(token);
            
            palavras[(*n)++] = token; 
            token = strtok(NULL, " ");
            if (*n == maxlen) { 
                void *tmp = realloc (palavras, maxlen * 2 * sizeof *palavras);
                if (!tmp) {
                    return palavras;
                }
                palavras = tmp;
                memset (palavras + maxlen, 0, maxlen * sizeof *palavras);
                maxlen *= 2;
            }    
        }    
    }

    fclose(arq);
    return palavras;
}

void liberaArray (char **words, int rows){
    int i;
    for (i = 0; i < rows; i++){
        free (words[i]);
    }
    free(words);
}

void limpaPalavra(char *palavra) {
    size_t tamanho = strlen (palavra);  

    int inicio = palavra[0];
    int fim = palavra[tamanho - 1];  

    if (palavra[tamanho - 1] == '\n') {
        palavra[--tamanho] = 0;
    } 
    
    if (!((fim >= 65 && fim <= 90) 
    || (fim >= 97 && fim <= 122)
    || (fim >= 128 && fim <= 167)
    || (fim >= 48 && fim <= 57)))  {
        palavra[--tamanho] = 0;
    } 

    if (!((inicio >= 65 && inicio <= 90) 
    || (inicio >= 97 && inicio <= 122)
    || (inicio >= 128 && inicio <= 167)
    || (inicio >= 48 && inicio <= 57)))  {
        for (size_t i = 1; i < tamanho; i++)
        {
            palavra[i - 1] = palavra[i]; 
        }
    }
}