
#include<arpa/inet.h>
#include<sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include "server.h"


PingServer::PingServer( int newPort ) {
    port = newPort;
}

void PingServer::start(void) {

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
      perror("Failed to open socket");
      exit(1);
    }

    srv_addr.sin_family = AF_INET;
    srv_addr.sin_addr.s_addr = INADDR_ANY;
    srv_addr.sin_port = htons(port);

    //TODO
    reuseaddr = 1;
    if (setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&reuseaddr,sizeof(reuseaddr))==-1) {
        perror("Failed to set socket options");
        exit(1);
    }

    //Get the addr size
    socklen = sizeof(struct sockaddr_in);

    int bind_res = bind(sockfd, (struct sockaddr *)&srv_addr, (socklen_t)socklen);
    if(bind_res < 0) {
        perror("Failed to bind");
        exit(1);
    }

    listen(sockfd,BACKLOG);

    while(1) {

        tmpsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t*)&socklen);
        if (tmpsockfd < 0) {
            perror("Failed to accept connection");
            exit(1);
        }

        n = read(tmpsockfd,msgbuf,MAXMSGSIZE);

        if( n < 0 ) {
            perror("Failed to read from socket");
            exit(1); //TODO - cleanup 
        }


        snprintf(msgbuf,n,"%s",msgbuf);
        n = write(tmpsockfd,msgbuf,n);

        close(tmpsockfd);


       // pid = fork();

       // if(pid == 0){
       //     handle(tmpsockfd);
       //     exit(0);
       // }
       // if(pid < 0){
       //     perror("Failed to fork");
       //     exit(1);
       // }

    }

}

