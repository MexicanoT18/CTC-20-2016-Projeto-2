#include "Graph.h"
#include "BruteForceTSP.h"
#include "HeldKarpTSP.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

void PrintTour(vector<int> & tour, int cost, FILE* out) {
	if (!tour.empty()) {
		fprintf(out,"Min cost: %d, tour:", cost);
		for (int i = 0; i<(int)tour.size(); i++) {
			fprintf(out," %d", tour[i]);
		}
		fprintf(out,".\n\n");
	}
	else fprintf(out,"Não existe circuito Hamiltoniano.\n\n");
}

//Função responsável por resolver os testes 1 e 2 da atividade.
void task1(Graph & G,BruteForceTSP & brute, HeldKarpTSP & optimized, FILE * out) {

    printf("Resolvendo atividade 1 e 2.\n");

	fprintf(out, "Tarefa 1 e 2: 10 grafos com 6 nós e 10 arestas.\n");

	for (int i = 0; i<10; i++) {
	    printf("%.2f%%... ", i*10.0);

		fprintf(out, "Grafo %d:\n", i+1);
		G.buildRandomGraph(6, 10);
		G.printMatrix(out);

		brute.computeTour(G);
		optimized.computeTour(G);

		fprintf(out, "Solução força bruta:\n");
		PrintTour(brute.getTour(), brute.getCost(), out);
		fprintf(out, "Solução Held Karp:\n");
		PrintTour(optimized.getTour(), optimized.getCost(), out);
		fprintf(out, "\n");
	}
	printf("100.00%%\n\n");
}

//Função responsável por resolver os testes 3a e 3b
void task2(Graph & G, BruteForceTSP & brute, HeldKarpTSP & optimized, FILE * out) {

    printf("Resolvendo atividade 3a e 3b.\n");

    clock_t last, current;
    double diff;
    int numIter = 5;

	fprintf(out, "Tarefa 3a e 3b: Grafos completos de 1 a 10 nós.\n");

	for (int n = 1; n <= 10; n++) {
	    printf("%.2f%%... ", (n-1)*10.0);

        fprintf(out, "Grafo completo com %d nós.\n", n);

        diff = 0;
        for(int i=0; i<numIter; i++){
            G.buildRandomGraph(n, n*(n - 1) / 2);
            last = clock();
            brute.computeTour(G);
            current = clock();
            diff += ((double)(current - last)/CLOCKS_PER_SEC);
        }
        diff /= numIter;
		fprintf(out, "Tempo força bruta: %f segundos.\n", diff);

		diff = 0;
        for(int i=0; i<numIter; i++){
            G.buildRandomGraph(n, n*(n - 1) / 2);
            last = clock();
            optimized.computeTour(G);
            current = clock();
            diff += ((double)(current - last)/CLOCKS_PER_SEC);
        }
        diff /= numIter;
		fprintf(out, "Tempo Help Karp: %f segundos.\n", diff);
	}
	fprintf(out, "\n");
	printf("100.00%%\n\n");
}

//Função responsável por resolver o teste 3c
void task3(Graph & G, BruteForceTSP & brute, HeldKarpTSP & optimized, FILE * out) {

    printf("Resolvendo atividade 3c.\n");

	int n = 10, numIter = 5;
	clock_t last, current;
    double diff;
	fprintf(out, "Tarefa 3c: Grafo de 10 nós com várias arestas.\n");

	for (int m = 0; m <= n*(n - 1) / 2; m++) {
	    printf("%.2f%%... ", m*200.0/(n*(n - 1)));
		fprintf(out, "Grafo de %d nós e %d arestas:\n", n, m);

		diff = 0;
        for(int i=0; i<numIter; i++){
            G.buildRandomGraph(n, n*(n - 1) / 2);
            last = clock();
            brute.computeTour(G);
            current = clock();
            diff += ((double)(current - last)/CLOCKS_PER_SEC);
        }
        diff /= numIter;
		fprintf(out, "Tempo força bruta: %f segundos.\n", diff);

		diff = 0;
        for(int i=0; i<numIter; i++){
            G.buildRandomGraph(n, n*(n - 1) / 2);
            last = clock();
            optimized.computeTour(G);
            current = clock();
            diff += ((double)(current - last)/CLOCKS_PER_SEC);
        }
        diff /= numIter;
		fprintf(out, "Tempo Held Karp: %f segundos.\n", diff);
	}
}

int main()
{
	Graph G;
	BruteForceTSP brute;
	HeldKarpTSP optimized;
    FILE * out = fopen("Atividade 2 resultados.txt", "w");
    printf("Atividade 2 CTC-20.\n\nAlunos:\nLucas França de Oliveira\nLucas Soares Ferreira\n\n");
    printf("Respostas serão escritas no arquivo Atividade 2 resultados.txt gerado na mesma pasta que o executável.\n\n");
    printf("Tempo esperado de execução: 2 minutos.\n\n");

	task1(G, brute, optimized, out);
	task2(G, brute, optimized, out);
	task3(G, brute, optimized, out);

	fclose(out);

	return 0;
}


