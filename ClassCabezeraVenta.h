#ifndef CLASSCABEZERAVENTA_H_INCLUDED
#define CLASSCABEZERAVENTA_H_INCLUDED
#include <string.h>

class Cabezera{
private:
    int IdVendedor;
    char nombreVendedor[20];
    int dniCliente;
    char nombreCliente[20];
    int numVenta;
public:
    Cabezera(int id=0, const char* nombreV="XXX", int dniC=0, const char* nombreC="XXX", int numV=0){
    this->IdVendedor=id;
    strcpy(nombreVendedor,nombreV);
    strcpy(nombreCliente,nombreC);
    this->dniCliente=dniC;
    this->numVenta=numV;
    }
    void setIdVendedor(int id){
    this->IdVendedor=id;
    }
    void setNombreVendedor(char nombreV[20]){
    strcpy(nombreVendedor,nombreV);
    }
    void setDniCliente(int dniC){
    this->dniCliente=dniC;
    }
    void setNombreCliente(char nombreC[20]){
    strcpy(nombreCliente,nombreC);
    }
    void setNumVenta(int numV){
    this->numVenta=numV;
    }
    int getIdVendedor(){
    return IdVendedor;
    }
    const char* getNombreVendedor(){
    return nombreVendedor;
    }
    int getDniCliente(){
    return dniCliente;
    }
    const char* getNombreCliente(){
    return nombreCliente;
    }
    int getNumVenta(){
    return numVenta;
    }
};

#endif // CLASSCABEZERAVENTA_H_INCLUDED
