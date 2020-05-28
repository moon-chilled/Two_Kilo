CC ?= cc
default:
	$(CC) -c -Wno-format -Wno-incompatible-pointer-types -Wno-implicit-int -Wno-int-conversion -Wno-implicit-function-declaration -g two_kilo.c
	$(CC) -o two_kilo two_kilo.o -lncurses
