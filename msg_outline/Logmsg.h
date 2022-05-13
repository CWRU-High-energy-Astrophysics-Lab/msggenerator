//
// Created by robin on 10/21/21.
//

#ifndef FAR_STATION_ROBIN_LOGMSG_H
#define FAR_STATION_ROBIN_LOGMSG_H
#include "Generalmsg.h"

class Logmsg : public Generalmsg{
public:
    explicit Logmsg(std::string payload);

};




#endif //FAR_STATION_ROBIN_LOGMSG_H
