#include <iostream>
#include <bits/stdc++.h>
#include <vector>
//#include <fstream>
#include <cstdio>

using namespace std;
 
long long int N, M;
vector <long long int> c;
/****************************************************************/

class Edge {
public:
    long long int src, dest, weight;
};
 
class Graph {
public:
    long long int N, M;
    Edge* edge;
};
 
Graph* createGraph(long long int N, long long int M) {
    Graph* graph = new Graph;
    graph->N = N;
    graph->M = M;
 
    graph->edge = new Edge[M];
 
    return graph;
}

/****************************************************************/

class ParentPointerTree {
public:
    long long int parent;
    long long int size;
};
 

long long int FIND(ParentPointerTree array[], long long int curr) {

    if (array[curr].parent != curr) {
        array[curr].parent = FIND(array, array[curr].parent);
    }
 
    return array[curr].parent;
}


void UNION(ParentPointerTree array[], long long int a, long long int b) {
    long long int aroot = FIND(array, a);
    long long int broot = FIND(array, b);
 
    if (aroot != broot)   {      
      if (array[broot].size > array[aroot].size) {
            array[aroot].parent = broot;
        } 
      else {
       array[broot].parent = aroot;
      }
    }
    else { 
        array[broot].parent = aroot;
        array[aroot].size++;
    }
}

/****************************************************************/

int compareWeights(const void* a, const void* b) {
    Edge* a1 = (Edge*)a;
    Edge* b1 = (Edge*)b;
    if (a1->weight < b1->weight)
        return 1;
    else if (a1->weight > b1->weight)
        return -1;

    return 0;
}
 
/****************************************************************/

void MaximumSpanningForest(Graph* graph)
{
    long long int N = graph->N;
    Edge portals[N]; 
    long long int p = 0; //index for portals[]
    long long int j = 0; //index for sorted edges


    qsort(graph->edge, graph->M, sizeof(graph->edge[0]), compareWeights);
  

    ParentPointerTree* array = new ParentPointerTree[(N * sizeof(ParentPointerTree))];
 
    for (long long int i = 0; i < N; ++i) 
    {
        array[i].parent = i;
        array[i].size = 0;
    }

    while (p < N-1 && j < graph->M) {

        Edge next_portal = graph->edge[j++];

       
        long long int x = FIND(array, next_portal.src);
        long long int y = FIND(array, next_portal.dest);


        if (x != y) {
            portals[p++] = next_portal;
            UNION(array, x, y);
        }

    }
   
    long long int minimumPortal = portals[0].weight;



    for (long long int i = 0; i < p; ++i) { 
        
       if (minimumPortal > portals[i].weight && (portals[i].src != c[portals[i].src-1] || portals[i].dest != c[portals[i].dest-1])) {

            minimumPortal = portals[i].weight;
        }
      
    }

    cout << minimumPortal << endl;
}

/****************************************************************/

int main () {

scanf("%lld" "%lld",&N, &M);

long long int ci;

for (long long int i=0; i<N; i++) {
    scanf("%lld" ,&ci);
    c.push_back(ci);
}

Graph* graph = createGraph(N, M);


long long int ai, bi, wi;
for (long long int i=0; i<M; i++) {
    scanf("%lld" "%lld" "%lld", &ai, &bi, &wi);
    graph->edge[i].src = ai;
    graph->edge[i].dest = bi;
    graph->edge[i].weight = wi;
}

 MaximumSpanningForest(graph);

    return 0;
}
