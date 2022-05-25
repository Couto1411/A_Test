#include "pilha.h"

void FPVazia(Pilha *p){
    p->base = (BlockPilha*) malloc (sizeof(BlockPilha));
    p->top  = p->base;
    p->base->prox = NULL;
}

void Push(Pilha *p, ItemPilha d){
    BlockPilha *aux = (BlockPilha*) malloc (sizeof(BlockPilha));
    aux->data = d;
    aux->prox = p->top;
    p->top = aux;
}

void Pop(Pilha *p){
    BlockPilha *aux;

    if(p->base == p->top || p == NULL){
        printf("PILHA VAZIA!\n");
        return;
    }
    
    aux = p->top;
    p->top = aux->prox;
    free(aux);
}

void PImprime(Pilha *p){
    BlockPilha *aux;

    aux = p->top;
    while(aux != p->base){
        printf("%d,%d - ", aux->data.lin, aux->data.col);
        aux = aux->prox;
    }
    printf("\n");

}

void logPilha(Pilha *pilha){
    FILE *f;
    char str[500]="\0";
    char numero[7];
    f=fopen("DFS.txt","a");
    BlockPilha *aux;
    aux = pilha->top;
    while(aux != pilha->base){
        sprintf(numero, "%d", aux->data.lin);
        strcat(str,numero);
        strcat(str,",");
        sprintf(numero, "%d", aux->data.col);
        strcat(str,numero);
        strcat(str," - ");
        aux = aux->prox;
    }
    strcat(str,"\n");
    fprintf(f, "%s",str);
    fclose(f);
}

int DFS(Pilha *pilha){
    int iteracoes=0;
    int posicoesLinha[4] = { 0, -1, 0, 1 };
    int posicoesColuna[4] = { -1, 0, 1, 0 };
    ItemPilha item;
    item.col=0;
    item.lin=0;
    matrix[0][0]=2;

    Push(pilha,item);

    while ((!((item.col==tamanhoMatrix-1)&&(item.lin==tamanhoMatrix-1)))&&pilha->top->prox!=NULL) {
        int x = pilha->top->data.lin;
        int y = pilha->top->data.col;
        matrix[x][y]=2;
        Pop(pilha);
 
        for (int i = 0; i < 4; i++) {
            int adjx = x + posicoesLinha[i];
            int adjy = y + posicoesColuna[i];
            if (isValid(adjx,adjy)) {
                item.lin=adjx;
                item.col=adjy;
                Push(pilha,item);
            }
        }
        iteracoes++;
        logPilha(pilha);
    }
    if (pilha->top->prox!=NULL)
        printf("Chega no final\n");
    else
        printf("Não chega no final\n");
    return iteracoes;
}


