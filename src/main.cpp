#include <stdio.h>
#include <limits.h>
#include <string.h>
#include "server.cpp"
#include "client.cpp"

#ifndef MESSAGE_H
#define MESSAGE_H
#include "message.h"
#endif

using namespace std;

#define MIN_PORT 1024
#define MAX_PORT USHRT_MAX

int main( int argc, char **argv )
{
    int server_flag = 0 ,client_flag = 0, port = 0, freq_seconds = 1, c = 0;
    char *target_host = NULL,*message = NULL;

    const char *help_str =
        "Ping-Pong commndline tool. Usage: \n"
        "\t-s server mode\n"
        "\t-c client mode\n"
        "\t-t <target host> (client mode only)\n"
        "\t-p <port> (between 1024 and 65535)\n"
        "\t-m <message> (between 1 and 255 chars in length)\n"
        "\t-h display this help message\n";

    while ((c = getopt (argc, argv, "scht:p:m:")) != -1)
    switch (c) {
      case 's':
        server_flag = 1;
        break;
      case 'c':
        client_flag = 1;
        break;
      case 't':
        target_host = optarg;
        break;
      case 'm':
        message = optarg;
        break;
      case 'p':
        port = atoi(optarg);
        break;
      case 'h':
        cout << help_str;
      case '?':
        return 1;
    }
    //Debug for cmdline input
    //printf("client_flag = %d, server_flag = %d, target_host = %s, message = %s, port = %d, freq_seconds = %d\n",
    //      client_flag, server_flag, target_host, message, port, freq_seconds);

    //Require exactly one of the two flags
    if((client_flag && server_flag) || (!client_flag && !server_flag)) {
        printf("Please select either client or server mode (-s/-c)\n");
        exit(1);
    }

    //Require message
    if(message == NULL || strlen(message)<MINMSGSIZE|| strlen(message)>MAXMSGSIZE){
        printf("Please provide a message of length: %d - %d\n",MINMSGSIZE,MAXMSGSIZE);
        exit(1);
    }

    //Require port
    if(port < MIN_PORT || port > MAX_PORT) {
        printf("Please provide a port in the range of: %d - %d\n",MIN_PORT,MAX_PORT);
        exit(1);
    }

    //Server mode
    if(server_flag){
        if(target_host != NULL ){
            printf("-t option is meaningless in server mode\n");
            exit(1);
        }
        PingServer server(port,message);
        server.start();
    }

    //Client mode
    if(client_flag){
        //TODO - Validate the hostip
        if(target_host == NULL ){
            printf("Please provide a remote host\n");
            exit(1);
        }
        PingClient client(target_host,port,message,freq_seconds);
        client.start();
    }

    return 0;
}
