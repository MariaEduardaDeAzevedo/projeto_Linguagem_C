#ifndef _LISTA_H_
#define _LISTA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Implementação de lista simples
 **/

struct node; 
struct node *lista();
struct node *add(struct node *n, char str[]);
void imprimeLista(struct node *l);

//Estrutura de nó da lista
struct node {
    char *elemento; //Elemento
    int index; //Índice
    struct node *link; //Próximo nó
};

//Construtor
struct node *lista() {
    //Alocando novo nó
    struct node *l = (struct node*) malloc(sizeof(struct node*));
    l->index = 0; //Adicionando índice 0
    l->link = NULL; //Próximo nó NULL
    l->elemento = NULL; //Elemento atual NULL
    return l;
}

//Adicionando novo nó na lista
struct node *add(struct node *n, char str[]) {
    //Percorrendo lista enquando o próximo elemento não for nulo
    while (n->elemento != NULL)
    {
        n = n->link;
    }

    //Alocando o novo nó da lista
    struct node *l = (struct node*) malloc(sizeof(struct node*));
    l->index = n->index + 1; //Incrementando índice para o próximo nó
    l->elemento = NULL; //Elemento do próximo nó recebe NULL
    l->link = n; //Link do próximo nó recebe o atual
    n->link = l; //Link do nó atual recebe o novo nó
    n->elemento = str; //Adicionando elemento no nó atual
    return n;
}

//Imprimindo conteúdo da lista
void imprimeLista(struct node *l) {
    //Criando referência para lista
    struct node *lista = (struct node*) malloc(sizeof(struct node*));
    lista = l;
    if (lista) { //Se a lista existir
        do
        {
            printf("%s ", lista->elemento); //Imprime o elemento do nó atual
            lista = lista->link; //Vai para o próximo nó da lista
        } while (lista->elemento != NULL); //Enquanto o próximo elemento da lista não for NULL
        printf("\n");
    } else { //Caso a lista seja vazia
        printf("Vazia\n");
    }
}

#endif 