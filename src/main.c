#include "fila.h"

int main()
{
	FILE* arquivo;
	arquivo = fopen("Log.txt", "w");
	fprintf(arquivo, "%s", "Inicio:\n");
	fclose(arquivo);
	int iteracoes, euc_manh;
	Fila f;
	preencheMatrix();
	printMatrix();
	FFVazia(&f);
	printf("Deseja tentar por qual heurística? (Euclidiana-1, Manhattan-2)\n");
	scanf("%d",&euc_manh);
	iteracoes = BFS(&f,euc_manh);
	printf("Foram necessarias %d iteracoes para chegar a essa conclusao.\n", iteracoes);
	printMatrix();
	arquivo = fopen("Log.txt", "a");
	fprintf(arquivo, "%s", "Fim.");
	fclose(arquivo);

	return 0;
}