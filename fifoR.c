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
	int f=open(path, O_RDONLY);
	char *buffer=(char *)malloc(20);
	read(f, buffer, 3);
	printf("Contenido: %s\n", buffer);
	close(f);

}
