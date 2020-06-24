#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define comprimentoDaLista 256
#define comprimentoDasPalavras 256

char **importDicionario (char *fileName, int *n);
char **lerArquivo (char *fileName, int *n);

char **importDicionario (char *fileName, int *n) {

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

char **lerArquivo (char *fileName, int *n) {
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
