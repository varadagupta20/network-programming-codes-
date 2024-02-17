#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
int main() {
    char recvline[1024];
    bzero(recvline, 1024);
    int sockfd;
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in servaddr, cliaddr;
    bzero(&servaddr, sizeof(servaddr));
    bzero(&cliaddr, sizeof(cliaddr));
    int slen = sizeof(servaddr);
    cliaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    cliaddr.sin_family = AF_INET;
    cliaddr.sin_port = htons(22060);
    bind(sockfd, (struct sockaddr*) &cliaddr, sizeof(cliaddr));
    recvfrom(sockfd, recvline, 1024, 0, (struct sockaddr*) &servaddr, &slen);
    printf("%s", recvline);
    close(sockfd);
}