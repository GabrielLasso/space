#include "fisica.h"

/* Retorna a distância dos corpos c1 e c2 */
long double dist (corpo c1, corpo c2) {
    return sqrt ((c1.x-c2.x)*(c1.x-c2.x)+(c1.y-c2.y)*(c1.y-c2.y));
}

/* Aplica a forca gravitacional entre dois corpos c1 e c2 */
void gravidade (corpo *c1, corpo *c2) {
    long double d = dist (*c1, *c2);
    if (d == 0) return;
    (*c1).ax += (*c2).m*((*c2).x-(*c1).x)*(G/(d*d*d));
    (*c2).ax += (*c1).m*((*c1).x-(*c2).x)*(G/(d*d*d));
    (*c1).ay += (*c2).m*((*c2).y-(*c1).y)*(G/(d*d*d));
    (*c2).ay += (*c1).m*((*c1).y-(*c2).y)*(G/(d*d*d));
}

/* Calcula as novas coordenadas e velocidades do corpo c apos um tempo dt */
void acelera (corpo *c) {
    (*c).vx += (*c).ax;
    (*c).vy += (*c).ay;
    (*c).x += (*c).vx + 0.5*(*c).ax;
    (*c).y += (*c).vy + 0.5*(*c).ay;
    (*c).ax = (*c).ay = 0;
}
