#include "space.h"
void fisica () {
    lista *aux1, *aux2;
    /* Angulo dos tiros */
    for (aux1 = tiros->prox; aux1 != NULL; aux1 = aux1->prox) {
        if (aux1->t->c.vy != 0) {
            aux1->t->c.a = atan (aux1->t->c.vx/(-aux1->t->c.vy)) * 57.2957795131; /* 180/pi */
            if (aux1->t->c.vy > 0) aux1->t->c.a += 180;
        }
        else if (aux1->t->c.vx > 0)
            aux1->t->c.a = 90;
        else if (aux1->t->c.vx < 0)
            aux1->t->c.a = 270;
        aux1->t->c.a = 0;
    }
    /* Calcula as aceleracoes */
    for (aux1 = tiros->prox; aux1 != NULL; aux1 = aux1->prox) {
        gravidade(&aux1->t->c, &n1.c);
        gravidade(&aux1->t->c, &n2.c);
        gravidade(&aux1->t->c, &planeta);
        for (aux2 = aux1->prox; aux2 != NULL; aux2 = aux2->prox)
            gravidade(&aux1->t->c, &aux2->t->c);
    }
    gravidade(&planeta, &n1.c);
    gravidade(&planeta, &n2.c);
    gravidade(&n1.c, &n2.c);
    /* Aplica as aceleracoes */
    for (aux1 = tiros->prox; aux1 != NULL; aux1 = aux1->prox) {
        acelera(&aux1->t->c);
        if ((aux1->t->c).x < -largura_janela/2) (aux1->t->c).x += largura_janela;
        if ((aux1->t->c).x > largura_janela/2) (aux1->t->c).x -= largura_janela;
        if ((aux1->t->c).y < -altura_janela/2) (aux1->t->c).y += altura_janela;
        if ((aux1->t->c).y > altura_janela/2) (aux1->t->c).y -= altura_janela;
    }
    acelera(&n1.c);
    if ((n1.c).x < -largura_janela/2) (n1.c).x += largura_janela;
    if ((n1.c).x > largura_janela/2) (n1.c).x -= largura_janela;
    if ((n1.c).y < -altura_janela/2) (n1.c).y += altura_janela;
    if ((n1.c).y > altura_janela/2) (n1.c).y -= altura_janela;
    acelera(&n2.c);
    if ((n2.c).x < -largura_janela/2) (n2.c).x += largura_janela;
    if ((n2.c).x > largura_janela/2) (n2.c).x -= largura_janela;
    if ((n2.c).y < -altura_janela/2) (n2.c).y += altura_janela;
    if ((n2.c).y > altura_janela/2) (n2.c).y -= altura_janela;
    /* Atualiza o tempo dos tiros e colisões */
    for (aux1 = tiros; aux1->prox != NULL; aux1 = aux1->prox) { 
        aux1->prox->t->t--;
        if (aux1->prox->t->t <= 0) {
            tira (aux1);
            if (aux1->prox == NULL) break;
        }
        for (aux2 = aux1->prox; aux2 != NULL && aux2->prox != NULL; aux2 = aux2->prox) {
            if (dist(aux1->prox->t->c, aux2->prox->t->c) <= diam_tiro) {
                tira (aux2);
                tira (aux1);
                if (aux1->prox == NULL) goto sai;
            }

        }
        if (dist (planeta, aux1->prox->t->c) <= (R + diam_tiro)/2) {
            tira(aux1);
            if (aux1->prox == NULL) break;
        }
        else if (dist (n1.c, aux1->prox->t->c) <= (n1.r + diam_tiro)/2) {
            tira (aux1);
            n1.vida--;
            if (aux1->prox == NULL) break;
        }
        else if (dist (n2.c, aux1->prox->t->c) <= (n2.r + diam_tiro)/2) {
            tira (aux1);
            n2.vida--;
            if (aux1->prox == NULL) break;
        } 
    }
sai:
    if (dist (n1.c, n2.c) <= (n1.r + n2.r)/2) {
        n1.vida--;
        n2.vida--;
    }
    if (dist (n1.c, planeta) <= (n1.r + R) / 2)
        n1.vida--;
    if (dist (n2.c, planeta) <= (n2.r + R) / 2)
        n2.vida--;
}
