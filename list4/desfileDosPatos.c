#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  int th[1000001];

  int n;
  while (1)
  {
    scanf("%d", &n);
    if (n == 0)
      break;
    int maiorCount = 0, maiorCor = 0;

    for (int i = 0; i < n; i++)
    {
      int t;
      scanf("%d", &t);
      th[t]++;

      if (th[t] > maiorCount)
      {
        maiorCount = th[t];
        maiorCor = t;
      }
    }

    printf("%d\n", maiorCor);
    memset(th, 0, 1000001 * sizeof(int));
  }
}