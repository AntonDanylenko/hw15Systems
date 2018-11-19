#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  printf("Intitial message\n");
  int childA = fork();
  printf("ChildA Pid: %d\n", childA);
  int x = 0;
  int status;
  while(x<8){
    waitpid(&childA, status, 0);
    sleep(1);
  }
  printf("ChildA done waiting\n");
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
