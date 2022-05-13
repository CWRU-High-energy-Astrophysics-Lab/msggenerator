#include <iostream>
#include "msg.h"

int main() {
    bool restart;
    while (!restart){
        std::string option1;// type
        int option2;// quality
        std::string option3; // size
        std::printf("What type of msg would you like to send or would you like to exit?");
        // display key



       std::cin>>option1;
    }
}

std::string encrypt(const Generalmsg &generalmsg) {
    return std::string(generalmsg.getID() + "[" + generalmsg.getRev() + "]:" + std::to_string(generalmsg.getSize()) +
                       generalmsg.getPayload());
}

Generalmsg decrypt(std::string input) {
    Generalmsg msg;
    std::string type = input.substr(0, 4);
    unsigned long headerend = input.find(':');
    try {
        std::string payload = input.substr(headerend+1);
        if (type == "T3LI") {
            msg = T3msg(payload);
        } else if (type.substr(0, 2) == "CMD") {
            msg = Cmdmsg(payload, type.at(3));
        } else if (type == "HIST") {
            msg = MsgHistory(payload);
        } else if (type == "T2LI") {
            msg = T2msg(payload);
        } else if (type == "LOGA") {
            msg = Logmsg(payload);
        } else {
            msg = Generalmsg(type, "REV0", payload, 12);
            //add a report to log

        }
    }
    catch (const std::out_of_range){
        msg = Generalmsg("ERRO", "REV0", input, 12);
    }

    return msg;
}
