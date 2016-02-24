#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <unistd.h>

#ifndef MESSAGE_H
#define MESSAGE_H 
#include "message.h"
#endif

#include "server.h"

using namespace std;

/**
 * Constructor
 */
PingServer::PingServer( int new_port, char* new_message ) {
    port = new_port;
    message = new_message;
}

/**
 * Start the server - Blocking
 */
void PingServer::start(void) {

    //Configure socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
      perror("Failed to open socket");
      exit(1);
    }
    srv_addr.sin_family = AF_INET;
    srv_addr.sin_addr.s_addr = INADDR_ANY;
    srv_addr.sin_port = htons(port);

    //Set socket as reusable
    reuseaddr = 1;
    if (setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&reuseaddr,sizeof(reuseaddr))==-1) {
        perror("Failed to set socket options");
        exit(1);
    }

    //Get the addr size
    socklen = sizeof(struct sockaddr_in);

    //Bind to socket
    int bind_res = bind(sockfd, (struct sockaddr *)&srv_addr, (socklen_t)socklen);
    if(bind_res < 0) {
        perror("Failed to bind");
        exit(1);
    }
    listen(sockfd,BACKLOG);

    //Block for client connection
    tmpsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t*)&socklen);
    if (tmpsockfd < 0) {
        perror("Failed to accept connection");
        exit(1);
    }

    //Prep buffer space
    outmsg = new Message;
    data = (char*)malloc(PACKETSIZE);

    while(1) {

        //Read
        n = read(tmpsockfd,data,PACKETSIZE);
        if( n < 0 ) {
            perror("Failed to read from socket");
            exit(1); //TODO - cleanup 
        }

        //Display
        inmsg = (Message*)data;
        cout << inmsg->index << ":" << inmsg->message << "\n";

        //Prep outgoing
        outmsg->index = inmsg->index;
        strncpy(outmsg->message,message,MAXMSGSIZE);

        //Write
        data = (char*)outmsg;
        n = write(tmpsockfd,data,PACKETSIZE);

    }
}

