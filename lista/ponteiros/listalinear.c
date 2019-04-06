#include <stdio.h>
#include <stdlib.h>
typedef struct no{
    int dado;
    struct no * prox;
}node;
typedef struct Arrey{
    int tamanho;
    node * head;
}lista;
void criar_lista(lista * list){
    list->head = NULL;
    list->tamanho = 0;
}
void inserir_inicio(lista * list, int dado){
    list->head = malloc(sizeof(node));
    list->head->dado = dado;
    list->head->prox = NULL;
    list->tamanho++;
}
void inserir_no_fim(lista * lista, int dado){
    node * novo = malloc(sizeof(node));
    novo->dado = dado;
    novo->prox = NULL;
    lista->head->prox = novo;
    lista->tamanho ++;
}
void inserir_por_index(lista * list, int dado, int pos){
        
}
void imprimir(lista  list){
    node * cabeca = list.head;
    int cont = 1;
    while (cabeca != NULL){
        printf("Conteudo |%d|   Index |%d|\n", cabeca->dado,cont);
        cabeca = cabeca->prox;
        cont++;
    }
}
int main() {
    lista list;
    criar_lista(&list);
    inserir_inicio(&list, 2);
    inserir_no_fim(&list, 50);
    imprimir(list);


    return 0;
}
