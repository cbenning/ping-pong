
class PingServer
{
    private:
        enum {BACKLOG=5};
        enum {MAXMSGSIZE=265};
        char msgbuf[MAXMSGSIZE];
        struct sockaddr_in srv_addr, cli_addr;
        int  sockfd, tmpsockfd, port, n, reuseaddr, socklen;

    public:
        PingServer(int newPort);
        void start();

};
