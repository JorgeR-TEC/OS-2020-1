#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#define BUFFER_SIZE 3
#define A 0
#define B 1
int *buffer;
int counter=0;
int ready[2]={0,0};
int turn=0;


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
		printf("Producer entering critical section\n");
		buffer[in]=i+1;
		in=(in+1)%BUFFER_SIZE;
		counter++;
		printf("Producer Buffer: ");
		printArray();
		printf("Producer leaving the critical section\n");
		i++;
	}
}

void *consumer(){
	int i=0;
	int out=0;
	while(i<10){
		
		while(counter==0);
		printf("Consumer entering critical section\n");
		buffer[out]=0;
		out=(out+1)%BUFFER_SIZE;
		counter--;
		printf("Consumer Buffer: ");
		printArray();
		printf("Consumer leaving the critical section\n");
		i++;
	}
}

int main(){
	buffer=(int *)malloc(BUFFER_SIZE*4);
	pthread_t prod, con;
	pthread_create(&prod, NULL, producer, NULL);
	pthread_create(&con, NULL, consumer, NULL);
	pthread_join(prod, NULL);
	pthread_join(con, NULL);
	
	
	return 0;
}