#ifndef FILA_H 
#define FILA_H

#include "matrix.h"

typedef struct ItemFila ItemFila;
typedef struct BlockFila BlockFila;
typedef struct Fila Fila;

struct ItemFila {
	int lin;
	int col;
	float distancia;
};

struct BlockFila {
	ItemFila data;
	BlockFila* prox;
};

struct Fila {
	BlockFila* first;
	BlockFila* last;
};

void FFVazia(Fila* f);
void Enfileira(Fila* f, ItemFila d);
void Desenfileira(Fila* f);
void logFila(Fila* fila, int bfs_euc_man);
void FImprime(Fila* f);
int BFS(Fila* fila,int eucli_manha);
float DistanciaEuclidiana(int lin, int col);
float DistanciaManhattan(int lin, int col);
void Ordena(Fila* fila, int lenght);
void swap(ItemFila* xp, ItemFila* yp);
int TamanhoFila(Fila* f);

#endif