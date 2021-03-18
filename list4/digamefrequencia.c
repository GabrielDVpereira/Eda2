#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct contagem
{
  char c;
  int count;
} Item;

void intercala(Item *vetor, int l, int meio, int r)
{

  Item *aux = malloc(sizeof(Item) * (r - l + 1));
  int a = l, b = meio + 1, c = 0;

  while (a <= meio && b <= r)
  {
    if (vetor[a].count <= vetor[b].count)
    {
      aux[c++] = vetor[a++];
    }
    else
    {
      aux[c++] = vetor[b++];
    }
  }

  while (a <= meio)
  {
    aux[c++] = vetor[a++];
  }

  while (b <= r)
  {
    aux[c++] = vetor[b++];
  }

  for (int i = l, j = 0; i <= r; i++, j++)
  {
    vetor[i] = aux[j];
  }

  free(aux);
}

void mergeSort(Item *vetor, int l, int r)
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
  Item th[128];
  memset(th, 0, sizeof(Item) * 128);
  char b;
  while (scanf("%c", &b) == 1 && b != '\n')
  {
    th[b].c = b;
    th[b].count++;
  };

  mergeSort(th, 0, 127);

  for (int i = 0; i < 128; i++)
  {
    if (th[i].count != 0)
    {
      printf("%d %d\n", th[i].c, th[i].count);
    }
  }
}