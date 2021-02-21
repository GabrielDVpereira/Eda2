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

int main()
{
  int count = 0;
  int n;
  int size = 0;
  int *v;

  while (scanf("%d", &n) == 1 && count < 16)
  {
    if (n != 0)
    {
      size += n;

      if (count == 0)
      {
        v = malloc(sizeof(int) * size);
        for (int i = 0; i < size; i++)
        {
          scanf("%d", v + i);
        }
      }
      else
      {
        v = realloc(v, sizeof(int) * size);
        for (int i = size - n; i < size; i++)
        {
          scanf("%d", v + i);
        }
        intercala(v, 0, (size - n - 1), size - 1);
      }
      count++;
    }
  }

  for (int i = 0; i < size; i++)
  {
    printf("%d ", *(v + i));
  }

  return 0;
}