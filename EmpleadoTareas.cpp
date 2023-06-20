#include "EmpleadoTareas.h"
#include "funciones.h"

void EmpleadoTareas::listados()
{
    int opcion;
    do
    {
        do
        {
            system("cls");
            cout<<"\tLISTADOS"<<endl;
            cout<<"--------------------------------------------"<<endl;
            cout<<"1 - TODOS LOS REGISTROS"<<endl;
            cout<<"2 - POR NOMBRE"<<endl;
            cout<<"3 - POR APELLIDO"<<endl;
            cout<<"4 - POR ANIO"<<endl;
            cout<<"5 - POR EDAD"<<endl;
            cout<<"6 - POR SUELDO "<<endl;
            cout<<"7 - DADOS DE BAJA"<<endl;
            cout<<"0 - SALIR"<<endl;
            cout<<"--------------------------------------------"<<endl;
            cout<<"OPCION: ";
            cin>>opcion;
            system("cls");

        }
        while(opcion<0||opcion>7);
        switch(opcion)
        {
        case 1:
            listarRegistros();
            break;
        case 2:
            listarOrdenadosPorNombre();
            break;
        case 3:
            listarOrdenadosPorApellido();
            break;
        case 4:
            listarEmpleadosPorAnio();
            break;
        case 5:
            listarPorEdad();
            break;
        case 6:
            listarPorSueldo();
            break;
        case 7:
            listarEmpleadosDadosDeBaja();
            break;
        }

        if(opcion!=0)
        {
            system("pause");
        }

    }
    while(opcion!=0);
}

void EmpleadoTareas::listarRegistros()
{
    int cant=_archivo.cantidadEmpleados();
    for(int i=0; i<cant; i++)
    {

        Empleado em=_archivo.leer(i);
        cout<<"ID Empleado #"<<em.getId()<<endl;
        em.mostrarEmpleado();
        cout<<"---------------------------------------"<<endl;
    }
}

void EmpleadoTareas::listarEmpleadosPorAnio()
{
    int anio;
    cout<<"Ingrese el anio para listar empleados"<<endl;
    cin>>anio;
    cout<<endl;
    _archivo.buscarPorAnio(anio);

}

void EmpleadoTareas::listarOrdenadosPorNombre()
{
    int orden;
    do
    {
        cout<<"Ingrese el orden(1 - Ordenados de mayor a menor, 2 - Ordenados de menor a mayor)"<<endl;
        cin>>orden;
    }
    while(orden<1||orden>2);
    EmpleadoArchivo archivo("empleados.dat");

    int cantidad=archivo.cantidadEmpleados();
    Empleado *vEmpleados=new Empleado[cantidad];
    Empleado aux;
    if(vEmpleados==NULL)
    {
        cout<<"Error al intentar cargar el vector dinamico"<<endl;
        return;
    }
    archivo.leerVector(vEmpleados,cantidad);

    if(orden==1)
    {
        int mayor=0;

        for(int i=0; i<cantidad-1; i++)
        {
            mayor=i;
            for(int x=i+1; x<cantidad; x++)
            {
                if(strcmp(vEmpleados[x].getNombre(),vEmpleados[mayor].getNombre())>0)
                {
                    mayor=x;
                }
            }
            if(mayor!=i)
            {
                aux=vEmpleados[i];
                vEmpleados[i]=vEmpleados[mayor];
                vEmpleados[mayor]=aux;
            }
        }


    }
    else
    {
        int menor=0;

        for(int i=0; i<cantidad-1; i++)
        {
            menor=i;
            for(int x=i+1; x<cantidad; x++)
            {
                if(strcmp(vEmpleados[x].getNombre(),vEmpleados[menor].getNombre())<0)
                {
                    menor=x;
                }
            }
            if(menor!=i)
            {
                aux=vEmpleados[i];
                vEmpleados[i]=vEmpleados[menor];
                vEmpleados[menor]=aux;
            }
        }


    }

    for(int i=0; i<cantidad; i++)
    {
        cout<<"ID Empleados #"<<vEmpleados[i].getId()<<endl;
        vEmpleados[i].mostrarEmpleado();
        cout<<endl;
    }

    delete []vEmpleados;
}

