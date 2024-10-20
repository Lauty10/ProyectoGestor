#ifndef ARCHIVOVENDEDORES_H_INCLUDED
#define ARCHIVOVENDEDORES_H_INCLUDED
#include <string>
#include "ClassVendedores.h"

class ArchivoVendedores{
private:

std::string arVendedores;
public:

ArchivoVendedores(std::string archivoV){
arVendedores=archivoV;
}


bool abrirArchivo(Vendedores vendedor){
FILE *pVendedor = fopen(arVendedores.c_str(), "ab");
if(pVendedor == NULL){
return false;
}
bool ok = fwrite(&vendedor, sizeof(Vendedores), 1, pVendedor);
fclose(pVendedor);
return ok;
}


bool guardar(Vendedores vendedor, int posicion){
FILE *pVendedor = fopen(arVendedores.c_str(), "rb+");
if(pVendedor == NULL){
return false;
}
fseek(pVendedor, sizeof(Vendedores)*posicion, SEEK_SET);
bool ok = fwrite(&vendedor, sizeof(Vendedores), 1, pVendedor);
fclose(pVendedor);
return ok;
}


int buscarVendedor(int idVendedor){
FILE *pVendedor = fopen(arVendedores.c_str(), "rb");
if(pVendedor == NULL){
return -1;
}
Vendedores vendedor;
int i=0;
while(fread(&vendedor, sizeof(Vendedores), 1, pVendedor)){
if(vendedor.getIdVendedor()==idVendedor){
fclose(pVendedor);
return i;
} i++;
}
fclose(pVendedor);
return -1;
}


Vendedores leer(int posicion){
FILE *pVendedor= fopen(arVendedores.c_str(), "rb");
if(pVendedor == NULL){
return Vendedores();
}
Vendedores vendedor;
fseek(pVendedor, sizeof(Vendedores)*posicion, SEEK_SET);
fread(&vendedor, sizeof(Vendedores), 1, pVendedor);
fclose(pVendedor);
return vendedor;
}


int CantidadRegistros(){
FILE *pVendedor=fopen(arVendedores.c_str(),"rb");
if(pVendedor==NULL){
return 0;
}
fseek(pVendedor, 0, SEEK_END);
int cantidadRegistros=ftell(pVendedor)/sizeof(Vendedores);
fclose(pVendedor);
return cantidadRegistros;
}


void Leer(int cantidadRegistros, Vendedores *vector){
FILE *pVendedor=fopen(arVendedores.c_str(),"rb");
if(pVendedor==NULL){
return;
}
for(int i=0; i<cantidadRegistros; i++){
fread(&vector[i], sizeof(Vendedores), 1, pVendedor);
}
fclose(pVendedor);
}

};
#endif // ARCHIVOVENDEDORES_H_INCLUDED
