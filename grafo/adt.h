typedef struct
{
  int v;
  int w;
} Edge;

Edge EDGE(int, int);

typedef struct graph *Graph;

Graph GRAPHinit(int);

void GRAPHInsertE(Graph, Edge);

void GRAPHRemoveE(Graph, Edge);

int GRAPHEdges(Edge[], Graph G);

Graph GRAPHCopy(Graph);
void GRAPHDestroy(Graph);
