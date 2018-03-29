#include<stdio.h>
int avail[3];
struct process
{
	char name[3];
	int allocation[3];
	int max[3];
	int need[3];
	int request[3];
	int finish; 
}p[3];
int sequence[3];
int safe_check()
{
	int finished=0;
	int i,j,k=0;
	while(finished<3)
	{
		int found = 0;
		for(i=0;i<3;i++)
		{
			int c = 0;
			for(j=0;j<3;j++)
			{
				if(p[i].need[j]<=avail[j] && p[i].finish==0)
				{
					c++;
				}
			}
			if(c==3 && p[i].finish==0)
			{
				for(j=0;j<3;j++)
				{	
					avail[j]=avail[j]+p[i].need[j];
				}	
				p[i].finish=1;
				finished++;
				found = 1;
				sequence[k]=i;
				k++;
			}
		}
		if(!found) {
			return 0;
		}
	}
	return 1;
}
void resource_allocation(struct process *pr)
{
	int i,c=0;
		printf("\nNeed;:\n");
	for(i=0;i<3;i++)
	{
		printf("%d\t",pr->need[i]);
	}
	for(i=0;i<3;i++)
	{
		if(pr->request[i]<=pr->need[i])
		{
			c++;
		}
		else
		{
			break;
		}
	}
	if(c!=3)
	{
		printf("\nThe %s has exceeded its maximum claim.",pr->name);
		return;
	}
	c=0;
	for(i=0;i<3;i++)
	{
		if(pr->request[i]<=avail[i])
		{
			c++;
		}
		else
		{
			break;
		}
	}
	if(c!=3)
	{
		printf("\nResources are not available.");
		return;
	}
	for(i=0;i<3;i++)
	{
		avail[i]=avail[i]-pr->request[i];
		pr->allocation[i]=pr->allocation[i]+pr->request[i];
		pr->need[i]=pr->need[i]-pr->request[i];
	}
	printf("\nResources allocated");

	int safe=safe_check();
	if(safe==1)
	{
		printf("\nsafe state");
		printf("\nSafe sequence is-%s %s %s",p[sequence[0]].name,p[sequence[1]].name,p[sequence[2]].name);
	}
	else
	{
		printf("not safe");
		for(i=0;i<3;i++)
		{
			avail[i]=avail[i]+pr->request[i];
			pr->allocation[i]=pr->allocation[i]-pr->request[i];
			pr->need[i]=pr->need[i]+pr->request[i];
		}
	}
}
int main()
{
	int i,j;
	for(i=0;i<3;i++)
	{
		printf("Enter the name of the process- ");
		scanf("%s",p[i].name);
		printf("\nEnter the maximum requirement of resources required by the process-");
		for(j=0;j<3;j++)
		{
			scanf("%d",&p[i].max[j]);
		}
		printf("\nEnter the resources held by the process-");
		for(j=0;j<3;j++)
		{
			scanf("%d",&p[i].allocation[j]);
		}
		for(j=0;j<3;j++)
		{
			p[i].need[j]=p[i].max[j]-p[i].allocation[j];
		}
		p[i].finish=0;	
	}
	printf("Enter the resources Avaiable in system:");
	for(j=0;j<3;j++)
	{
		scanf("%d",&avail[j]);
	}
	int choice;
	for(i=0;i<3;i++)
	{
		printf("\nDoes %s request any process?0/1",p[i].name);
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter the resources requested by the process-");
				for(j=0;j<3;j++)
				{
					scanf("%d",&p[i].request[j]);
				}
				resource_allocation(&p[i]);
				break;
			case 0:
				break;				
		}
	}
	
	printf("\nMax:\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			printf("%d\t",p[i].max[j]);
		printf("\n");
	}
	printf("\nAllocation:\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			printf("%d\t",p[i].allocation[j]);
		printf("\n");
	}
	printf("\nNeed:\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			printf("%d\t",p[i].need[j]);
		printf("\n");
	}
	int safe=safe_check();
	if(safe==1)
	{
		printf("\nsafe state");
		printf("\nSafe sequence is-%s %s %s",p[sequence[0]].name,p[sequence[1]].name,p[sequence[2]].name);
	}
	else
	{
		printf("\nnot safe");
	}
}

