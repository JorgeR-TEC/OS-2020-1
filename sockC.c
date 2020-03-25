#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
int main(){
	char buffer[1024]="GET / HTTP/1.1\r\n\r\n";
	int sock=socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in addr;
	addr.sin_family=AF_INET;
	addr.sin_port=htons(90);
	inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr);
	int connection=connect(sock, (struct sockaddr *)&addr, sizeof(addr));
	send(sock, buffer, strlen(buffer),0);
	read(sock, buffer, 1024);
	printf("%s\n", buffer);
	close(sock);
}