// Node A
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

void sendToPeer(char *message, char *ip, int port)
{
    int sockfd;
    struct sockaddr_in serverAddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.s_addr = inet_addr(ip);

    if (connect(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0)
    {
        perror("Error connecting");
        exit(EXIT_FAILURE);
    }

    send(sockfd, message, strlen(message), 0);
    close(sockfd);
}

int main()
{
    char *message = "Hello from Node A!";
    char *peerIP = "127.0.0.1";
    int peerPort = 8888;

    sendToPeer(message, peerIP, peerPort);

    return 0;
}
