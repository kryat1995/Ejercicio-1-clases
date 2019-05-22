#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<conio.h>
using namespace std;

#include"funciones/fechas.h"
#include"funciones/tinturas.h"
int main(){
  int choice;
  while(true){
    system("cls");
    cout<<"MENU PRINCIPAL"<<endl;
    cout<<"----------"<<endl;
    cout<<"1)cargar"<<endl;
    cout<<"2)mostrar"<<endl;
    cout<<"3)Punto Unico"<<endl;
    cout<<"----------"<<endl;
    cout<<"0)SALIR."<<endl;
    cout<<"opcion: ";
    cin>>choice;
    system("cls");
    switch(choice){
      case 1:
        AgregarTintura();
      ;break;
      case 2:
        ListarTintura();
      ;break;
      case 3:
        PuntoUnico();
      ;break;
      case 0:return 0;break;
      default:
        cout<<"INGRESE OPCION CORRECTA.\n";
        system("pause");
      ;break;
    }
  }
}
