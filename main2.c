#include  <stdio.h>
#include  <sys/types.h>
#include <stdlib.h>
//Jose Ruiz
#define   MAX_COUNT  2

void  ChildProcess(int);    /* child process prototype  */
void  ParentProcess(void);               /* parent process prototype */

void  main(void)
{
     int i;
  
     pid_t  pid;
     srand(getpid());
       for( i = 0; i <2; i++){
       pid = fork();
       if (pid == 0) 
          ChildProcess(i);
       else if(pid > 0)
          ParentProcess();
       else
          printf("Error in Fork\n");
     }
     
  
}

void  ChildProcess(int myid)
{
  
     int  i;
  
      if(myid == 0){
      printf("\nIn Child %d\n", myid);
      }
     else if (myid == 1){
     printf("\nIn Child %d\n", myid);
     }
      
     
     for (i = 1; i <= MAX_COUNT; i++){
          printf("\nChild Pid: %d is going to sleep!\n", getpid());
          sleep(rand() % 10);
          printf("\nChild Pid: is awake!\n Where is my parent: %d\n", getppid());
          
     }
  exit(0);
}


void  ParentProcess(void)
{
     int   i;
     int status;
     pid_t cpid;
  
     for (i = 1; i < 2; i++){
      cpid = wait(&status);
       
      printf("\nChild Pid: %d has completed\n", cpid);
     }
       
  
  
     printf("*** Parent is done ***\n");
}