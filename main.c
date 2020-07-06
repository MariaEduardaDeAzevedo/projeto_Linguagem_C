#include <stdio.h>
#include <stdlib.h>
#include <string.h>    
#include "imports.h"
#include "funcoes.h" 
#include "lista.h"       

/**
 * Corretor Ortográfico 
 **/
int main(int argc, char const *argv[]) 
{          
    char **dicionario;               
    int nDicionario = 0;              
    dicionario = lerLinhas("arquivos/sort_dict.txt", &nDicionario); //Importando dicionário
    ordena(dicionario, 0, nDicionario);  //Ordenando dicionário
    struct node *l = lista(); // Criando lista para armazenar palavras corrigidas
    if (argc >= 3) {    
        //Por linha de comando
        if (strcmp(argv[1], "1") == 0) {            
            for (size_t i = 2; i < argc; i++)    
            {   
                char *str = correcao(dicionario, nDicionario, argv[i]); //Correção da palavra
                add(l, str); //Adicionando palavra corrigida na lista
            }                            
        } else if (strcmp(argv[1], "2") == 0) { 
            int *n = 0; 
            char **linhas;
            linhas = lerLinhas(argv[2], &n); //Lendo linhas do arquivo
            FILE *file;
            printf("%s%sDeseja corrigir direto no arquivo %s?%s\n", BOLD, YELLOW, argv[2], NONE);
            printf("%s[S/N]-> %s", YELLOW, NONE); 
            char op = ' '; 
            scanf("%c", &op); //Lendo opção de gravação
            while (tolower(op) != 's' && tolower(op) != 'n')
            {
                printf("Entrada inválida. Tente novamente\n[S/N]-> ");
                scanf("%c", &op);
            }

            if (tolower(op) == 's') {
                file = fopen(argv[2], "w");//Abrindo arquivo para reescrita
            }
            
            add(l, "\n"); //Adicionando quebra de linha
            for (size_t i = 0; i < n; i++)
            {   
                //Lendo palavras por linha do arquivo
                char *token = strtok(linhas[i], " "); 
                while (token != NULL) {
                    char *str = correcao(dicionario, nDicionario, token); //Correção da palavra
                    add(l, str); //Adicionando palavra correta à lista de palavras
                    if (tolower(op) == 's') {
                        fputs(str, file);
                        fputs(" ", file);
                    }
                    token = strtok(NULL, " ");
                }
                if (tolower(op) == 's') {
                    fputs("\n", file); //Quebra de linha do arquivo
                }
                add(l, "\n"); //Adicionando quebra de linha à lista
            }  

            if (tolower(op) == 's') {
                fclose(file); //Fechando arquivo
            }

        } else {   
            printf("Comando inválido.\n"); 
        }   
        imprimeLista(l); //Imprimindo na saída o texto corrigido
    } else if (argc == 2) {
        if (strcmp(argv[1], "1") == 0) {
            printf("Nada foi digitado...\n");
        } else {
            printf("Comando inválido.\n");
        }  
    } else if (argc == 1) {
        //Interface fora da linha de comando
        int op = 0;
        printf("%sCORRETOR ORTOGRÁFICO%s\n", BOLD, NONE);
        printf("%s%sOPÇÕES DE CORREÇÃO: %s\n", BOLD, MAGENTA, NONE);
        printf("%s%s1. DIGITAR TEXTO\n2. IMPORTAR CONTEÚDO DE ARQUIVO%s\n", BOLD, YELLOW, NONE);
        printf("-> ");
        scanf("%d", &op);
        while (op != 1 && op != 2) {
            scanf("%d", &op);
        }

        if (op == 1) {
            //Lendo entrada digitada
            printf("%s%sDigite o texto a ser corrigido\n-> %s", BOLD, GREEN, NONE);
            char entrada[280];
            gets(entrada);
            gets(entrada);
            
            char *token = strtok(entrada, " "); //Separando linhas da entrada

            while (token != NULL)
            {
                char *str = correcao(dicionario, nDicionario, token); //Correção da palavra
                add(l, str); //Adicionando palavra corrigida à lista
                token = strtok(NULL, " ");
            }
        } else {
            //Lendo entrada de um arquivo
            printf("%s%sDigite o caminho do arquivo a ser corrigido\n-> %s", BOLD, GREEN, NONE);
            char entrada[280];
            gets(entrada);
            gets(entrada);
            int *n = 0; 
            char **linhas;
            linhas = lerLinhas(entrada, &n); //Lendo lihas do arquivo
            FILE *file;
            printf("%s%sDeseja corrigir direto no arquivo %s?%s\n", BOLD, YELLOW, entrada, NONE);
            printf("%s[S/N]-> %s", YELLOW, NONE); 
            char op = ' ';
            scanf("%c", &op); //Lendo opção de gravação
            printf("%c\n", op);
            while (tolower(op) != 's' && tolower(op) != 'n')
            {
                printf("%s%sEntrada inválida. Tente novamente\n[S/N]-> %s", BOLD, MAGENTA, NONE);
                scanf("%c", &op);
            }

            if (tolower(op) == 's') {
                printf("Arquivo %s modificado pela correção.\n", entrada);
                file = fopen(entrada, "w"); //Abrindo arquivo para a escrita
            }
            
            add(l, "\n");
            for (size_t i = 0; i < n; i++)
            {   
                //Separando palavras por linha do arquivo
                char *token = strtok(linhas[i], " "); 
                while (token != NULL) {
                    char *str = correcao(dicionario, nDicionario, token); //Correção da palavra
                    add(l, str); //Adicionando palavra corrigida à lista
                    if (tolower(op) == 's') {
                        fputs(str, file);
                        fputs(" ", file);
                    }
                    token = strtok(NULL, " ");
                }
                if (tolower(op) == 's') {
                    fputs("\n", file); //Adicionando quebra de linha ao arquivo
                }
                add(l, "\n"); //Adicionando quebra de linha à lista
            }  

            if (tolower(op) == 's') {
                fclose(file); //Fechando arquivo
            }
        }
        imprimeLista(l); //Imprimindo texto corrigido na saída 
    }
}      
    