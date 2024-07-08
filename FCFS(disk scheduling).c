#include <stdio.h>
#include <stdlib.h>
void main()
{
   int head,limit,distance,seektime = 0;
   
   printf("Enter initial head position\n");
   scanf("%d",&head);
   
   printf("Enter number of requests\n");
   scanf("%d",&limit);
   int req[limit + 1];
   req[0]= head;
   
   printf("Enter requests\n");
   for(int i=1; i< limit+1 ;i++)
    scanf("%d",&req[i]);
    
   
   printf("FCFS\n");
   for(int i=0 ;i<limit ;i++){
    distance = abs(req[i] - req[i+1]);
    printf("Head movement from %d to %d is %d\n",req[i],req[i+1],distance);
    seektime+=distance;
   }
   printf("Seektime is %d",seektime);
}
