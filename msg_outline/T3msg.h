//
// Created by robin on 10/21/21.
//

#ifndef FAR_STATION_ROBIN_T3MSG_H
#define FAR_STATION_ROBIN_T3MSG_H
#include "Generalmsg.h"

class T3msg : public Generalmsg{
public:
    explicit T3msg(std::string payload);

};


#endif //FAR_STATION_ROBIN_T3MSG_H
