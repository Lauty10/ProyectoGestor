#ifndef CLASSAUTO_H_INCLUDED
#define CLASSAUTO_H_INCLUDED
#include <string.h>

class Auto{
private:
int idDeAuto;
char nombreA[30];
char modelo[30];
char marca[30];
int anio;
float precio;

public:
Auto(int i=0, const char* nA="", const char* m="", const char* mar="", int a=0, float p=0){
idDeAuto=i;
strcpy(this->nombreA,nA);
strcpy (this->modelo,m);
strcpy (this->marca,mar);
anio=a;
precio=p;
}
void setIdDeAuto(int idA){
idDeAuto=idA;
};
void setNombreA(char nAuto[30]){
strcpy(this->nombreA,nAuto);
}
void setModelo(char mAuto[30]){
strcpy(this->modelo,mAuto);
}
void setMarca(char marcaA[30]){
strcpy(this->marca,marcaA);
}
void setAnio(int a){
anio=a;
}
void setPrecio(float p){
precio=p;
}
int getIdDeAuto(){
return idDeAuto;
}
const char* getNombre(){
return nombreA;
}
const char* getModelo(){
return modelo;
}
const char* getMarca(){
return marca;
}
int getAnio(){
return anio;
}
float getPrecio(){
return precio;
}
};
#endif // CLASSAUTO_H_INCLUDED
