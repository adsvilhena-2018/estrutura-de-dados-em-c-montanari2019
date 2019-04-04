#include <stdio.h>
typedef struct arrey{
    int vet[1000];
    int inicio;
    int fim;
}arrey;
void criar_lista(arrey * lista){
    lista->fim = 0;
    lista->inicio = 0;
}
void inserir_inicio(arrey * lista, int dado){
        for (int i = lista->fim; i >= 0 ; --i) {
            lista->vet[i+1] = lista->vet[i];
        }
        lista->fim++;
        lista->vet[lista->inicio] = dado;

}
void inserir_fim(arrey* lista, int dado){
    if (lista->inicio = 0){
        inserir_inicio(lista,dado);
    } else {
        lista->vet[lista->fim] = dado;
        lista->fim++;
    }
}
void inserir_posicao(arrey* lista, int dado, int posis){
    posis --;
    if(posis == 0 || posis == 1){
        inserir_inicio(lista,dado);
    }else if(posis == lista->fim){
        inserir_fim(lista,dado);
    }else {
        for (int i = lista->fim; i >= posis; --i) {
            lista->vet[i + 1] = lista->vet[i];
        }
        lista->vet[posis] = dado;
        lista->fim++;
    }
}
void remover_inicio(arrey* lista){
    for (int i = 0; i <lista->fim ; ++i) {
        lista->vet[i] = lista->vet[i+1];
    }
    lista->fim--;
}
void remover_fim(arrey* lista){
    lista->fim--;
}
void imprimir(arrey lista){
    printf("--------------Função Imprimir--------------\n");
    for (int i = 0; i <lista.fim ; ++i) {
        printf("          Conteudo |%d| Indice |%d|\n", lista.vet[i], i+1);
    }
    printf("-------------------------------------------\n");
}
int main() {
    arrey  lista;
    criar_lista(&lista);
    inserir_inicio(&lista, 2);
    inserir_inicio(&lista, 3);
    inserir_inicio(&lista, 5);
    inserir_inicio(&lista, 99);
    inserir_inicio(&lista, 20);
    imprimir(lista);
    inserir_fim(&lista, 52);
    imprimir(lista);
    inserir_posicao(&lista, 250, 4);
    imprimir(lista);
    remover_inicio(&lista);
    imprimir(lista);
    remover_fim(&lista);
    imprimir(lista);

    //printf("Hello, World!\n");
    return 0;
}
