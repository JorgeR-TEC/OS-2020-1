#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
int main(){
	char *path="/home/jura/Desktop/back1.txt";
	mkfifo(path, 0666);
	int f=open(path, O_WRONLY);
	write(f, "hello", strlen("hello")+1);
	close(f);

}
