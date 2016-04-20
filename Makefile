# Makefile 文件
des:des_start.o des.o
	gcc -o des des_start.o des.o
des_start.o:des_start.c des.h
	gcc -c -g des_start.c
des.o:des.c des.h
	gcc -c -g des.c
