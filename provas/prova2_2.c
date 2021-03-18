#include <stdio.h>
#include <stdlib.h>

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

void quickSort(int *v, int l, int r)
{
  int j;
  if (r <= l)
    return;

  exch(*(v + (l + r) / 2), *(v + r - 1));
  cmpExch(*(v + l), *(v + r - 1));
  cmpExch(*(v + l), *(v + r));
  cmpExch(*(v + r - 1), *(v + r));

  j = separa(v, l + 1, r - 1);
  quickSort(v, l, j - 1);
  quickSort(v, j + 1, r);
}

void quickSelect(int *v, int l, int r, int k)
{
  int i;
  if (r <= l)
    return;
  i = separa(v, l, r);

  if (i > k)
    quickSelect(v, l, i - 1, k);
  if (i < k)
    quickSelect(v, i + 1, r, k);
}

int main()
{
  int n, p, x;
  scanf("%d %d %d", &n, &p, &x);

  int *v = malloc(sizeof(int) * n);

  for (int i = 0; i < n; i++)
  {
    scanf("%d", v + i);
  }

  int inicio = p * x;
  int fim = p * x + x;

  quickSelect(v, 0, n - 1, inicio);
  // quickSelect(v, inicio + 1, n - 1, fim);
  quickSort(v, inicio, n - 1);

  for (int i = inicio; i < fim; i++)
  {
    if (i <= (n - 1))
    {

      printf("%d\n", *(v + i));
    }
  }

  free(v);
}