#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  srand(time(NULL));
  int shleep = (rand()%16)+5;
  printf("Parent pid: %d\n", getpid());
  int childA = fork();
  if(!childA){
    printf("ChildA Pid: %d\n", getpid());
    sleep(shleep);
    printf("Child process %d done waiting after %d seconds\n",getpid(),shleep);
    return shleep;
  }
  else{
    int childB = fork();
    if(!childB){
      shleep = (rand()%16)+5;
      printf("ChildB Pid: %d\n", getpid());
      sleep(shleep);
      printf("Child process %d done waiting after %d seconds\n",getpid(),shleep);
      return shleep;
    }
    else {
      int status;
      int childpid = wait(&status);
      printf("Completed child process %d slept for %d seconds\n",childpid,WEXITSTATUS(status));
      return 0;
    }
    return 0;
  }
}
