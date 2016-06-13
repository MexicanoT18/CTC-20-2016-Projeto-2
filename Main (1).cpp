#define _CRT_SECURE_NO_WARNINGS
#include "Graph.h"
#include "BruteForceTSP.h"
#include "HeldKarpTSP.h"
#include <chrono>

using  ms = chrono::milliseconds;
using get_time = chrono::steady_clock;

void PrintTour(vector<int> & tour,int cost,FILE* out) {
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
void task1(Graph G,BruteForceTSP brute,HeldKarpTSP optimized) {
	FILE* out = fopen("task1.txt", "w");
	for (int i = 0; i<10; i++) {
		G.buildRandomGraph(6, 10);
		G.printMatrix(out);
		brute.computeTour(G);
		optimized.computeTour(G);
		fprintf(out, "Solução força bruta:\n");
		PrintTour(brute.getTour(), brute.getCost(), out);
		fprintf(out, "Solução Held Karp:\n");
		PrintTour(optimized.getTour(), optimized.getCost(), out);
	}
	fclose(out);
}

//Função responsável por resolver os testes 3a e 3b
void task2(Graph G, BruteForceTSP brute, HeldKarpTSP optimized) {
	FILE* out = fopen("time.txt", "w");
	for (int n = 1; n <= 10; n++) {
		G.buildRandomGraph(n, n*(n - 1) / 2);
		auto start = get_time::now();
		brute.computeTour(G);
		auto end = get_time::now();
		auto diff = end - start;
		fprintf(out, "%lf ", (double)chrono::duration_cast<ms>(diff).count() / 1000);
		start = get_time::now();
		optimized.computeTour(G);
		end = get_time::now();
		diff = end - start;
		fprintf(out, "%lf\n", (double)chrono::duration_cast<ms>(diff).count() / 1000);
	}
	fclose(out);
}

//Função responsável por resolver o teste 3c
void task3(Graph G, BruteForceTSP brute, HeldKarpTSP optimized) {
	FILE* out = fopen("time1.txt", "w");
	int n = 10;
	for (int m = 0; m <= n*(n - 1) / 2; m++) {
		G.buildRandomGraph(n, m);
		auto start = get_time::now();
		brute.computeTour(G);
		auto end = get_time::now();
		auto diff = end - start;
		fprintf(out, "%lf ", (double)chrono::duration_cast<ms>(diff).count() / 1000);
		start = get_time::now();
		optimized.computeTour(G);
		end = get_time::now();
		diff = end - start;
		fprintf(out, "%lf\n", (double)chrono::duration_cast<ms>(diff).count() / 1000);
	}
	fclose(out);
}

int main()
{
	Graph G;
	BruteForceTSP brute;
	HeldKarpTSP optimized;

	//task1(G, brute, optimized);
	task2(G, brute, optimized);
	//task3(G, brute, optimized);
	
	return 0;
}


