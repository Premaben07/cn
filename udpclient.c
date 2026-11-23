#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

int main() {
    int sockfd;
    char buf[100], buf1[100];
    struct sockaddr_in sa;
    socklen_t length;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = inet_addr("127.0.0.1");
    sa.sin_port = htons(6025);

    printf("Enter a message: ");
    fgets(buf, sizeof(buf), stdin);
    buf[strcspn(buf, "\n")] = '\0'; // remove newline

    sendto(sockfd, buf, strlen(buf), 0, (struct sockaddr *)&sa, sizeof(sa));

    length = sizeof(sa);
    int k = recvfrom(sockfd, buf1, sizeof(buf1), 0, (struct sockaddr *)&sa, &length);
    buf1[k] = '\0';
    printf("Received: %s\n", buf1);

    close(sockfd);
    return 0;
}