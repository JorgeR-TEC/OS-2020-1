#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

int main(){
	char buffer[1024]={0};
	int sock=socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in addr;
	addr.sin_family=AF_INET;
	addr.sin_port=htons(90);
	addr.sin_addr.s_addr=INADDR_ANY;
	bind(sock, (struct sockaddr *)&addr, sizeof(addr));
	listen(sock, 1);
	int conn=accept(sock, NULL, NULL);
	read(conn, buffer, 1024);
	printf("%s\n", buffer);
	close(conn);
	close(sock);
}
