#ifndef ARCHIVOAUTOS_H_INCLUDED
#define ARCHIVOAUTOS_H_INCLUDED
#include "ClassAuto.h"
#include <string>

class ArchivoAutos{
private:

std::string arAutos;
public:

ArchivoAutos(std::string archivoA){
arAutos=archivoA;
}


bool abrirArchivo(Auto autos){
FILE *pAuto = fopen(arAutos.c_str(), "ab");
if(pAuto == NULL){
return false;
}
bool ok = fwrite(&autos, sizeof(Auto), 1, pAuto);
fclose(pAuto);
return ok;
}


bool guardar(Auto autos, int posicion){
FILE *pAuto = fopen(arAutos.c_str(), "rb+");
if(pAuto== NULL){
return false;
}
fseek(pAuto, sizeof(Auto)*posicion, SEEK_SET);
bool ok = fwrite(&autos, sizeof(Autos), 1,pAuto);
fclose(pAuto);
return ok;
}


int buscarAuto(int idDelAuto){
FILE *pAuto = fopen(arAutos.c_str(), "rb");
if(pAuto == NULL){
return -1;
}
Auto autos;
int i=0;
while(fread(&autos, sizeof(Auto), 1, pAuto)){
if(autos.getId()==idDelAuto){
fclose(pAuto);
return i;
} i++;
}
fclose(pAuto);
return -1;
}


Auto leer(int posicion){
FILE *pAuto= fopen(arAutos.c_str(), "rb");
if(pAuto== NULL){
return Auto();
};
Auto autos;
fseek(pAuto, sizeof(Auto)*posicion, SEEK_SET);
fread(&autos, sizeof(Auto), 1, pAuto);
fclose(pAuto);
return autos;
}


int cantidadRegistros(){
FILE *pAuto=fopen(arAutos.c_str(),"rb");
if(pAuto==NULL){
return 0;
}
fseek(pAuto, 0, SEEK_END);
int cantidadRegistros=ftell(pAuto)/sizeof(Auto);
fclose(pAuto);
return cantidadRegistros;
}


void leer(int cantidadRegistros, Auto *vector){
FILE *pAuto=fopen(arAutos.c_str(),"rb");
if(pAuto==NULL){
return;
}
for(int i=0; i<cantidadRegistros; i++){
fread(&vector[i], sizeof(Auto), 1, pAuto);
}
fclose(pAuto);
}

};


#endif // ARCHIVOAUTOS_H_INCLUDED
