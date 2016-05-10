#include "HeldKarpTSP.h"
#include <stdio.h>
#define INFINITY (1<<29)

HeldKarpTSP::HeldKarpTSP()
{
    cost = INFINITY;
}

void HeldKarpTSP::computeTour(Graph & graph)
{

}

void HeldKarpTSP::printTour()
{
    printf("Cost: %d, tour:", cost);
    for(int i=0; i<(int)tour.size(); i++){
        printf(" %d", tour[i]);
    }
    printf(".\n");
}

HeldKarpTSP::~HeldKarpTSP()
{
    //dtor
}
