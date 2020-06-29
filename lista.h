#ifndef _LISTA_H_
#define _LISTA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node;
struct node *lista();
struct node *add(struct node *n, char str[]);
void imprimeLista(struct node *l);

struct node {
    char *elemento;
    int index;
    struct node *link;
};

struct node *lista() {
    struct node *l = (struct node*) malloc(sizeof(struct node*));
    l->index = 0;
    l->link = NULL;
    l->elemento = NULL;
    return l;
}

struct node *add(struct node *n, char str[]) {
    while (n->elemento != NULL)
    {
        n = n->link;
    }

    struct node *l = (struct node*) malloc(sizeof(struct node*));
    l->index = n->index + 1;
    l->elemento = NULL;
    l->link = n;
    n->link = l;
    n->elemento = str;
    return n;
}

void imprimeLista(struct node *l) {
    struct node *lista = (struct node*) malloc(sizeof(struct node*));
    lista = l;
    if (lista) {
        do
        {
            printf("%s ", lista->elemento);
            lista = lista->link;
        } while (lista->elemento != NULL);
        printf("\n");
    } else {
        printf("Vazia\n");
    }
}

#endif 