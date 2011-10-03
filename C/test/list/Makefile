INCDIR := $(shell pwd)/../../include
test:	main.c tmp.c
	gcc -I$(INCDIR) -o $@ $^
clean:
	-rm test
