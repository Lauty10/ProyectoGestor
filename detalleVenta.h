#ifndef DETALLEVENTA_H_INCLUDED
#define DETALLEVENTA_H_INCLUDED
#include <iostream>
#include <string.h>
using namespace std;

class Detalle{
private:
    int idVenta;
    int idAuto;
    float importeVenta;
    char modeloAuto[20];
    char marcaAuto[20];
    char nombreAuto[20];
public:
    Detalle(int id,int idA, float importeV, const char* modeloA, const char* marcaA, const char* nombreA){
    this->idVenta=id;
    this->idAuto=idA;
    this->importeVenta=importeV;
    strcpy(modeloAuto,modeloA);
    strcpy(marcaAuto,marcaA);
    strcpy(nombreAuto,nombreA);
    }
    void setIdVenta(int id){
    this->idVenta=id;
    }
    void setIdAuto(int idA){
    this->idAuto=idA;
    }
    void setImporteVenta(float importeV){
    this->importeVenta=importeV;
    }
    void setModeloAuto(char modeloA[20]){
    strcpy(modeloAuto,modeloA);
    }
    void setMarcaAuto(char marcaA[20]){
    strcpy(marcaAuto,marcaA);
    }
    void setNombreAuto(char nombreA[20]){
    strcpy(nombreAuto,nombreA);
    }
    int getId(){
    return idVenta;
    }
    int getIdAuto(){
    return idAuto;
    }
    float getImporteVenta(){
    return importeVenta;
    }
    const char* getModeloAuto(){
    return modeloAuto;
    }
    const char* getMarcaAuto(){
    return marcaAuto;
    }
    const char* getNombreAuto(){
    return nombreAuto;
    }
    ~Detalle(){};
};

class VentaD{
public:
void detallesVenta(){
cout<<"DATOS DE DETALLE DE VENTA:"<<endl;
cout<<"-------------------------------------------------------"<<endl;
FILE *detalles;
detalles=fopen("registros.dat","rb");
if(detalles==NULL){
cout<< "ERROR AL INTENTAR ABRIR EL ARCHIVO DE REGISTROS"<<endl;
return ;
}
Detalle obj(0, 0, 0.0f, "Modelo", "Marca", "Nombre");
static int idVenta=0;
int idA;
char modelo[20];
char marca[20];
char nombreA[20];
float iV;
cout<<"Id venta: "<<idVenta<<endl;
obj.setIdVenta(idVenta++);
cout<<"Ingrese el id del auto: ";
cin>>idA;
obj.setIdAuto(idA);

while(fread(&obj, sizeof(Detalle),1,detalles)!=0){
if(obj.getIdAuto()==idA){
cout<<"Modelo del auto: "<<obj.getModeloAuto();
cout<<"Marca del auto: "<<obj.getMarcaAuto();
cout<<"Nombre del auto: "<<obj.getNombreAuto();
}
}
cout<<"Importe Venta: "<<obj.getImporteVenta();

fwrite(&obj, sizeof(Detalle), 1, detalles);
fclose(detalles);
}
};

#endif // DETALLEVENTA_H_INCLUDED
