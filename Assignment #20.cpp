/*Ezigbo Ugochukwu 11/9/2020 Assignment #20 Simulate throwing a dart*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(void)
{
	/*declare variables*/
	int N, M, k;
	double pi_estimate, x, y;
	
	/*before the loop, only once*/
	srand((unsigned)time(NULL));
	
	/*get input values*/
	printf("Enter the total number of darts: ");
	scanf("%d", &N);
	
	/*error checking*/
	while(1)
	{
		if(N<=500)
		{
			printf("Error> N must be greater than 500. \n");
			printf("Enter the total number of darts again: ");
			scanf("%d", &N);
		}
		else
			break;
	}
	
	/*Simulate*/
	M=0;
	k=0;
	while(k<N)
	{
		x = (rand()/32767.0) - 0.5;
		y = (rand()/32767.0) - 0.5;
		k++;
		if((pow(x,2)+pow(y,2))<=0.25)
		M++;
	}
	
	/*Compute*/
	pi_estimate = (4.0*M)/N;
	
	/*Display*/
	printf("An estimate for pi is %f with %d darts thrown in this Monte Carlo experiment. \n", pi_estimate, N);
	
	return 0;
}

/*Enter the total number of darts: 500
Error> N must be greater than 500.
Enter the total number of darts again: 501
An estimate for pi is 3.105788 with 501 darts thrown in this Monte Carlo experiment.
Enter the total number of darts: 32767
An estimate for pi is 3.148167 with 32767 darts thrown in this Monte Carlo experiment.*/
