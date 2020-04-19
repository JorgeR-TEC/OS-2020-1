#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#define BUFFER_SIZE 3

int *buffer;
int counter=0;

pthread_spinlock_t lock;


void printArray(){
	int i=0;
	for(i=0; i<BUFFER_SIZE; i++){
		printf("%d,", buffer[i]);
	}
	printf("\n");
}

void *producer(){
	int i=0;
	int in=0;
	while(i<10){
		
		while(counter==BUFFER_SIZE);
		pthread_spin_lock(&lock);
		printf("Producer entering critical section\n");
		buffer[in]=i+1;
		in=(in+1)%BUFFER_SIZE;
		counter++;
		printf("Producer Buffer: ");
		printArray();
		printf("Producer leaving the critical section\n");
		pthread_spin_unlock(&lock);
		i++;
	}
}

void *consumer(){
	int i=0;
	int out=0;
	while(i<10){
		
		while(counter==0);
		pthread_spin_lock(&lock); 
		printf("Consumer entering critical section\n");
		buffer[out]=0;
		out=(out+1)%BUFFER_SIZE;
		counter--;
		printf("Consumer Buffer: ");
		printArray();
		printf("Consumer leaving the critical section\n");
		pthread_spin_unlock(&lock); 
		i++;
	}
}

int main(){
	pthread_spin_init(&lock, PTHREAD_PROCESS_PRIVATE);
	buffer=(int *)malloc(BUFFER_SIZE*4);
	pthread_t prod, con;
	pthread_create(&prod, NULL, producer, NULL);
	pthread_create(&con, NULL, consumer, NULL);
	pthread_join(prod, NULL);
	pthread_join(con, NULL);
	pthread_spin_destroy(&lock);
	
	return 0;
}