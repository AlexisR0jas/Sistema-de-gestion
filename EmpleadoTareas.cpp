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
            validarIngresos(opcion);

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
        /* if (em.getEstado() == true)*/
        {
            em.mostrarEmpleado();

        }

    }

}

void EmpleadoTareas::listarEmpleadosPorAnio()
{
    int anio;
    cout<<"Ingrese el anio de ingreso para listar empleados"<<endl;
    cin>>anio;
    validarIngresos(anio);

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
     validarIngresos(orden);
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
    validarIngresos(orden);
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
     validarIngresos(orden);

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
        cout<<"Ingrese el orden (1 - Ordenados de sueldo maximo a minimo, 2 - Ordenados de sueldo minimo a maximo)"<<endl;
        cin>>orden;
    validarIngresos(orden);

    }
    while(orden<1||orden>2);

    EmpleadoArchivo archivo("empleados.dat");
    int cantidad=archivo.cantidadEmpleados();
    Empleado aux;
    Empleado *vEmpleados=new Empleado[cantidad];
    archivo.leerVector(vEmpleados,cantidad);
    if(vEmpleados==NULL)
    {
        cout<<"Error al cargar el vector de empleados"<<endl;
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
        for(int i=0; i<cantidad-1; i++)
        {
            menor=i;
            for(int x=i+1; x<cantidad; x++)
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
        em.mostrarEmpleadosDadosDeBaja();
        cout<<endl;
    }


}

void EmpleadoTareas::darDeBajaEmpleado()
{
    EmpleadoArchivo archivo("empleados.dat");
    int id;
    cout<<"Ingrese el ID del empleado que quiere dar de baja"<<endl;
    cin>>id;
    validarIngresos(id);

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
       validarIngresos(op);

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
            validarIngresos(opcion);

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
    validarIngresos(id);

    if(_archivo.buscarPorID(id)>0)
    {
        cout<<"ID Encontrado!"<<endl<<endl;
    }
    else if(_archivo.buscarPorID(id)==-1)
    {
        cout<<"No se pudo abrir el archivo"<<endl;
    }
    else
    {
        cout<<"No existe ese ID o esta dado de baja el registro"<<endl;
    }

}

void EmpleadoTareas::consultaPorDni()
{
    int dni;
    cout<<"Ingrese el DNI"<<endl;
    cin>>dni;
    validarIngresos(dni);

    if(_archivo.buscarPorDni(dni)>0)
    {
        cout<<"DNI Encontrado!"<<endl<<endl;
    }
    else if(_archivo.buscarPorDni(dni)==-1)
    {
        cout<<"No se pudo abrir el archivo"<<endl;
    }
    else
    {
        cout<<"No existe ese DNI o esta dado de baja el registro"<<endl;
    }
}

void EmpleadoTareas::consultaPorNombre()
{
    char nombre[30];
    cout<<"Ingrese el nombre"<<endl;
    cargarCadena(nombre,29);
    convertirAMayusculas(nombre);
    if(_archivo.buscarPorNombre(nombre)>0)
    {
        cout<<"NOMBRE Encontrado!"<<endl<<endl;
    }
    else if(_archivo.buscarPorNombre(nombre)==-1)
    {
        cout<<"No se pudo abrir el archivo"<<endl;
    }
    else
    {
        cout<<"No existe ese nombre o esta dado de baja el registro"<<endl;
    }

}

void EmpleadoTareas::consultaPorApellido()
{
    char apellido[30];
    cout<<"Ingrese el apellido"<<endl;
    cargarCadena(apellido,29);
    convertirAMayusculas(apellido);
    if(_archivo.buscarPorApellido(apellido)>0)
    {
        cout<<"APELLIDO Encontrado!"<<endl<<endl;
    }
    else if(_archivo.buscarPorApellido(apellido)==-1)
    {
        cout<<"No se pudo abrir el archivo"<<endl;
    }
    else
    {
        cout<<"No existe ese apellido o esta dado de baja el registro"<<endl;
    }
}

