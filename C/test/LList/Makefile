INCDIR := $(shell pwd)/../../include
CFLAGS=-Wall
test:	main.c
	gcc $(CFLAGS) -I$(INCDIR) -o $@ $^
clean:
	-rm test
