#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>
#define BUFFER_SIZE 3
int *buffer;
int counter=0;
sem_t sem, empty, full;

void printArray(){
	int i=0;
	for(i=0; i<BUFFER_SIZE; i++){
		printf("%d,", buffer[i]);
	}
	printf("\n");
}
empty=2
sem=1
full=1
void *producer(){
	int i=0;
	int in=0;
	while(i<10){
		sem_wait(&empty);
		sem_wait(&sem);
		printf("Producer entering critical section\n");
		buffer[in]=i+1;
		in=(in+1)%BUFFER_SIZE;
		counter++;
		printf("Producer Buffer: ");
		printArray();
		printf("Producer leaving the critical section\n");
		sem_post(&sem);
		sem_post(&full);
		i++;
	}
}

void *consumer(){
	int i=0;
	int out=0;
	while(i<10){
		
		sem_wait(&full);
		sem_wait(&sem);
		printf("Consumer entering critical section\n");
		buffer[out]=0;
		out=(out+1)%BUFFER_SIZE;
		counter--;
		printf("Consumer Buffer: ");
		printArray();
		printf("Consumer leaving the critical section\n");
		sem_post(&sem);
		sem_post(&empty);
		i++;
	}
}

int main(){
	sem_init(&sem, 0, 1);//sem is the semaphore variable, 0 is only share between threads, and 1 is the number of available resources
	sem_init(&empty, 0, BUFFER_SIZE);
	sem_init(&full, 0, 0);
	buffer=(int *)malloc(BUFFER_SIZE*4);
	pthread_t prod, con;
	pthread_create(&prod, NULL, producer, NULL);
	pthread_create(&con, NULL, consumer, NULL);
	pthread_join(prod, NULL);
	pthread_join(con, NULL);
	sem_destroy(&sem);
	
	
	return 0;
}