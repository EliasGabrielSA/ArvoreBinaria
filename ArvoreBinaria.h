typedef struct _arv {
    int info;
    struct _arv *esq;
    struct _arv *dir;
} Arv;

Arv *inicializa();
void imprime(Arv* a);
Arv *busca(Arv *a, int v);
Arv *insere(Arv *a, int v);
Arv *retira(Arv *a, int v);