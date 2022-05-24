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
void printMatrix();
bool isValid(int lin, int col);

#endif