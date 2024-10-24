#include <iostream>
#include "ClassVendedores.h"
#include "Funciones.h"
#include "ClassCabezeraVenta.h"
#include "detalleVenta.h"
#include "ClassClientes.h"
#include <string>
#include "windows.h"

void LH();
void LH2();

//MENU
void menu(){
int opcion;
while(true){
 LH(); cout<<endl;
 cout<<"  BIENVENIDO AL SISTEMA GESTOR DE LA CONSESIONARIA"<<endl;
 LH();
 cout << R"(
                ______
              //  ||\ \
         ____//___||_\ \___
         )  _          _    \
         |_/ \________/ \___|
        ___\_/________\_/______
    )"; cout<<endl;

LH2();cout<<endl;
cout<<"1-)INICIAR SESION"<<endl;
LH2();cout<<endl;
cout<<"2-)REGISTRARSE"<<endl;
LH2();cout<<endl;
cout<<"3-)RECUPERAR CLAVE"<<endl;
LH2();cout<<endl;
cout<<"4-)SALIR DEL SISTEMA"<<endl;
LH2();cout<<endl;
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
    recuperarClave();
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
registro=fopen("registros.dat","rb");
if(registro==NULL){
cout<< "ERROR AL INTENTAR ABRIR EL ARCHIVO DE REGISTROS"<<endl;
return ;
}
Vendedores obj;
char correo[35];
char clave[20];

cout<<"Ingrese su correo:";
cin.ignore();
cin.getline(correo,35,'\n');
cout<<"Ingrese su clave:";
cin.ignore();
cin.getline(clave,20,'\n');

bool inicio=false;

while(fread(&obj, sizeof(Vendedores), 1, registro)!=0){
if(strcmp(obj.getCorreo(),correo)==0){
if(strcmp(obj.getClave(),clave)==0){
cout<<"EL INICIO DE SESION SE REALIZO CORRECTAMENTE"<<endl;
inicio=true;
break;
}
}
}
if(!inicio){
cout<<"UNO DE LOS DATOS INGRESADOS NO ES CORRECTO"<<endl;
system("pause");
system("cls");
}
fclose(registro);
system("pause");
system("cls");
if(inicio){
menuVendedores();
}
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
  int IdVendedor;
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
IdVendedor=nuevoId();
obj.setId(IdVendedor);
fwrite(&obj,sizeof(Vendedores),1,registro);
system("cls");
cout<<"Usuario dado de alta..."<<endl;
system("pause");
system("cls");
fclose(registro);
}

//RECUPERAR CLAVE
void recuperarClave(){
FILE *clave;
clave=fopen("registros.dat","rb+");
if(clave==nullptr){
cout<<"ERROR AL INTENTAR ABRIR EL ARCHIVO DE REGISTROS"<<endl;
return;
}
Vendedores objC;
int dni;
char correo[30];
char nuevaClave[30];
bool encontrado=false;
cout<<"Ingrese los siguientes datos para recuperar su clave: "<<endl;
LH();cout<<endl;
cout<<"D.N.I: ";
cin>>dni;
cout<<"Correo: ";
cin.ignore();
cin.getline(correo,30,'\n');
while(fread(&objC, sizeof(Vendedores),1,clave)!=0){
if(strcmp(objC.getCorreo(),correo)==0 && objC.getDni()==dni){
cout<<"Ingrese su nueva Clave:";
cin.ignore();
cin.getline(nuevaClave,30,'\n');
objC.setClave(nuevaClave);
long pos=ftell(clave)-sizeof(Vendedores);
fseek(clave,pos,SEEK_CUR);
fwrite(&objC, sizeof(Vendedores), 1, clave);
cout << "Su nueva clave fue guardada con exito" << endl;
encontrado=true;
break;

}
}
if(!encontrado){
cout<<"LOS DATOS INGRESADOS NO ESTAN EN LA BASE DE DATOS"<<endl;
}
fclose(clave);
system("pause");
system("cls");
}

//MENU VENDEDORES
void menuVendedores(){
int opcion;
while(true){
cout<<"BIEVENIDO AL SISTEMA DE LA CONSECIONARIA"<<endl;
LH(); cout<<endl;
cout<<"1-)DAR DE ALTA VEHICULO NUEVO"<<endl;
LH(); cout<<endl;
cout<<"2-)REALIZAR VENTA DE VEHICULO"<<endl;
LH(); cout<<endl;
cout<<"3-)DAR DE BAJA CLIENTE DEL SISTEMA"<<endl;
LH(); cout<<endl;
cout<<"4-)LISTAR VEHICULOS DISPONIBLES"<<endl;
LH(); cout<<endl;
cout<<"5-)LISTAR USUARIOS"<<endl;
LH(); cout<<endl;
cout<<"6-)MODIFICAR VEHICULOS"<<endl;
LH(); cout<<endl;
cout<<"7-)MODIFICAR CLIENTES"<<endl;
LH(); cout<<endl;
cout<<"8-)CERRAR SESION"<<endl;
LH(); cout<<endl;
cout<<"ELIGA LA OPCION QUE DESEE:";
cin>>opcion;

switch(opcion){

case 1:
    system("cls");
    Alta obj;
    obj.NuevoAuto();
    break;
case 2:
    system("cls");
    ventaVehiculo();
    break;
case 3:
    system("cls");
    BajaCliente objB;
    objB.darDeBajaCliente();
    break;
case 4:
    system("cls");
    AutosList objLista;
    objLista.stockAutos();
    break;
case 5:
    system("cls");
    Lista empleados;
    empleados.ListarEmpleados();
    break;
case 6:
    system("cls");
   AutosList objModificar;
   objModificar.realizarCambiosAutos();
    break;
case 7:
    break;
case 8:
    system("cls");
    return menu();
    break;
default:
    cout<<"La opcion elegida no es correcta"<<endl;
}
}
}

//FUNCION PARA LA VENTA DE VEHICULOS
void ventaVehiculo(){
int opcion;
while(true){
cout<<"VENTAS"<<endl;
LH(); cout<<endl;
cout<<"1)Registrar nuevo cliente"<<endl;
LH(); cout<<endl;
cout<<"2)Nueva venta"<<endl;
LH(); cout<<endl;
cin>>opcion;
switch(opcion){
case 1:
    system("cls");
AltaCliente obj1;
obj1.registrarCliente();
    break;
case 2:
    system("cls");
VentaC obj;
obj.cabezeraVenta();
VentaD objD;
objD.detallesVenta();
    break;
}
}
}
//FUNCION PARA CREAR ID UNICOS
int nuevoId(){
int nuevoIdentificador=0;
FILE *nuevo;
nuevo=fopen("registros.dat","rb");
if(nuevo==NULL){
    cout<<"Error al crear nuevo ID";
}
Vendedores obj;
while(fread(&obj,sizeof(Vendedores),1,nuevo)!=0){
    nuevoIdentificador++;
}
fclose(nuevo);
return nuevoIdentificador+1;
}

void LH(){ /// linea horizontal
    int i, tam;
    for (i = 0;i < 52;i++ )
        cout<<char(196);
}
void LH2(){
    int i, tam;
    for (i = 0;i < 61;i++ )
        cout<<char(196);
}
void LV(){ /// linea vertical
    int i, tam;
    for (i = 0;i < 1 ;i++ )
        cout<<char(179)<<endl;
}
