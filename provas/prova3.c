#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

  cmpExch(*(v + (l + r) / 2), *(v + r));
  cmpExch(*(v + l), *(v + (l + r) / 2));
  cmpExch(*(v + r), *(v + (l + r) / 2));

  j = separa(v, l, r);
  quickSort(v, l, j - 1);
  quickSort(v, j + 1, r);
}

int main()
{
  int v[100];
  memset(v, 0, 100 * sizeof(int));

  int o, n;
  int count = 0;
  while (scanf("%d %d", &o, &n) != EOF)
  {
    if (o == 1)
    {
      if (count < 100)
      {
        v[count] = n;
        quickSort(v, 0, count);
        count++;
      }
      else
      {
        if (n < v[count - 1])
        {
          v[count - 1] = n;
          quickSort(v, 0, count - 1);
        }
      }
    }
    else if (o == 2)
    {
      for (int i = 0; i < n; i++)
      {
        printf("%d ", v[i]);
      }
      printf("\n");
    }
  }
}