//
// Created by robin on 10/21/21.
//

#include "MsgHistory.h"

#include <utility>

MsgHistory::MsgHistory() : Generalmsg("HIST", "Rev1", "",7) {

}
MsgHistory::MsgHistory(std::string payload) : Generalmsg("HIST", "Rev1", std::move(payload),7) {

}
void MsgHistory::addMSG(const std::string& id, int size) {
    std::string temp = '\n'+id +':'+std::to_string(size);
    msglist.append(temp);
}





