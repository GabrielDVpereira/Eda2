#include <stdio.h>
#include <stdlib.h>

void intercala(int *vetor, int l, int meio, int r)
{

  int *aux = malloc(sizeof(int) * (r - l + 1));
  int a = l, b = meio + 1, c = 0;

  while (a <= meio && b <= r)
  {
    if (*(vetor + a) <= *(vetor + b))
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

void mergeSort(int *vetor, int l, int r)
{
  if (l >= r)
    return;

  int meio = (l + r) / 2;
  mergeSort(vetor, l, meio);
  mergeSort(vetor, meio + 1, r);
  intercala(vetor, l, meio, r);
}

int binary_search(int *v, int x, int n)
{
  int e = -1, d = n;
  int exits = -1;
  while (e < d - 1)
  {
    int m = (e + d) / 2;
    if (*(v + m) < x)
      e = m;
    else if (*(v + m) == x)
    {
      d = m;
      exits = 1;
    }
    else
      d = m;
  }

  if (exits == 1)
  {
    return 1;
  }
  else
  {
    return -1;
  }
}

int main()
{

  int m;
  scanf("%d", &m);
  int *v = malloc(sizeof(int) * m);

  for (int i = 0; i < m; i++)
  {
    scanf("%d ", v + i);
  }

  mergeSort(v, 0, m - 1);

  int x;
  while (scanf("%d", &x) == 1)
  {
    int index = binary_search(v, x, m);
    if (index == -1)
    {
      printf("nao\n");
    }
    else
    {
      printf("sim\n");
    }
  }

  return 0;
}