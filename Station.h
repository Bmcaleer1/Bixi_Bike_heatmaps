//
// Created by Evan Keller on 10/24/24.
//

#ifndef INC_1M3OEP_EHKELLER_BCMCALEE_STATION_H
#define INC_1M3OEP_EHKELLER_BCMCALEE_STATION_H

#include <string>

using std::string;

class Station {
private:
    string name;
    string ID;
    int bikes;
    int emptySpace;

public:

    Station() {
        name = "";
        ID = "";
        bikes = 0;
        emptySpace = 0;
    }

    Station(string name, string ID, int bikes, int emptySpace) {
        this->name = name;
        this->ID = ID;
        this->bikes = bikes;
        this->emptySpace = emptySpace;
    }
};

#endif //INC_1M3OEP_EHKELLER_BCMCALEE_STATION_H
