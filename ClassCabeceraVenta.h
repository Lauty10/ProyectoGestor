#ifndef CLASSCABECERAVENTA_H_INCLUDED
#define CLASSCABECERAVENTA_H_INCLUDED
#include <string.h>

class CabeceraVentas{
private:
int idVendedor;
char nombreVendedor[30];
int dniVendedor;
int idCliente;
char nombreCliente[30];
int dniCliente;
public:
CabeceraVentas(int iV=0, const char* nV="", int dniV=0, int iC=0,const char* nC="", int dniC=0){
idVendedor=iV;
strcpy(this->nombreVendedor,nV);
dniVendedor=dniV;
idCliente=iC;
strcpy(this->nombreCliente,nC);
dniCliente=dniC;
}

void setIdVendedor(int i){
idVendedor=i;
}

void setNombreVendedor(char n[30]){
strcpy(this->nombreVendedor, n);
}

void setDniVendedor(int dV){
dniVendedor=dV;
}

void setIdCliente(int iC){
idCliente=iC;
}

void setNombreCliente(char nC[30]){
strcpy(this->nombreCliente, nC);
}

void setDniCliente(int dC){
dniCliente=dC;
}

int getIdVendedor(){
return idVendedor;
}

const char* getNombreVendedor(){
return nombreVendedor;
}

int getDniVendedor(){
return dniVendedor;
}

int getIdCliente(){
return idCliente;
}

const char* getNombreCliente(){
return nombreCliente;
}

int getDniCliente(){
return dniCliente;
}

};


#endif // CLASSCABECERAVENTA_H_INCLUDED
