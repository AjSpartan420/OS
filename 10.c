#include<stdio.h>
void main()
{
	int blocksize[10], processessize[10], b, p, f[10], allocation[10], i, j;
	for(i = 0; i < 10; i++)
	{
		f[i] = 0;
		allocation[i] = -1;
	}
	printf("Enter no. of blocks: ");
	scanf("%d", &b);
	printf("\nEnter size of each block: ");
	for(i = 0; i < b; i++)
		scanf("%d", &blocksize[i]);
	printf("\nEnter no. of processes: ");
	scanf("%d", &p);
	printf("\nEnter size of each process: ");
	for(i = 0; i < p; i++)
		scanf("%d", &processessize[i]);
	for(i = 0; i < p; i++)        
		for(j = 0; j < b; j++)
			if(f[j] == 0 && blocksize[j] >= processessize[i])
			{
				allocation[j] = i;
				f[j] = 1;
				break;
			}
	printf("\nBlock no.\tsize\t\tprocess no.\t\tsize");
	for(i = 0; i < b; i++)
	{
		printf("\n%d\t\t%d\t\t", i+1, blocksize[i]);
		if(f[i] == 1)
			printf("%d\t\t\t%d",allocation[i]+1,processessize[allocation[i]]);
		else
			printf("Not allocated");
	}
}

