#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// GOAL: Exécution de 2 compte à rebours dans 2 processus différents

int main(int argc, char** argv)
{
    if (fork()){
        execl("./rebours", "./rebours", "1", NULL);     // Ne revient pas
    } else {
        execl("./rebours", "./rebours", "3", NULL);
    }

    // return EXIT_SUCCESS;
    
}
