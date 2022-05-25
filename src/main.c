#include "fila.h"
#include "pilha.h"

int main()
{
	Pilha p;
	Fila f;
	int iteracoes, opcao;
	bool loop=true;
	preencheMatrix();
	printMatrix();
	do
	{
		resetaMatrix();
		printf("Qual algoritmo de busca deseja?\n\t0-BFS\n\t1-A*\n\t3-DFS\n\t9-SAIR\n");
		scanf("%d",&opcao);
		switch (opcao)
		{
		case 0:
			AbreArquivo(0);
			FFVazia(&f);
			iteracoes = BFS(&f,opcao);
			
			FechaArquivo(0);
			break;
		case 1:
			FFVazia(&f);
			printf("Qual heurística de busca deseja?\n\t1-Euclidiana\n\t2-Manhattan\n");
			scanf("%d",&opcao);
			if (opcao==1)
				AbreArquivo(1);
			else
				AbreArquivo(2);
			iteracoes = BFS(&f,opcao);
			
			if (opcao==1)
				FechaArquivo(1);
			else
				FechaArquivo(2);
			break;
		case 3:
			AbreArquivo(3);
			FPVazia(&p);
			iteracoes=DFS(&p);
			
			
			FechaArquivo(3);
			break;
		case 9:
			loop=false;
			break;
		default:
			break;
		}
		if (opcao!=9)
		{
			printf("Foram necessarias %d iteracoes para chegar a essa conclusao.\n", iteracoes);
			printMatrix();
		}
		
	} while (loop);

	return 0;
}