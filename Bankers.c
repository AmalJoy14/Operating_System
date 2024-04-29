#include <stdio.h>
#include <stdlib.h>

void main() {
	int n_pro, n_res, i, j, pro_count = 0, flag = 0, exec_count = 0;
	printf("Enter the number of processes: ");
	scanf("%d", &n_pro);
	int visited[n_pro];
	int seq[n_pro];
	printf("Enter the number of resources: ");
	scanf("%d", &n_res);
	int allocation[n_pro][n_res], max_need[n_pro][n_res], available[n_res], need[n_pro][n_res];
	printf("Enter the available instances of resources: ");
	for(i = 0; i < n_res; i++)
		scanf("%d", &available[i]);
		
	for(i = 0; i < n_pro; i++) {
		visited[i] = 0;
		printf("Enter the max need for process P%d: ", i);
		for(j = 0; j < n_res; j++)
			scanf("%d", &max_need[i][j]);
		printf("Enter the allocation for process P%d: ", i);
		for(j = 0; j < n_res; j++)
			scanf("%d", &allocation[i][j]);
		for(j = 0; j < n_res; j++)
			need[i][j] = max_need[i][j] - allocation[i][j];
	}
	printf("\nAllocation\tMax\tNeed\n");
	for(i = 0; i < n_pro; i++) {
		for(j = 0; j < n_res; j++)
			printf("%d ", allocation[i][j]);
		printf("\t\t");
		for(j = 0; j < n_res; j++)
			printf("%d ", max_need[i][j]);
		printf("\t");
		for(j = 0; j < n_res; j++)
			printf("%d ", need[i][j]);
		printf("\n");
	}
	while(pro_count < n_pro) {
		flag = 0;
		for(i = 0; i < n_pro; i++) {
			exec_count = 0;
			for(j = 0; j < n_res; j++) {
				if(need[i][j] <= available[j])
					exec_count++;
			}
			if(exec_count == n_res && visited[i] == 0) {
				for(j = 0; j < n_res; j++)
					available[j] += allocation[i][j];
				flag = 1;
				visited[i] = 1;
				pro_count++;
				seq[pro_count - 1] = i;
			}
		}
		if(flag == 0) {
			printf("No safe sequence!!");
			exit(0);
		}
	}
	printf("\nSafe Sequence:\n");
	printf("<");
	for(i = 0; i < n_pro; i++)
		printf("P%d ", seq[i]);
	printf(">\n");

}


