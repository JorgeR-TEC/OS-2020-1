#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	

	
	pid_t created=fork();
	pid_t ownPID=getpid();
	if(created==0){//the child
			printf("child is going to print the ls\n");
			char *args[]={"/bin/ls", "-la", NULL};
			execv(args[0], args);
	}else{//the parent
		sleep(20);
		wait(NULL);
		printf("My pid is %d, and my child is %d\n", ownPID, created);
	
	}
	return 0;


}