void EmpleadoTareas::listarOrdenadosPorApellido()
{
    int orden;
    do
    {
        cout<<"Ingrese el orden(1 - Ordenados de mayor a menor, 2 - Ordenados de menor a mayor)"<<endl;
        cin>>orden;
    }
    while(orden<1||orden>2);
    EmpleadoArchivo archivo("empleados.dat");

    int cantidad=archivo.cantidadEmpleados();
    Empleado *vEmpleados=new Empleado[cantidad];
    Empleado aux;
    if(vEmpleados==NULL)
    {
        cout<<"Error al intentar cargar el vector dinamico"<<endl;
        return;
    }
    archivo.leerVector(vEmpleados,cantidad);

    if(orden==1)
    {
        int mayor=0;

        for(int i=0; i<cantidad-1; i++)
        {
            mayor=i;
            for(int x=i+1; x<cantidad; x++)
            {
                if(strcmp(vEmpleados[x].getApellido(),vEmpleados[mayor].getApellido())>0)
                {
                    mayor=x;
                }
            }
            if(mayor!=i)
            {
                aux=vEmpleados[i];
                vEmpleados[i]=vEmpleados[mayor];
                vEmpleados[mayor]=aux;
            }
        }


    }
    else
    {
        int menor=0;

        for(int i=0; i<cantidad-1; i++)
        {
            menor=i;
            for(int x=i+1; x<cantidad; x++)
            {
                if(strcmp(vEmpleados[x].getApellido(),vEmpleados[menor].getApellido())<0)
                {
                    menor=x;
                }
            }
            if(menor!=i)
            {
                aux=vEmpleados[i];
                vEmpleados[i]=vEmpleados[menor];
                vEmpleados[menor]=aux;
            }
        }


    }

    for(int i=0; i<cantidad; i++)
    {
        cout<<"ID Empleados #"<<vEmpleados[i].getId()<<endl;
        vEmpleados[i].mostrarEmpleado();
        cout<<endl;
    }

    delete []vEmpleados;
}

void EmpleadoTareas::listarPorEdad()
{
    Fecha hoy;

    int orden;
    do
    {
        cout<<"Ingrese el orden (1 - Ordenados de mayor a menor, 2 - Ordenados de menor a mayor)"<<endl;
        cin>>orden;

    }
    while(orden<1||orden>2);

    EmpleadoArchivo archivo("empleados.dat");
    int cantidad=archivo.cantidadEmpleados();
    Empleado aux;
    Empleado *vEmpleados=new Empleado[cantidad];
    archivo.leerVector(vEmpleados,cantidad);

    if(vEmpleados==NULL)
    {
        cout<<"Error al cargar el vector"<<endl;
        return;
    }

    if(orden==1)
    {
        int mayor=0;
        for(int i=0; i<cantidad-1; i++)
        {
            mayor=i;
            for(int x=i+1; x<cantidad; x++)
            {
                if(calcularEdad(vEmpleados[x].getFechaNacimiento())>calcularEdad(vEmpleados[mayor].getFechaNacimiento()))
                {
                    mayor=x;
                }
            }
            if(mayor!=i)
            {
                aux=vEmpleados[i];
                vEmpleados[i]=vEmpleados[mayor];
                vEmpleados[mayor]=aux;
            }
        }



    }
    else
    {
        int menor=0;
        for(int i=0; i<cantidad-1; i++)
        {
            menor=i;
            for(int x=i+1; x<cantidad; x++)
            {
                if(calcularEdad(vEmpleados[x].getFechaNacimiento())<calcularEdad(vEmpleados[menor].getFechaNacimiento()))
                {
                    menor=x;
                }
            }
            if(menor!=i)
            {
                aux=vEmpleados[i];
                vEmpleados[i]=vEmpleados[menor];
                vEmpleados[menor]=aux;
            }
        }



    }

    for(int i=0; i<cantidad; i++)
    {
        cout<<"ID Empleado #"<<vEmpleados[i].getId()<<endl;
        vEmpleados[i].mostrarEmpleado();
        cout<<endl;
    }
    delete []vEmpleados;
}

