//
// Created by Pablo on 15/3/2023.
//

#ifndef AYED_01_ALUMNO_H
#define AYED_01_ALUMNO_H

#include <string>

using namespace std;

class Alumno {
public:
    Alumno();
    explicit Alumno(string name);
    void setName(string name);
    string getName();
private:
    string name;
};


#endif //AYED_01_ALUMNO_H
