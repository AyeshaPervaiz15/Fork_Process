#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
pid_t pidB,pidC,pidD,pidE,pidF,pidG,pidH,pidI,pidJ;

printf("A process %d\n",getpid());
//B Node and its Children
{
pidB=fork();
if(pidB<0){ 
fprintf(stderr,"Fork Failed"); 
return 1;}
else if (pidB==0){ 

//
pidE=fork();
if(pidE<0){ 
fprintf(stderr,"Fork Failed");
 return 1;}
else if(pidE==0){ printf("No child of E\n");  }

else{ 
printf("E process %d\n",getpid());
wait(NULL);
//
 pidF=fork();
if(pidF<0){ 
fprintf(stderr,"Fork Failed"); 
return 1;}
else if(pidF==0){
 printf("No child of F\n"); }
else{ printf("F process %d\n",getpid());  
wait(NULL);} }

return 0;
}
else
{
printf("B process %d\n",getpid());
wait(NULL);

}
}

// C Node and its Children
pidC=fork();
if(pidC<0)
{
fprintf(stderr,"Fork Failed");
return 1;
}
else if (pidC==0)
{
pidG=fork();
if(pidG<0){ 
fprintf(stderr,"Fork Failed"); 
return 1;}
else if(pidG==0){ 
printf("No G Child\n");  }
else{ 
printf("G process %d\n",getpid());  
wait(NULL);}

return 0;
}
else
{
printf("C process %d\n",getpid());
wait(NULL);
//printf("Child_C complete\n");
}

// D node and its Children
pidD=fork();
if(pidD<0)
{
fprintf(stderr,"Fork Failed");
return 1;
}
else if (pidD==0)
{
pidH=fork();
if(pidH<0){
 fprintf(stderr,"Fork Failed"); 
 return 1;}
else if(pidH==0){ 

pidI=fork();
if(pidI<0){ 
fprintf(stderr,"Fork Failed");
 return 1;}
else if(pidI==0){ 
printf("No I Child\n");  }
else{ 
printf("I process %d\n",getpid()); 
wait(NULL);

pidJ=fork();
if(pidJ<0){ 
fprintf(stderr,"Fork Failed");
 return 1;}
else if(pidJ==0){
 printf("No J Child\n");  }
else{ printf("J process %d\n",getpid());
wait(NULL);}
}

return 0;
}
 
else{ printf("H process %d\n",getpid());
wait(NULL);}
return 0;
}

else
{
printf("D process %d\n",getpid());
wait(NULL);
}
return 0;
}
