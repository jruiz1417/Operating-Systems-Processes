#include  <stdio.h>
#include  <sys/types.h>
#include <stdlib.h>

#define   MAX_COUNT  2

void  ChildProcess();    /* child process prototype  */
void  ParentProcess(void);               /* parent process prototype */

void  main(void)
{
     int i;
  
     pid_t  pid;
     srand(getpid());
       for( i = 0; i <2; i++){
       pid = fork();
       if (pid == 0) 
          ChildProcess();
       else if(pid > 0)
          ParentProcess();
       else
          printf("Error in Fork\n");
     }
     
  
}

void  ChildProcess()
{
     int   i;
   
     for (i = 1; i <= MAX_COUNT; i++){
          printf("Child Pid: %d is going to sleep", getpid());
          sleep(rand() % 10);
          printf("Child Pid: is awake!\n Where is my parent: %d?", getppid());
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
       
      printf("Child Pid: %d has completed", cpid);
     }
       
  
  
     printf("*** Parent is done ***\n");
}