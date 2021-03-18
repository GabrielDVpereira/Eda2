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

NO *contem(TIPOCHAVE ch, NO *raiz)
{
  if (raiz == NULL)
    return NULL;
  if (raiz->chave == ch)
    return raiz;

  if (raiz->chave > ch)
  {
    return contem(ch, raiz->esq);
  }
  else
  {
    return contem(ch, raiz->dir);
  }
}

NO *criaNovoNO(TIPOCHAVE ch)
{
  NO *novoNo = (NO *)malloc(sizeof(NO));
  novoNo->chave = ch;
  novoNo->esq = NULL;
  novoNo->dir = NULL;
  return novoNo;
}

int numeroNos(NO *raiz)
{
  if (!raiz)
    return 0;
  return numeroNos(raiz->esq) + 1 + numeroNos(raiz->dir);
}

void exibirArvore(NO *raiz)
{
  if (raiz != NULL)
  {
    printf("%i", raiz->chave);
    printf("(");
    exibirArvore(raiz->esq);
    exibirArvore(raiz->dir);
    printf(")");
  }
}

NO *buscaNO(NO *raiz, TIPOCHAVE ch, NO *pai)
{
  NO *atual = raiz;
  pai = NULL;
  while (atual)
  {
    if (atual->chave == ch)
      return NULL;
    pai = atual;
    if (ch < atual->chave)
      atual = atual->esq;
    else
      atual = atual->dir;
  }

  return NULL;
}

NO *removeNo(NO *raiz, TIPOCHAVE ch)
{
  NO *pai, *no, *p, *q;
  no = buscaNO(raiz, ch, &pai);
  if (no == NULL)
    return raiz;
  if (!no->esq || !no->dir)
  {
    if (!no->esq)
      q = no->dir;
    else
      q = no->esq;
  }
  else
  {
    p = no;
    q = no->esq;
    while (q->dir)
    {
      p = q;
      q = q->dir;
    }

    if (p != no)
    {
      p->dir = q->esq;
      p->esq = no->esq;
    }
    q->dir = no->dir;
  }
  if (!pai)
  {
    free(no);
    free(q);
  }

  if (ch < pai->chave)
    pai->esq = q;
  else
    pai->dir = q;
  free(no);
  return raiz;
}

int main()
{
  NO *r = inicializa();
  NO *no = criaNovoNO(23);

  r = adiciona(r, no);

  NO *no2 = criaNovoNO(12);

  r = adiciona(r, no2);

  // NO *p = contem(12, r);
  // printf("%d", numeroNos(r));
  exibirArvore(r);
}