#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
int main() {
    char sendline[] = "hey there!";
    int sockfd;
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in cliaddr;
    bzero(&cliaddr, sizeof(cliaddr));
    int broadcastPermission = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, &broadcastPermission, sizeof(broadcastPermission));
    cliaddr.sin_family = AF_INET;
    cliaddr.sin_addr.s_addr = inet_addr("172.16.95.255");
    cliaddr.sin_port = htons(22060);
    int clen = sizeof(cliaddr);
    sendto(sockfd, sendline, sizeof(sendline), 0, (struct sockaddr*) &cliaddr, clen);
    printf("Broadcast Successful");
    close(sockfd);
} 