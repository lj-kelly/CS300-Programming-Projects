#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){

    printf("hello world (pid:%d)\n", (int) getpid());
    int x = 100;
    printf("x value is:%d\n", x);
    int rc = fork();

    if (rc < 0) { // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0) { // child (new process)
        x = 101;
        printf("hello, I am child (pid:%d)\n", (int) getpid());
        printf("x value is:%d\n", x);
    }
    else { // parent goes down this path (main)
        x = 102;
        int rc_wait = wait(NULL);
        printf("hello, I am parent of %d (rc_wait:%d) (pid:%d)\n", rc, rc_wait, (int) getpid());
        printf("x value is:%d\n", x);
    }
    return 0;
}
