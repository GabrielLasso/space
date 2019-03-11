/*
   Este programa le do stdin o nome da fase, o nome da nave do jogador 1 e o nome da nave do jogador 2, seguidos dos seguintes dados para cada frame:
   Coordenada x da nave 1, coordenada y da nave 1, angulo da nave 1 em relação ao eixo y
   Coordenada x da nave 2, coordenada y da nave 2, angulo da nave 2 em relação ao eixo y
   Quantidade de tiros na tela
   Uma linha para cada tiro contendo suas coordenadas x e y e seu angulo em relação ao eixo y

   E desenha numa janela as posiçoes das naves e do tiro a cada frame
   */
#include "space.h"
void arte () {
    int i, a, x, y;
    lista *aux;
    WClear (w);
    PutPic (w, bg, 0, 0, largura_janela, altura_janela, 0, 0);
    draw (w, planetasprite, mplaneta, R, R, 0, 0);
    a = ((int)(n1.c.a + 11.25)%360)/22.5;
    while (a < 0) a += 16;
    x = (int)n1.c.x;
    y = (int)n1.c.y;
    draw (w, n1.c.c.p[a], n1.c.c.m[a], n1.r, n1.r, x, y);
    a = ((int)(n2.c.a + 11.25)%360)/22.5;
    while (a < 0) a += 16;
    x = (int)n2.c.x;
    y = (int)n2.c.y;
    draw (w, n2.c.c.p[a], n2.c.c.m[a], n2.r, n2.r, x, y);
    for (aux = tiros->prox; aux != NULL; aux = aux->prox) {
        a = ((int)(aux->t->c.a + 11.25)%360)/22.5;
        while (a < 0) a += 16;
        x = (int)aux->t->c.x;
        y = (int)aux->t->c.y;
        draw (w, tirosprite.p[a], tirosprite.m[a], diam_tiro, diam_tiro, x, y);
    } 
    x = n1.c.x + largura_janela/2 - n1.r/2;
    y = n1.c.y + n1.r/2 + altura_janela/2;
    a = n1.r / vidamax1;
    for (i = 0; i < vidamax1; i++) {
        if (n1.vida >= i + 1)
            WFillRect (w, x, y, a, 10, 0x00ffff);
        else
            WRect (w, x, y, a, 10, 0x00ffff);
        x += a;
    }
    x = n2.c.x + largura_janela/2 - n2.r/2;
    y = n2.c.y + n2.r/2 + altura_janela/2;
    a = n2.r / vidamax2;
    for (i = 0; i < vidamax2; i++) {
        if (n2.vida >= i + 1)
            WFillRect (w, x, y, a, 10, 0xff0000);
        else
            WRect (w, x, y, a, 10, 0xff0000);
        x += a;
    }
}

