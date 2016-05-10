#include <stdio.h>
#include "Graph.h"
#include "BruteForceTSP.h"

int main()
{
    Graph G;
    BruteForceTSP brute;

    for(int i=0; i<10; i++){
        G.buildRandomGraph(6, 10);
        G.printMatrix();
        brute.computeTour(G);
        vector<int> & tour = brute.getTour();
        if (!tour.empty()){
            printf("Min cost: %d, tour:", brute.getCost());
            for(int i=0; i<(int)tour.size(); i++){
                printf(" %d", tour[i]);
            }
            printf(".\n");
        }
        else printf("No tour found.\n");
    }
    return 0;
}
