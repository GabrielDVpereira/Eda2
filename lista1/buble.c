#include <stdio.h>

void buble(int *v, int start, int end)
{
  for (int i = start; i <= end; i++)
  {
    for (int j = start + 1; j <= end; j++)
    {
      if (*(v + j - 1) > *(v + j))
      {
        int aux;
        aux = *(v + j - 1);
        *(v + j - 1) = *(v + j);
        *(v + j) = aux;
      }
    }
  }

  for (int i = start; i <= end; i++)
  {
    printf("%d ", *(v + i));
  }
  printf("\n");
}

int main()
{
  int vetor[1000];

  int size = 0;
  while (scanf("%d", (vetor + size)) == 1)
  {
    size++;
  }
  buble(vetor, 0, size - 1);
}