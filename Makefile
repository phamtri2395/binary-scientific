binary-scientific: main.c libs/processFile.c libs/convertLib.c
	gcc -o binary-scientific main.c libs/processFile.c libs/convertLib.c -Ilibs
	./binary-scientific
