#include "ClienteTareas.h"
#include "Cliente.h"
#include "ClienteArchivo.h"

void ClienteTareas::cargar()
{

    Cliente cliente;
    cliente.cargarCliente();

    _archivoCliente.guardar(cliente);


}
void ClienteTareas::modificar()
{


    int numeroRegistro = _archivoCliente.buscarRegistro();
    if (numeroRegistro>=0)
    {
        cout <<"el cliente que usted quiere modificar es: " << endl;
        _archivoCliente.leer(numeroRegistro).mostrarCliente();
        cout << endl;
        cout << "Modifique al cliente"<<endl;
        Cliente clienteModificado ;
        clienteModificado.cargarCliente();

        bool exito = _archivoCliente.editar(clienteModificado, numeroRegistro);
        if (exito)
        {
            cout << "Registro modificado exitosamente." << endl;
        }
        else
        {
            cout << "No se pudo modificar el registro." << endl;
        }
    }
}
void ClienteTareas::listarClientesBox(){
ClienteArchivo clienteArch;
int cantidadDeClientes = clienteArch.getCantidad();

     for (int i = 0; i < cantidadDeClientes; i++){
       Cliente cliente =  clienteArch.leer(i);


        if ( strcmp( cliente.getNombreDeporte(), "boxeo") == 0 ){

cliente.mostrarCliente();
cout <<"----------------------------"<< endl;

        }


     }

}



void ClienteTareas::mostrarPorDni()
{
    int documento;
    cout <<"ingrese documento: " << endl;
    cin >> documento;
    int cantidadDeClientes = _archivoCliente.getCantidad();


    for (int i = 0; i < cantidadDeClientes; i++ )
    {
        Cliente cliente = _archivoCliente.leer(i);

        if ( documento == cliente.getDni() )
        {

            cliente.mostrarCliente();


        }


    }



}

void ClienteTareas::mostrarTodos()
{
    int cantidadDeClientes = _archivoCliente.getCantidad();
    for (int i = 0; i < cantidadDeClientes; i++ )
    {
        Cliente cliente = _archivoCliente.leer(i);

        cliente.mostrarCliente();
        cout << endl;
cout <<"--------------------------------------"<< endl;

    }




}


void ClienteTareas::darBajaCliente(){
 int op;
 int numeroRegistro = _archivoCliente.buscarRegistro();
    if (numeroRegistro>=0)
    {
        cout <<"el cliente que usted quiere dar de baja es: " << endl;
        _archivoCliente.leer(numeroRegistro).mostrarCliente();
       system("pause");
        cout <<"�desea dar la baja?" <<endl;
       cout <<"1 - SI o 2 - NO" << endl;
        cin >> op;
        if (op == 1) {
        Cliente clienteEnBaja ;
        clienteEnBaja.setEstado(false);

        bool exito = _archivoCliente.editar(clienteEnBaja, numeroRegistro);
        if (exito)
        {
            cout << "Registro dado de baja exitosamente." << endl;
             system("pause");
        }
        else
        {
            cout << "No se pudo modificar el registro." << endl;
        }


    } else {    }


    }

}


