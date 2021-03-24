#include <stdio.h>
#include <stdlib.h>

int main()
{
  int s_begin, s_end;
  scanf("%d %d", &s_begin, &s_end);

  if (s_begin == s_end)
  {
    printf("%d", s_begin);
    return 0;
  }

  int n;
  int s;
  while (scanf("%d", &n) == 1)
  {
    for (int i = s_begin; i <= s_end; i++)
    {
      int semente = i;
      for (int j = 1; j < 1000; j++)
        rand_r(&semente);
      if (rand_r(&semente) % 256 == n)
        s = i;
    }
  }

  printf("%d", s);

  return 0;
}