#include <algorithm>
#include "funciones.h"
#include "Persona.h"
#include "Empleado.h"
using namespace std;

void cargarCadena(char *pal,int tam)
{

    int i;

    fflush(stdin);

    for(i=0; i<tam; i++)
    {

        pal[i]=cin.get();

        if(pal[i]=='\n') break;

    }

    pal[i]='\0';

    fflush(stdin);

}

void convertirAMayusculas(char* str)
{
    transform(str, str + strlen(str), str, [](unsigned char c)
    {
        return toupper(c);
    });
}

bool validar(int ingreso)
{
    bool esNumero=false;

    if (cin)
    {
        // Se ingres� un entero correctamente
        esNumero=true;
    }
    else
    {
        // Se ingres� un valor no v�lido


        // Limpiamos el estado de error de cin
        cin.clear();

        // Descartamos el contenido inv�lido ingresado por el usuario
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    }


    return esNumero;

}

void validarDosRangos(int &ingreso,int rangoMin,int rangoMax)
{
    bool esValido=false;

    while(!esValido)
    {
        if(!validar(ingreso)||ingreso<rangoMin||ingreso>rangoMax)
        {
            cout<<"INGRESO UN CARACTER O UN NUMERO FUERA DEL RANGO, POR FAVOR, INTENTE DENUEVO "<<endl;
            cin>>ingreso;
        }

        else
        {
            esValido=true;
        }
    }
}

void validarQueNoSeaNegativa(int &ingreso)
{
    bool esValido=false;

    while(!esValido)
    {
        if(!validar(ingreso)||ingreso<0)
        {
            cout<<"INGRESO UN CARACTER O UN NUMERO NEGATIVO, POR FAVOR, INTENTE DENUEVO "<<endl;
            cin>>ingreso;
        }else
        {
            esValido=true;
        }


    }
}

void validarQueNoSeaNegativa(float &ingreso)
{
    bool esValido=false;

    while(!esValido)
    {
        if(!validar(ingreso)||ingreso<0)
        {
            cout<<"INGRESO UN CARACTER O UN NUMERO NEGATIVO, POR FAVOR, INTENTE DENUEVO "<<endl;
            cin>>ingreso;
        }else
        {
            esValido=true;
        }


    }
}



void validarIngresos(int &ingreso)
{
    bool esValido = false;

    while(!esValido)
    {
        if(!validar(ingreso))
        {
            cout<<"INGRESE UN CARACTER VALIDO"<<endl;
            cin>>ingreso;
        }
        else
        {
            break;
        }

    }

}

void validarGenero(char &letra)
{
    bool esValido=false;
    while(!esValido)
    {
        if(letra=='F'||letra=='M')
        {
            esValido=true;
        }else
        {
            cout<<"INGRESE M O F"<<endl;
            cin>>letra;
        }
    }
}


