#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
    int clientSocket;

    char clientMessage[] = "Hello";
    char serverReply[256];

    struct sockaddr_in serverAddress;
    socklen_t addrSize = sizeof(serverAddress);

    // Create UDP socket
    clientSocket = socket(AF_INET, SOCK_DGRAM, 0);

    if(clientSocket < 0)
    {
        printf("Socket creation failed\n");
        return 0;
    }

    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(9000);
    serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Send message to server
    sendto(clientSocket,
           clientMessage,
           strlen(clientMessage),
           0,
           (struct sockaddr*)&serverAddress,
           addrSize);

    // Receive reply
    int bytesReceived = recvfrom(clientSocket,
             serverReply,
             sizeof(serverReply) - 1,
             0,
             (struct sockaddr*)&serverAddress,
             &addrSize);

    if(bytesReceived >= 0)
    {
        serverReply[bytesReceived] = '\0';
        printf("Reply from Server: %s\n", serverReply);
    }

    close(clientSocket);

    return 0;
}