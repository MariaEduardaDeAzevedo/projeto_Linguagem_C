#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lista.h"

//CORES
#define NONE "\033[0m"
#define BOLD "\033[1m"
#define MAGENTA "\033[35m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"

int split(char str[], char **array);
void ordena(char *array[], int inicio, int fim);
void merge(char *array[], int inicio, int meio, int fim);
void slice(char*dest[], char *array[], int inicio, int fim);
int busca(char *array[], char item[], int inicio, int fim);
char *correcao(char **dicionario, int nDicionario, char str[]);
void getPalavra(char palavra[]);

char *corrigePalavra(char str[], char correta[], char errada[]);
int buscaParecidas(char **array, int n, char palavra[], int enc[]);
int existeNoArray(int array[], int index);
void invertePalavra(char palavra[], char ret[]);


int split(char str[], char **array) {
    char *token = strtok(str, " ");
    int cont = 0; //Guardar a posição
    while (token != NULL) { //Enquando o token for diferente de NULL
        array[cont] = token; //Guarda a palavra
        cont ++; //Avança posição
        token = strtok(NULL, " ");
    }
    return cont;
}


void ordena(char *array[], int inicio, int fim) {
    if (fim - inicio > 1) { // Se o array tiver mais de um elemento
        int meio = (fim + inicio) / 2; //Calcula o meio do array
        ordena(array, inicio, meio); //Ordena primeira metade
        ordena(array, meio, fim); //Ordena a segunda metade
        merge(array, inicio, meio, fim); //Une partes ordenadas
    }
}


void merge(char *array[], int inicio, int meio, int fim) {
    int tamEsquerda = meio - inicio; //Tamanho do array da esquerda
    int tamDireita = fim - meio; //Tamanho do array da direita
    char *esquerda[tamEsquerda]; //Array da esquerda
    char *direita[tamDireita]; //Array da direita
    int topoEsquerda = 0; //Posição do topo da esquerda
    int topoDireita = 0; //Posição do topo da direita
    slice(esquerda, array, inicio, meio); //Split do array da esquerda
    slice(direita, array, meio, fim); //Split do array da direita

    for (size_t i = inicio; i < fim; i++)
    {   
        if (topoEsquerda >= tamEsquerda) { //Caso do array da esquerda estoure
            array[i] = direita[topoDireita];
            topoDireita ++;
        } else if (topoDireita >= tamDireita) { //Caso do array da esquerda estoure
            array[i] = esquerda[topoEsquerda];
            topoEsquerda ++;
        } else if (strcmp(direita[topoDireita], esquerda[topoEsquerda]) > 0) { //Caso o array da esquerda tenha o menor valor
            array[i] = esquerda[topoEsquerda];
            topoEsquerda ++;
        } else { //Caso o array da direita tenha o menor valor
            array[i] = direita[topoDireita];
            topoDireita ++;
        }
    }
}


void slice(char*dest[], char *array[], int inicio, int fim) {
    int cont = 0;
    for (size_t i = inicio; i < fim; i++)
    {
        dest[cont] = array[i];
        cont ++;
    }
}


int busca(char *array[], char item[], int inicio, int fim) {

    if (inicio <= fim) { //Se o array for possível
        int meio = (inicio + fim) / 2; //Calcula o meio do array
        if (strcmp(array[meio], item) == 0) { 
            //Caso o meio for igual ao que se procura, retorna o índice
            return meio;
        } else if (strcmp(item, array[meio]) > 0) { 
            //Caso o item procurado esteja mais a direita
            busca(array, item, meio + 1, fim);
        } else {
            //Caso o item procurado esteja mais a esquerda
            busca(array, item, inicio, meio - 1);
        }
    } else {
        return -1;
    }
}


char *correcao(char **dicionario, int nDicionario, char str[]) {
    char palavra[100];
    slice(palavra, str, 0, strlen(str));
    getPalavra(palavra);
    int buscaRes = busca(dicionario, palavra, 0, nDicionario);
    if (buscaRes == -1) {
        int indices[3] = {-1};
        //buscaParecidas(dicionario, nDicionario, palavra, indices);
        indices[0] = buscaParecidas(dicionario, nDicionario, palavra, indices);
        indices[1] = buscaParecidas(dicionario, nDicionario, palavra, indices);
        indices[2] = buscaParecidas(dicionario, nDicionario, palavra, indices);
        printf("\n%s%sA palavra %s%s%s pode estar escrita incorretamente, as opções de substituição são:%s\n", BOLD, MAGENTA, YELLOW, palavra, MAGENTA, NONE);
        printf("%s%s1. %s\n2. %s\n3. %s%s\n", BOLD, GREEN, dicionario[indices[0]], dicionario[indices[1]], dicionario[indices[2]], NONE);
        printf("%sDigite o número da palavra a ser usada ou 0 para permanecer com a palavra %s.%s\n-> ", YELLOW, palavra, NONE);
        int opcao = 0;
        scanf("%d", &opcao);
        if (opcao == 1) {
            return corrigePalavra(str, dicionario[indices[0]], palavra);
        } else if (opcao == 2) {
            return corrigePalavra(str, dicionario[indices[1]], palavra);
        } else if (opcao == 3) {
            return corrigePalavra(str, dicionario[indices[2]], palavra);
        } else {
            return str;
        }
    }
    return str;
}


