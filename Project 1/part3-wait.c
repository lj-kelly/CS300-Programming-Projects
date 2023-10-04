#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
  printf("hello world (pid:%d)\n", (int) getpid());
  int rc = fork();
  if (rc < 0) { // fork failed; exit
    fprintf(stderr, "fork failed\n");
    exit(1);
  } 
  else if (rc == 0) { // child (new process)
    
    int rc_wait = wait(NULL); // (part 3a)
    //int rc_wait = waitpid(rc, NULL, 0); (part 3b)
    printf("hello, I am child of %d (rc_wait:%d) (pid:%d)\n", rc, rc_wait, (int) getpid());
    
    
  } 
  else { // parent goes down this path (main)
    //int rc_wait = wait(NULL); (part of parent wait call)
    printf("hello, I am parent (pid:%d)\n", (int) getpid());
    //printf("hello, I am parent of %d (rc_wait:%d) (pid:%d)\n", rc, rc_wait, (int) getpid()); (parent wait call)
  }
  return 0;
}
