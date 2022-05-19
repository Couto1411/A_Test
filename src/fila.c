#include "fila.h"

void FFVazia(Fila *f){
	f->first = (Block*) malloc (sizeof(Block));
	f->last  = f->first;
	f->first->prox = NULL;
}

void Enfileira(Fila *f, Item d){
	f->last->prox = (Block*) malloc (sizeof(Block));
	f->last = f->last->prox;
	f->last->data = d;
	f->last->prox = NULL;
}

void Desenfileira(Fila *f){
	Block *aux;
	if(f->first == f->last || f == NULL || f->first->prox == NULL){
		return;
	}
	aux = f->first;
	f->first = f->first->prox;
	free(aux);
}

void preencheMatrix(){
    FILE *f;
	char arquivo[80];
	int barreirai,barreiraj;
	printf("Qual o nome do arquivo do labirinto? (Max 80)\n");
	fgets(arquivo,80,stdin);
	arquivo[strlen(arquivo)-1]='\0';
    if(!(f=fopen(arquivo,"r"))){
        printf("Erro ao abrir arquivo.\n");
        exit(1);
    }
	fscanf(f,"%d",&tamanhoMatrix);
	matrix=(int**) malloc(sizeof(int*)*(tamanhoMatrix+1));
	for (int i = 0; i < tamanhoMatrix+1; i++){
		matrix[i]=(int*)malloc(sizeof(int)*tamanhoMatrix);
		for (int j = 0; j < tamanhoMatrix; j++)
			matrix[i][j]=0;
	}
	while(!feof (f)){
		fscanf(f,"%d",&barreirai);
		fgetc(f);
		fscanf(f,"%d",&barreiraj);
		matrix[barreirai][barreiraj]=1;
	}
    fclose(f);
}

void logFila(Fila *fila){
	FILE *f;
	char str[500]="\0";
	char numero[7];
	f=fopen("Log.txt","a");
	Block *aux;
	aux = fila->first->prox;
	while(aux != NULL){
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

void FImprime(Fila *f){
	Block *aux;

	aux = f->first->prox;
	while(aux != NULL){
		printf("%d, %d-", aux->data.lin, aux->data.col);
		aux = aux->prox;
	}
	printf("\n");
}

void printMatrix(){
	for (int i = 0; i < tamanhoMatrix; i++)
	{
		for (int j = 0; j < tamanhoMatrix; j++)
			printf("%d ",matrix[i][j]);
		printf("\n");
	}
}

int BFS(Fila *fila){
	int iteracoes=0;
	int posicoesLinha[4] = { 1, 0, -1, 0 };
	int posicoesColuna[4] = { 0, 1, 0, -1 };
    Item item;
	item.col=0;
	item.lin=0;
	matrix[0][0]=2;

    Enfileira(fila,item);

    while ((!((item.col==tamanhoMatrix-1)&&(item.lin==tamanhoMatrix-1)))&&fila->first->prox!=NULL) {
        int x = fila->first->prox->data.lin;
        int y = fila->first->prox->data.col;
        Desenfileira(fila);

        for (int i = 0; i < 4; i++) {
            int adjx = x + posicoesLinha[i];
            int adjy = y + posicoesColuna[i];
            if (isValid(adjx,adjy)) {
				item.lin=adjx;
				item.col=adjy;
                Enfileira(fila,item);
				matrix[adjx][adjy]=2;
            }
        }

		iteracoes++;
		logFila(fila);
    }
	if (fila->first->prox!=NULL)
		printf("Chega no final\n");
	else
		printf("Não chega no final\n");
	return iteracoes;
}

bool isValid(int lin, int col){
    if (lin < 0 || col < 0 || lin >= tamanhoMatrix || col >= tamanhoMatrix)
        return false;
    else if (matrix[lin][col]==1||matrix[lin][col]==2)
        return false;
    else
		return true;
}