CC = gcc

LINK_TARGET = main

OBJS = \
tinfin.o

MAIN = main.c	

build:
	$(CC) -c tinfin.c -o $(OBJS)
	ar rcs libtinfin.a $(OBJS)
	$(CC) -c $(MAIN) -o main.o
	$(CC) -shared -fPIC -o libtinfin.so $(OBJS)
    $(CC) -o $(LINK_TARGET) main.c libtinfin.so