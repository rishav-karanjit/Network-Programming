#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 

#define MAX 1024 

int main() 
{ 
	char buffer[MAX], msg[MAX]; 
	 
	int sock = socket(AF_INET, SOCK_DGRAM, 0);

	struct sockaddr_in servaddr={AF_INET,htons(1234),INADDR_ANY}; 
	struct sockaddr_in cliaddr;
		
	// Bind the socket with the server address 
	bind(sock, (const struct sockaddr *)&servaddr, sizeof(servaddr));
	printf("Waiting for message from client...\n");
	
	int len = sizeof(cliaddr);
	 
	while(1)
	{
		int n = recvfrom(sock, (char *)buffer, sizeof(buffer), 0, ( struct sockaddr *) &cliaddr, &len); 
		buffer[n] = '\0'; 
		printf("Client : %s", buffer); 
		
		printf("Server : ");
		fgets(msg, MAX, stdin);
		sendto(sock, (const char *)msg, strlen(msg), 0, (const struct sockaddr *) &cliaddr, len);
	}
	return 0; 
} 
