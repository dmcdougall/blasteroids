CFLAGS=-O3
LDFLAGS=-lm -framework GLUT -framework OpenGL

%.o: %.c
	$(CC) -c $< $(CFLAGS) -o $@

OBJS = data.o blasteroids.o
HEADERS = data.h

blast: $(OBJS) $(HEADERS)
	$(CC) $(OBJS) -o blast -framework GLUT -framework OpenGL
