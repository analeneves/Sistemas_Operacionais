all: shellso.c func.c
	gcc shellso.c func.c -o shellso

clean: shellso
	rm -rf shellso