void EmpleadoTareas::listarPorSueldo()
{
    int orden;
    do
    {
        cout<<"Ingrese el orden (1 - Ordenados de sueldo minimo a maximo, 2 - Ordenados de sueldo minimo a maximo)"<<endl;
        cin>>orden;

    }
    while(orden<1||orden>2);

    EmpleadoArchivo archivo("empleados.dat");
    int cantidad=archivo.cantidadEmpleados();
    Empleado aux;
    Empleado *vEmpleados=new Empleado[cantidad];
    if(vEmpleados==NULL)
    {
        cout<<"Error al cargar el vector de empleados"<<endl;
        return;
    }

    if(orden==1)
    {
        int mayor=0;
        for(int i=0; i<cantidad; i++)
        {
            mayor=i;
            for(int x=0; x<cantidad; x++)
            {
                if(vEmpleados[x].getSueldo()>vEmpleados[mayor].getSueldo())
                {
                    mayor=x;
                }
            }
            if(mayor!=i)
            {
                aux=vEmpleados[i];
                vEmpleados[i]=vEmpleados[mayor];
                vEmpleados[mayor]=aux;
            }
        }
    }
    else
    {
        int menor=0;
        for(int i=0; i<cantidad; i++)
        {
            menor=i;
            for(int x=0; x<cantidad; x++)
            {
                if(vEmpleados[x].getSueldo()<vEmpleados[menor].getSueldo())
                {
                    menor=x;
                }
            }
            if(menor!=i)
            {
                aux=vEmpleados[i];
                vEmpleados[i]=vEmpleados[menor];
                vEmpleados[menor]=aux;
            }
        }
    }

    for(int i=0; i<cantidad; i++)
    {
        cout<<"ID Empleado #"<<vEmpleados[i].getId()<<endl;
        vEmpleados[i].mostrarEmpleado();
        cout<<endl;
    }

    delete []vEmpleados;

}

void EmpleadoTareas::listarEmpleadosDadosDeBaja()
{

    EmpleadoArchivo archivo("empleados.dat");
    int cantidad=archivo.cantidadEmpleados();
    Empleado em;

    for(int i=0; i<cantidad; i++)
    {
        em=archivo.leer(i);
        if(em.getEstado()==false)
        {
            em.mostrarEmpleado();
        }
    }


}

void EmpleadoTareas::darDeBajaEmpleado()
{
    EmpleadoArchivo archivo("empleados.dat");
    int id;
    cout<<"Ingrese el ID del empleado que quiere dar de baja"<<endl;
    cin>>id;
    archivo.bajaLogica(id);
}

void EmpleadoTareas::reactivarEmpleado()
{
    int op;
    int numeroRegistro = _archivo.buscarRegistro();
    if (numeroRegistro>=0)
    {
        cout <<"el empleado que usted quiere reactivar es: " << endl;
        Empleado empleado= _archivo.leer(numeroRegistro);
        empleado.mostrarEmpleado();
        system("pause");
        cout <<"�desea reactivar?" <<endl;
        cout <<"1 - SI o 2 - NO" << endl;
        cin >> op;
        if (op == 1)
        {

            empleado.setEstado(true);

            bool exito = _archivo.editar(empleado, numeroRegistro);
            if (exito)
            {
                cout << "Registro activado exitosamente." << endl;

            }
            else
            {
                cout << "No se pudo modificar el registro." << endl;
            }


        }



    }


}


