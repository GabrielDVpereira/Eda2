// tipo de arvore binaria que vai implementar fila de prioridade de forma mais eficiente
// dois tipos: heap descrente(max no topo) e heap crescente (min no topo)

/*
    Propiedades de heap decrescente: 
      - O item de qqr nó é menor ou igual ao item do pai
    Propiedades de heap crescente: 
      - O item de qqr nó é maior ou igual ao item do pai
*/

// representação de uma heap dentro de um vetor v[1...n], onde o item 0 n é utilizado
// Os dois filhos de um nó no indice k são, respectivamente 2*k e 2*k +1. O pai de qqr indice k é então [k/2]

#include <stdio.h>
#include "helpers.h"

/*
  TODO - refazer a partir do min 51 do video: https://www.youtube.com/watch?v=b_a8NbG1Bq8&ab_channel=Prof.BrunoRibas
*/

// função para ajustar a ordenação de uma heap ("consertar para cima", pegar um elemento com maior prioridade e trazer para cima no heap)
void fixUp(item *v, int k)
{
  int father_index = k / 2;

  while (k > 1 && less(v[father_index], v[k]))
  {
    exch(v[k], v[father_index]);
    k = father_index;
  }
}

// conserta de cima para baixo( trazer elementos de menor prioridade para baixo
// n é o tamanho da fila
void fixDown(item *v, int k, int n)
{
  int j;

  while (2 * k <= n)
  {
    j = 2 * k;
    if (j < n && less(v[j], v[j + 1]))
    {
      j++;
    }
    if (!less(v[k], v[j]))
      break;
    exch(v[k], v[j]);
    k = j;
  }
}

// representando a file de prioridade (PQ) como uma struct
struct pq_st
{
  int *pq; // fila de prioridades, que armazena os indices do conjunto de item
  int *qp; // mantem a posição da heap para o elemento de indice k do conjunto de item (vai funcionar como uma hash)
  int N;
};

void PQinit(int maxN, struct pq_st *PQ)
{
  PQ->pq = malloc(sizeof(item) * (maxN + 1));
  PQ->qp = malloc(sizeof(item) * (maxN + 1));

  PQ->N = 0;
}

int PQempty(struct pq_st *PQ)
{
  return !PQ->N;
}

void PQinsert(struct pq_st *PQ, int k)
{
  PQ->qp[k] = ++PQ->N; // guarda-se o indice na lista de prioridade
  PQ->pq[PQ->N] = k;   //guarda o indice na list original
  fixUp(PQ->pq, PQ->N);
}

// remover o elemtento de maior prioridade
item PQdelMax(struct pq_st *PQ)
{
  // a gente remove o item com maior prioridade jogando ele para o fim da lista
  exch(PQ->pq[1], PQ->pq[PQ->N]);
  fixDown(PQ->pq, 1, PQ->N - 1);
  return PQ->pq[PQ->N--]; // retorna o elemento de maior prioridade, que agora está no final
}

void PQChange(struct pq_st *PQ, int k)
{
}
int main()
{
}