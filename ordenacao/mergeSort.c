#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"

void intercala(item *vetor, int l, int meio, int r)
{

  item *aux = malloc(sizeof(item) * (r - l + 1));
  int a = l, b = meio + 1, c = 0;

  while (a <= meio && b <= r)
  {
    if (lessEq(*(vetor + a), *(vetor + b)))
    {
      *(aux + c++) = *(vetor + a++);
    }
    else
    {
      *(aux + c++) = *(vetor + b++);
    }
  }

  while (a <= meio)
  {
    *(aux + c++) = *(vetor + a++);
  }

  while (b <= r)
  {
    *(aux + c++) = *(vetor + b++);
  }

  for (int i = l, j = 0; i <= r; i++, j++)
  {
    *(vetor + i) = *(aux + j);
  }

  free(aux);
}

void mergeSort(item *vetor, int l, int r)
{
  if (l >= r)
    return;

  int meio = (l + r) / 2;
  mergeSort(vetor, l, meio);
  mergeSort(vetor, meio + 1, r);
  intercala(vetor, l, meio, r);
}

int main()
{
  int vetor[5] = {
      30,
      50,
      80,
      0,
      20,
  };

  mergeSort(vetor, 0, 4);

  for (int i = 0; i < 5; i++)
  {
    printf("%d ", vetor[i]);
  }

  return 0;
}