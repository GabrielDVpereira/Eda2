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
  int n;
  scanf("%d", &n);
  int *vector = malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", vector + i);
  }

  mergeSort(vector, 0, n - 1);

  int *non_repeat_vector = malloc(sizeof(int) * n);

  int j = 0;
  for (int i = 0; i < n; i++)
  {
    if (i == 0)
    {
      *(non_repeat_vector + j++) = *(vector + i);
    }
    else if (*(vector + i) != *(vector + i - 1))
    {
      *(non_repeat_vector + j++) = *(vector + i);
    }
  }

  free(vector);

  if (j % 2 != 0)
  {
    j++;
    *(non_repeat_vector + j - 1) = 1000000000;
  }

  int *nmu = malloc(sizeof(int) * (j / 2));

  int k = 0;
  for (int i = 0; i < j; i += 2)
  {
    *(nmu + k++) = *(non_repeat_vector + i) + *(non_repeat_vector + i + 1);
  }

  for (int i = 0; i < k; i++)
  {
    if (binary_search(non_repeat_vector, *(nmu + i), j) == -1)
    {
      j++;
      non_repeat_vector = realloc(non_repeat_vector, sizeof(int) * j);
      *(non_repeat_vector + j - 1) = *(nmu + i);
    }
  }

  mergeSort(non_repeat_vector, 0, j - 1);

  int size = 0;

  int *final_vector = malloc(sizeof(int) * j);
  for (int i = 0; i < j; i++)
  {
    if (i == 0)
    {
      *(final_vector + size++) = *(non_repeat_vector + i);
    }
    else if (*(non_repeat_vector + i) != *(non_repeat_vector + i - 1))
    {
      *(final_vector + size++) = *(non_repeat_vector + i);
    }
  }

  for (int i = 0; i < size; i += 4)
  {
    printf("%d\n", *(final_vector + i));
  }
  printf("Elementos: %d", size);

  free(non_repeat_vector);
  free(final_vector);
  return 0;
}