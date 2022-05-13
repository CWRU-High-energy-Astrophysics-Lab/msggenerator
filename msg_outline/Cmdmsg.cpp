//
// Created by robin on 10/22/21.
//

#include "Cmdmsg.h"

#include <utility>

// CMDB = bash command
//CMDA = os9

Cmdmsg::Cmdmsg(std::string cmd, char type) : Generalmsg(&"CMD"[type], "Rev1", std::move(cmd),5) {

}
