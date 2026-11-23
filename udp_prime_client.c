    #include<stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <arpa/inet.h>
    #include <unistd.h>
    
    int main() {
        int sockfd;
        struct sockaddr_in servaddr;
        char buffer[1024];
        socklen_t len;
    
        sockfd = socket(AF_INET, SOCK_DGRAM, 0);
        servaddr.sin_family = AF_INET;
        servaddr.sin_port = htons(12345);
        servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    
        printf("Enter a number: ");
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = 0;
    
        sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr*)&servaddr, sizeof(servaddr));
        len = sizeof(servaddr);
        int n = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&servaddr, &len);
        buffer[n] = '\0';
        printf("Next prime number is: %s\n", buffer);
    
        close(sockfd);
        return 0;
    }
