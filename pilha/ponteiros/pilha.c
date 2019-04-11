#include <stdio.h>
#include <stdlib.h>
typedef struct no{
    int dado;
    struct no *baixo;
}node;
typedef struct pilha{
    int tamanho;
    node *topo;
}pilha;
void criar_pilha(pilha * pilhas){
    pilhas->topo = NULL;
    pilhas->tamanho = 0;
}
void inserir_pilha_vazia(pilha * pilha1, int dado){
    pilha1->topo = malloc(sizeof(node));
    pilha1->topo->dado = dado;
    pilha1->topo->baixo = NULL;
    //ALterando o fim da lista
    pilha1->tamanho++;
}
void inserir_no_fim(pilha * pilha1, int dado){
    if(pilha1->topo == NULL){
        inserir_pilha_vazia(pilha1, dado);
    }else{
        node * novo = malloc(sizeof(node));
        novo->dado = dado;
        novo->baixo = pilha1->topo;
        pilha1->topo = novo;
        pilha1->tamanho++;
    }
}
void impirmir(pilha pilha1){
    node * topo = pilha1.topo;
    while (topo  != NULL){
        printf("Conteudo |%d|\n", topo->dado);
        topo = topo->baixo;
    }
}
int main() {
    pilha stak;
    criar_pilha(&stak);
    inserir_pilha_vazia(&stak, 30);
    inserir_no_fim(&stak, 2);
    inserir_no_fim(&stak, 5);
    inserir_no_fim(&stak, 6);

    impirmir(stak);
    return 0;
}
