/*
 * Declaração das variáveis globais e das structs utilizadas
 */
#ifndef _STRUCTS_H
#define _STRUCTS_H
#include "../arte/xwc.h"
#include <stdlib.h>


typedef struct spritechart {
    PIC p[16];
    MASK m[16];
    char* nome;
} chart;

typedef struct corpo {
    long double m, x, y, vx, vy, ax, ay, a;
    chart c;
} corpo;

typedef struct nave {
    corpo c;
    int vida, r, vt;
    long double a;
} nave;

typedef struct tiro {
    int t;
    corpo c;
} tiro;

typedef struct lista {
    tiro *t;
    struct lista *prox;
} lista;

WINDOW *w;
PIC bg, planetasprite;
MASK mplaneta;
chart tirosprite;
/* delay do tiro */
int d1, d2, t1, t2;
/* delay de rotação */
int dr1, dr2, tr1, tr2;
int vidamax1, vidamax2;
int diam_tiro, largura_janela, altura_janela;
long double R;
nave n1, n2;
lista *tiros;
corpo planeta;
char *fase;

/* Insere um tiro de endereço x na lista p */
void insere (tiro *x, lista *p);

void tira (lista *p);
#endif
