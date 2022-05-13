//
// Created by robin on 10/21/21.
//
#include <iostream>
#include <string>
#ifndef FAR_STATION_ROBIN_GENERALMSG_H
#define FAR_STATION_ROBIN_GENERALMSG_H


class Generalmsg {
public:
    Generalmsg();
    [[nodiscard]] int getweight() const;
    [[nodiscard]] std::string getID() const;
    [[nodiscard]] std::string getRev() const;
    [[nodiscard]] unsigned long getSize() const; // in bytes
    [[nodiscard]] virtual std::string getPayload() const;



    Generalmsg(std::string id, std::string rev , std::string payload, int weight);
    bool operator==(const Generalmsg &that)const
    { return weight == that.weight; }
    bool operator<(const Generalmsg &that)const
    { return weight < that.weight; }
    bool operator>(const Generalmsg &that)const
    { return weight > that.weight; }


    bool operator!=(const Generalmsg &that)const
    { return weight != that.weight; }
    bool operator<=(const Generalmsg &that)const
    { return weight <= that.weight; }
    bool operator>=(const Generalmsg &that)const
    { return weight >= that.weight; }






private:
    std::string id;
    std::string rev;
    std::string payload;
    int weight{};




};


#endif //FAR_STATION_ROBIN_GENERALMSG_H
