#include <stdio.h>
#include <stdlib.h>

void main()
{
    int n_pro, n_res,done = 0, flag = 0, condition_satisfied;

    printf("Enter the number of processes: ");
    scanf("%d", &n_pro);
    printf("Enter the number of resources: ");
    scanf("%d", &n_res);
    
    int allocation[n_pro][n_res], max_need[n_pro][n_res], available[n_res], need[n_pro][n_res],visited[n_pro],seq[n_pro];

    printf("Enter the max need for processes:");
    for (int i = 0; i < n_pro; i++)
    {  
        visited[i] = 0;
        for (int j = 0; j < n_res; j++)
        {
            scanf("%d", &max_need[i][j]);
        }
    }

    printf("Enter the allocation for processes:");
    for (int i = 0; i < n_pro; i++)
    {  
        for (int j = 0; j < n_res; j++)
        {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("Enter the available resources: ");
    for (int i = 0; i < n_res; i++)
        scanf("%d", &available[i]);

    //Calculating need matrix
    for (int i = 0; i < n_pro; i++)
    {    
        for (int j = 0; j < n_res; j++)
            need[i][j] = max_need[i][j] - allocation[i][j];
    }
        
    //Display
    printf("\nMax\tAllocation\tNeed\n");
    for (int i = 0; i < n_pro; i++)
    {   
        for (int j = 0; j < n_res; j++)
            printf("%d ", max_need[i][j]);
        printf("\t");

        for (int j = 0; j < n_res; j++)
            printf("%d ", allocation[i][j]);
        printf("\t\t");
        
        for (int j = 0; j < n_res; j++)
            printf("%d ", need[i][j]);
        printf("\n");
    }
    while (done < n_pro)
    {
        flag = 0;
        for (int i = 0; i < n_pro; i++)
        {   
            //condition check
            condition_satisfied = 1;
            for (int j = 0; j < n_res; j++)
            {
                if (need[i][j] > available[j])
                    condition_satisfied=0;
            }
            
            if (condition_satisfied == 1 && visited[i] == 0)
            {
                for (int j = 0; j < n_res; j++)
                    available[j] += allocation[i][j];
                flag = 1;
                visited[i] = 1;
                seq[done] = i;
                done++;
            }
        }
        if (flag == 0)
        {
            printf("No safe sequence!!");
            exit(0);
        }
    }
    printf("\nSafe Sequence:\n");
    printf("<");
    for (int i = 0; i < n_pro; i++)
        printf("P%d ", seq[i]);
    printf(">\n");
}
