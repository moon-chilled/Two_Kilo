CC ?= cc
default:
	$(CC) two_kilo.c -o two_kilo -Wno-format -Wno-incompatible-pointer-types -Wno-incompatible-pointer-types -Wno-implicit-int -Wno-int-conversion -Wno-implicit-function-declaration -g -lncurses
