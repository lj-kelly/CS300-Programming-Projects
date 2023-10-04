#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
  printf("execvpe\n");
  printf("hello world (pid:%d)\n", (int) getpid());
  int rc = fork();
  if (rc < 0) { // fork failed; exit
    fprintf(stderr, "fork failed\n");
    exit(1);
  } 
  else if (rc == 0) { // child (new process)
    printf("hello, I am child (pid:%d)\n", (int) getpid());
    //execl("/bin/ls", "ls", "-1", NULL); // execl call (part 2a)
    //execle("/bin/ls", "ls", "-1", NULL, NULL); // execle call (part 2b)
    //execlp("ls", "ls", "-1", NULL); // execlp call  (part 2c)
    //execv("/bin/ls", argv); // execv call (part 2d)
    //execvp("ls", argv); // execvp call (part 2e)
    //execvpe("ls", argv, NULL); // execvpe call (part 2f) not working currently
    printf("this shouldn't print out");
  }
  else { // parent goes down this path (main)
    int rc_wait = wait(NULL);
    printf("hello, I am parent of %d (rc_wait:%d) (pid:%d)\n",
    rc, rc_wait, (int) getpid());
  }
  return 0;
}
