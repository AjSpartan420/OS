#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

sem_t diningroom;
sem_t chopstick[5];

void * coustmer(void *);
void eat(int);
int main()
{
	int i,a[5];
	pthread_t tid[5];
	
	sem_init(&diningroom,0,4);
	
	for(i=0;i<5;i++)
		sem_init(&chopstick[i],0,1);
		
	for(i=0;i<5;i++){
		a[i]=i;
		pthread_create(&tid[i],NULL,coustmer,(void *)&a[i]);
	}
	for(i=0;i<5;i++)
		pthread_join(tid[i],NULL);
}

void * coustmer(void * num)
{
	int c=*(int *)num;

	sem_wait(&diningroom);
	printf("\ncoustmer %d has entered room",c);
	sem_wait(&chopstick[c]);
	sem_wait(&chopstick[(c+1)%5]);

	eat(c);
	sleep(2);
	printf("\ncoustmer %d has finished eating",c);

	sem_post(&chopstick[(c+1)%5]);
	sem_post(&chopstick[c]);
	sem_post(&diningroom);
}

void eat(int c)
{
	printf("\ncoustmer %d is eating",c);
}
