#ifndef MATRIX_H
#define MATRIX_H

#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

int tamanhoMatrix;
int** matrix;

void preencheMatrix();
void resetaMatrix();
void printMatrix();
bool isValid(int lin, int col);
void AbreArquivo(int opcao);
void FechaArquivo(int opcao);

#endif