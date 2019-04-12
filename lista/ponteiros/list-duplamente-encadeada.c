#include <stdio.h>
#include <stdlib.h>
typedef struct no{
    int dado;
    struct no * prox;
    struct no *ant;
}node;
typedef struct lista{
    int tamanho;
    node *inicio;
    node *fim;
}arrey;
void criar_lista(arrey * lista){
    lista->tamanho = 0;
    lista->inicio = NULL;
    lista->fim = NULL;
}
void inserir_lista_vazia(arrey * lista, int dado){
    lista->inicio = malloc(sizeof(node));
    lista->inicio->dado = dado;
    lista->inicio->prox = NULL;
    lista->inicio->ant = NULL;
    lista->fim = lista->inicio;
    lista->tamanho ++;
}
void inserir_no_inicio(arrey * lista, int dado){
    if(lista->inicio == NULL)
        inserir_lista_vazia(lista,dado);
    else{
        node *novo = malloc(sizeof(node));
        novo->dado = dado;
        novo->prox = lista->inicio;
        novo->ant = NULL;
        lista->inicio = novo;
        lista->tamanho++;
    }

}
void inserir_no_fim(arrey *lista, int dado){
    if(lista->inicio == NULL)
        inserir_lista_vazia(lista,dado);
    else{
        node *novo = malloc(sizeof(node));
        novo->dado = dado;
        novo->ant = lista->fim;
        novo->prox = NULL;
        lista->fim->prox = novo;
        lista->fim=novo;
        lista->tamanho ++;
    }
}
void inserir_por_index(arrey * lista, int dado, int pos){
    if(lista->inicio == NULL){
        inserir_lista_vazia(lista,dado);
    }else{
        for (int i = 0; i <pos-2 ; ++i) {
            lista->inicio = lista->inicio->prox;
        }
        node *novo = malloc(sizeof(node));
        novo->dado = dado;
        novo->prox = lista->inicio->prox;
        novo->ant = lista->inicio;
        lista->inicio->prox = novo;
        lista->tamanho++;
    }
}
void impirmir(arrey lista)
{
    int cont = 1;
    node *cabecas = lista.inicio;
    while (cabecas != NULL){
        printf("Conteudo |%d| ----------- Indice |%d|\n", cabecas->dado, cont);
        cabecas = cabecas->prox;
        cont++;
    }
}
void remover_inicio(arrey *lista){
    node * del = lista->inicio;
    lista->inicio = del->prox;
    lista->inicio->ant = NULL;
    free(del);
    lista->tamanho--;
}
void remover_fim(arrey *lista){

    node *del = lista->fim;
    lista->fim = del->ant;
    lista->fim->prox = NULL;
    free(del);
    lista->tamanho--;
}
int main() {
    arrey lista;
    criar_lista(&lista);
    inserir_lista_vazia(&lista, 30);
    inserir_no_inicio(&lista, 15);
    inserir_no_inicio(&lista, 10);
    inserir_no_inicio(&lista, 20);
    inserir_no_inicio(&lista, 28);
    inserir_no_fim(&lista, 98);
    inserir_por_index(&lista, 36, 2);
    remover_fim(&lista);
    return 0;
}
