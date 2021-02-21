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
int main()
{
  int n;
  scanf("%d", &n);
  int *v = malloc(sizeof(int) * n);

  for (int i = 0; i < n; i++)
  {
    scanf("%d", v + i);
  }

  mergeSort(v, 0, n - 1);

  for (int i = 0; i < n; i++)
  {
    printf("%d ", *(v + i));
  }

  free(v);
  return 0;
}