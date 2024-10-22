#ifndef CLASSVENDEDORES_H_INCLUDED
#define CLASSVENDEDORES_H_INCLUDED
#include <string.h>

using namespace std;

class Vendedores{
private:
    int idVendedor;
    char nombre[30];
    int dni;
    char correo[35];
    char clave[20];
    char rol[6];
public:
    Vendedores(int i=0, const char* n="XXX", int d=1000000,const char * c="usuariox@gmail.com",const char* claveV="123456789",const char* r="seller"){
    this->idVendedor=i;
    strcpy(this->nombre,n);
    this->dni=d;
    strcpy(this->correo,c);
    strcpy(this->clave,claveV);
    strcpy(this->rol,r);
    }
    void setId(int idV){
    this->idVendedor=idV;
    };
    void setNombre(char nombre[30]){
    strcpy(this->nombre,nombre);
    };
    void setDni(int dni){
    this->dni=dni;
    };
    void setCorreo(char correo[35]){
    strcpy(this->correo,correo);
    };
    void setClave(char clave[20]){
    strcpy(this->clave,clave);
    };
    void setRol(char rol[6]){
    strcpy(this->rol,rol);
    };
    int getIdVendedor(){
    return idVendedor;
    }
    const char* getNombre(){
    return nombre;
    }
    int getDni(){
    return dni;
    }
    const char* getCorreo(){
    return correo;
    }
    const char* getClave(){
    return clave;
    }
    const char* getRol(){
    return rol;
    }
};

class Lista{
public:
    void ListarEmpleados(){
    FILE *empleados;
    empleados=fopen("registros.dat","rb");
    if(empleados==NULL){
        cout<<"Error al intentar listar empleados"<<endl;
    }
    Vendedores obj;
    while(fread(&obj,sizeof(Vendedores),1,empleados)!=0){
        cout<<"EL ID DEL VENDEDOR ES:"<<obj.getIdVendedor()<<endl;
        cout<<"EL NOMBRE DEL VENDEDOR ES:"<<obj.getNombre()<<endl;
        cout<<"EL DNI DEL EMPLEADO ES:"<<obj.getDni()<<endl;
        cout<<"EL ROL DEL EMPLEADO ES:"<<obj.getRol()<<endl;
        cout<<"-------------------------------------------------------------------"<<endl;
    }
    fclose(empleados);
    cout<<endl;
    cout<<"Estos son todos los vendedores..."<<endl;
    system("pause");
    system("cls");
    }
};
#endif // CLASSVENDEDORES_H_INCLUDED
