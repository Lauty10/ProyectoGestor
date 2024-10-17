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
    Auto(int id, const char* nombreA, const char* modeloA, const char* marcaA, int anioA, float precioA){
    this->idDelAuto=id;
    strcpy(this->nombreAuto,nombreA);
    strcpy(this->modeloAuto,modeloA);
    strcpy(this->marcaAuto,marcaA);
    this->anioAuto=anioA;
    this->precioAuto=precioA;
    }
    void setIdAuto(int id){
    this->idDelAuto=id;
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
    void setAnio(int anioA){
    this->anioAuto=anioA;
    }
    void setPrecioAuto(float precioA){
    this->precioAuto=precioA;
    }
    int getId(){
    return idDelAuto;
    }
    const char* getNombreAuto(){
    return nombreAuto;
    }
    const char* getModeloAuto(){
    return modeloAuto;
    }
    const char* getMarcaAuto(){
    return marcaAuto;
    }
    int getAnioAuto(){
    return anioAuto;
    }
    float getPrecioAuto(){
    return precioAuto;
    }
};

#endif // CLASSAUTO_H_INCLUDED
