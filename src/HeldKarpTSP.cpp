#include "HeldKarpTSP.h"
#include <stdio.h>
#include <stdlib.h>
#define INFINITY (1<<29)

HeldKarpTSP::HeldKarpTSP()
{
	cost = INFINITY;
}

void HeldKarpTSP::computeTour(Graph & graph)
{
	cost = INFINITY;
	numNodes = graph.getNumNodes();

	initializeArray();

	tour.clear();
	maxsize = (1 << numNodes)-1;

	cost = DP(0, 1, graph);

	if (cost != INFINITY) {
		int bitmask = 1;
		tour.push_back(0);
		for (int next=0; bitmask != maxsize;) {
			next = dparray[next][bitmask].second;
			tour.push_back(next);
			bitmask |= 1 << next;
		}
		tour.push_back(0);
	}
}

void HeldKarpTSP::printTour()
{
	printf("Cost: %d, tour:", cost);
	for (int i = 0; i<(int)tour.size(); i++) {
		printf(" %d", tour[i]);
	}
	printf(".\n");
}

void HeldKarpTSP::initializeArray()
{
	dparray.resize(numNodes);
	int maxsize = 1 << numNodes;
	for (int i = 0; i < numNodes; i++) {
		dparray[i].resize(maxsize);
		for (int j = 0; j < maxsize; j++) {
			dparray[i][j] = make_pair(-1, -1);
		}
	}
}

int HeldKarpTSP::DP(int pos, int bitmask, Graph & graph)
{
	if (bitmask == maxsize) {
		if (graph.getEdge(pos, 0) != -1) {
			return graph.getEdge(pos, 0);
		}
		else {
			return INFINITY;
		}
	}

	if (dparray[pos][bitmask].first != -1) {
		return dparray[pos][bitmask].first;
	}

	int bit, edgecost, value, minvalue = INFINITY;
	int nextbest;

	for (int i = 1; i < numNodes; i++) {
		bit = bitmask & (1 << i);
		edgecost = graph.getEdge(pos, i);
		if (bit == 0 && edgecost >= 0) {
			value = edgecost + DP(i, bitmask | (1 << i), graph);
			if (value < minvalue) {
				minvalue = value;
				nextbest = i;
			}
		}
	}

	dparray[pos][bitmask] = pair<int, int>(minvalue, nextbest);
	return dparray[pos][bitmask].first;
}

HeldKarpTSP::~HeldKarpTSP()
{
	//dtor
}
