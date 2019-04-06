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
void inserir_inicio(arrey * lista ){
    int dado;
    printf("Digite o novo conteudo qeu deseja inserir: ");
    scanf("%d", &dado);
        for (int i = lista->fim; i >= 0 ; --i) {
            lista->vet[i+1] = lista->vet[i];
        }
        lista->fim++;
        lista->vet[lista->inicio] = dado;

}
void inserir_fim(arrey* lista){
    int dado;
    printf("Digite o novo conteudo qeu deseja inserir: ");
    scanf("%d", &dado);
    if (lista->inicio = 0){
        inserir_inicio(lista);
    } else {
        lista->vet[lista->fim] = dado;
        lista->fim++;
    }
}
void inserir_posicao(arrey* lista){
    int dado;
    int posis;
    printf("Digite a Posição que deseja inserir: ");
    scanf("%d", &posis);
    printf("Digite o novo conteudo da posição |%d|: ", posis);
    scanf("%d", &dado);
    posis --;
    if(posis == 0 || posis == 1){
        inserir_inicio(lista);
    }else if(posis == lista->fim){
        inserir_fim(lista);
    }else {
        for (int i = lista->fim; i >= posis; --i) {
            lista->vet[i + 1] = lista->vet[i];
        }
        lista->vet[posis] = dado;
        lista->fim++;
    }
}
void remover_por_indice(arrey * lista){
    int index;
    printf("Digite o indice que deseja excluir: ");
    scanf("%d", &index);
    index --;
    for (int i= index; i <=lista->fim ; ++i) {
            lista->vet[i] = lista->vet[i+1];
    }
    lista->fim --;

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
    int opcao, dado;
    do{
        printf("\n------------Menu de opções------------\n");
        printf("Digite |1| para Inserir no Inicio: \n");
        printf("Digite |2| para Remover no Inicio: \n");
        printf("Digite |3| para Inserir no Fim: \n");
        printf("Digite |4| para Remover no Fim: \n");
        printf("Digite |5| para Inserir por Posição: \n");
        printf("Digite |6| para Remover por Posição: \n");
        printf("Digite |7| para Imprimir o Conteudo: \n");
        printf("Digite |0| para Sair: \n");
        scanf("%d", &opcao);
        if(opcao == 1)
            inserir_inicio(&lista);
        else if(opcao == 2)
            remover_inicio(&lista);
        else if(opcao == 3)
            inserir_fim(&lista);
        else if(opcao == 4)
            remover_fim(&lista);
        else if(opcao == 5)
            inserir_posicao(&lista);
        else if(opcao == 6)
            remover_por_indice(&lista);
        else if(opcao == 7)
            imprimir(lista);



    }while (opcao != 0);


    //printf("Hello, World!\n");
    return 0;
}
