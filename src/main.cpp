#include <stdio.h>
#include "server.cpp"

int main( int argc, char **argv )
{

    int server_flag ,client_flag, port, freq_millis, c = 0;
    char *target_host ,*message = NULL;

    while ((c = getopt (argc, argv, "sct:p:m:f:")) != -1)
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
      case 'f':
        freq_millis = atoi(optarg);
        break;
      case '?':
        return 1;
    }
    printf("client_flag = %d, server_flag = %d, target_host = %s, message = %s, port = %d, freq_millis = %d\n",
          client_flag, server_flag, target_host, message, port, freq_millis);

    //PingServer server(4321);
    //server.start();
    return 0;
}
