#include "GimnasioMenu.h"
#include"marco_menu.h"
#include "rlutil.h"
#include "ClienteTareas.h"
#include "PagoTareas.h"
void GimnasioMenu::mostrar()
{
   // marco_menu marco;
    int opcion;
    ClienteTareas clienteTareas;
    PagoTareas pagoTareas;
    do
    {
     //   marco.mostrar_gimnasio();
        system("cls");
        cout<<"----------------------------------"<<endl;
        cout<<"\tMENU GIMNASIO"<<endl;
        cout<<"1  - REGISTRAR PAGO"<<endl;
        cout <<"2 - MOSTRAR CLIENTES CON FECHA POR VENCER" << endl;
        cout <<"3 - MOSTRAR RECAUDACION ANUAL" << endl;
        cout <<"4 - REGISTRAR INGRESOS" << endl;
        cout<<"0 - SALIR"<<endl;
        cout<<"----------------------------------"<<endl;
        //rlutil::locate(10,18);
        cout<<"OPCION: ";
        cin>>opcion;
        system("cls");

        switch(opcion)
        {
        case 1:
            pagoTareas.regPago();
            break;

        case 2:
clienteTareas.mostrarClientesConFechaPorVencer(); //metodo incompleto
            break;

        case 3:
            pagoTareas.cargarPago();

            break;

        case 4:
            pagoTareas.recaudacionAnual ();
//clienteTareas.registrarIngresos();
system("pause");
            break;


        }
       // if(opcion!=0)
      //  {
      //      system("pause");
      //  }

    }
    while(opcion!=0);
}
