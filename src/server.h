
class PingServer
{
    private:
        enum {BACKLOG=5};
        enum {MAX_MSG_LENGTH=265};
        char msgbuf[MAX_MSG_LENGTH];
        char* message;
        struct sockaddr_in srv_addr, cli_addr;
        int  sockfd, tmpsockfd, port, n, reuseaddr, socklen;

    public:
        PingServer(int newPort, char* newMessage);
        void start();

};
