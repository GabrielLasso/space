#include "space.h"

int keys[256];

static void update () {
    XEvent event;
    if (WCheckKBD (w)) {
        WGetEvent(w);
        event = WLastEvent();
        if (event.type == KeyPress){
            keys[event.xkey.keycode] = 1;
        }
        if(event.type == KeyRelease){
            keys[event.xkey.keycode] = 0;
        }
    }
}

void input() {
    tiro *t;
    t1--;
    t2--;
    tr1--;
    tr2--;
    update();

    if (keys[111]) { /* Up */
        n1.c.vy -= n1.a*cos(n1.c.a / 57.2957795131);
        n1.c.vx += n1.a*sin(n1.c.a / 57.2957795131);
    }
    if (keys[116]) { /* Down */
        if (t1 <= 0) {
            t1 = d1;
            t = malloc (sizeof (tiro));
            t->c.x = n1.c.x + (n1.r + diam_tiro)*sin(n1.c.a / 57.2957795131)/2;
            t->c.y = n1.c.y - (n1.r + diam_tiro)*cos(n1.c.a / 57.2957795131)/2;
            t->c.vx = n1.c.vx + 10*sin(n1.c.a / 57.2957795131);
            t->c.vy = n1.c.vy - 10*cos(n1.c.a / 57.2957795131);
            t->c.ax = t->c.ay = 0;
            t->c.m = 10;
            t->t = 60;
            insere (t, tiros);
        }
    }
    if (keys[113]) { /* Left */
        if (tr1 <= 0) {
            tr1 = dr1;
            n1.c.a -= 22.5;
            if (n1.c.a < 0) n1.c.a += 360;
        }
    }
    if (keys[114]) { /* Right */
        if (tr1 <= 0) {
            tr1 = dr1;
            n1.c.a += 22.5;
        }
    }
    if (keys[25]) { /* W */
        n2.c.vy -= n2.a*cos(n2.c.a / 57.2957795131);
        n2.c.vx += n2.a*sin(n2.c.a / 57.2957795131);
    }
    if (keys[39]) { /* S */
        if (t2 <= 0) {
            t2 = d2;
            t = malloc (sizeof (tiro));
            t->c.x = n2.c.x + (n2.r + diam_tiro)*sin(n2.c.a / 57.2957795131)/2;
            t->c.y = n2.c.y - (n2.r + diam_tiro)*cos(n2.c.a / 57.2957795131)/2;
            t->c.vx = n2.c.vx + 10*sin(n2.c.a / 57.2957795131);
            t->c.vy = n2.c.vy - 10*cos(n2.c.a / 57.2957795131);
            t->c.ax = t->c.ay = 0;
            t->c.m = 10;
            t->t = 60;
            insere (t, tiros);
        }
    }
    if (keys[38]) { /* A */
        if (tr2 <= 0) {
            tr2 = dr1;
            n2.c.a -= 22.5;
            if (n2.c.a < 0) n2.c.a += 360;
        }
    }
    if (keys[40]) { /* D */
        if (tr2 <= 0) {
            tr2 = dr1;
            n2.c.a += 22.5;
        }
    }
}
