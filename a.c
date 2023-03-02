#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// GOAL: Affichage de A dans chaque processus -> il doit en apparaître 6

int main(int argc, char** argv)
{
    fork();
    if (fork()){
        fork();
    }
    printf("%d : A\n", getpid());

    return EXIT_SUCCESS;
}
