#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
  printf("waitpid in parent call\n");
  printf("hello world (pid:%d)\n", (int) getpid());
  int rc = fork();
  if (rc < 0) { // fork failed; exit
    fprintf(stderr, "fork failed\n");
    exit(1);
  } 
  else if (rc == 0) { // child (new process)
    
    //int rc_wait = wait(NULL); // (part of child wait call)
    //int rc_wait = waitpid(rc, NULL, 0); //(part of child waitpid call)
    //printf("hello, I am child of %d (rc_wait:%d) (pid:%d)\n", rc, rc_wait, (int) getpid()); //(child wait call)


    printf("hello, I am child (pid:%d)\n", (int) getpid()); //(child pid call)
    
    
  } 
  else { // parent goes down this path (main)
    //int rc_wait = wait(NULL); //(part of parent wait call)
    int rc_wait = waitpid(rc, NULL, 0); //(part of parent waitpid call)
    printf("hello, I am parent of %d (rc_wait:%d) (pid:%d)\n", rc, rc_wait, (int) getpid()); //(parent wait call)

    //printf("hello, I am parent (pid:%d)\n", (int) getpid()); //(parent pid call)
  }

  return 0;
}
