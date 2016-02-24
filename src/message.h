

#include <sstream>
#include <stdlib.h>

#define MAXMSGSIZE 256
#define PACKETSIZE sizeof(Message)

typedef struct Message
{
    unsigned long index;
    char message[MAXMSGSIZE];
}Message;



//void serialize(Message* msg, char *data)
//{
//    int n = 0;
//
//    //strncpy(&data[n],(char*)msg->index,sizeof(msg->index));
//    sprintf(&data[n],"%u",
//    //data[n] = msg->index;
//    n += sizeof(msg->index);
//    strncpy(&data[n],msg->message,sizeof(msg->message));
//    //data[n] = *msg->message;
//}
//
//void deserialize(char *data, Message* msg)
//{
//    int n = 0;
//    //unsigned long strtoul(const char *restrict str,
//    //   char **restrict endptr, int base);
//    msg->index = stroul(&data[n],&data[n+sizeof(msg->index)],10);
//    //strncpy((char*)msg->index,&data[n],sizeof(msg->index));
//    //msg->index = data[n];
//    n += sizeof(msg->index);
//    strncpy(msg->message,&data[n],sizeof(msg->message));
//    //msg->message = &data[n];
//}



//void serialize(Message* msg, char* data) {
//    std::stringstream os;
//    os << msg->index << msg->message;
//}
//
//void deserialize(char* data, Message* msg) {
//    std::stringstream is(data);
//    is >> msg->index >> msg->message;
//}
