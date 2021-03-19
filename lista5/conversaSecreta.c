#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char M[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char m[26] = "abcdefghijklmnopqrstuvwxyz";

int main()
{
  char phrase[1000000];
  memset(phrase, 0, 1000000);
  char aux;
  int count = -1;
  int letter_count = 0;
  while (scanf("%c", &aux) != EOF)
  {
    if (aux == 10)
    {
      printf("%s\n", phrase);
      memset(phrase, 0, 1000000);
      count = -1;
      letter_count = 0;
    }
    else
    {

      if (aux != ' ')
      {
        count++;
      }
      else if (aux == ' ')
      {
        count = 1;
      }
      if (count % 2 != 0)
      {
        if (aux == ' ')
        {
          phrase[letter_count] = aux;
          letter_count++;
        }
        else
        {
          if (aux < 91)
          {
            if (aux - 65 + 13 > 25)
            {
              phrase[letter_count] = M[abs(65 - aux + 13)];
            }
            else
            {
              phrase[letter_count] = M[abs(aux - 65 + 13)];
            }
            letter_count++;
          }
          else
          {
            if (aux - 97 + 13 > 25)
            {
              phrase[letter_count] = m[abs(97 - aux + 13)];
            }
            else
            {
              phrase[letter_count] = m[abs(aux - 97 + 13)];
            }
            letter_count++;
          }
        }
      }
    }
  }

  printf("%s", phrase);

  return 0;
}