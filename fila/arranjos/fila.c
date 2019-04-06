#include <stdio.h>
typedef struct arrey{
    int vet[1000];
    int fim;
}fila;
void criar_fila(fila *kiui){
    kiui->fim = 0;
}
void enfileirar(fila * kiui){
    int dado;
    printf("Digite o novo conteudo qeu deseja inserir: ");
    scanf("%d", &dado);
    kiui->vet[kiui->fim] = dado;
    kiui->fim ++;
}
void desinfeleirar(fila * kiui){

    for (int i = 0; i <kiui->fim ; ++i) {
        kiui->vet[i] = kiui->vet[i+1];
    }kiui->fim--;
}
void imprimir(fila  kiui){
    if(kiui.fim == 0){
        printf("fila Vazia\n");
        printf("Deseja Popular a Fila");
    }

        printf("--------------Função Imprimir--------------\n");
        for (int i = 0; i <kiui.fim ; ++i) {
            printf("          Conteudo |%d| Indice |%d|\n", kiui.vet[i], i+1);
        }
        printf("-------------------------------------------\n");

}
int main() {
    fila arrey;
    criar_fila(&arrey);
    int opcao;
    do{
        printf("\n------------Menu de opções------------\n");
        printf("Digite |1| para Emfileirar: \n");
        printf("Digite |2| para Desenfileirar: \n");
        printf("Digite |3| para Impirmir a Fila: \n");
        printf("Digite |0| para Sair: \n");
        scanf("%d", &opcao);
        if(opcao == 1){
            enfileirar(&arrey);
        }
        if (opcao == 2){
            desinfeleirar(&arrey);
            printf("Item Desinfeleirado\n");

        }
        if(opcao == 3){
            imprimir(arrey);
        }

    }while (opcao != 0);





    return 0;
}
