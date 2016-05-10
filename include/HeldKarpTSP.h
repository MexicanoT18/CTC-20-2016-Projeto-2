#ifndef HELDKARPTSP_H
#define HELDKARPTSP_H

#include "Graph.h"
#include <vector>
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
        vector<int> tour;
        int cost;
        int numNodes;
};

#endif // HELDKARPTSP_H
