#ifndef CLASSAUTO_H_INCLUDED
#define CLASSAUTO_H_INCLUDED
#include <string.h>

using namespace std;

class Auto{
private:
    int idDelAuto;
    char nombreAuto[20];
    char modeloAuto[20];
    char marcaAuto[20];
    int anioAuto;
    float precioAuto;
public:
    Auto(int id=0, const char* nombreA="XXX", const char* modeloA="XXX", const char* marcaA="XXX", int anioA=0, float precioA=0.0){
    this->idDelAuto=id;
    strcpy(this->nombreAuto,nombreA);
    strcpy(this->modeloAuto,modeloA);
    strcpy(this->marcaAuto,marcaA);
    this->anioAuto=anioA;
    this->precioAuto=precioA;
    }
    void setIdAuto(int id){
    this->idDelAuto=id;
    }
    void setNombreAuto(char nombreA[20]){
    strcpy(this->nombreAuto,nombreA);
    }
    void setModeloAuto(char modeloA[20]){
    strcpy(this->modeloAuto,modeloA);
    }
    void setMarcaAuto(char marcaA[20]){
    strcpy(this->marcaAuto,marcaA);
    }
    void setAnio(int anioA){
    this->anioAuto=anioA;
    }
    void setPrecioAuto(float precioA){
    this->precioAuto=precioA;
    }
    int getId(){
    return idDelAuto;
    }
    const char* getNombreAuto(){
    return nombreAuto;
    }
    const char* getModeloAuto(){
    return modeloAuto;
    }
    const char* getMarcaAuto(){
    return marcaAuto;
    }
    int getAnioAuto(){
    return anioAuto;
    }
    float getPrecioAuto(){
    return precioAuto;
    }
};

class Alta{
public:
 void NuevoAuto(){
 FILE *vehiculo;
 vehiculo=fopen("C:\\Users\\Lauty\\OneDrive\\Escritorio\\ProyectoGestor\\vehiculos.dat","ab");
 if(vehiculo==NULL){
    cout<<"Error al intentar cargar vehiculo"<<endl;
 }
  Auto nuevoVehiculo;
  int idDelAuto;
  char nombreAuto[20];
  char modeloAuto[20];
  char marcaAuto[20];
  int anioAuto;
  float precioAuto;
  cout<<"Ingrese el ID del auto:";
  cin>>idDelAuto;
  cout<<"Ingrese el nombre del auto:";
  cin.ignore();
  cin.getline(nombreAuto,20,'\n');
  cout<<"Ingrese el modelo del auto:";
  cin.ignore();
  cin.getline(modeloAuto,20,'\n');
  cout<<"Ingrese la marca del auto:";
  cin.ignore();
  cin.getline(marcaAuto,20,'\n');
  cout<<"Ingrese el anio de fabricacion del auto:";
  cin>>anioAuto;
  cout<<"Ingrese el precio del auto:";
  cin>>precioAuto;
  fwrite(&nuevoVehiculo,sizeof(Auto),1,vehiculo);
  cout<<"Vehiculo cargado....";
  fclose(vehiculo);
 }
};

#endif // CLASSAUTO_H_INCLUDED
