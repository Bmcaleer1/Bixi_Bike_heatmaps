//
// Created by Evan Keller on 10/24/24.
//

#ifndef INC_1M3EOP_EHKELLER_BCMCALEE_DATA_VECTOR_H
#define INC_1M3EOP_EHKELLER_BCMCALEE_DATA_VECTOR_H

#include <vector>
#include <fstream>
#include <string>
#include <filesystem>
#include <iostream>
#include "Station.h"

using std::string, std::vector, std::fstream, std::cin, std::cout, std::endl;


class Data_Vector {
private:
    string fileName;
    int timeStamp;
    vector<Station> stations;


public:

    Data_Vector() {
        fileName = "";
        timeStamp = 0;
        stations = vector<Station>();
    }

    Data_Vector(string fileName) {
        this->fileName = fileName;
        fstream inFile;
        //inFile.open("./api_data/" + fileName);
        inFile.open(fileName);
        if (inFile) {
            string firstLine;
            char comma;
            while (inFile) {
                int bikes;
                int emptySpaces;
                string id;
                string name;
                getline(inFile, firstLine);
                getline(inFile, id, ',');
                getline(inFile, name, ',');
                inFile >> bikes >> comma;
                inFile >> emptySpaces >> comma;
                stations.emplace_back(name, id, bikes, emptySpaces);
            }
        } else {
            cout << "Error opening file [" << fileName << "]" << endl;
        }
    }


};

#endif //INC_1M3EOP_EHKELLER_BCMCALEE_DATA_VECTOR_H
