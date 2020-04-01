#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <pthread.h>

void *printMessage(void *args){
	char *message=(char *)args;
	pid_t t=syscall(SYS_gettid);
	pid_t p=getpid();
	sleep(3);
	printf("Inside function: %d,%d\n", p, t);
	printf("%s\n", message);
}

int main(){
	pid_t t=syscall(SYS_gettid);
	pid_t p=getpid();
	char * a="hello";
	pthread_t tid;
	printf("Main thread: %d,%d\n", p, t);
	pthread_create(&tid, NULL, &printMessage, (void *)a);
	pthread_join(tid, NULL);
	return 0;
}