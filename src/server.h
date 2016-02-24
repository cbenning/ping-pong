
class PingServer
{
    private:
        enum {BACKLOG=5};
        //enum {MAXMSGSIZE=256};
        char msgbuf[MAXMSGSIZE];
        char* message = NULL;
        Message *outmsg, *inmsg;
        //char data[PACKETSIZE];
        char *data;
        struct sockaddr_in srv_addr, cli_addr;
        int  sockfd, tmpsockfd, port, n, reuseaddr, socklen;

    public:
        PingServer(int newPort, char* newMessage);
        void start();

};
