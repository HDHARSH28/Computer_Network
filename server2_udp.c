#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
    int serverSocket;
    char buffer[256];
    char serverMessage[] = "Hello Client";

    struct sockaddr_in serverAddress, clientAddress;
    socklen_t clientLen = sizeof(clientAddress);

    // Create UDP socket
    serverSocket = socket(AF_INET, SOCK_DGRAM, 0);

    if(serverSocket < 0)
    {
        printf("Socket creation failed\n");
        return 0;
    }

    memset(&serverAddress, 0, sizeof(serverAddress));
    memset(&clientAddress, 0, sizeof(clientAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(9000);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    if(bind(serverSocket, (struct sockaddr*)&serverAddress,
            sizeof(serverAddress)) < 0)
    {
        printf("Binding failed\n");
        return 0;
    }

    printf("Server is waiting...\n");

    // Receive message from client
    int bytesReceived = recvfrom(serverSocket,
             buffer,
             sizeof(buffer) - 1,
             0,
             (struct sockaddr*)&clientAddress,
             &clientLen);

    if(bytesReceived < 0)
    {
        printf("Receive failed\n");
        close(serverSocket);
        return 0;
    }

    buffer[bytesReceived] = '\0';

    printf("Client says: %s\n", buffer);

    // Send reply
    sendto(serverSocket,
           serverMessage,
           strlen(serverMessage),
           0,
           (struct sockaddr*)&clientAddress,
           clientLen);

    close(serverSocket);

    return 0;
}
