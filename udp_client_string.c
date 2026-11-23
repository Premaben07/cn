// udp_client_reverse.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_addr;
    socklen_t len = sizeof(server_addr);

    
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY; // or use inet_addr("127.0.0.1")

    
    printf("Enter a string to send to the server: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    buffer[strcspn(buffer, "\n")] = '\0'; // remove newline

    
    sendto(sockfd, buffer, strlen(buffer), 0,
           (const struct sockaddr *)&server_addr, len);

    
    int n = recvfrom(sockfd, buffer, BUFFER_SIZE, 0,
                     (struct sockaddr *)&server_addr, &len);
    buffer[n] = '\0';

    printf("Reversed string from server: %s\n", buffer);

    close(sockfd);
    return 0;
}
