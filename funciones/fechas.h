#ifndef FECHAS_H_INCLUDED
#define FECHAS_H_INCLUDED
class fecha{
private:
  int dia,mes,anio;
public:
  void set_dia(int d){dia=d;}
  void set_mes(int m){mes=m;}
  void set_anio(int a){anio=a;}
  int get_dia(){return dia;}
  int get_mes(){return mes;}
  int get_anio(){return anio;}
  void cargar();
  void mostrar();
  //constructores
  fecha(){dia=0;mes=0;anio=0;} //por omisión
  fecha(int d,int m,int a){dia=d;mes=m;anio=a;} //
};
void fecha::cargar(){
  cout<<"FECHA: ";
  cout<<"Dia: ";cin>>dia;
  cout<<"Mes: ";cin>>mes;
  cout<<"Anio: ";cin>>anio;
}
void fecha::mostrar(){
  cout<<"FECHA: "<<endl;
  cout<<"Dia: "<<dia<<endl;
  cout<<"Mes: "<<mes<<endl;
  cout<<"Anio: "<<anio<<endl;
}

#endif // FECHAS_H_INCLUDED
