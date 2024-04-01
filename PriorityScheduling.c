#include<stdio.h>
void main()
   {
    int limit,tot_wt=0,tot_tat=0,temp;
    float avg_wt,avg_tat;
    printf("Enter the number of processes :");
    scanf("%d",&limit);
    int P[limit],BT[limit],WT[limit],TAT[limit],Pri[limit];
    printf("Enter the Processes and their corresponding Burst Time & Priority\n");
    for (int i=0;i<limit;i++)
       {
        scanf("%d",&P[i]);
        scanf("%d",&BT[i]);
        scanf("%d",&Pri[i]);
       }
    
    //Sorting according to Priority
    for (int i=0;i<limit;i++)
       {
        for (int j=i+1;j<limit;j++)
           {
            if (Pri[j]<Pri[i])
               {
                //Swapping the processes according to their priority
                temp=Pri[i];
                Pri[i]=Pri[j];
                Pri[j]=temp;
                
                temp=BT[i];
                BT[i]=BT[j];
                BT[j]=temp;
                
                temp=P[i];
                P[i]=P[j];
                P[j]=temp;
               }
           }
       }
       
    //Calculating Waiting Time and Turn Around Time
    for (int i=0;i<limit;i++)
       {
        if (i==0)
           {
            WT[i]=0;
            TAT[i]=BT[i];
            tot_tat=TAT[i];
           }
        else
           {
            WT[i]=WT[i-1]+BT[i-1];
            tot_wt+=WT[i];
            
            TAT[i]=TAT[i-1]+BT[i];
            tot_tat+=TAT[i];
           }
       }
    avg_wt=tot_wt/(float)limit;
    avg_tat=tot_tat/(float)limit;
    
    //Displaying Results
    printf("Process    BT   Priority   WT   TAT\n");
    for (int i=0;i<limit;i++)
       {
        printf("    %d      %d       %d       %d    %d\n",P[i],BT[i],Pri[i],WT[i],TAT[i]);
       }
    printf("Average WT = %f\n",avg_wt);
    printf("Average TAT = %f\n",avg_tat);
   }
