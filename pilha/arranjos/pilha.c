#include <stdio.h>
#include <stdlib.h>
typedef struct arrey{
    int vetor[1000];
    int fim;
}vet;
void criar_arrey(vet * pilha){
    pilha->fim = -1;
}
void empilhar(vet *pilha , int dado){
    pilha->vetor[pilha->fim+1] = dado;
    pilha->fim++;
}
void desempilha(vet * pilha){
   if(pilha->fim == -1){
       printf("Fila vazia");
   }else
    pilha->fim--;
}
void imprimir(vet pilha){
    printf("-----------Função Imprimir---------------\n");
    for (int i = 0; i <=pilha.fim ; ++i) {
        printf("Conteudo |%d| Indice |%d|\n", pilha.vetor[i], i+1);
    }
}

int main() {
    vet pilha;
    criar_arrey(&pilha);
    empilhar(&pilha, 20);
    empilhar(&pilha, 30);
    empilhar(&pilha, 40);
    empilhar(&pilha, 50);
    desempilha(&pilha);
    desempilha(&pilha);
    
    return 0;
}
