#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  srand(time(NULL));
  int shleep = rand();
  printf("Initial. Parent pid: %d\n", getpid());
  int childA = fork();
  if(!childA){
    printf("ChildA Pid: %d\n", getpid());
    int x = 0;
    while(x<shleep){
      wait(&childA);
      sleep(1);
    }
    printf("ChildA done waiting\n");
  }
  /*int childB = fork();
  printf("ChildB Pid: %d\n", childB);
  x = 0;
  int status;
  while (x<14){
    waitpid(&childB, status, 0);
    sleep(1);
  }
  printf("ChildB done waiting\n");*/
}
