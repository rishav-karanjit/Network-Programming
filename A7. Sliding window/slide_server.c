#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h> 
#include<arpa/inet.h> 

#define MAX 20

int main() 
{ 
	int sersock = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in addr = { AF_INET, htons(1234), inet_addr("127.0.0.1") };

	// Forcefully connecting to same port everytime
	int reuse = 1;
	setsockopt(sersock, SOL_SOCKET, SO_REUSEADDR, (char *)&reuse, sizeof(reuse));

	bind(sersock, (struct sockaddr *) &addr, sizeof(addr));
	printf("\nServer is Online\n");

	listen(sersock, 5);
	int sock = accept(sersock, NULL, NULL);

	char frame[MAX];
	char res[MAX]; // to store all bytes that are recieved successfully
	int ack;
	int k=0;	   // iterator for res
	srand(time(NULL));
	
	while(1) 
	{ 
		int recvsize = 5;
		memset(frame, 0, MAX); // re-initialise frame buffer with 0

		recv(sock, frame, recvsize, 0);  // recv(socket, buffer, length, flag)
		if(strcmp(frame, "Exit") == 0) break; // at end exit frame is recieved 

		if(strlen(frame) < recvsize) 
		{
			recvsize = strlen(frame);
		}
		
		int err_idx = rand()%8; // probability of byte to get corrupted = 50%
		if(err_idx < recvsize)
		{
			recvsize = err_idx;
			frame[err_idx]='x';
			printf("\nError occured at = %d", err_idx+1);
		}

		int j;
		for(j=0; j<recvsize ; j++)
		{
			res[k++] = frame[j];
		}
		printf("\nPacket received  = %s", frame);
		printf("\nReceiving window: ");
		printf("\n start seqno = %d", k-recvsize);
		printf("\n end seqno   = %d", k-1);

		ack = k ;
		printf("\nSending ack = %d", ack);
		send(sock, &ack, sizeof(ack), 0) ;  
		printf("\n");
	}

	res[k] = '\0';
	printf("\n\nFinal string recieved at Destination = ");
	fputs(res, stdout);

	printf("\n\n");
	close(sock); close(sersock);
}
