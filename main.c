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
    dicionario = lerLinhas("arquivos/sort_dict.txt", &nDicionario);
    ordena(dicionario, 0, nDicionario);  
    struct node *l = lista();        
    if (argc >= 3) {    
        if (strcmp(argv[1], "1") == 0) {            
            for (size_t i = 2; i < argc; i++)    
            {   
                char *str = correcao(dicionario, nDicionario, argv[i]);
                add(l, str);                     
            }                            
        } else if (strcmp(argv[1], "2") == 0) { 
            int *n = 0; 
            char **linhas;
            linhas = lerLinhas(argv[2], &n); 
            FILE *file;
            printf("Deseja corrigir direto no arquivo %s?\n", argv[2]);
            printf("[S/N]-> "); 
            char op = ' ';
            scanf("%c", &op);
            printf("%c\n", op);
            while (tolower(op) != 's' && tolower(op) != 'n')
            {
                printf("Entrada inválida. Tente novamente\n[S/N]-> ");
                scanf("%c", &op);
            }

            if (tolower(op) == 's') {
                file = fopen(argv[2], "w");
            }
            
            add(l, "\n");
            for (size_t i = 0; i < n; i++)
            {   
                char *token = strtok(linhas[i], " ");
                while (token != NULL) {
                    char *str = correcao(dicionario, nDicionario, token);
                    add(l, str);
                    if (tolower(op) == 's') {
                        fputs(str, file);
                        fputs(" ", file);
                    }
                    token = strtok(NULL, " ");
                }
                if (tolower(op) == 's') {
                    fputs("\n", file);
                }
                add(l, "\n");
            }  

            if (tolower(op) == 's') {
                fclose(file);
            }

        } else {   
            printf("Comando inválido.\n"); 
        }   
        imprimeLista(l);      
    } else if (argc == 2) {
        if (strcmp(argv[1], "1") == 0) {
            printf("Nada foi digitado...\n");
        } else {
            printf("Comando inválido.\n");
        }  
    }
}      
    