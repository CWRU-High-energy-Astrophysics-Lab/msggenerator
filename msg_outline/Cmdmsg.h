//
// Created by robin on 10/22/21.
//
#include "Generalmsg.h"

#ifndef FAR_STATION_ROBIN_CMDMSG_H
#define FAR_STATION_ROBIN_CMDMSG_H


class Cmdmsg : public Generalmsg{
public:
    Cmdmsg(std::string cmd, char type);
};


#endif //FAR_STATION_ROBIN_CMDMSG_H
