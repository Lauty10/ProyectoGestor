#ifndef ARCHIVOCLIENTES_H_INCLUDED
#define ARCHIVOCLIENTES_H_INCLUDED
#include "ClassClientes.h"
#include <string>

class ArchivoClientes{
private:

std::string arClientes;
public:

ArchivoClientes(std::string archivoC){
arClientes=archivoC;
}


bool abrirArchivo(Clientes cliente){
FILE *pCliente = fopen(arClientes.c_str(), "ab");
if(pCliente == NULL){
return false;
}
bool ok = fwrite(&cliente, sizeof(Clientes), 1, pCliente);
fclose(pCliente);
return ok;
}


bool guardar(Clientes cliente, int posicion){
FILE *pCliente = fopen(arClientes.c_str(), "rb+");
if(pCliente == NULL){
return false;
}
fseek(pCliente, sizeof(Clientes)*posicion, SEEK_SET);
bool ok = fwrite(&cliente, sizeof(Clientes), 1,pCliente);
fclose(pCliente);
return ok;
}


int buscarCliente(int idCliente){
FILE *pCliente = fopen(arClientes.c_str(), "rb");
if(pCliente == NULL){
return -1;
}
Clientes cliente;
int i=0;
while(fread(&cliente, sizeof(Clientes), 1, pCliente)){
if(cliente.getIdCliente()==idCliente){
fclose(pCliente);
return i;
} i++;
}
fclose(pCliente);
return -1;
}


Clientes leer(int posicion){
FILE *pCliente= fopen(arClientes.c_str(), "rb");
if(pClientes == NULL){
return Clientes();
}
Clientes cliente;
fseek(pCliente, sizeof(Clientes)*posicion, SEEK_SET);
fread(&cliente, sizeof(Clientes), 1, pCliente);
fclose(pCliente);
return cliente;
}


int cantidadRegistros(){
FILE *pCliente=fopen(arClientes.c_str(),"rb");
if(pCliente==NULL){
return 0;
}
fseek(pCliente, 0, SEEK_END);
int cantidadRegistros=ftell(pCliente)/sizeof(Clientes);
fclose(pCliente);
return cantidadRegistros;
}


void leer(int cantidadRegistros, Clientes *vector){
FILE *pCliente=fopen(arClientes.c_str(),"rb");
if(pCliente==NULL){
return;
}
for(int i=0; i<cantidadRegistros; i++){
fread(&vector[i], sizeof(Clientes), 1, pCliente);
}
fclose(pCliente);
}

};
#endif // ARCHIVOVENDEDORES_H_INCLUDED


#endif // ARCHIVOCLIENTES_H_INCLUDED
