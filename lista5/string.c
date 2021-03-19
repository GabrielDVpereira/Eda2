#include <stdio.h>
#include <string.h>

int main()
{
  char s[10001];
  scanf("%s", s);

  printf("%zu", strlen(s));
}