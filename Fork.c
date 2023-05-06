//#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
int main()
{
pid_t pid;
//Fork a child process 
pid=fork();
if(pid<0)
{
fprintf(stderr,"Fork Failed");
return 1;
}
else if (pid==0)
{
//getppid();
//printf("in child process %d,%d",getpid(),getppid());
execlp("/bin/ls","ls",NULL);
}
else
{
//printf("in parent process %d,%d",getpid(),getppid());
wait(NULL);
printf("Child Complete");
}
return 0;
}
