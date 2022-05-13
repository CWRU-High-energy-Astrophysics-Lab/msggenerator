//
// Created by robin on 10/21/21.
//

#include "T3msg.h"

#include <utility>

T3msg::T3msg( std::string payload) : Generalmsg("T3LI", "rev1", std::move(payload),10) {


}


