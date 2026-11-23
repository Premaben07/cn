#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

int is_prime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0) return 0;
    return 1;
}

int next_prime(int n) {
    int candidate = n + 1;
    while (!is_prime(candidate)) candidate++;
    return candidate;
}

int main() {
    int sockfd;
    struct sockaddr_in servaddr, cliaddr;
    char buffer[1024];
    socklen_t len;
    int num, prime;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(12345);

    bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
    printf("UDP server listening on port 12345...\n");

    while (1) {
        len = sizeof(cliaddr);
        int n = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&cliaddr, &len);
        buffer[n] = '\0';
        num = atoi(buffer);
        prime = next_prime(num);
        printf("Received %d, next prime is %d\n", num, prime);
        sprintf(buffer, "%d", prime);
        sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr*)&cliaddr, len);
    }
    close(sockfd);
    return 0;
}