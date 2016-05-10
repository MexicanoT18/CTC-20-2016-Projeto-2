#include "BruteForceTSP.h"
#include <stdio.h>
#define INFINITY (1<<29)

BruteForceTSP::BruteForceTSP()
{
    cost = INFINITY;
}

void BruteForceTSP::computeTour(Graph & graph)
{
    numNodes = graph.getNumNodes();

    isPresent.resize(numNodes);
    isPresent.assign(numNodes, false);
    tour.clear();
    currentTour.clear();
    cost = INFINITY;

    backTrack(1, 0, graph, 0);
}

void BruteForceTSP::backTrack(int depth, int node, Graph & graph, int currentCost)
{
    if (node < 0 || node >= numNodes) return;
    if (isPresent[node]) return;

    isPresent[node] = true;
    currentTour.push_back(node);

    if (depth < numNodes){
        for(int v = 0; v < numNodes; v++){
            if (!isPresent[v] && graph.getEdge(node, v) != -1){
                backTrack(depth+1, v, graph, currentCost + graph.getEdge(node, v));
            }
        }
    }
    else if (depth == numNodes){
        if (graph.getEdge(node, 0) != -1 && cost > currentCost + graph.getEdge(node, 0)){
            cost = currentCost + graph.getEdge(node, 0);
            tour = currentTour;
            tour.push_back(0);
            printTour();
        }
    }

    isPresent[node] = false;
    currentTour.pop_back();
}

void BruteForceTSP::printTour()
{
    printf("Cost: %d, tour:", cost);
    for(int i=0; i<(int)tour.size(); i++){
        printf(" %d", tour[i]);
    }
    printf(".\n");
}

BruteForceTSP::~BruteForceTSP()
{
    //dtor
}
