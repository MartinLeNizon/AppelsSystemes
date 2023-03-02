#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// GOAL: Idem parexec1, mais ici limitation du nombre de processus tournant en même temps, donné par 2ème argument

int main(int argc, char** argv) {
    assert(argc >= 3);

    int N = atoi(argv[2]);
    int nbProcess = 0;


    for (int i=3; i<argc; i++) {  
        if (!fork()){
            // Dans le process enfant
            execl(argv[1], argv[1], argv[i], NULL);     // Ne revient pas
        } else {
            nbProcess++;
        }

        if (nbProcess >= N) {
            wait(NULL);
            nbProcess--;
        }
    }

    for (int i=0; i<nbProcess; i++) {
        wait(NULL);
    }

    return EXIT_SUCCESS;
}
