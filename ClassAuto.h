#ifndef CLASSAUTO_H_INCLUDED
#define CLASSAUTO_H_INCLUDED
#include <string.h>

class Auto{
private:
    int idDelAuto;
    char nombreAuto[20];
    char modeloAuto[20];
    char marcaAuto[20];
    int anioAuto;
    float precioAuto;
public:
    Auto(int idDelAuto=0, const char* nombreA="XXX", const char* modeloA="XXX",const char* marcaA="XXX",int anioA=0,float precioA=0.0){
    this->idDelAuto=idDelAuto;
    strcpy(this->nombreAuto,nombreA);
    strcpy(this->modeloAuto,modeloA);
    strcpy(this->marcaAuto,marcaA);
    this->anioAuto=anioA;
    this->precioAuto=precioA;
    }
    void setIdDelAuto(int idDelAuto){
    this->idDelAuto=idDelAuto;
    }
    void setNombreAuto(char nombreA[20]){
    strcpy(this->nombreAuto,nombreA);
    }
    void setModeloAuto(char modeloA[20]){
    strcpy(this->modeloAuto,modeloA);
    }
    void setMarcaAuto(char marcaA[20]){
    strcpy(this->marcaAuto,marcaA);
    }
    void setAnioAuto(int anioA){
    this->anioAuto=anioA;
    }
    void setPrecioAuto(float precioA){
    this->precioAuto=precioA;
    }
    int getIdAuto(){
    return idDelAuto;
    }
    const char* getNombreAuto(){
    return nombreAuto;
    }
    const char* getMarcaAuto(){
    return marcaAuto;
    }
    const char* getModeloAuto(){
    return modeloAuto;
    }
    int getAnioAuto(){
    return anioAuto;
    }
    float getPrecioAuto(){
    return precioAuto;
    }
};

#endif // CLASSAUTO_H_INCLUDED
