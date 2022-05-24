#ifndef FILA_H 
#define FILA_H

#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef struct Item Item;
typedef struct Block Block;
typedef struct Fila Fila;

struct Item {
	int lin;
	int col;
	float distancia;
};

struct Block {
	Item data;
	Block* prox;
};

struct Fila {
	Block* first;
	Block* last;
};

void FFVazia(Fila* f);
void Enfileira(Fila* f, Item d);
void Desenfileira(Fila* f);
void logFila(Fila* fila);
void FImprime(Fila* f);
void preencheMatrix();
void printMatrix();
int BFS(Fila* fila,int eucli_manha);
bool isValid(int lin, int col);
float DistanciaEuclidiana(int lin, int col);
float DistanciaManhattan(int lin, int col);
void Ordena(Fila* fila, int lenght);
void swap(Item* xp, Item* yp);
int TamanhoFila(Fila* f);

#endif