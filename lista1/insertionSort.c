#include <stdio.h>

void printArray(int *array, int length)
{
  for (int i = 0; i < length; i++)
  {
    printf("%d ", *(array + i));
  }
}

void insertionSort(int *v, int start, int end)
{
  for (int i = start + 1; i <= end; i++)
  {
    for (int j = i; j > start; j--)
    {
      if (*(v + j) < *(v + j - 1))
      {
        int aux;
        aux = *(v + j);
        *(v + j) = *(v + j - 1);
        *(v + j - 1) = aux;
      }
    }
  }
  printArray(v, end - start + 1);
}

int main()
{
  int vetor[1000];

  int size = 0;
  while (scanf("%d", (vetor + size)) == 1)
  {
    size++;
  }
  insertionSort(vetor, 0, size - 1);
}