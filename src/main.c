#include "fisica/space.h"
#include "arte/space.h"
#include "input/space.h"
#include "menu.h"

int main () {
    int i;
    menu();
    w = InitGraph (largura_janela, altura_janela, nome_jogo);
    InitKBD (w);
    memset (keys, 0, 256);
    disableAutoRepeat();
    bg = criabg(w, fase);
    planetasprite = criaplaneta (w, fase, &mplaneta);
    criachart (w, n1.r, n1.r, &n1.c.c);
    criachart (w, n2.r, n2.r, &n2.c.c);
    criachartmissil (w, diam_tiro, diam_tiro, &tirosprite);
    planeta.x = planeta.y = planeta.vx = planeta.vy = planeta.ax = planeta.ay = n1.c.ax = n1.c.ay = n2.c.ax = n2.c.ay = n1.c.a = n2.c.a = 0;
    t1 = d1;
    t2 = d2;
    tr1 = dr1;
    tr2 = dr2;
    tiros = malloc (sizeof(lista));
    tiros->prox = NULL;

    while (n1.vida > 0 && n2.vida > 0) {
        usleep(1000000/frame_rate);
        fisica();
        arte();
        input();
    }

    if (n1.vida > 0) printf ("Jogador 1 ganhou\n");
    else if (n2.vida > 0) printf ("Jogador 2 ganhou\n");
    else printf ("Empate\n");
    getchar();
    printf ("Aperte enter para continuar");
    while (getchar() != '\n');

    while (tiros->prox != NULL) tira (tiros);
    free (tiros);
    FreePic(bg);
    FreePic(planetasprite);
    for (i=0; i<16; i++) {
        FreePic (n1.c.c.p[i]);
        FreePic (n2.c.c.p[i]);
    }
    WDestroy (w);
    CloseGraph ();
    return 0;
}
