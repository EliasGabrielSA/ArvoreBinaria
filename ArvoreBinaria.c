#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"

Arv *inicializa(){
    return NULL;
}

void imprime(Arv* a) {
    if(a != NULL) {
        imprime(a->esq);
        printf("%d\n", a->info);
        imprime(a->dir);
    }
}

Arv *busca(Arv *a, int v) {
    if(a == NULL) return NULL;
    else if(a->info > v) return busca(a->esq, v);
    else if(a->info < v) return busca(a->dir, v);
    else return a;
}

Arv *insere(Arv *a, int v) {
    if(a == NULL) {
        a = (Arv*)malloc(sizeof(Arv));
        a->info = v;
        a->esq = a->dir = NULL;
    } else if(v < a->info) {
        a->esq = insere(a->esq, v);
    } else {
        a->dir = insere(a->dir, v);
    }
}

Arv *retira(Arv *a, int v) {
    if (a == NULL) return NULL;
    else if(a->info > v) a->esq = retira(a->esq, v);
    else if(a->info < v) a->dir = retira(a->dir, v);
    else { /* achou o elemento */
        if (a->esq == NULL && a->dir == NULL) {
            free (a);
        } else if (a->esq == NULL) { 
            Arv* t = a;
            a = a->dir;
            free (t);
        } else if (a->dir == NULL) {
            Arv* t = a;
            a = a->esq;
            free (t);
        } else { 
            Arv* pai = a;
            Arv* f = a->esq;
            while (f->dir != NULL) {
                pai = f;
                f = f->dir;
            }
            a->info = f->info; /* troca as informações */
            f->info = v;
            a->esq = retira(a->esq,v);
        }
    }
    return a;
}
