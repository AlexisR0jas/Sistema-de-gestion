#ifndef EMPLEADOARCHIVO_H
#define EMPLEADOARCHIVO_H
#include <iostream>
#include <string.h>

using namespace std;
#include "Empleado.h"

class EmpleadoArchivo
{
private:
    char _nombreArchivo[30];

public:
    EmpleadoArchivo();/// CONSTRUCTOR PARA PONER POR DEFECTO empleados.dat
    EmpleadoArchivo(char *nombreArchivo);/// CONSTRUCTOR PARA ELEGIR ALGUN OTRO NOMBRE QUE NO SEA empleados.dat

    bool guardar(Empleado empl);
    Empleado leer(int nroRegistro);

};

#endif // EMPLEADOARCHIVO_H
