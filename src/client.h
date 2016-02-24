
class PingClient
{
    private:
        enum {BACKLOG=5};
        char msgbuf[MAXMSGSIZE];
        char *message = NULL, *target_host = NULL;
        //char data[PACKETSIZE];
        char *data;
        Message *outmsg, *inmsg;
        struct sockaddr_in srv_addr;
        int  sockfd, tmpsockfd, port, n, reuseaddr, socklen, freq;
        unsigned long index;

    public:
        PingClient(char* new_target_host, int new_port, char* new_message, int new_freq);
        void start();

};
