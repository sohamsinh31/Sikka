// Node B
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

void listenForMessages(int port)
{
    int sockfd, newSock;
    struct sockaddr_in serverAddr, newAddr;
    socklen_t addrSize;
    char buffer[1024];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0)
    {
        perror("Error binding");
        exit(EXIT_FAILURE);
    }

    if (listen(sockfd, 10) == 0)
    {
        printf("Listening...\n");
    }
    else
    {
        perror("Error listening");
        exit(EXIT_FAILURE);
    }

    addrSize = sizeof(newAddr);
    newSock = accept(sockfd, (struct sockaddr *)&newAddr, &addrSize);
    recv(newSock, buffer, sizeof(buffer), 0);

    printf("Received message: %s\n", buffer);
    close(newSock);
}

int main()
{
    int port = 8888;

    listenForMessages(port);

    return 0;
}
