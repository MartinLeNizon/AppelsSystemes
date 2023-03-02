#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// GOAL: Si interruption non spontannée d'un processus, on n'en lance pas de nouveaux

int main(int argc, char** argv) {
	assert(argc >= 3);

	int N = atoi(argv[2]);
	int nbProcess = 0;

    int childProcessStatus=0;

	for (int i=3; i<argc; i++) {
		 
		if (!fork()) { // * Dans le process enfant
			execl(argv[1], argv[1], argv[i], NULL);     // ! Ne revient pas
		} else {
			nbProcess++;
		}

		if (nbProcess >= N) {
			wait(&childProcessStatus);
			nbProcess--;
		}

		if (childProcessStatus != 0) {
			break;
		}

	}

	for (int i=0; i<nbProcess; i++) {
		wait(NULL);
		nbProcess--;
	}

	return EXIT_SUCCESS;
}
