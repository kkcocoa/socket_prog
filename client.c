#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>


#define Port 9527

void sys_err(const char *str){
    perror(str);
    exit(1);
}

int main(int argc, char* argv[]){
    int cfd;
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(Port);
    inet_pton(AF_INET, "127.0.0.1", 
            &serv_addr.sin_addr.s_addr);

    cfd = socket(AF_INET, SOCK_STREAM, 0);

    connect(cfd, (struct sockaddr*) &serv_addr, 
            sizeof(serv_addr));
    int cnt = 2;
    int buff[1024];
    while (cnt --){
        write(cfd, "hello", 5);
        int ret = read(cfd, buff, sizeof(buff));
        write(STDOUT_FILENO, buff, ret);
    }
    close(cfd);

    return 0;
}   