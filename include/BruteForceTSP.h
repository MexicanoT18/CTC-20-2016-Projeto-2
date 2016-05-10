#ifndef BRUTEFORCETSP_H
#define BRUTEFORCETSP_H

#include "Graph.h"
#include <vector>
using namespace std;

class BruteForceTSP
{
    public:
        BruteForceTSP();
        void computeTour(Graph & graph);
        vector<int> & getTour() { return tour; }
        int getCost() { return cost; }
        virtual ~BruteForceTSP();
    protected:
    private:
        void backTrack(int depth, int node, Graph & graph, int currentCost);
        void printTour();
        vector<bool> isPresent;
        vector<int> tour;
        vector<int> currentTour;
        int cost;
        int numNodes;
};

#endif // BRUTEFORCETSP_H
