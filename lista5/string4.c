#include <stdio.h>
#include <string.h>

int main()
{

  int n;
  char s[10001];
  char b[10001];

  scanf("%d", &n);
  int biggest = 0;

  for (int i = 0; i < n; i++)
  {
    scanf("%s", s);
    if (strlen(s) > biggest)
    {
      biggest = strlen(s);
      strcpy(b, s);
    }
  }

  puts(b);

  return 0;
}