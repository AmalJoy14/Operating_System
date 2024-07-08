#include <stdio.h>
#include <stdlib.h>
void main()
{
   int head,i,n,distance,seektime = 0,a[20];
   printf("Enter initial head position\n");
   scanf("%d",&head);
   printf("Enter number of requests\n");
   scanf("%d",&n);
   printf("Enter requests\n");
   for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
   a[0]= head;
   printf("FCFS\n");
   for(i=0;i<n;i++){
    distance=abs(a[i]-a[i+1]);
    printf("Head movement from %d to %d is %d",a[i],a[i+1],distance);
    seektime+=distance;
   }
   printf("Seektime is %d",seektime);
}
