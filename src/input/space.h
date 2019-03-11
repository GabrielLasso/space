#include "/usr/include/X11/keysym.h"
#include <stdio.h>
#include <math.h>
#include "../arte/xwc.h"
#include "../arte/space.h"
#include "../public/structs.h"

extern nave n1, n2;
extern lista *tiros;

int keys[256];

void input();
