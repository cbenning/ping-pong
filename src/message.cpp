
#include <sstream>
//#include "message.h"

//void serialize(Message* msg, char *data)
//{
//    int n = 0;
//    data[n] = msg->index;
//    n += sizeof(msg->index);
//    data[n] = *msg->message;
//}
//
//void deserialize(char *data, Message* msg)
//{
//    int n = 0;
//    strncpy(msg->index,&data[n],sizeof(msg->index));
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
