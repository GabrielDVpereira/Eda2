#include <stdio.h>
#include "string.h"

int main()
{

  char s[3];
  int s_count = 0;
  int p_count = 0;
  int t_count = 0;
  int aux = 0;
  while (scanf("%s", s) != EOF)
  {
    p_count++;
    if (s[0] == 's')
    {
      s_count++;
    }

    if (s_count >= 2 && aux == 0)
    {
      t_count++;
      aux = 1;
    }

    if (p_count == 10)
    {
      s_count = 0;
      p_count = 0;
      aux = 0;
    }
  }

  printf("%d", t_count);
}