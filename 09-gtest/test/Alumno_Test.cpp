//
// Created by Pablo on 15/3/2023.
//

#include <Alumno.h>
#include "gtest/gtest.h"

TEST (AlumnoTestSuite, ContructorConParam) {
    Alumno a = Alumno("ab");
    EXPECT_EQ(a.getName(),"ab");
}

TEST (AlumnoTestSuite, Contructor) {
    Alumno a = Alumno();
    EXPECT_EQ(a.getName(),"");
}