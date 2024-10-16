#ifndef CLASSCLIENTES_H_INCLUDED
#define CLASSCLIENTES_H_INCLUDED

#include <string.h>

class Clientes{
private:
    int idCliente;
    char nombreCliente[30];
    int dni;
    char correoCliente[35];
    char claveCliente[25];
    char rol[4];
public:
    Clientes(int idC=0,const char* nombreC="XXX",int dniC=1000000, const char* correoC="cliente123@gmail.com",const char* claveC="12345678",const char* rol="user"){
    this->idCliente=idC;
    strcpy(this->nombreCliente,nombreC);
    this->dni=dniC;
    strcpy(this->correoCliente,correoC);
    strcpy(this->claveCliente,claveC);
    strcpy(this->rol,rol);
    }
    void setIdCliente(int idC){
    this->idCliente=idC;
    }
    void setNombreCliente(char nombreC[30]){
    strcpy(this->nombreCliente,nombreC);
    }
    void setDni(int dniC){
    this->dni=dniC;
    }
    void setCorreoCliente(char correoC[35]){
    strcpy(this->correoCliente,correoC);
    }
    void setClaveCliente(char claveC[25]){
    char claveCliente[25];
    }
    void setRol(char rol[4]){
    strcpy(this->rol,rol);
    }
    int getIdCliente(){
    return idCliente;
    }
    const char* getNombreCliente(){
    return nombreCliente;
    }
    int getDni(){
    return dni;
    }
    const char* getCorreoCliente(){
    return correoCliente;
    }
    const char* getClaveCliente(){
    return claveCliente;
    }
    const char* getRolCliente(){
    return rol;
    }
};

#endif // CLASSCLIENTES_H_INCLUDED
