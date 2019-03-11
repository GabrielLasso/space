#include "arte.h"

/* Retorna a pic da imagem em resources/fase/$fase/bg.xpm */
PIC criabg (WINDOW *w, char* fase) {
    char nome[100];
    sprintf (nome, "resources/fases/%s/bg.xpm", fase);
    return ReadPic (w, nome, NULL);
}

/* Retorna a pic da imagem em resources/fase/$fase/planeta.xpm e salva a mask correspondente em m */
PIC criaplaneta (WINDOW *w, char* fase, MASK *m) {
    char nome[100];
    PIC p;
    sprintf (nome, "resources/fases/%s/planeta.xpm", fase);
    p = ReadPic (w, nome, NULL);
    *m = NewMask (p, R, R);
    FreePic (p);
    p = ReadPic (w, nome, *m);
    return p;
}

/* Recebe um chart c e cria as PICs e MASKs dele baseado nos arquivos $i.xpm da pasta $(*c).nome, com i variando de 0 a 15 */
void criachartmissil (WINDOW *w, int largura, int altura, chart *c) {
    int i;
    char fname[100];
    for (i = 0; i < 1; i++) {
        sprintf (fname, "resources/missil/%02d.xpm", i);
        (*c).p[i] = ReadPic (w, fname, NULL);
        (*c).m[i] = NewMask ((*c).p[i], largura, altura);
        FreePic ((*c).p[i]);
        (*c).p[i] = ReadPic (w, fname, (*c).m[i]);
    }
}

/* Recebe um chart c e cria as PICs e MASKs dele baseado nos arquivos $i.xpm da pasta resources/naves/$(*c).nome, com i variando de 0 a 15 */
void criachart (WINDOW *w, int largura, int altura, chart *c) {
    int i;
    char fname[100];
    for (i = 0; i < 16; i++) {
        sprintf (fname, "resources/naves/%s/%02d.xpm", (*c).nome, i);
        (*c).p[i] = ReadPic (w, fname, NULL);
        (*c).m[i] = NewMask ((*c).p[i], largura, altura);
        FreePic ((*c).p[i]);
        (*c).p[i] = ReadPic (w, fname, (*c).m[i]);
    }
}

/* Recebe uma PIC, uma MASK e dois inteiros x e y e desenha a PIC de largura w e altura h com a MASK aplicada na posicao (x,y) no sistema cartesiano centrado no centro da janela */
void draw (WINDOW *w, PIC p, MASK m, int largura, int altura, int x, int y) {
    SetMask (w, m);
    PutPic (w, p, 0, 0, largura, altura, x + (largura_janela-largura)/2, y + (altura_janela-altura)/2);
    UnSetMask (w);
}

