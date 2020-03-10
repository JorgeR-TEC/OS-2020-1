#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
	//char *message=(char *)malloc(20);
	//char *message=(char *)mmap(NULL, 20, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	int f=open("/mnt/c/Users/L03040561/Desktop/fileExample.txt", O_RDWR| O_CREAT, 0666);
	ftruncate(f, 20);
	char *message=(char *)mmap(NULL, 20, PROT_READ | PROT_WRITE, MAP_SHARED , f, 0);
	memcpy(message, "hello", strlen("hello")+1);
	pid_t pid=fork();
	if(pid==0){//child code
		memcpy(message, "bye", strlen("bye")+1);
		printf("The child prints %s\n", message);
	}else{//parent code
		wait(NULL);
		printf("The parent prints %s\n", message);
	}
	close(f);
	
}