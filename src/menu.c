#include "menu.h"
void menu () {
    FILE *f;
    char aux[100], *fases[100], *naves[100];
    int i;
    DIR *df, *dn;
    struct dirent *myfile;
    i = 0;
    dn = opendir ("resources/naves");
    while ((myfile = readdir(dn)) != NULL) {
        if (myfile->d_name[0] != '.') {
            naves[i] = myfile->d_name;
            i++;
        }
    }
    naves[i] = NULL;
    i = 0;
    df = opendir ("resources/fases");
    while ((myfile = readdir(df)) != NULL) {
        if (myfile->d_name[0] != '.') {
            fases[i] = myfile->d_name;
            i++;
        }
    }
    fases[i] = NULL;
    printf ("Escolha a nave do primeiro jogador (digite o número):\n");
    for (i = 0; naves[i] != NULL; i++)
        printf ("%d. %s\n", i+1, naves[i]);
    scanf ("%d", &i);
    n1.c.c.nome = naves[i-1];
    printf ("Escolha a nave do segundo jogador (digite o número):\n");
    for (i = 0; naves[i] != NULL; i++)
        printf ("%d. %s\n", i+1, naves[i]);
    scanf ("%d", &i);
        n2.c.c.nome = naves[i-1];
    printf ("Escolha a fase (digite o número):\n");
    for (i = 0; fases[i] != NULL; i++)
        printf ("%d. %s\n", i+1, fases[i]);
    scanf ("%d", &i);
    fase = fases[i-1];
    sprintf (aux, "resources/fases/%s/newgame", fase);
    f = fopen (aux, "r");
    fscanf (f, "%Lf %Lf", &R, &(planeta.m));
    fscanf (f, "%Lf %Lf %Lf %Lf", &n1.c.x, &n1.c.y, &n1.c.vx, &n1.c.vy);
    fscanf (f, "%Lf %Lf %Lf %Lf", &n2.c.x, &n2.c.y, &n2.c.vx, &n2.c.vy);
    fscanf (f, "%d %d", &largura_janela, &altura_janela);
    fclose (f);
    sprintf (aux, "resources/naves/%s/proprieties", n1.c.c.nome);
    f = fopen (aux, "r");
    fscanf (f, "%Lf %d %d %d %d %Lf", &n1.c.m, &d1, &dr1, &vidamax1, &n1.r, &n1.a);
    n1.vida = vidamax1;
    fclose (f);
    sprintf (aux, "resources/naves/%s/proprieties", n2.c.c.nome);
    f = fopen (aux, "r");
    fscanf (f, "%Lf %d %d %d %d %Lf", &n1.c.m, &d2, &dr2, &vidamax2, &n2.r, &n2.a);
    n2.vida = vidamax2;
    fclose (f);
    f = fopen ("resources/missil/proprieties", "r");
    fscanf (f, "%d", &diam_tiro);
}
