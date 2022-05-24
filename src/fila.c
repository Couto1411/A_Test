#include "fila.h"

void FFVazia(Fila* f) {
	f->first = (BlockFila*)malloc(sizeof(BlockFila));
	f->last = f->first;
	f->first->prox = NULL;
}

void Enfileira(Fila* f, ItemFila d) {
	f->last->prox = (BlockFila*)malloc(sizeof(BlockFila));
	f->last = f->last->prox;
	f->last->data = d;
	f->last->prox = NULL;
}

void Desenfileira(Fila* f) {
	BlockFila* aux;
	if (f->first == f->last || f == NULL || f->first->prox == NULL) {
		return;
	}
	aux = f->first;
	f->first = f->first->prox;
	free(aux);
}

void logFila(Fila* fila) {
	FILE* f;
	char str[500] = "\0";
	char numero[7];
	f = fopen("Log.txt", "a");
	BlockFila* aux;
	aux = fila->first->prox;
	while (aux != NULL) {
		sprintf(numero, "%d", aux->data.lin);
		strcat(str, numero);
		strcat(str, ",");
		sprintf(numero, "%d", aux->data.col);
		strcat(str, numero);
		strcat(str, " - ");
		aux = aux->prox;
	}
	strcat(str, "\n");
	fprintf(f, "%s", str);
	fclose(f);
}

void FImprime(Fila* f) {
	BlockFila* aux;

	aux = f->first->prox;
	while (aux != NULL) {
		printf("%d, %d/%.2f\t", aux->data.lin, aux->data.col, aux->data.distancia);
		aux = aux->prox;
	}
	printf("\n");
}

int BFS(Fila* fila,int eucli_manha) {
	int iteracoes = 0;
	int posicoesLinha[4] = { 1, 0, -1, 0 };
	int posicoesColuna[4] = { 0, 1, 0, -1 };
	ItemFila item;
	item.col = 0;
	item.lin = 0;
	if (eucli_manha==1)
		item.distancia = DistanciaEuclidiana(item.lin, item.col);
	else if(eucli_manha==2)
		item.distancia = DistanciaManhattan(item.lin, item.col);
	matrix[0][0] = 2;
	Enfileira(fila, item);

	while ((!((item.col == tamanhoMatrix - 1) && (item.lin == tamanhoMatrix - 1))) && fila->first->prox != NULL) {

		int x = fila->first->prox->data.lin;
		int y = fila->first->prox->data.col;
		Desenfileira(fila);

		for (int i = 0; i < 4; i++) {
			int adjx = x + posicoesLinha[i];
			int adjy = y + posicoesColuna[i];
			if (isValid(adjx, adjy)) {
				item.lin = adjx;
				item.col = adjy;
				if (eucli_manha==1)
            		item.distancia = DistanciaEuclidiana(item.lin, item.col);
            	else if(eucli_manha==2)
            		item.distancia = DistanciaManhattan(item.lin, item.col);
				Enfileira(fila, item);
				matrix[adjx][adjy] = 2;
			}
		}
		if(eucli_manha==2||eucli_manha==1)
			Ordena(fila, TamanhoFila(fila));
		item.lin = fila->first->prox->data.lin;
		item.col = fila->first->prox->data.col;
		iteracoes++;
		logFila(fila);
	}
	if (fila->first->prox != NULL)
		printf("Chega no final\n");
	else
		printf("Não chega no final\n");
	return iteracoes;
}

float DistanciaEuclidiana(int lin, int col) {
	float distancia;
	distancia = sqrt((pow((lin - (tamanhoMatrix - 1)), 2) + pow((col - (tamanhoMatrix - 1)), 2)));
	return distancia;
}
float DistanciaManhattan(int lin, int col) {
	float distancia;
	distancia = abs((lin-(tamanhoMatrix-1)))+abs((col-(tamanhoMatrix-1)));
	return distancia;
}

void Ordena(Fila* fila, int lenght) {
	BlockFila* aux;
	ItemFila lista[lenght];
	int i = 0, j;
	aux = fila->first->prox;
	while (aux != NULL) {
		lista[i] = aux->data;
		aux = aux->prox;
		i++;
	}
	bool swapped;
	for (i = 0; i < lenght - 1; i++)
	{
		swapped = false;
		for (j = 0; j < lenght - i - 1; j++)
		{
			if (lista[j].distancia > lista[j + 1].distancia)
			{
				swap(&lista[j], &lista[j + 1]);
				swapped = true;
			}
		}
		if (swapped == false)
			break;
	}
	aux = fila->first->prox;
	i = 0;
	while (aux != NULL) {
		aux->data=lista[i];
		aux = aux->prox;
		i++;
	}

}
void swap(ItemFila* xp, ItemFila* yp)
{
	ItemFila temp = *xp;
	*xp = *yp;
	*yp = temp;
}

int TamanhoFila(Fila* f) {
	BlockFila* aux;
	int cont = 0;
	aux = f->first->prox;
	while (aux != NULL) {
		cont++;
		aux = aux->prox;
	}
	return cont;
}