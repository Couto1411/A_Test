#include "matrix.h"

void preencheMatrix() {
	FILE* f;
	char arquivo[80];
	int barreirai, barreiraj;
	printf("Qual o nome do arquivo do labirinto? (Max 80)\n");
	fgets(arquivo, 80, stdin);
	arquivo[strlen(arquivo) - 1] = '\0';
	if (!(f = fopen(arquivo, "r"))) {
		printf("Erro ao abrir arquivo.\n");
		exit(1);
	}
	fscanf(f, "%d", &tamanhoMatrix);
	matrix = (int**)malloc(sizeof(int*) * (tamanhoMatrix + 1));
	for (int i = 0; i < tamanhoMatrix + 1; i++) {
		matrix[i] = (int*)malloc(sizeof(int) * tamanhoMatrix);
		for (int j = 0; j < tamanhoMatrix; j++)
			matrix[i][j] = 0;
	}
	while (!feof(f)) {
		fscanf(f, "%d", &barreirai);
		fgetc(f);
		fscanf(f, "%d", &barreiraj);
		matrix[barreirai][barreiraj] = 1;
	}
	fclose(f);
}

void printMatrix() {
	for (int i = 0; i < tamanhoMatrix; i++)
	{
		for (int j = 0; j < tamanhoMatrix; j++)
			printf("%d ", matrix[i][j]);
		printf("\n");
	}
}

bool isValid(int lin, int col){
    if (lin < 0 || col < 0 || lin >= tamanhoMatrix || col >= tamanhoMatrix){
        return false;
    }
    else if (matrix[lin][col]==1||matrix[lin][col]==2){
        return false;
    }
    else
        return true;
}