void EmpleadoTareas::consultas()
{
    int opcion;
    do
    {
        do
        {
            system("cls");
            cout<<"\tCONSULTAS"<<endl;
            cout<<"---------------------------------"<<endl;
            cout<<"1 - BUSCAR POR ID"<<endl;
            cout<<"2 - BUSCAR POR DNI"<<endl;
            cout<<"3 - BUSCAR POR NOMBRE"<<endl;
            cout<<"4 - BUSCAR POR APELLIDO"<<endl;
            cout<<"5 - BUSCAR POR EDAD"<<endl;
            cout<<"0 - SALIR"<<endl;
            cout<<"---------------------------------"<<endl;
            cout<<"OPCION: ";
            cin>>opcion;
            system("cls");
        }
        while(opcion<0||opcion>5);
        switch(opcion)
        {
        case 1:
            consultaPorId();
            break;
        case 2:
            consultaPorDni();
            break;
        case 3:
            consultaPorNombre();
            break;
        case 4:
            consultaPorApellido();
            break;
        case 5:
            consultaPorEdad();
            break;
        }
        if(opcion!=0)
        {
            system("pause");
        }

    }
    while(opcion!=0);
}

void EmpleadoTareas::consultaPorId()
{
    int id;
    cout<<"Ingrese el id"<<endl;
    cin>>id;
    if(_archivo.buscarPorID(id)>0)
    {
        cout<<"ID Encontrado!"<<endl<<endl;
    }else
    {
        cout<<"No existe ese ID o no se pudo abrir el archivo"<<endl;
    }

}

void EmpleadoTareas::consultaPorDni()
{
    int dni;
    cout<<"Ingrese el DNI"<<endl;
    cin>>dni;
    if(_archivo.buscarPorDni(dni)>0)
    {
        cout<<"DNI Encontrado!"<<endl<<endl;
    }else
    {
        cout<<"No existe ese DNI O no se pudo abrir el archivo"<<endl;
    }
}

void EmpleadoTareas::consultaPorNombre()
{
    char nombre[30];
    cout<<"Ingrese el nombre"<<endl;
    cargarCadena(nombre,29);
    if(_archivo.buscarPorNombre(nombre)>0)
    {
        cout<<"NOMBRE Encontrado!"<<endl<<endl;
    }else
    {
        cout<<"No existe ese nombre o no se pudo abrir el archivo"<<endl;
    }

}

void EmpleadoTareas::consultaPorApellido()
{
    char apellido[30];
    cout<<"Ingrese el apellido"<<endl;
    cargarCadena(apellido,29);
    if(_archivo.buscarPorApellido(apellido)>0)
    {
        cout<<"APELLIDO Encontrado!"<<endl<<endl;
    }else
    {
        cout<<"No existe ese apellido o no se pudo abrir el archivo"<<endl;
    }
}

void EmpleadoTareas::consultaPorEdad()
{
    int edad;
    cout<<"Ingrese la edad"<<endl;
    cin>>edad;
    if(_archivo.buscarPorEdad(edad)>0)
    {
        cout<<"EDAD Encontrada!"<<endl<<endl;
    }else
    {
        cout<<"No existe esa edad o no se pudo abrir el archivo"<<endl;
    }
}


void EmpleadoTareas::cargar()
{
    Empleado reg;
    int id=generarID();
    cout<<"ID Empleado #"<<id<<endl;
    reg.setId(id);
    cout<<endl;
    reg.cargarEmpleado();


    _archivo.guardar(reg);
}

