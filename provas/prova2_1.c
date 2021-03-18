#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  int ht[1001];
  memset(ht, 0, sizeof(int) * 1001);

  int n;
  scanf("%d", &n);
  int maiorNota = 0, maiorCount = 0;

  for (int i = 0; i < n; i++)
  {
    int t;
    scanf("%d", &t);
    ht[t]++;

    if (ht[t] > maiorCount)
    {
      maiorNota = t;
      maiorCount = ht[t];
    }
    else if (ht[t] == maiorCount)
    {
      if (t > maiorNota)
      {
        maiorNota = t;
      }
    }
  }

  printf("%d\n", maiorNota);
  return 0;
}