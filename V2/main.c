#include "funcoes.h"
#include "imports.h"
#include <stdio.h>  
#include <ctype.h>
#include <string.h>   
#include <stdlib.h>  
  
//CORES
#define NONE "\033[0m" 
#define BOLD "\033[1m"  
#define MAGENTA "\033[35m"
#define GREEN "\033[32m" 
#define YELLOW "\033[33m"


int main(int argc, char const *argv[])
{
    
    int escolha = 0; //Opção a ser escolhida pelo usuário

    //Validação da entrada. Repetir pedido enquanto a entrada for inválida.
    while (escolha != 1 && escolha != 2)
    {       
        printf("%sCORRETOR ORTOGRÁFICO\n%sOPÇÕES DE CORREÇÃO:\n%s1. CORRIGIR ARQUIVO DE TEXTO\n2. DIGITAR TEXTO\n%s",
        BOLD, MAGENTA, YELLOW, NONE);
        printf("-> ");
        scanf("%d", &escolha);
        if (escolha != 1 && escolha != 2) {
            printf("\nOPÇÃO DESCONHECIDA... TENTE NOVAMENTE\n\n");
        }  
    }           
 
    //Importa arquivo com dicionário de palavras
    int nDicionario = 0; //Número de palavras do dicionário
    char **dicionario = NULL; 
    if (!(dicionario = importDicionario ("./arquivos/dicionario.txt", &nDicionario))) {
        fprintf (stderr, "erro: importaDicionario retornou NULL.\n");
        return 1; 
    }  
 
    //Ordena as palavras do dicionário  
    ordena(dicionario, 0, nDicionario);
      
    char entrada[1000] = "";      
     
    if (escolha == 1) { 
        printf("Informe o caminho do arquivo:\n-> ");
    } else {   
        printf("Digite o texto a ser corrigido:\n-> ");
    } 
    
    fgets(entrada, 1000, stdin);
    fgets(entrada, 1000, stdin);        
       
    char **palavras;
    int nPalavras = 0;    
       
    if (escolha == 1) { 
        entrada[strlen(entrada) - 1] = '\0';
        printf("%s\n", entrada); 
        if (!(palavras = lerArquivo(entrada, &nPalavras))) {
            fprintf (stderr, "erro: lerArquivo retornou NULL.\n");            
            return 1;      
        }                                         
        char *textoCorreto[nPalavras];
        correcao(dicionario, nDicionario, palavras, nPalavras, textoCorreto);  
    } else if (escolha == 2) { 
        entrada[strlen(entrada)] = '\0';        
        nPalavras = split(entrada, palavras); 
        char *textoCorreto[nPalavras]; 
        correcao(dicionario, nDicionario, palavras, nPalavras, textoCorreto);
        for (size_t i = 0; i < nPalavras; i++) 
        {      
            printf("%s ", textoCorreto[i]);         
        }
        printf("\n");
    }    
}
          