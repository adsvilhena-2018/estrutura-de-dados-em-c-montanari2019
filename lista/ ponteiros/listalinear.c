#include <stdio.h>
#include <stdlib.h>
typedef struct no{
    int dado;
    struct no * prox;
}node;
typedef struct arrey{
    int tamanho;
    node * inicio;
}List;
void criar_lista(List * lista){
    lista->tamanho = 0;
    lista->inicio = NULL;
}
void inserir_lista_vazia(List * lista, int dado){
    lista->inicio = malloc(sizeof(node));
    lista->inicio->dado = dado;
    lista->inicio->prox = NULL;
    lista->tamanho++;
}
void inserir_inicio(List *lista, int dado){
    if (lista->inicio == NULL){
        inserir_lista_vazia(lista,dado);
    }else{
        node * cabeca = lista->inicio;
        node * novo = malloc(sizeof(node));
        novo->dado = dado;
        novo->prox = cabeca->prox;
        cabeca->prox = novo;
        lista->tamanho++;

    }
}
void inserir_no_fim(List * lista, int dado){
    if (lista->inicio == NULL){
        inserir_lista_vazia(lista,dado);
    }else{
        node *cabeca= lista->inicio;
        node *novo = malloc(sizeof(node));
        while (cabeca->prox != NULL){
            cabeca = cabeca->prox;
        }
        novo->dado = dado;
        novo->prox = NULL;
        cabeca->prox = novo;
        lista->tamanho++;
    }

}
void inserir_por_index(List * lista, int poss, int dado){
    if (lista->inicio == NULL){
        inserir_lista_vazia(lista,dado);
    }else{
        node * cabeca = lista->inicio;
        node *novo = malloc(sizeof(node));
        for (int i = 0; i <poss-2 ; ++i) {
            cabeca = cabeca->prox;
        }
        novo->dado = dado;
        novo->prox = cabeca->prox;
        cabeca->prox = novo;
        lista->tamanho++;
    }
}
void remover_inicio(List * lista){
    char op;
    int dado;
    if (lista->inicio == NULL){
        printf("Lista vazia\n Deseja popular sua lista?(S/N)");
        scanf(op);
        if(op == 'S'){
            printf("DIigte o valor a ser inserido: ");
            scanf("%d",&dado);
            inserir_lista_vazia(lista,dado);
        }else{
            printf("Você prefiriu deixar a lista vazia\n");
        }
    }else {
        node *cabeca = lista->inicio;
        lista->inicio = lista->inicio->prox;
        free(cabeca);
        lista->tamanho--;
    }
}
void remover_fim(List * lista){
    char op;
    int dado;
    if (lista->inicio == NULL){
        printf("Lista vazia\n Deseja popular sua lista?(S/N)");
        scanf(op);
        if(op == 'S'){
            printf("DIigte o valor a ser inserido: ");
            scanf("%d",&dado);
            inserir_lista_vazia(lista,dado);
        }else{
            printf("Você prefiriu deixar a lista vazia\n");
        }
    }else{
        node *cabeca = lista->inicio;
        node *anterior = lista->inicio;
        while (cabeca->prox != NULL){
            anterior = cabeca;
            cabeca = cabeca->prox;
        }
        anterior->prox = NULL;
        free(cabeca);
        lista->tamanho--;

    }
}
void remover_por_index(List * lista, int pos){
    char op;
    int dado;
    if (lista->inicio == NULL){
        printf("Lista vazia\n Deseja popular sua lista?(S/N)");
        scanf(op);
        if(op == 'S'){
            printf("DIigte o valor a ser inserido: ");
            scanf("%d",&dado);
            inserir_lista_vazia(lista,dado);
        }else{
            printf("Você prefiriu deixar a lista vazia\n");
        }
    }else{
        node *cabeca = lista->inicio;
        node * antetior = lista->inicio;
        for (int i = 0; i <pos-1 ; ++i) {
            antetior = cabeca;
            cabeca = cabeca->prox;
        }
        antetior->prox = cabeca->prox;
        free(cabeca);
        lista->tamanho--;
    }

}
void imprimir(List lista){
    int cont = 1;
    node* cabeca = lista.inicio;
    printf("-----------IMPRIMIR LISTA-----------\n");
    while (cabeca != NULL){
        printf("Conteudo |%d| ------------ Indice |%d|\n", cabeca->dado, cont);
        cabeca = cabeca->prox;
        cont++;
    }
    printf("\n");

}
int main() {
    List lista;
    criar_lista(&lista);
    inserir_lista_vazia(&lista, 2);
    inserir_inicio(&lista, 35);
    inserir_inicio(&lista, 25);
    inserir_inicio(&lista, 14);
    inserir_inicio(&lista, 99);
    inserir_no_fim(&lista, 2018);
    inserir_por_index(&lista, 3,2015);
    imprimir(lista);

    return 0;
}
