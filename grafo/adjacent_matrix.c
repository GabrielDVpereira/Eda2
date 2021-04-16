#include <stdio.h>
#include "adt.h"

struct graph
{
  int v;
  int e;
  int **adj;
};

Graph GRAPHinit(int v) // v a quantidad de elementos do grafo
{
  Graph G = malloc(sizeof(*G));
  G->v = v;
  G->e = 0;
  G->adj = MatrixInit(v, v, 0); // alocação de matriz
  return G;
}

int **MatrixInit(int m, int n, int initV)
{
  // implementar alocação de matriz
}

void GRAPHInsertE(Graph G, Edge e)
{
  int v = e.v, w = e.w;

  if (G->adj[v][w] == 0)
  {
    G->e++;
  }
  G->adj[v][w] = 1;
  G->adj[w][v] = 1;
}

void GRAPHRemoveE(Graph G, Edge e)
{
  int v = e.v, w = e.w;

  if (G->adj[v][w] == 1)
    G->e--;
  G->adj[v][w] = 0;
  G->adj[w][v] = 0;
}

int GRAPHEdges(Edge a[], Graph G)
{
  int v, w, E = 0;
  for (v = 0; v < G->v; v++)
  {
    for (w = v + 1; w < G->v; w++)
    {
      if (G->adj[v][w] == 1)
      {
        a[E++] = EDGE(v, w);
      }
    }
  }
  return E;
}