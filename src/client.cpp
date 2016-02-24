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

#include "client.h"

using namespace std;

PingClient::PingClient( char* new_target_host, int new_port, char* new_message, int new_freq) {
    target_host = new_target_host;
    port = new_port;
    message = new_message;
    freq = new_freq;
}

void PingClient::start(void) {

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
      perror("Failed to open socket");
      exit(1);
    }

    srv_addr.sin_family = AF_INET;
    srv_addr.sin_addr.s_addr = inet_addr(target_host);
    srv_addr.sin_port = htons(port);

    //Set socket as reusable
    reuseaddr = 1;
    if(setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&reuseaddr,sizeof(reuseaddr))==-1) {
        perror("Failed to set socket options");
        exit(1);
    }

    //Get the addr size
    socklen = sizeof(struct sockaddr_in);

    if(connect(sockfd,(struct sockaddr *)&srv_addr, socklen) < 0) {
        perror("Failed to connect to remote host");
        exit(1);
    }

    index = 0;
    outmsg = new Message;

    data = (char*)malloc(PACKETSIZE);

    while(1) {

        //Prep outgoing
        outmsg->index = index;
        strncpy(outmsg->message,message,MAXMSGSIZE);

        //Write
        data = (char*)outmsg;
        n = send(sockfd, data, PACKETSIZE, 0);
        if(n<0){
            perror("Failed to send data to remote host");
            exit(1);
        }

        //Read
        n = recv(sockfd,data,PACKETSIZE, 0);
        if(n<0) {
            perror("Failed to send data to remote host");
            exit(1);
        }

        //Display
        inmsg = (Message*)data;
        cout << inmsg->index << ":" << inmsg->message << "\n";

        //Increment and sleep
        index++;
        sleep(freq);
    }
}
