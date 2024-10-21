#include <iostream>
#include "ClassVendedores.h"
#include "Funciones.h"

using namespace std;

//MENU

void menu(){
int opcion;
while(true){
cout<<"BIENVENIDO AL SISTEMA GESTOR DE LA CONSESIONARIA"<<endl;
cout<<"-------------------------------------------------------------"<<endl;
cout<<"1-)INICIAR SESION"<<endl;
cout<<"-------------------------------------------------------------"<<endl;
cout<<"2-)REGISTRARSE"<<endl;
cout<<"-------------------------------------------------------------"<<endl;
cout<<"3-)RECUPERAR CLAVE"<<endl;
cout<<"-------------------------------------------------------------"<<endl;
cout<<"SALIR DEL SISTEMA"<<endl;
cout<<"-------------------------------------------------------------"<<endl;
cout<<"INGRESE LA OPCION QUE DESEE:";
cin>>opcion;
switch(opcion){
case 1:
    system("cls");
    iniciarSesion();
    break;
case 2:
    system("cls");
    registrarse();
    break;
case 3:
    system("cls");
    break;
case 4:
    return;
default:
    cout<<"Opcion invalida...";
}
}
}

//INICIAR SESION
void iniciarSesion(){
FILE *registro;
registro=fopen("C:\\Users\\Lauty\\OneDrive\\Escritorio\\ProyectoGestor\\registros.dat","rb");
if(registro==NULL){
cout<< "ERROR AL INTENTAR ABRIR EL ARCHIVO DE REGISTROS"<<endl;
return ;
}
Vendedores obj;
  char nombre[30];
  int dni;
  char correo[35];
  char clave[20];

cout<<"Ingrese su nombre:";
cin.ignore();
cin.getline(nombre,30,'\n');
obj.setNombre(nombre);

cout<<"Ingrese su dni:";
cin>>dni;
obj.setDni(dni);

cout<<"Ingrese su correo:";
cin.ignore();
cin.getline(correo,35,'\n');
obj.setCorreo(correo);

cout<<"Ingrese su clave:";
cin.ignore();
cin.getline(clave,20,'\n');
obj.setClave(clave);

bool inicio=false;

while (fread(&obj, sizeof(Vendedores), 1, registro) == 1){
if(strcmp(obj.getNombre(),nombre)==0&& obj.getDni()==dni&&strcmp(obj.getCorreo(),correo)==0&& strcmp(obj.getClave(), clave)==0 ){
cout<<"EL INICIO DE SESION SE REALIZO CORRECTAMENTE"<<endl;
inicio=true;
break;
}
}
if(!inicio){
cout<<"UNO DE LOS DATOS INGRESADOS NO ES CORRECTO"<<endl;
}
fclose(registro);
system("pause");
}


//REGISTRARSE EN EL SISTEMA
void registrarse(){
FILE *registro;
registro=fopen("C:\\Users\\Lauty\\OneDrive\\Escritorio\\ProyectoGestor\\registros.dat","ab");
if(registro==nullptr){
    cout<<"ERROR AL CREAR UN ARCHIVO DE REGISTROS"<<endl;
}
Vendedores obj;
  char nombre[30];
  int dni;
  char correo[35];
  char clave[20];
cout<<"Ingrese su nombre:";
cin.ignore();
cin.getline(nombre,30,'\n');
obj.setNombre(nombre);
cout<<"Ingrese su dni:";
cin>>dni;
obj.setDni(dni);
cout<<"Ingrese su correo:";
cin.ignore();
cin.getline(correo,35,'\n');
obj.setCorreo(correo);
cout<<"Ingrese su clave:";
cin.ignore();
cin.getline(clave,20,'\n');
obj.setClave(clave);
fwrite(&obj,sizeof(Vendedores),1,registro);
system("cls");
cout<<"Usuario dado de alta..."<<endl;
system("pause");
system("cls");
fclose(registro);
}
