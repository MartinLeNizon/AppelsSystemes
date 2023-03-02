#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// GOAL: Exécute le programme passé en premier argument autant de fois qu'il y a d'autres arguments.
// Exemple : ./parexec1 ./rebours 1 2 3         Exécution 3 Exécution 3 compte à rebours de 1, 2 et 3 secondes

int main(int argc, char** argv)
{
    assert(argc >= 3);

    for (int i=2; i<argc; i++) {  
        if (!fork()){
            // Dans le process enfant
            execl(argv[1], argv[1], argv[i], NULL);     // Ne revient pas
        }
    }
    for (int i=2; i<argc; i++) {
        wait(NULL);
    }
    return EXIT_SUCCESS;
}