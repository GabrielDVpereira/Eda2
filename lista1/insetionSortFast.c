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

  for (int i = end; i > start; i--)
  {
    if (*(v + i - 1) > *(v + i))
    {
      int aux;
      aux = *(v + i);
      *(v + i) = *(v + i - 1);
      *(v + i - 1) = aux;
    }
  }

  for (int i = start + 2; i <= end; i++)
  {
    int j = i;
    int tmp = *(v + j);

    while (tmp < *(v + j - 1))
    {
      *(v + j) = *(v + j - 1);
      j--;
    }
    *(v + j) = tmp;
  }
  printArray(v, end - start + 1);
}

int main()
{
  int vetor[50000];

  int size = 0;
  while (scanf("%d", (vetor + size)) == 1)
  {
    size++;
  }
  insertionSort(vetor, 0, size - 1);
}