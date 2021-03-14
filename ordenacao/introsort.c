#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef int item;
#define key(a) (a)
#define less(a, b) (key(a) < key(b))
#define lessEq(a, b) (key(a) <= key(b))
#define exch(a, b) \
  {                \
    item t = a;    \
    a = b;         \
    b = t;         \
  }
#define cmpExch(a, b) \
  {                   \
    if (less(b, a))   \
      exch(a, b);     \
  }

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
  if (r - l <= 32)
    return;

  int meio = (l + r) / 2;
  mergeSort(vetor, l, meio);
  mergeSort(vetor, meio + 1, r);
  intercala(vetor, l, meio, r);
}

int separa(int *v, int l, int r)
{
  int i = l - 1, j = r, c = *(v + r);
  for (;;)
  {
    while (less(*(v + ++i), c))
      ;
    while (less(c, *(v + --j)))
      if (j == l)
        break;
    if (i >= j)
      break;
    exch(*(v + i), *(v + j));
  }

  exch(*(v + i), *(v + r));
  return i;
}

void insertionSort(item *array, item start, item end)
{

  for (int i = end; i > start; i--)
  {
    cmpExch(*(array + i - 1), *(array + i))
  }

  for (int i = start + 2; i <= end; i++)
  {
    int j = i;
    item tmp = *(array + j);

    while (less(tmp, *(array + j - 1)))
    {
      *(array + j) = *(array + j - 1);
      j--;
    }

    *(array + j) = tmp;
  }
}

int quicktrapstop = 0;
void quickSort(int *v, int l, int r, int max_rec)
{
  int j;

  if (max_rec == 0)
  {
    quicktrapstop = 1;
    return;
  }
  if (quicktrapstop == 1)
    return;
  if (r <= l)
    return;

  cmpExch(*(v + (l + r) / 2), *(v + r));
  cmpExch(*(v + l), *(v + (l + r) / 2));
  cmpExch(*(v + r), *(v + (l + r) / 2));

  j = separa(v, l, r);
  quickSort(v, l, j - 1, max_rec - 1);
  quickSort(v, j + 1, r, max_rec - 1);
}

void introSort(int *v, int l, int r)
{
  int max_rec = 2 * log2((r - l + 1));
  quickSort(v, l, r, max_rec);

  if (quicktrapstop == 1)
  {
    mergeSort(v, l, r);
  }
  else
  {
    insertionSort(v, l, r);
  }
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

  introSort(v, 0, n - 1);

  for (int i = 0; i < n; i++)
  {
    printf("%d ", *(v + i));
  }
}