/*first come first serve schedule */
/*Ngakan Putu Ariastu, 12 November 2017*/

#include <stdio.h>
#include <stdlib.h>

/* create datatype to store schedule */
typedef struct schedule {
	int arrival; //arrival time of process
	int service; //service time required (burst)
	int remain; //remaining time of service required
	int finish; //the process finish time 
	float weighted; //weighted turnaround
}schedule;

int main ()
{
	int i,j;
	schedule proc[30];
	int tot_time=0;
	int target;
	float weighted_m=0.0;;
	float m=0.0;
	
	int n_data;
	
	/* read how many data to be processed */
	printf("input n data : ");
	scanf("%d",&n_data);
	printf("\n");
	
	/* input the data */
	printf("input data arrival and service: ");
	for (i=0;i<n_data;i++)
	{
		scanf("%d %d",&proc[i].arrival,&proc[i].service);
		tot_time += proc[i].service; //get total time required
		proc[i].remain =  proc[i].service;
	}
	printf ("%d\n",tot_time);
	printf ("-----------------------------------\n");
	
	/* start FCFS scheduling */
	target = 0;
	/* do process per time until total time */
	for (i=0;i<tot_time;i++)
	{		
		/* decrease remaining time required of current target process */
		proc[target].remain--;
		
		/* if the remaining time required already 0*/
		/* change to next target based on arrival time */
		if (proc[target].remain==0)
		{	
			/*store finish time and calculate weighted turnaround */
			proc[target].finish = i+1;
			proc[target].weighted = (float)(proc[target].finish-proc[target].arrival)/(float)proc[target].service;
			
			/* change to next target based on arrival time */
			target++;
		}
	}
	
	/* print all process arrival, service, finish,turnaround and weighted turnaround*/
	printf("arrival \t service \t finish \t turnaround \t weighted \n");
	for (i=0;i<n_data;i++)
	{
		printf("%d \t %d \t %d \t %d \t %f \n",proc[i].arrival,proc[i].service,proc[i].finish,proc[i].finish-proc[i].arrival,proc[i].weighted);
		m += (float)(proc[i].finish-proc[i].arrival);
		weighted_m += proc[i].weighted;
	}
	/* print average turnaround and average weighted turnaround */
	printf("\n average turnaround time : %f", m/(float)n_data);
	printf("\n average weighted turnaround time : %f\n", weighted_m/(float)n_data);
	
	return 0;
}