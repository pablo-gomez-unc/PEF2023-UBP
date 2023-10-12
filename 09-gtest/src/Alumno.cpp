//
// Created by Pablo on 15/3/2023.
//

#include "Alumno.h"

Alumno::Alumno() = default;

Alumno::Alumno(string name) {
    this->name = name;
}

string Alumno::getName() {
    return name;
}

void Alumno::setName(string name) {
    this->name = name;
}


