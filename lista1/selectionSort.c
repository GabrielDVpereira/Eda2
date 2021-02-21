#include <stdio.h>

void printArray(int *array, int length)
{
  for (int i = 0; i < length; i++)
  {
    printf("%d ", *(array + i));
  }
}

void selectionSort(int *v, int start, int end)
{

  for (int i = 0; i <= end; i++)
  {
    int min = i;
    for (int j = i + 1; j <= end; j++)
    {
      if (*(v + j) < *(v + min))
      {
        min = j;
      }
    }
    int aux;
    aux = *(v + i);
    *(v + i) = *(v + min);
    *(v + min) = aux;
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
  selectionSort(vetor, 0, size - 1);
}