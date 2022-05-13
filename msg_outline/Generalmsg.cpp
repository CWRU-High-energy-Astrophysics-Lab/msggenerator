//
// Created by robin on 10/21/21.
//

#include "Generalmsg.h"

#include <utility>

unsigned long Generalmsg::getSize() const {
    return payload.length(); //one character is one byte
}

std::string Generalmsg::getID() const {
    return id;
}

std::string Generalmsg::getRev() const {
    return rev;
}

Generalmsg::Generalmsg(std::string id, std::string rev, std::string payload, int weight) {
    this->id = std::move(id);
    this->rev = std::move(rev);
    this->payload = std::move(payload);
    this->weight =weight;

}

std::string Generalmsg::getPayload() const {
    return payload;
}

Generalmsg::Generalmsg() = default;

int Generalmsg::getweight() const{
    return weight;
}
