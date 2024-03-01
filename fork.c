#include<stdio.h>
#include <unistd.h>
void main()
   {
    pid_t id;
    id=fork();
    if (id==0)
       {
        printf("\nChild Process\n");
        printf("Process id is : %d\n",getpid());
        printf("Parent's id is : %d\n",getppid());
        
        int num;
        printf("\nEnter a number :");
        scanf("%d",&num);
        if (num%2==0)
            printf("%d is even\n",num);
        else
            printf("%d is odd\n",num);
       }
       
    else if (id>0)
       {
        wait(NULL);
        printf("\nParent process\n");
        printf("Process id is : %d\n",getpid());
       
        int num;
        printf("\nEnter limit :");
        scanf("%d",&num);
        for (int i=1;i<=num;i++)
           {
            printf("%d ",i);
           }
          printf("\n");
       }
      
    else 
       {
        printf("Fork failed\n");
       }
   }
