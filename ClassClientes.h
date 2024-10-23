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
    bool rol=false;
public:
    Clientes(int idC=0,const char* nombreC="XXX",int dniC=1000000, const char* correoC="cliente123@gmail.com",const char* claveC="12345678",bool rol=false){
    this->idCliente=idC;
    strcpy(this->nombreCliente,nombreC);
    this->dni=dniC;
    strcpy(this->correoCliente,correoC);
    strcpy(this->claveCliente,claveC);
    this->rol=rol;
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
    void setRol(bool rol){
    this->rol=rol;
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
    bool getRolCliente(){
    return rol;
    }
    //const char* getRolCliente(){
    //return rol;
    //}
    ~Clientes(){};
};

class AltaCliente{
public:
void registrarCliente(){
FILE *cliente;
cliente=fopen("cliente.dat","ab");
if(cliente==NULL){
cout<<"Error al intentar abrir este archivo"<<endl;
return;
}

Clientes obj;
static int idC=0;
char nombreC[30];
int dniC;
char correoC[35];
bool rol;
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

rol=true;
obj.setRol(rol);
fwrite(&obj,sizeof(Clientes),1,cliente);
cout<<"EL nuevo cliente fue registrado en el sistema "<<endl;
system("pause");
system("cls");
fclose(cliente);

}
};


class BajaCliente{
public:
void darDeBajaCliente(){
FILE *baja;
baja=fopen("cliente.dat","rb+");
if(baja==NULL){
cout<<"Error al intentar abrir este archivo"<<endl;
return;
}
Clientes obj;
int idC;
bool encontrado=false;
bool rol=true;
cout<<"DAR DE BAJA"<<endl;
cout<<"-------------------------------------------------------"<<endl;
cout<<"Ingrese el id del cliente a dar de baja:"<<endl;
cout<<"-------------------------------------------------------"<<endl;
cin>>idC;
while(fread(&obj, sizeof(Clientes),1,baja)!=0){
 if(obj.getIdCliente()==idC){
cout<<"Los datos del cliente a dar de baja"<<endl;
cout<<"-------------------------------------------------------"<<endl;
cout<<"Nombre: "<<obj.getNombreCliente()<<endl;
cout<<"D.N.I: "<<obj.getDni()<<endl;
cout<<"Correo: "<<obj.getCorreoCliente()<<endl;
rol=false;
obj.setRol(rol);
fseek(baja,-sizeof(Clientes), SEEK_CUR);
fwrite(&obj, sizeof(Clientes), 1, baja);
encontrado=true;
}
}
if(!encontrado){
cout<<"EL ID INGRESADO NO FUE ENCONTRADO"<<endl;
}
fclose(baja);
}
};
#endif // CLASSCLIENTES_H_INCLUDED
