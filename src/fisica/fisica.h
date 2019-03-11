#ifndef _FISICA_H
#define _FISICA_H
#include <math.h>
#include <stdio.h>
#include "../config.h"
#include "../public/structs.h"

/* Retorna a distância dos corpos c1 e c2 */
long double dist (corpo c1, corpo c2);

/* Aplica a forca gravitacional entre dois corpos c1 e c2 */
void gravidade (corpo *c1, corpo *c2);

/* Calcula as novas coordenadas e velocidades do corpo c apos um tempo dt */
void acelera (corpo *c);

#endif
