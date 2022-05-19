#ifndef FILA_H 
#define FILA_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef struct Item Item;
typedef struct Block Block;
typedef struct Fila Fila;

struct Item{
	int lin;
	int col;
};

struct Block{
	Item data;
	Block *prox;
};

struct Fila{
	Block *first;
	Block *last;
};

int tamanhoMatrix;
int **matrix;

void FFVazia(Fila *f);
void Enfileira(Fila *f, Item d);
void Desenfileira(Fila *f);
void logFila(Fila *fila);
void FImprime(Fila *f);
void preencheMatrix();
void printMatrix();
int BFS(Fila *fila);
bool isValid(int lin, int col);

#endif