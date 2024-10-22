#include <iostream>
#include "ClassVendedores.h"
#include "Funciones.h"
#include "ClassCabezeraVenta.h"
#include "detalleVenta.h"
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
cout<<"4-)SALIR DEL SISTEMA"<<endl;
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

//MENU VENDEDORES
void menuVendedores(){
int opcion;
while(true){
cout<<"BIEVENIDO AL SISTEMA DE LA CONSECIONARIA"<<endl;
cout<<"-------------------------------------------------------"<<endl;
cout<<"1-)DAR DE ALTA VEHICULO NUEVO"<<endl;
cout<<"-------------------------------------------------------"<<endl;
cout<<"2-)REALIZAR VENTA DE VEHICULO"<<endl;
cout<<"-------------------------------------------------------"<<endl;
cout<<"3-)DAR DE BAJA CLIENTE DEL SISTEMA"<<endl;
cout<<"-------------------------------------------------------"<<endl;
cout<<"4-)LISTAR VEHICULOS DISPONIBLES"<<endl;
cout<<"-------------------------------------------------------"<<endl;
cout<<"5-)LISTAR USUARIOS"<<endl;
cout<<"-------------------------------------------------------"<<endl;
cout<<"6-)MODIFICAR VEHICULOS"<<endl;
cout<<"-------------------------------------------------------"<<endl;
cout<<"7-)MODIFICAR CLIENTES"<<endl;
cout<<"-------------------------------------------------------"<<endl;
cout<<"8-)CERRAR SESION"<<endl;
cout<<"-------------------------------------------------------"<<endl;
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
    break;
case 4:
    break;
case 5:
    break;
case 6:
    break;
case 7:
    break;
case 8:
    break;
default:
    cout<<"La opcion elegida no es correcta"<<endl;
}
}
}

//FUNCION PARA LA VENTA DE VEHICULOS

void ventaVehiculo(){
cout<<"NUEVA VENTA"<<endl;
cout<<"-------------------------------------------------------"<<endl;
cabezeraVenta();
detallesVenta();
}

void cabezeraVenta(){
FILE *cabecera;
cabecera=fopen("registros.dat","ab");
if(cabecera==NULL){
cout<< "ERROR AL INTENTAR ABRIR EL ARCHIVO DE REGISTROS"<<endl;
return ;
}
Cabezera obj;
static int numV=0;
int idV;
char nombreV[20];
int dniC;
char nombreC[20];
cout<<"DATOS DE LA CABECERA DE VENTA:"<<endl;
cout<<"-------------------------------------------------------"<<endl;

cout<<"Ingrese el id del Vendedor: "<<endl;
cin>>idV;
obj.setIdVendedor(idV);

cout<<"Ingrese el nombre del vendedor: "<<endl;
cin.ignore();
cin.getline(nombreV,20, '\n');
obj.setNombreVendedor(nombreV);

cout<<"Ingrese el D.N.I del cliente: "<<endl;
cin>>dniC;
obj.setDniCliente(dniC);

cout<<"Ingrese el nombre del cliente: "<<endl;
cin.ignore();
cin.getline(nombreC,20, '\n');
obj.setNombreCliente(nombreC);

cout<<"Numero de venta: "<<numV<<endl;
obj.setNumVenta(numV++);


fwrite(&obj, sizeof(Cabezera), 1, cabecera);
fclose(cabecera);
}




void detallesVenta(){
cout<<"DATOS DE DETALLE DE VENTA:"<<endl;
cout<<"-------------------------------------------------------"<<endl;
FILE *detalles;
detalles=fopen("registros.dat","ab");
if(detalles==NULL){
cout<< "ERROR AL INTENTAR ABRIR EL ARCHIVO DE REGISTROS"<<endl;
return ;
}
Detalle obj1(0, 0.0f, "", "", "");
static int idVenta=0;
char modelo[20];
char marca[20];
char nombreA[20];
float iV;

cout<<"Id venta: "<<idVenta<<endl;
obj1.setIdVenta(idVenta++);

cout<<"Ingrese el modelo del auto: "<<endl;
cin.ignore();
cin.getline(modelo,20, '\n');
obj1.setModeloAuto(modelo);

cout<<"Ingrese la marca del auto: "<<endl;
cin.ignore();
cin.getline(marca,20, '\n');
obj1.setMarcaAuto(marca);

cout<<"Ingrese el nombre del auto: "<<endl;
cin.ignore();
cin.getline(nombreA,20, '\n');
obj1.setNombreAuto(nombreA);

detalles = fopen("detalles.dat", "rb");
if (detalles == NULL) {
cout << "ERROR AL INTENTAR ABRIR EL ARCHIVO DE DETALLES" << endl;
return;
}
while (fread(&obj1, sizeof(Detalle), 1, detalles) != 0){
if (strcmp(obj1.getModeloAuto(), modelo)==0 &&
strcmp(obj1.getMarcaAuto(), marca)==0 &&
strcmp(obj1.getNombreAuto(), nombreA)==0){
cout << "IMPORTE AUTO: " << obj1.getImporteVenta() << endl;
}
}
fclose(detalles);
detalles = fopen("detalles.dat", "ab");
if (detalles == NULL) {
cout << "ERROR AL INTENTAR ABRIR EL ARCHIVO DE DETALLES" << endl;
return;
}
fwrite(&obj1, sizeof(Detalle), 1, detalles);
fclose(detalles);

 system("pause");
}
