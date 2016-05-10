#include "Graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <time.h>
using namespace std;

Graph::Graph()
{
    adjMatrix = NULL;
    numNodes = 0;
    numEdges = 0;

    srand(time(NULL));
}

Graph::Graph(int numNodes)
{
    this->numNodes = numNodes;

    adjMatrix = allocateSquareMatrix(numNodes);
    fillAdjMatrix(-1);

    srand(time(NULL));
}

void Graph::buildRandomGraph(int numNodes, int numEdges)
{
    if (numNodes != this->numNodes){
        deleteAdjMatrix();
        adjMatrix = allocateSquareMatrix(numNodes);
        this->numNodes = numNodes;
    }

    fillAdjMatrix(-1);

    vector<pair<int, int> > pairs;
    for(int i = 0; i < numNodes; i++){
        for(int j = i+1; j < numNodes; j++){
            pairs.push_back(make_pair(i, j));
        }
    }

    int pairToChoose;
    int u, v;
    for(int i = 0; !pairs.empty() && i < numEdges; i++){
        pairToChoose = rand()%((int)pairs.size());
        u = pairs[pairToChoose].first;
        v = pairs[pairToChoose].second;
        pairs[pairToChoose] = pairs[(int)pairs.size()-1];
        pairs.pop_back();
        setEdge(u, v, (rand()%10) + 1);
    }
}

int Graph::getEdge(int i, int j)
{
    if (i<0 || i>=numNodes || j<0 || j>=numNodes) return -1;
    if (adjMatrix == NULL || adjMatrix[i] == NULL) return -1;
    return adjMatrix[i][j];
}

void Graph::setEdge(int i, int j, int value)
{
    if (i<0 || i>=numNodes || j<0 || j>=numNodes) return;
    if (adjMatrix == NULL || adjMatrix[i] == NULL) return;

    if (adjMatrix[i][j] == -1) numEdges++;
    adjMatrix[i][j] = value;
    adjMatrix[j][i] = value;
}

void Graph::deleteAdjMatrix()
{
    if (adjMatrix == NULL) return;

    for(int i = 0; i < numNodes; i++){
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;

    adjMatrix = NULL;
    numNodes = 0;
    numEdges = 0;
}

int ** Graph::allocateSquareMatrix(int n)
{
    if (n<=0) return NULL;

    int ** matrix;

    matrix = new int*[n];
    for(int i = 0; i < n; i++){
        matrix[i] = new int[n];
        for(int j = 0; j < n; j++){
            matrix[i][j] = -1;
        }
    }

    return matrix;
}

void Graph::fillAdjMatrix(int n)
{
    if (adjMatrix == NULL) return;

    numEdges = (n == -1? 0: (numNodes*(numNodes-1))/2);

    for(int i = 0; i < numNodes; i++){
        for(int j = 0; j < numNodes; j++){
            adjMatrix[i][j] = n;
        }
    }
}

void Graph::printMatrix()
{
    printf("|ij|");
    for(int i=0; i<numNodes; i++){
        printf("%2d|", i);
    }
    printf("\n");
    for(int i=0; i<numNodes; i++){
        printf("|%2d|", i);
        for(int j=0; j<numNodes; j++){
            printf("%2d|", getEdge(i,j));
        }
        printf("\n");
    }
}

Graph::~Graph()
{
    deleteAdjMatrix();
}
