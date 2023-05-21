#include "Persona.h"
#include "funciones.h"

Persona::Persona()
{
    strcpy(_nombre,"sinNombre");
    strcpy(_apellido,"sinApellido");
    _dni=0;
    _edad=0;
    strcpy(_genero,"sinGenero");
    _fechaNacimiento.ponerPrimerDiaDelAnio();

}

Persona::Persona(char *nombre,char *apellido,int dni,int edad,char *genero,Fecha fechaNacimiento)
{
    strcpy(_nombre,nombre);
    strcpy(_apellido,apellido);
    _dni=dni;
    _edad=edad;
    strcpy(_genero,genero);
    _fechaNacimiento=fechaNacimiento;
}

void Persona::cargarPersona()
{
    cout<<"Nombre: "; cargarCadena(_nombre,29);
    cout<<"Apellido: "; cargarCadena(_apellido,29);
    cout<<"DNI: "; cin>>_dni;
    cout<<"Edad: "; cin>>_edad;
    cout<<"Genero: "; cargarCadena(_genero,29);
    cout<<"Fecha nacimiento: "<<endl; _fechaNacimiento.cargar();
}

void Persona::mostrarPersona()
{
    cout<<"Nombre: "<<_nombre<<endl;
    cout<<"Apellido: "<<_apellido<<endl;
    cout<<"DNI: "<<_dni<<endl;
    cout<<"Edad: "<<_edad<<endl;
    cout<<"Genero: "<<_genero<<endl;
    cout<<"Fecha nacimiento: "<<endl;
    _fechaNacimiento.mostrar();
}



void Persona::setNombre(char *nombre)
{
    strcpy(_nombre,nombre);
}

void Persona::setApellido(char *apellido)
{
    strcpy(_apellido,apellido);
}

void Persona::setDni(int dni)
{
    _dni=dni;
}

void Persona::setEdad(int edad)
{
    _edad=edad;
}

void Persona::setSexo(char *genero)
{
    strcpy(_genero,genero);
}

void Persona::setFechaNacimiento(Fecha fechaNacimiento)
{
    _fechaNacimiento=fechaNacimiento;
}

const char *Persona::getNombre()
{
    return _nombre;
}

const char *Persona::getApellido()
{
    return _apellido;
}

int Persona::getDni()
{
    return _dni;
}

int Persona::getEdad()
{
    return _edad;
}

const char *Persona::getGenero()
{
    return _genero;
}

Fecha Persona::getFechaNacimiento()
{
    return _fechaNacimiento;
}

