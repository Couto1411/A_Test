#ifndef PILHA_H 
#define PILHA_H

#include "matrix.h"

typedef struct ItemPilha ItemPilha;
typedef struct BlockPilha BlockPilha;
typedef struct Pilha Pilha;

struct ItemPilha{
	int lin;
	int col;
};

struct BlockPilha{
	ItemPilha data;
	BlockPilha *prox;
};

struct Pilha{
	BlockPilha *base;
	BlockPilha *top;
};

void FPVazia(Pilha *p);
void Push(Pilha *p, ItemPilha d);
void Pop(Pilha *p);
void PImprime(Pilha *p);
int DFS(Pilha *p);
#endif