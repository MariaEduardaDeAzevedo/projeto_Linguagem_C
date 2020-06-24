#include <stdio.h>
#include <string.h>

int busca(char *array[], char item[], int inicio, int fim);
void ordena(char *array[], int inicio, int fim);
void merge(char *array[], int inicio, int meio, int fim);
void separa(char*dest[], char *array[], int inicio, int fim);
void ordenaPorDistancia(char *array[], int len_array, char palavra[]);
void selectionSort(char *array[], int inicio, int size, char palavra[]);
/**
 *Algoritmo de ordenação do Merge Sort 
 **/
void ordena(char *array[], int inicio, int fim) {
    if (fim - inicio > 1) { // Se o array tiver mais de um elemento
        int meio = (fim + inicio) / 2; //Calcula o meio do array
        ordena(array, inicio, meio); //Ordena primeira metade
        ordena(array, meio, fim); //Ordena a segunda metade
        merge(array, inicio, meio, fim); //Une partes ordenadas
    }
}

/**
 * Algoritmo do merge
 **/
void merge(char *array[], int inicio, int meio, int fim) {
    int tamEsquerda = meio - inicio; //Tamanho do array da esquerda
    int tamDireita = fim - meio; //Tamanho do array da direita
    char *esquerda[tamEsquerda]; //Array da esquerda
    char *direita[tamDireita]; //Array da direita
    int topoEsquerda = 0; //Posição do topo da esquerda
    int topoDireita = 0; //Posição do topo da direita
    separa(esquerda, array, inicio, meio); //Split do array da esquerda
    separa(direita, array, meio, fim); //Split do array da direita

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

/** 
 * Copia parte de um array para outro array 
 **/
void separa(char*dest[], char *array[], int inicio, int fim) {
    int cont = 0;
    for (size_t i = inicio; i < fim; i++)
    {
        dest[cont] = array[i];
        cont ++;
    }
}

/** 
 * Algoritmo da busca binária 
 **/
int busca(char *array[], char item[], int inicio, int fim) {

    if (inicio < fim) { //Se o array for possível
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
        //Caso não encontre nada
        return -1;
    }
}

/**
 * Algoritmo de Levenshtein para calcular similaridade entre strings  
 **/
int levenshtein(const char *str1, int len_str1, const char *str2, int len_str2) {
    int a, b, c;

    if (len_str1 == 0) { 
        //Se o comprimento da str1 for 0, retorna o comprimento da str2
        return len_str2;
    } else if (len_str2 == 0) {
        //Se o comprimento da str2 for 0, retorna o comprimento da str1
        return len_str1;
    } else if (str1[len_str1 - 1] == str2[len_str2 - 1]) {
        //Caso as últimas posições das strings sejam iguais,
        //chama-se mais uma vez o algoritmo até o tamanho anterior - 1
        return levenshtein(str1, len_str1 - 1, str2, len_str2 - 1);
    }
        
    //Caso não satisfaça as condições

    //Calcula a distância até o penúltimo elemento
    a = levenshtein(str1, len_str1 - 1, str2, len_str2 - 1);
    //Calcula a distância da str1 completa com a str2
    //até o penúltimo
    b = levenshtein(str1, len_str1, str2, len_str2 - 1);
    //Calcula a distância da str2 completa com a str1
    //até o penúltimo
    c = levenshtein(str1, len_str1 - 1, str2, len_str2);

    if (a > b) { 
        a = b;
    }
    if (a > c) {  
        a = c;
    }
    return a + 1;
}

int min(char *array[], int inicio, int fim, char palavra[]) {
    int men = inicio;
    for (size_t i = inicio; i < fim; i++)
    {
        int dist = levenshtein(array[i], strlen(array[i]), palavra, strlen(palavra));
        if (dist == 1) {
            return i;
        } else if (men > dist) {
            men = i;
        }
    }

    return men;
}

void selectionSort(char *array[], int inicio, int size, char palavra[]) {

    for (size_t i = inicio; i < size; i++)
    {
        int men = min(array, i, size, palavra);
        int dist1 = levenshtein(array[i], strlen(array[i]), palavra, strlen(palavra));
        int dist2 = levenshtein(array[men], strlen(array[men]), palavra, strlen(palavra));
        if (dist2 < dist1) {
            int *temp = array[i];
            array[i] = array[men];
            array[men] = temp;
        } 
        
        int distA = levenshtein(array[0], strlen(array[0]), palavra, strlen(palavra));
        int distB = levenshtein(array[1], strlen(array[1]), palavra, strlen(palavra));
        int distC = levenshtein(array[2], strlen(array[2]), palavra, strlen(palavra));
        printf("%d, %d, %d\n", distA, distB, distC);
        if (distA == 1 && distB == 1 && distC == 1) {
            return;
        }
    }
}