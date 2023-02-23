/* 
Nombre: Daniela Sanabria.
Fecha: Febrero 15.
Ejercicio: Captura de datos de cliente para imprimir en una factura. Se requiere crear una estructura de datos que encapsule los datos de los usuarios. Se requiere que el uso de la estrutura sea a través de punteros. Imprimir facturas en un fichero de texto.

1.- Hacer funciones por separado
2.- Anunciar/Documentar acciones
3.- Identificar su fichero fuente .cpp
4.- Subir el fichero fuente a un repositorio.
*/
#include <iostream>
#include <fstream>
using namespace std;
struct datos{ //Se crea estructura para saber los datos de los usuarios
  string nombre;
  string apellido;
  int cedula;
  int totalfactura;
  string frecuente;
  };
void llenar(int cant, datos cliente[cant]);
void imprimir(int cant, datos cliente[cant]);
int main() {
  string llena;
  int cant;
  cout<<"¿Cuántos clientes desea registar? ";
  cin>>cant;
  datos cliente[cant];
  llenar(cant, cliente);
  cout<<"A continuación se imprimirán los datos ";
  imprimir(cant, cliente);
}

void llenar(int cant, datos cliente[cant]){
  for(int i=0;i<cant;i++){
    cout<<"Cuál es el nombre del cliente? ";
    cin>>cliente[i].nombre;
    cout<<"Cuál es el apellido del cliente? ";
    cin>>cliente[i].apellido;
    cout<<"Cuál es la cédula del cliente? ";
    cin>>cliente[i].cedula;
    cout<<"Cuál es total de la factura del cliente? ";
    cin>>cliente[i].totalfactura;
    cout<<"Este es un cliente frecuente? ";
    cin>>cliente[i].frecuente;
    cout<<endl;
    }
}
void imprimir(int cant, datos cliente[cant]){
  int *apuntadorcedula, *apuntadortotalfactura;
  string *apuntadorfrecuente, *apuntadornombre, *apuntadorapellido;
  ofstream archivo;
  for(int j=0;j<cant;j++){
    apuntadornombre=&cliente[j].nombre;
    apuntadorapellido=&cliente[j].apellido;
    apuntadorcedula=&cliente[j].cedula;
    apuntadortotalfactura=&cliente[j].totalfactura;
    apuntadorfrecuente=&cliente[j].frecuente;

    archivo.open("archivodatos.txt", ios::out);
  for(int i=0;i<cant;i++){
    archivo<<"Nombre: "<<*apuntadornombre<<endl;
    archivo<<"Apellido: "<<*apuntadorapellido<<endl;
    archivo<<"Cédula: "<<*apuntadorcedula<<endl;
    archivo<<"Total factura: "<<*apuntadortotalfactura<<endl;
    archivo<<"Frecuente: "<<*apuntadorfrecuente<<endl;
    }
  }
  archivo.close();
}