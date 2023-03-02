# si on tape "make" sans préciser de cible, make va chercher à
# construire la *première* cible du Makefile.
default: all

all: rebours fourche doublerebours parexec1 parexec2 parexec3 parexec4 a

##########################################
# compilation des programmes

rebours: rebours.c
	gcc -g -Wall -Werror -o rebours rebours.c 

fourche: fourche.c
	gcc -g -Wall -Werror -o fourche fourche.c

doublerebours: doublerebours.c
	gcc -g -Wall -Werror -o doublerebours doublerebours.c 

parexec1: parexec1.c
	gcc -g -Wall -Werror -o parexec1 parexec1.c

parexec2: parexec2.c
	gcc -g -Wall -Werror -o parexec2 parexec2.c

parexec3: parexec3.c
	gcc -g -Wall -Werror -o parexec3 parexec3.c

parexec4: parexec4.c
	gcc -g -Wall -Werror -o parexec4 parexec4.c

a: a.c
	gcc -g -Wall -Werror -o a a.c

##########################################
# nettoyage des fichiers générés

.PHONY:clean mrproper

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf rebours doublerebours fourche parexec1 parexec2 parexec3 parexec4 a
