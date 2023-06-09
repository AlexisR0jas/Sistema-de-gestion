#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>

using namespace std;
#include "Persona.h"
#include "string.h"

class Cliente : public Persona
{
private:
    int _numeroDeSocio;
    Fecha _fechaDelAlta;
    Fecha _fechaLimiteParaPagarAbono;
    float _abonoMensual;
    int _nombreDeporte;
    bool _pesas;
    int _controlDeIngresosPesas;
    bool _estado;
//bool boxeo;
//bool yoga;

//string _actividad;

public:
    int getNumeroDeSocio();
    void setNumeroDeSocio(int nSocio);

    Fecha getFechaDelAlta();
    void setFechaDelAlta(Fecha f);

    float getAbonoMensual();
    void setAbonoMensual(float abonoM);

    void setNombreDeporte(int nombreDeporte);
    const char *getNombreDeporte();

    void cargarCliente();
    void mostrarCliente();

    void setPesas(bool pesas);
    bool getPesas();

    void setControl(int control);
    int getControl();

    void setEstado(bool estado);
    bool getEstado();

    void hacePesas();
    void establecerPlanMensual(int opcion);
    void calcularUnMesDeEntreno();
//string getNombreActividad();
//void setNombreDeActividad(string nombreAct);
};

#endif // CLIENTE_H
