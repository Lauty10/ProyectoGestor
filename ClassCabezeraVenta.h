#ifndef CLASSCABEZERAVENTA_H_INCLUDED
#define CLASSCABEZERAVENTA_H_INCLUDED
#include <iostream>
#include <string.h>
#include "ClassFecha.h"
using namespace std;

class Cabezera{
private:
    int IdVendedor;
    char nombreVendedor[20];
    int idCliente;
    int dniCliente;
    char nombreCliente[20];
    int numVenta;
public:
    Cabezera(int id=0, const char* nombreV="XXX",int idC=0, int dniC=0, const char* nombreC="XXX", int numV=0){
    this->IdVendedor=id;
    strcpy(nombreVendedor,nombreV);
    strcpy(nombreCliente,nombreC);
    this->idCliente=idC;
    this->dniCliente=dniC;
    this->numVenta=numV;
    }
    void setIdVendedor(int id){
    this->IdVendedor=id;
    }
    void setNombreVendedor(char nombreV[20]){
    strcpy(nombreVendedor,nombreV);
    }
    void setIdCliente(int idC){
    this->idCliente=idC;
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
    int getIdCliente(){
    return idCliente;
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

class VentaC{
public:
void cabezeraVenta(){
FILE *cabecera;
cabecera=fopen("registros.dat","ab");
if(cabecera==NULL){
cout<< "ERROR AL INTENTAR ABRIR EL ARCHIVO DE REGISTROS"<<endl;
return ;
}
Cabezera obj;
static int numV=0;
int idV;
int idC;
cout<<"DATOS DE LA CABECERA DE VENTA: "<<endl;
cout<<"-------------------------------------------------------"<<endl;
cout<<"Ingrese el id del Vendedor: "<<endl;
cin>>idV;
obj.setIdVendedor(idV);
while(fread(&obj, sizeof(Cabezera), 1,cabecera) != 0){
if(obj.getIdVendedor()==idV){
cout<<"Nombre vendedor: "<<obj.getNombreVendedor()<<endl;
}}
cout<<"Ingrese el id del vendedor: "<<endl;
cin>>idC;
obj.setIdCliente(idC);
while(fread(&obj, sizeof(Cabezera),1,cabecera)!=0){
if(obj.getIdCliente()==idC){
cout<<"Nombre cliente: "<<obj.getNombreCliente();
cout<<"D.N.I cliente: "<<obj.getDniCliente();
}
}
cout<<"Numero de venta: "<<numV<<endl;
obj.setNumVenta(numV++);
fwrite(&obj, sizeof(Cabezera), 1, cabecera);
fclose(cabecera);
}
};

#endif // CLASSCABEZERAVENTA_H_INCLUDED