void getPalavra(char palavra[]) {
    size_t tamanho = strlen (palavra);  
    int inicio = palavra[0];
    int fim = palavra[tamanho - 1];  

    if (fim == '\n') {
        palavra[--tamanho] = '\0';
        fim = palavra[tamanho - 1];
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
        palavra[tamanho - 1] = '\0';
    }

    for (size_t i = 0; i <= tamanho; i++)
    {
        palavra[i] = tolower(palavra[i]);
    }
}


char *corrigePalavra(char str[], char correta[], char errada[]) {
    int tamanhoTexto = strlen(str);
    int tamanhoCorreta = strlen(correta);
    int tamanhoErrada = strlen(errada);
    int tamanhoNova = tamanhoErrada + (tamanhoCorreta - tamanhoErrada);  
    int fim = str[tamanhoTexto - 1];
    int inicio = str[0];

    int charI = 0;
    int charF = 0;

    if (!((fim >= 65 && fim <= 90) 
    || (fim >= 97 && fim <= 122)
    || (fim >= 128 && fim <= 167)
    || (fim >= 48 && fim <= 57)))  {
        tamanhoNova ++;
        charF = 1;
    }

    if (!((inicio >= 65 && inicio <= 90) 
    || (inicio >= 97 && inicio <= 122)
    || (inicio >= 128 && inicio <= 167)
    || (inicio >= 48 && inicio <= 57)))  {
        tamanhoNova ++;
        charI = 1;
    }

    char *nova;
    nova = malloc(tamanhoNova);
    nova[tamanhoNova] = '\0';

    if (charI == 1) {
        nova[0] = str[0];   
    }

    if (charF == 1) {
        nova[tamanhoNova - 1] = str[tamanhoTexto - 1];
    }

    int j = 0;
    for (size_t i = charI; i < tamanhoNova - charF; i++)
    {
        if (i == charI && ((int) str[charI] >= 65 && (int) str[charI] <= 90)) {
            nova[i] = toupper(correta[j]);    
        } else {
            nova[i] = correta[j];
        }
        j ++;
    }

    return nova;
}


int buscaParecidas(char **array, int n, char palavra[], int enc[]) {
    double maior = -1;
    int menorIndex;
    int tamPalavra = strlen(palavra);
    char erradaInvertida[tamPalavra];
    invertePalavra(palavra, erradaInvertida);
    for (size_t i = 0; i < n; i++)
    {
        if (existeNoArray(enc, i) == 0) {
            int tamCorreta = strlen(array[i]);
            
            int p1 = 0;
            for (size_t j = 0; j < tamCorreta; j++)
            {
                if ((int) array[i][j] == (int) palavra[j]) {
                    p1 ++;
                }
            }
            
            char corretaInvertida[tamCorreta];
            invertePalavra(array[i], corretaInvertida);
            
            int p2 = 0;
            for (size_t j = 0; j < tamCorreta; j++)
            {
                if ((int) corretaInvertida[j] == (int) erradaInvertida[j]) {
                    p2 ++;
                }
            }

            double porcentagem = 0;



            if (tamPalavra > tamCorreta) {
                porcentagem = (p1 + p2)/(tamPalavra * 1.0);
            } else if (p1 == p2) {
                porcentagem = (p1 + 1)/(tamCorreta * 1.0);
            } else {
                porcentagem = (p1 + p2)/(tamCorreta * 1.0);
            }
            
            while (porcentagem > 1)
            {
                porcentagem--;
            }

            int tamMenor = 0;
            if (tamCorreta > tamPalavra) {
                tamMenor = tamPalavra;
            } else {
                tamMenor = tamCorreta;
            }

            tamMenor ++;
            tamMenor = tamMenor/2;

            if (porcentagem > maior || maior == -1) {
                maior = porcentagem;
                menorIndex = i;
            } else if (porcentagem == maior && strncmp(array[i], palavra, tamMenor) == 0) {
                maior = porcentagem;
                menorIndex = i;
            }
        }
    }
    return menorIndex;
}


void invertePalavra(char palavra[], char ret[]) {
    int tam = strlen(palavra);
    int j = tam - 1;
    for (size_t i = 0; i < tam; i++)
    {
        ret[i] = palavra[j];
        j --;
    }
}


int existeNoArray(int array[], int index) {
    for (size_t i = 0; i < 3; i++)
    {
        if (array[i] == index) {
            return 1;
        }
    }
    return 0;
}