void EmpleadoTareas::consultaPorEdad()
{
    int edad;
    cout<<"INGRESE LA EDAD"<<endl;
    cin>>edad;
    validarIngresos(edad);

    if(_archivo.buscarPorEdad(edad)>0)
    {
        cout<<"EDAD ENCONTRADA!"<<endl<<endl;
    }
    else if(_archivo.buscarPorEdad(edad))
    {
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
    }
    else
    {
        cout<<"NO EXISTE ESA EDAD O ESTA DADO DE BAJA EL REGISTRO"<<endl;
    }
}


void EmpleadoTareas::cargar()
{
    Empleado reg;
    char nombre[30],apellido[30];
    char genero;
    float sueldo;
    int dni;
    int edad;
    Fecha fechaNacimiento;
    Fecha fechaIngreso;
    int especializacion;
    bool estado;

    int id=generarID();

    cout<<"NOMBRE: ";
    cargarCadena(nombre,29);
    convertirAMayusculas(nombre);
    cout<<"APELLIDO: ";
    cargarCadena(apellido,29);
    convertirAMayusculas(apellido);
    cout<<"DNI: ";
    cin>>dni;
    validarIngresos(dni);

    cout<<"FECHA NACIMIENTO: "<<endl;
    fechaNacimiento.cargar();
    edad=calcularEdad(fechaNacimiento);
    do
    {
        cout<<"GENERO (M - MASCULINO, F - FEMENINO): ";
        cin>>genero;
        toupper(genero);

    }
    while(genero!='F'&&genero!='f'&&genero!='m'&&genero!='M');

    do
    {
        cout <<"SUELDO: "<<endl;
        cin >> sueldo;
   // validarIngresos(sueldo);

    }
    while(sueldo<=0);

    cout <<"FECHA DE INGRESO: "<<endl;
    fechaIngreso.cargar();
    do
    {
        cout <<"ESPECIALIZACION (1 - PROFESOR, 2 - ADMINISTRATIVO, 3 - LIMPIEZA): "<<endl;
        cin >> especializacion;
    }
    while(especializacion<1||especializacion>3);

    estado=true;

    reg.setId(id);
    reg.setNombre(nombre);
    reg.setApellido(apellido);
    reg.setDni(dni);
    reg.setFechaNacimiento(fechaNacimiento);
    reg.setEdad(edad);
    reg.setSexo(genero);
    reg.setSueldo(sueldo);
    reg.setFechaIngreso(fechaIngreso);
    reg.setEspecializacion(especializacion);
    reg.setEstado(estado);


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
            validarIngresos(opcion);

             system("cls");
        }
        while(opcion<0||opcion>9);



        switch(opcion)
        {
        case 1:
            cout<<"INGRESE EL NUEVO NOMBRE"<<endl;
            cargarCadena(nombre,29);
            convertirAMayusculas(nombre);
            empleadoModificado.setNombre(nombre);
            cout <<"NOMBRE CAMBIADO CON EXITO"<< endl;
            break;
        case 2:
            cout<<"INGRESE EL NUEVO APELLIDO"<<endl;
            cargarCadena(apellido,29);
            convertirAMayusculas(apellido);
            empleadoModificado.setApellido(apellido);
              cout <<"APELLIDO CAMBIADO CON EXITO"<< endl;
            break;
        case 3:

            do
            {
                cout<<"INGRESE EL NUEVO DNI "<<endl;
                cin>>dni;
                validarIngresos(dni);

                empleadoModificado.setDni(dni);
            }
            while(_archivo.existeEmpleado(empleadoModificado)!=0);

  cout <<"DNI CAMBIADO CON EXITO"<< endl;


            break;
        case 4:
            do
            {
                cout<<"INGRESE EL NUEVO GENERO(M - MASCULINO, F - FEMENINO) "<<endl;
                cin>>genero;
                toupper(genero);
            }
            while(genero!='F'&&genero!='f'&&genero!='m'&&genero!='M');

            empleadoModificado.setSexo(genero);
              cout <<"SEXO CAMBIADO CON EXITO"<< endl;
            break;
        case 5:
            cout<<"INGRESE LA NUEVA FECHA DE NACIMIENTO "<<endl;
            fechaNacimiento.cargar();
            empleadoModificado.setEdad(calcularEdad(fechaNacimiento));
            empleadoModificado.setFechaNacimiento(fechaNacimiento);
              cout <<"FECHA CAMBIADA CON EXITO"<< endl;
            break;
        case 6:
            cout<<"INGRESE LA NUEVA FECHA DE ALTA"<<endl;
            fechaIngreso.cargar();
            empleadoModificado.setFechaIngreso(fechaIngreso);
            cout <<"FECHA CAMBIADA CON EXITO"<< endl;
            break;
        case 7:
            cout<<"INGRESE EL NUEVO SUELDO"<<endl;
            cin>>sueldo;
            cout <<"SUELDO CAMBIADO CON EXITO"<< endl;
            empleadoModificado.setSueldo(sueldo);
            break;

        case 8:
            cout<<"INGRESE LA NUEVA ESPECIALIZACION"<< endl;
            cout <<"ESPECIALIZACION (1 - PROFESOR, 2 - ADMINISTRATIVO, 3 - LIMPIEZA): "<<endl;
            cin >> especializacion;
            empleadoModificado.setEspecializacion(especializacion);
            cout <<"ESPECIALIZACION CAMBIADA CON EXITO"<< endl;
            break;

        case 9:
            cout <<"MODIFICAR TODO EL REGISTRO" << endl;
            char nombre[30],apellido[30];
            char genero;
            float sueldo;
            int dni;
            int edad;
            Fecha fechaNacimiento;
            Fecha fechaIngreso;
            int especializacion;




            cout<<"NOMBRE: ";
            cargarCadena(nombre,29);
            convertirAMayusculas(nombre);
            cout<<"APELLIDO: ";
            cargarCadena(apellido,29);
            convertirAMayusculas(apellido);
            do
            {
                cout<<"INGRESE EL DNI "<<endl;
                cin>>dni;
                validarIngresos(dni);

                empleadoModificado.setDni(dni);
            }
            while(_archivo.existeEmpleado(empleadoModificado)!=0);
            cout<<"FECHA NACIMIENTO: "<<endl;
            fechaNacimiento.cargar();
            edad=calcularEdad(fechaNacimiento);
            do
            {
                cout<<"GENERO (M - MASCULINO, F - FEMENINO): ";
                cin>>genero;
                toupper(genero);
            }
            while(genero!='F'&&genero!='f'&&genero!='m'&&genero!='M');


            cout <<"SUELDO: "<<endl;
            cin >> sueldo;
            cout <<"FECHA DE INGRESO: "<<endl;
            fechaIngreso.cargar();
            do
            {
                cout <<"ESPECIALIZACION (1 - PROFESOR, 2 - ADMINISTRATIVO, 3 - LIMPIEZA): "<<endl;
                cin >> especializacion;
            }
            while(especializacion<1||especializacion>3);



            empleadoModificado.setNombre(nombre);
            empleadoModificado.setApellido(apellido);
            empleadoModificado.setDni(dni);
            empleadoModificado.setFechaNacimiento(fechaNacimiento);
            empleadoModificado.setEdad(edad);
            empleadoModificado.setSexo(genero);
            empleadoModificado.setSueldo(sueldo);
            empleadoModificado.setFechaIngreso(fechaIngreso);
            empleadoModificado.setEspecializacion(especializacion);


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
        cout << "MODIFIQUE EL EMPLEADO"<<endl;
        Empleado empleadoModificado= _archivo.leer(numeroRegistro) ;

        cout << endl;
        cout << "USTED VA A MODIFICAR A:"<<endl;
        empleadoModificado.mostrarEmpleado();
        system("pause");

        elegirQueModificar(empleadoModificado);


        bool exito = _archivo.editar(empleadoModificado, numeroRegistro);
        if (exito)
        {
            cout << "REGISTRO MODIFICADO EXITOSAMENTE." << endl;
        }
        else
        {
            cout << "NO SE PUDO MODIFICAR EL REGISTRO." << endl;
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
