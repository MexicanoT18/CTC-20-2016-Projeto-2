#ifndef HELDKARPTSP_H
#define HELDKARPTSP_H

#include "Graph.h"
#include <vector>
#include <iostream>
using namespace std;

class HeldKarpTSP
{
    public:
        HeldKarpTSP();
        void computeTour(Graph & graph);
        vector<int> & getTour() { return tour; }
        int getCost() { return cost; }
        virtual ~HeldKarpTSP();
    protected:
    private:
        void printTour();
        void initializeArray();
        int DP(int pos, int bitmask, Graph & graph);
        vector< vector< pair<int,int> > > dparray;
        vector<int> tour;
        int cost;
        int numNodes;
        int maxsize;
};

#endif // HELDKARPTSP_H
