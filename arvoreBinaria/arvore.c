#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef int bool;
typedef int TIPOCHAVE;

typedef struct aux
{
  TIPOCHAVE chave;
  struct aux *esq, *dir;
} NO;

NO *inicializa()
{
  return NULL;
}

NO *adiciona(NO *raiz, NO *no)
{
  if (raiz == NULL)
    return no;
  if (no->chave < raiz->chave)
  {
    raiz->esq = adiciona(raiz->esq, no);
  }
  else
  {
    raiz->dir = adiciona(raiz->dir, no);
  }

  return raiz;
}

NO *criaNovoNO(TIPOCHAVE ch)
{
  NO *novoNo = (NO *)malloc(sizeof(NO));
  novoNo->chave = ch;
  novoNo->esq = NULL;
  novoNo->dir = NULL;
  return novoNo;
}

int main()
{
  NO *r = inicializa();
  NO *no = criaNovoNO(23);

  r = adiciona(r, no);

  NO *no2 = criaNovoNO(12);

  r = adiciona(r, no2);
}