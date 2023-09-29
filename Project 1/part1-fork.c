#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    printf("hello world (pid:%d)\n", (int) getpid());
    int x = 100;
    printf("x initial (x:%d)\n", x);
    int rc = fork();
    
    if (rc < 0) {
        // fork failed
        fprintf(stderr, "fork failed\n");
        exit(1);
    } 
    else if (rc == 0) {
        // child (new process)
        x = 101;
        printf("child (x:%d)\n", x);
        printf("hello, I am child (pid:%d)\n", (int) getpid());
    } 
    else {
        // parent goes down this path (main)
        x = 102;
        printf("parent (x:%d)\n", x);
        printf("hello, I am parent of %d (pid:%d)\n",
        rc, (int) getpid());
    }
    printf("x final (x:%d)\n", x);
    return 0;
}
