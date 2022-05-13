//
// Created by robin on 10/21/21.
//

#ifndef FAR_STATION_ROBIN_T2MSG_H
#define FAR_STATION_ROBIN_T2MSG_H
#include "Generalmsg.h"

class T2msg : public Generalmsg{
public:
    explicit T2msg(std::string payload);


};


#endif //FAR_STATION_ROBIN_T2MSG_H
