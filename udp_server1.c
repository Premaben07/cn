#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    int sockfd;
    char buf[100], buf1[100];
    struct sockaddr_in sa, ca;
    socklen_t length;
    int n;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = INADDR_ANY;
    sa.sin_port = htons(6025);
    printf("enter the number of messages to exchange:");
    scanf("%d",&n);
    for(int i=0; i<n;i++){
    bind(sockfd, (struct sockaddr*)&sa, sizeof(sa));

    length = sizeof(ca);
    
    int k = recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr*)&ca, &length);
    buf[k] = '\0';
    printf("Received: %s\n", buf);

    printf("Enter a message: ");
    fgets(buf1, sizeof(buf1), stdin);
    buf1[strcspn(buf1, "\n")] = '\0';

    sendto(sockfd, buf1, strlen(buf1), 0, (struct sockaddr*)&ca, length);

    close(sockfd);
    }
    return 0;
}