void EmpleadoTareas::elegirQueModificar(Empleado &empleadoModificado)
{
    int opcion, especializacion;
    char nombre[30],apellido[30];
    char genero;
    int dni;

    Fecha fechaNacimiento,fechaIngreso;
    float sueldo;

    do
    {
        do
        {
            system("cls");
            cout<<"\tMODIFICAR EMPLEADO"<<endl;
            cout<<"-------------------------------------"<<endl;
            cout<<"1 - MODIFICAR NOMBRE"<<endl;
            cout<<"2 - MODIFICAR APELLIDO"<<endl;
            cout<<"3 - MODIFICAR DNI"<<endl;
            cout<<"4 - MODIFICAR GENERO"<<endl;
            cout<<"5 - MODIFICAR FECHA NACIMIENTO"<<endl;
            cout<<"6 - MODIFICAR FECHA DE ALTA"<<endl;
            cout<<"7 - MODIFICAR SUELDO"<<endl;
            cout<<"8 - MODIFICAR ESPECIALIZACION"<< endl;
            cout<<"9 - MODIFICAR TODO EL REGISTRO"<< endl;
            cout<<"-------------------------------------"<<endl;
            cout<<"0 - SALIR"<<endl;
            cout<<"OPCION: ";
            cin>>opcion;
            system("cls");
        }
        while(opcion<0||opcion>9);



        switch(opcion)
        {
        case 1:
            cout<<"Ingrese el nuevo nombre"<<endl;
            cargarCadena(nombre,29);
            empleadoModificado.setNombre(nombre);
            break;
        case 2:
            cout<<"Ingrese el nuevo apellido"<<endl;
            cargarCadena(apellido,29);
            empleadoModificado.setApellido(apellido);
            break;
        case 3:
            cout<<"Ingrese el nuevo DNI "<<endl;
            cin>>dni;
            empleadoModificado.setDni(dni);
            break;
        case 4:
            do
            {
                cout<<"Ingrese el nuevo genero(M - MASCULINO, F - FEMENINO) "<<endl;
                cin>>genero;
            }
            while(genero!='F'&&genero!='f'&&genero!='m'&&genero!='M');

            empleadoModificado.setSexo(genero);
            break;
        case 5:
            cout<<"Ingrese la nueva fecha de nacimiento "<<endl;
            fechaNacimiento.cargar();
            empleadoModificado.setFechaNacimiento(fechaNacimiento);
            break;
        case 6:
            cout<<"Ingrese la nueva fecha de alta"<<endl;
            fechaIngreso.cargar();
            empleadoModificado.setFechaIngreso(fechaIngreso);
            break;
        case 7:
            cout<<"Ingrese el nuevo sueldo"<<endl;
            cin>>sueldo;
            empleadoModificado.setSueldo(sueldo);
            break;

        case 8:
            cout<<"Ingrese la nueva especializacion"<< endl;
            cout <<"Especializacion(1 - Profesor, 2 - Administrativo, 3 - Limpieza): "<<endl;
            cin >> especializacion;
            empleadoModificado.setEspecializacion(especializacion);
       break;

        case 9:
        cout <<"modificar todo el registro" << endl;
        empleadoModificado.cargarEmpleado();

        }
        if(opcion!=0)
        {
            system("pause");
        }


    }
    while(opcion!=0);

}





void EmpleadoTareas::modificar()
{
    Empleado empleado;

    int numeroRegistro = _archivo.buscarRegistro();
    if (numeroRegistro>=0)
    {
        cout << "Modifique al empleado"<<endl;
 Empleado empleadoModificado= _archivo.leer(numeroRegistro) ;

        cout << endl;
        cout << "Usted va a modificar a:"<<endl;
        empleadoModificado.mostrarEmpleado();
         system("pause");

        elegirQueModificar(empleadoModificado);


        bool exito = _archivo.editar(empleadoModificado, numeroRegistro);
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

void EmpleadoTareas::borrarRegistros()
{
    _archivo.vaciar();
}

int EmpleadoTareas::generarID()
{
    return _archivo.cantidadEmpleados()+1;
}

int EmpleadoTareas::calcularEdad(Fecha fechaNacimiento)
{
    Fecha hoy;
    int edad;
    edad=hoy.getAnio()-fechaNacimiento.getAnio(); /// OBTENGO EL A�O ACTUAL

    if(hoy.getMes()<fechaNacimiento.getMes()||hoy.getMes()==fechaNacimiento.getMes()&&hoy.getDia()<fechaNacimiento.getDia())
    {
        edad--;
    }

    return edad;
}
