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
	
	// Creating socket file descriptor 
	int sock = socket(AF_INET, SOCK_DGRAM, 0);

	// Filling server information 
	struct sockaddr_in servaddr={AF_INET,htons(1234),INADDR_ANY}; 
	
	while(1)
	{
		printf("Client : ");
		fgets(msg, MAX, stdin); 
		sendto(sock, (const char *)msg, strlen(msg), 0, (const struct sockaddr *) &servaddr, sizeof(servaddr));
			
		int n = recvfrom(sock, (char *)buffer, sizeof(buffer), 0, NULL, NULL); 
		buffer[n] = '\0'; 
		printf("Server : %s", buffer); 
	}
	return 0; 
}
