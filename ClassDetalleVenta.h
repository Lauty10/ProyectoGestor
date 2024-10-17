#ifndef CLASSDETALLEVENTA_H_INCLUDED
#define CLASSDETALLEVENTA_H_INCLUDED
#include <string.h>

class DetalleVentas{
private:
float importeVenta;
int idVenta;
char modelo[30];
char marca[30];
char nombre[30];
public:
DetalleVentas(float iV=0, int idV=0, const char* m[30]="", const char* marcaA[30]="", const char* n[30]=""){
importeVenta=iV;
idVenta=idV;
strcpy(this->modelo,m);
strcpy(this->marca, marcaA);
strcpy(this->nombre, n);
}

void setImporteVenta(float i){
importeVenta=i;
}

void setIdVenta(int id){
idVenta=id;
}

void setModelo(char m[30]){
strcpy(this->modelo,m);
}

void setMarca(char mA[30]){
strcpy(this->marca,mA);
}
void setNombre(char nombreA[30]){
strcpy(this->nombre, nombreA);
}
float getImporteVenta(){
return importeVenta;
}

int getIdVenta(){
return idVenta;
}

const char* getModelo(){
return modelo;
}

const char* getMarca(){
return marca;
}

const char* getNombre(){
return nombre;
}
};


#endif // CLASSDETALLEVENTA_H_INCLUDED
