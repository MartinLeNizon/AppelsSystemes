#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// GOAL: Compte à rebours en secondes - ./rebours 5

int main(int argc, char** argv)
{
    assert(argc == 2);
    int count = atoi(argv[1]);
    assert(count > 0);
    int pid = getpid();
    printf("%d : debut \n", pid);

    for (int i = atoi(argv[1]) ; i > 0 ; i--) {
        printf("%d : %d \n", pid, i);
        sleep(1);
    }

    printf("%d : fin \n", pid);

    return EXIT_SUCCESS;
}
