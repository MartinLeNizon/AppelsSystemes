#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// GOAL: Création d'un processus enfant

int main(int argc, char** argv) {
    printf("%d : hello world \n", getpid());

    if(fork() == 0) {
        printf("%d : je suis l'enfant \n", getpid());
    } else {
        printf("%d : je suis le parent \n", getpid());
    }    

    return EXIT_SUCCESS;
}
