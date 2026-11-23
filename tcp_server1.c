#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h> // for close()

int main()
{
    int sockfd, newsockfd, clilen, n;
    char buf[100], rev[100];
    struct sockaddr_in serv_addr, cli_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(6034);

    bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    listen(sockfd, 5);

    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t *)&clilen);

    n = recv(newsockfd, buf, sizeof(buf) - 1, 0);
    if (n > 0) {
        buf[n] = '\0';

        // Reverse the received string
        int len = strlen(buf);
        for (int i = 0; i < len; i++) {
            rev[i] = buf[len - i - 1];
        }
        rev[len] = '\0';

        send(newsockfd, rev, strlen(rev), 0);
    }

    close(newsockfd);
    close(sockfd);
    return 0;
}