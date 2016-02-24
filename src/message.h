

#include <sstream>
#include <stdlib.h>

#define MAXMSGSIZE 256
#define MINMSGSIZE 1
#define PACKETSIZE sizeof(Message)

typedef struct Message
{
    unsigned long index;
    char message[MAXMSGSIZE];
}Message;

