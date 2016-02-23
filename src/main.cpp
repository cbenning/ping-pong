#include <stdio.h>
#include <limits.h>
#include <string.h>
#include "server.cpp"
#include "client.cpp"

int main( int argc, char **argv )
{

    enum {MIN_MSG_LENGTH=1};
    enum {MAX_MSG_LENGTH=255};
    enum {MIN_PORT=1024};
    enum {MAX_PORT=USHRT_MAX};
    int server_flag = 0 ,client_flag = 0, port = 0, freq_seconds = 1, c = 0;
    char *target_host = NULL,*message = NULL;

    while ((c = getopt (argc, argv, "sct:p:m:")) != -1)
    switch (c)
    {
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
      case '?':
        return 1;
    }
    printf("client_flag = %d, server_flag = %d, target_host = %s, message = %s, port = %d, freq_seconds = %d\n",
          client_flag, server_flag, target_host, message, port, freq_seconds);

    //Require exactly one of the two flags
    if((client_flag && server_flag) || (!client_flag && !server_flag)) {
        printf("Please select either client or server mode (-s/-c)\n");
        exit(1);
    }

    //Require message
    if(message == NULL || strlen(message)<MIN_MSG_LENGTH || strlen(message)>MAX_MSG_LENGTH){
        printf("Please provide a message of length: %d - %d\n",MIN_MSG_LENGTH,MAX_MSG_LENGTH);
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
