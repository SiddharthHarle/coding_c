#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void* printx(void* arg)
{
	int *n= (int*)arg;
	for(int i=0;i<10;i++)
	{

		printf("\nValue of x: %d !!! -- n=%d",i,*n);
		(*n)++;
		sleep(2);
	}

	return (void*) 9;
}

void printy()
{
	for(int i=0;i<10;i++)
	{

		printf("\nValue of y: %d",i);
	}			
	
}


int main(int argc, int** argv)
{
	pthread_t newt;
	int n=50;
	int *ch;
	pthread_create(&newt,NULL,printx,&n);
	//printx();
	printy();

	pthread_join(newt,(void*)&ch);

	printf("\n Final value of n: %d ",n);
	printf("\n Result value: %c ",*ch);
	return 0;
}