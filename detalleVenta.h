#ifndef DETALLEVENTA_H_INCLUDED
#define DETALLEVENTA_H_INCLUDED
#include <string.h>

class Detalle{
private:
    int idVenta;
    float importeVenta;
    char modeloAuto[20];
    char marcaAuto[20];
    char nombreAuto[20];
public:
    Detalle(int id, float importeV, const char* modeloA, const char* marcaA, const char* nombreA){
    this->idVenta=id;
    this->importeVenta=importeV;
    strcpy(modeloAuto,modeloA);
    strcpy(marcaAuto,marcaA);
    strcpy(nombreAuto,nombreA);
    }
    void setIdVenta(int id){
    this->idVenta=id;
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
    return id;
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

#endif // DETALLEVENTA_H_INCLUDED
