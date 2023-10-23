#include "core.h"

void startNode(const char *ip, int port)
{
    int sockfd, newsockfd, clilen;
    struct sockaddr_in serv_addr, cli_addr;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("ERROR opening socket");
        exit(1);
    }

    // Initialize server address structure
    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr.s_addr = inet_addr(ip);

    // Bind socket to address
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("ERROR on binding");
        exit(1);
    }

    // Listen for incoming connections
    listen(sockfd, 5);

    clilen = sizeof(cli_addr);

    // Accept incoming connections
    while (1)
    {
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
        if (newsockfd < 0)
        {
            perror("ERROR on accept");
            exit(1);
        }

        // Handle incoming connection (implement logic to receive and process blockchain data)
        // You'll need to add the necessary logic here

        close(newsockfd);
    }

    close(sockfd);
}

void connectToPeer(const char *peerIP, int peerPort)
{
    int sockfd;
    struct sockaddr_in serv_addr;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("ERROR opening socket");
        exit(1);
    }

    // Initialize server address structure
    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(peerPort);
    serv_addr.sin_addr.s_addr = inet_addr(peerIP);

    // Connect to peer
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("ERROR connecting");
        exit(1);
    }

    // Handle connection to peer (implement logic to send and receive blockchain data)
    // You'll need to add the necessary logic here

    close(sockfd);
}
