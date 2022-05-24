#include "fila.h"
#include "pilha.h"

int main()
{
	Pilha p;
	Fila f;
	FILE* arquivo;
	int iteracoes, opcao;
	arquivo = fopen("Log.txt", "w");
	fprintf(arquivo, "%s", "Inicio:\n");
	fclose(arquivo);
	preencheMatrix();
	printMatrix();
	FFVazia(&f);
	FPVazia(&p);
	printf("Qual algoritmo de busca deseja?\n\t0-BFS\n\t1-A*\n\t2-DFS\n");
	scanf("%d",&opcao);
	switch (opcao)
	{
	case 0:
		iteracoes = BFS(&f,opcao);
		break;
	case 1:
		printf("Qual heurística de busca deseja?\n\t1-Euclidiana\n\t2-Manhattan\n");
		scanf("%d",&opcao);
		iteracoes = BFS(&f,opcao);
		break;
	case 2:
		iteracoes=DFS(&p);
		break;
	default:
		break;
	}
	printf("Foram necessarias %d iteracoes para chegar a essa conclusao.\n", iteracoes);
	printMatrix();
	arquivo = fopen("Log.txt", "a");
	fprintf(arquivo, "%s", "Fim.");
	fclose(arquivo);

	return 0;
}