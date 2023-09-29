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
        //PART 1- CHILD DOES NOT CHANGE X
        //x = 101;
        //PART 2- CHILD DOES CHANGE X
        //x = 101;
        printf("child (x:%d)\n", x);
        printf("hello, I am child (pid:%d)\n", (int) getpid());
    } 
    else {
        // parent goes down this path (main)
        //PART 1- PARENT DOES NOT CHANGE X
        //x = 102;
        //PART 2- PARENT DOES CHANGE X
        //x = 102;
        printf("parent (x:%d)\n", x);
        printf("hello, I am parent of %d (pid:%d)\n",
        rc, (int) getpid());
    }
    printf("x final (x:%d)\n", x);
    return 0;
}
