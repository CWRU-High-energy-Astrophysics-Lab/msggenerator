//
// Created by robin on 10/21/21.
//

#include "T2msg.h"

#include <utility>


T2msg::T2msg(std::string payload) : Generalmsg("T2LI", "rev1", std::move(payload),9) {


}

