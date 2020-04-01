#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct message {
               long mtype;       /* message type, must be > 0 */
               char mtext[100];    /* message data */
};


int main(){
	key_t key=ftok("/home/jura/Desktop/file", 60);
	int queue=msgget(key, 0666|IPC_CREAT);
	struct message m;
	msgrcv(queue, &m, sizeof(m), 1,IPC_NOWAIT);
	printf("Recibido: %s\n", m.mtext);

}
