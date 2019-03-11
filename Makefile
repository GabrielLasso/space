CC=gcc
CFLAGS=-W -Wall -ansi -pedantic

space: lib/main.o lib/fisica/space.o lib/fisica/fisica.o lib/arte/space.o lib/arte/xwc.o lib/arte/arte.o lib/public/structs.o lib/input/space.o lib/menu.o
	$(CC) -o space lib/main.o lib/fisica/space.o lib/fisica/fisica.o lib/arte/space.o lib/arte/arte.o lib/arte/xwc.o lib/public/structs.o lib/input/space.o lib/menu.o -lm -lX11 -lXpm

#Controle
lib/main.o: src/main.c
	$(CC) -o lib/main.o -c src/main.c $(CFLAGS)

lib/menu.o: src/menu.c src/menu.h
	$(CC) -o lib/menu.o -c src/menu.c $(CFLAGS)

# Parte 1 (fisica)
lib/fisica/space.o: src/fisica/space.c src/fisica/space.h
	$(CC) -o lib/fisica/space.o -c src/fisica/space.c $(CFLAGS)

lib/fisica/fisica.o: src/fisica/fisica.c src/fisica/fisica.h src/config.h
	$(CC) -o lib/fisica/fisica.o -c src/fisica/fisica.c $(CFLAGS)

# Parte 2 (grafica)
lib/arte/space.o: src/arte/space.c src/arte/space.h src/config.h
	$(CC) -o lib/arte/space.o -c src/arte/space.c $(CFLAGS)
	
lib/arte/arte.o: src/arte/arte.c src/arte/arte.h src/config.h
	$(CC) -o lib/arte/arte.o -c src/arte/arte.c $(CFLAGS)

lib/arte/xwc.o: src/arte/xwc.c src/arte/xwc.h
	$(CC) -o lib/arte/xwc.o -c src/arte/xwc.c $(CFLAGS)

# Parte 3 (input)
lib/input/space.o: src/input/space.c src/input/space.h
	$(CC) -o lib/input/space.o -c src/input/space.c $(CFLAGS)

# Public
lib/public/structs.o: src/public/structs.c src/public/structs.h
	$(CC) -o lib/public/structs.o -c src/public/structs.c $(CFLAGS)

clean: 
	find . -name '*.o' -delete
	find . -name '*.swp' -delete
	[[ -f space ]] && rm space
