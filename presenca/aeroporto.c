#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

  int a = 1, v = 1;
  int count = 1;
  while (1)
  {
    scanf("%d %d", &a, &v);

    if (a == 0 && v == 0)
      break;

    int *h = malloc(sizeof(int) * a);
    memset(h, 0, sizeof(int) * a);

    int s, c;
    int b = 0;
    for (int i = 0; i < v; i++)
    {
      scanf("%d %d", &s, &c);
      h[s - 1]++;
      h[c - 1]++;

      if (h[s - 1] > b)
      {
        b = h[s - 1];
      }
      else if (h[c - 1] > b)
      {
        b = h[c - 1];
      }
    }

    printf("Teste %d\n", count);

    for (int i = 0; i < a; i++)
    {
      if (h[i] == b)
      {
        printf("%d ", i + 1);
      }
    }

    printf("\n\n");

    count++;
    free(h);
  }

  return 0;
}