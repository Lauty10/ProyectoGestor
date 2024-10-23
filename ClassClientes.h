#ifndef CLASSCLIENTES_H_INCLUDED
#define CLASSCLIENTES_H_INCLUDED
#include <string.h>
#include <iostream>
using namespace std;

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
    //bool getRolCliente(){
    //return false;
    //}
    const char* getRolCliente(){
    return rol;
    }
    ~Clientes(){};
};

class AltaCliente{
public:
void registrarCliente(){
FILE *cliente;
cliente=fopen("cliente.dat","ab");
if(cliente==NULL){
cout<<"Error al intentar dar de alta a un nuevo cliente"<<endl;
}

Clientes obj;
static int idC=0;
char nombreC[30];
int dniC;
char correoC[35];
//char rol[4];
cout<<"INGRESE LOS DATOS DEL CLIENTE A REGISTRAR:"<<endl;
cout<<"-------------------------------------------------------"<<endl;
cout<<"Nombre: ";
cin.ignore();
cin.getline(nombreC,30,'\n');
obj.setNombreCliente(nombreC);
cout<<"D.N.I: ";
cin>>dniC;
obj.setDni(dniC);
cout<<"Correo: ";
cin.ignore();
cin.getline(correoC,35,'\n');
obj.setCorreoCliente(correoC);
cout<<"ID: "<<idC<<endl;
obj.setIdCliente(idC++);

fwrite(&obj,sizeof(Clientes),1,cliente);
cout<<"EL nuevo cliente fue registrado en el sistema "<<endl;
system("pause");
system("cls");
fclose(cliente);

}
};

#endif // CLASSCLIENTES_H_INCLUDED
