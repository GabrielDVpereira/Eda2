#include <stdio.h>
#include "string.h"
#include <stdlib.h>

int main()
{
  int d[31];
  int l[31];
  memset(d, 0, sizeof(int) * 31);
  memset(l, 0, sizeof(int) * 31);

  int n;
  char c;
  while (scanf("%d %c", &n, &c) == 2)
  {
    if (c == 'D')
    {
      d[n - 30]++;
    }
    else
    {
      l[n - 30]++;
    }
  }
  int count = 0;
  for (int i = 0; i < 31; i++)
  {
    if (d[i] != 0 && l[i] != 0)
    {

      if (d[i] > l[i])
      {
        count += l[i];
      }
      else
      {
        count += d[i];
      }
    }
  }

  printf("%d\n", count);

  return 0;
}