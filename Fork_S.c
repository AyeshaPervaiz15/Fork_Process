#include <stdio.h>
#include <stdlib.h>
int main()
{
int a;
printf("Enter Size of Array:\n");
scanf("%d",&a);

printf("Enter %d Elements of Array: ",a);
int* arr=(int*)malloc(a * (sizeof(int))); 
for(int i=0;i<a;i++)
{
scanf("%d",&arr[i]);
}
pid_t pid;
pid=fork();

if(pid<0)
{
printf("Failed");
return 1;
}
else if(pid==0)
 {
 for(int i=0;i<a;i++)
 {
  printf("cube of %d is %d \n",arr[i],arr[i]*arr[i]*arr[i]);
 }
}

else
{
 for(int i=0;i<a;i++)
 {
 printf("Square of %d is %d\n" ,arr[i] ,arr[i]*arr[i]);
 }
 wait(NULL);
}

 return 0;
}
