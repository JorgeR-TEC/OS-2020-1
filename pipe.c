#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
	int f[2];
	pipe(f);
	pid_t pid=fork();
	if(pid==0){//child code
		close(f[0]);
		write(f[1], "hello world", strlen("hello world")+1);
		close(f[1]);
	}else{//parent code
		close(f[1]);
		wait(NULL);
		char *buffer=(char *)malloc(20);
		read(f[0], buffer, 20);
		printf("The message received is %s\n", buffer);
		close(f[0]);
	}
	return 0;
}