#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// GOAL: Si interruption non spontannée d'un processus, on n'en lance pas de nouveaux

// TODO: Non functionnal

void removeFromArray(int *array, int *sizePtr, int valueToRemove);

int main(int argc, char** argv) {

	assert(argc >= 3);

	int N = atoi(argv[2]);
	
	int nbProcess = 0;
	int childProcessPIDs[argc-3];

	int endedProcessPID;

	int childProcessStatus;

	for (int i=3; i<argc; i++) { // Pour chaque compte à faire

		childProcessPIDs[nbProcess] = fork();
		nbProcess++;

		if (childProcessPIDs[nbProcess-1] == 0) {		// Dans le processus enfant
			execl(argv[1], argv[1], argv[i], NULL);		// Lancement du chrono associé		// ! Ne revient pas
		}

		if (nbProcess >= N) {	// Lorsque atteinte de la limite d'instances lancées
			endedProcessPID = wait(&childProcessStatus);		// Attente qu'un processus soit terminé
			removeFromArray(childProcessPIDs, &nbProcess, endedProcessPID);		// Le retire du tableau des processus en cours
		}

		if (endedProcessPID != 0) {		// Si le processus s'est terminé anormalement
			for (int i=0; i<nbProcess; i++) {			// Pour chaque processus restant
				kill(childProcessPIDs[i], SIGTERM);		// On tue le processus
				nbProcess--;
			}
		}

	}

	for (int i=0; i<nbProcess; i++) {	// Attente fin des processus restants (si aucun processus ne s'est terminé anormalement)
		endedProcessPID = wait(&childProcessStatus);
		removeFromArray(childProcessPIDs, &nbProcess, endedProcessPID);
	}

	return EXIT_SUCCESS;
}

void removeFromArray(int *array, int *sizePtr, int valueToRemove) {
	int index = -1;

	for (int i = 0; i < *sizePtr; i++) {
        if (array[i] == valueToRemove) {
            index = i; // Found the element, store its index
			(*sizePtr)--;
			break;
        }
    }

	if (index != -1) {
		for (int i = index; i < *sizePtr; i++) {
			array[i] = array[i+1];	// Not a problem because there was an element at *sizePtr position
		}
	}
}