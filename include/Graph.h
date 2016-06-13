#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>

class Graph
{
    public:
        Graph();
        Graph(int numNodes);
        void buildRandomGraph(int numNodes, int numEdges);
        virtual ~Graph();
        int getNumNodes() { return numNodes; }
        int getNumEdges() { return numEdges; }
        int getEdge(int i, int j);
        void setEdge(int i, int j, int value);
        void printMatrix(FILE* out);
    protected:
    private:
        int ** adjMatrix;
        int numNodes;
        int numEdges;
        void deleteAdjMatrix();
        int ** allocateSquareMatrix(int n);
        void fillAdjMatrix(int n);
};

#endif // GRAPH_H
