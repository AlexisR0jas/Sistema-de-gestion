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

bool validar(int opcionMensual)
{

    cin>>opcionMensual;

    if (cin >> opcionMensual)
    {
        // Se ingres� un entero correctamente
        cout << "El n�mero ingresado es: " << opcionMensual << endl;
        return true;
    }
    else
    {
        // Se ingres� un valor no v�lido
        cout << "Error: no se ingres� un n�mero entero v�lido." << endl;

        // Limpiamos el estado de error de cin
        cin.clear();

        // Descartamos el contenido inv�lido ingresado por el usuario
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }





}



