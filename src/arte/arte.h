#ifndef _ARTE_H
#include "xwc.h"
#include "string.h"
#include "../config.h"
#include "../public/structs.h"
#include "../fisica/space.h"
#include <stdio.h>
#define _ARTE_H

/* Retorna a pic da imagem em images/fase/$fase/bg.xpm */
PIC criabg (WINDOW *w, char* fname);

/* Retorna a pic da imagem em images/fase/$fase/planeta.xpm e salva a mask correspondente em m*/
PIC criaplaneta (WINDOW *w, char* fase, MASK *m);

/* Recebe um chart c e cria as PICs e MASKs dele baseado nos arquivos $i.xpm da pasta $(*c).nome, com i variando de 0 a 15 */
void criachartmissil (WINDOW *w, int largura, int altura, chart *c);

/* Recebe um chart c e cria as PICs e MASKs dele baseado nos arquivos $i.xpm da pasta resources/naves/$(*c).nome, com i variando de 0 a 15 */
void criachart (WINDOW *w, int largura, int altura, chart *c);

/* Recebe uma PIC, uma MASK e dois inteiros x e y e desenha a PIC de largura w e altura h com a MASK aplicada na posicao (x,y) no sistema cartesiano centrado no centro da janela */
void draw (WINDOW *w, PIC p, MASK m, int largura, int altura, int x, int y);

#endif
