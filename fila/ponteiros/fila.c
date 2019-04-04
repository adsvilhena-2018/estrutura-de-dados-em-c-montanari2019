#include <stdio.h>
#include <stdlib.h>
typedef struct no{
    int file;
    struct no* prox;
}Node;
typedef struct Fila{
    int tamanho;
    Node* head;
    Node* end;
}Kiui;
Kiui* criar_fila(Kiui* fila){
    fila->head = NULL;
    fila->end = NULL;
    fila->tamanho = 0;
    return fila;
}
void enfileirar(Kiui *fila, int dado){

    if(fila->head == NULL){
        fila->head = malloc(sizeof(Node));
        fila->end = fila->head;
        fila->head->prox = NULL;
        fila->head->file=dado;
    }else{
        Node* new = malloc(sizeof(Node));
        new->file = dado;
        new->prox = NULL;
        fila->end->prox = new;
        fila->end = new;
        fila->tamanho++;
    }

}
void desinfeleirar(Kiui* fila){
    Node *cabeca = fila->head;
    fila->head = cabeca->prox;
    free(cabeca);
}
void imprirmir_fila(Kiui Fila){
    Node *cabeca = Fila.head;
    printf("\n---------------FILA-------------\n");
    while (cabeca != NULL) {
        printf("|%d|", cabeca->file);
        cabeca = cabeca->prox;
    }
    printf("\n");
}

int main() {
    Kiui fila;
    criar_fila(&fila);
    int opcao, dado;
    do{
        printf("\n------------Menu de opções------------\n");
        printf("Digite |1| para Emfileirar: \n");
        printf("Digite |2| para Desenfileirar: \n");
        printf("Digite |3| para Impirmir a Fila: \n");
        printf("Digite |0| para Sair: \n");
        scanf("%d", &opcao);
        if(opcao == 1){
            printf("Digite o Item a ser inserido: ");
            scanf("%d", &dado);
            enfileirar(&fila, dado);
            printf("\n----------FILA ATUALIZADA----------");
            imprirmir_fila(fila);
        }
        if (opcao == 2){
            desinfeleirar(&fila);
            printf("Item Desinfeleirado\n");
            printf("----------FILA ATUALIZADA----------");
            imprirmir_fila(fila);
        }
        if(opcao == 3){
            imprirmir_fila(fila);
        }

    }while (opcao != 0);
    printf("Você encerrou o programa");

    return 0;
}
