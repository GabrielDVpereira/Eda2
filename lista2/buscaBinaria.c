#include <stdio.h>
#include <stdlib.h>

void binary_search(int *v, int x, int n)
{
  int e = -1, d = n;
  while (e < d - 1)
  {
    int m = (e + d) / 2;
    if (*(v + m) < x)
      e = m;
    else
      d = m;
  }

  printf("%d\n", d);
}

int main()
{

  int m, n;
  scanf("%d %d", &m, &n);
  int *v = malloc(sizeof(int) * m);

  for (int i = 0; i < m; i++)
  {
    scanf("%d", v + i);
  }

  int x;

  for (int i = 0; i < n; i++)
  {
    scanf("%d", &x);
    binary_search(v, x, m);
  }

  return 0;
}