#include "structs.h"
/* Insere um tiro de endereço x na lista p */
void insere (tiro *x, lista *p){
   lista *nova;
   nova = malloc (sizeof (lista));
   nova->t = x;
   nova->prox = p->prox;
   p->prox = nova;
}

void tira (lista *p) {
   lista *lixo;
   lixo = p->prox;
   p->prox = lixo->prox;
   free (lixo->t);
   free (lixo);
}

