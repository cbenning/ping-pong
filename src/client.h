
class PingClient
{
    private:
        enum {BACKLOG=5};
        enum {MAX_MSG_LENGTH=265};
        char msgbuf[MAX_MSG_LENGTH];
        char *message = NULL, *target_host = NULL;
        struct sockaddr_in srv_addr;
        int  sockfd, tmpsockfd, port, n, reuseaddr, socklen, freq;

    public:
        PingClient(char* new_target_host, int new_port, char* new_message, int new_freq);
        void start();

};
