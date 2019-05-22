#ifndef TINTURAS_H_INCLUDED
#define TINTURAS_H_INCLUDED
class tintura {
private:
  int codigo;
  fecha calen;
  char genero;
  char pelo[30];
public:
  void set_codigo(int cod){codigo=cod;}
  void set_genero(char gen){genero=gen;}
  void set_pelo(const char *pel){strcpy(pelo,pel);}
  int get_codigo(){return codigo;}
  char get_genero(){return genero;}
  char *get_pelo(){return pelo;}
  void cargar();
  void mostrar();
  void GrabarEnDisco();
  bool LeerDeDisco(int pos);
  int Contar_Registros();
  //constructores
  tintura(int cod,char gen, char *pel){codigo=cod;genero=gen;strcpy(pelo,pel);} //mandando parametros
  tintura(){genero='X';codigo=0;strcpy(pelo,"vacio");} //por omision
};
///PRIVATE: CARGAR
void tintura::cargar(){
  do{
  cout<<"Ingrese Codigo de Tintura: ";
  cin>>codigo;
  if(codigo<100||codigo>135){cout<<"Ingrese Codigo Valido."; system("pause>null");system("cls");}
  }while(codigo<100||codigo>135);
  calen.cargar();
  cout<<"Ingrese Genero: ";
  cin>>genero;
  cout<<"Ingrese Tipo de Pelo: ";
  cin.ignore();
  cin.getline(pelo,30);
}
///PRIVATE: MOSTRAR
void tintura::mostrar(){
  cout<<"Codigo de Tintura: "<<codigo<<endl;
  calen.mostrar();
  cout<<"Genero: "<<genero<<endl;
  cout<<"Tipo de Pelo: "<<pelo<<endl;
  cout<<"------------"<<endl;
}
///PRIVATE: GRABAR EN DISCO
void tintura::GrabarEnDisco(){
  FILE *p;
  p=fopen("color.dat","ab");
  if(p==NULL){cout<<"Error de archivo.";system("pause>null");return;}
  fwrite(this,sizeof *this,1,p);
  fclose(p);
}
///GENERAL: AGREGAR TINTURA
void AgregarTintura(){
  tintura a;
  a.cargar();
  system("pause");
  a.GrabarEnDisco();
}
///PRIVATE: LEER DE DISCO
bool tintura::LeerDeDisco(int pos){
  FILE *p;
  p=fopen("color.dat","rb");
  if(p==NULL){cout<<"Error de archivo.";system("pause>null");exit (1);}
  fseek(p,sizeof(*this)*pos,0);
  bool leyo=fread(this,sizeof *this,1,p);
  fclose(p);
  return leyo;
}
///PRIVATE: CONTAR REGISTROS
int tintura::Contar_Registros(){
  FILE *p;
  int cont=0;
  p=fopen("color.dat","rb");
  if(p==NULL){cout<<"Error de archivo.";system("pause>null");return -1;}
  while(fread(this,sizeof *this,1,p)){
    cont++;
  }
  fclose(p);
  return cont;
}
///GENERAL: LISTAR TINTURA
void ListarTintura(){
  tintura reg;
  int pos=0;
  while(reg.LeerDeDisco(pos)==true){
    reg.mostrar();
    pos++;
  }
  system("pause>null");
}
///GENERAL PUNTO UNICO / MOSTRAR
void PuntoUnicoMostrar(int *v,int tam){
  tintura tint;
  int i,v_cod[tam]={0};
  bool flag=false;
  for(i=0;i<tam;i++){
    if(v[i]>=1){v_cod[i]=1;flag=true;}
  }
  if(flag==true){
    cout<<"Codigos De Tintura con Al Menos de 10 Coloraciones en Marzo: "<<endl;
    for(i=0;i<tam;i++){
      if(v_cod[i]==1){
        cout<<i+100<<", ";
      }
    }
    system("pause");
  }else{
    cout<<"No hay Codigos de tintura con mas de 9 coloraciones en Marzo: "<<endl;
    system("pause");
  }
}
///GENERAL: PUNTO UNICO
void PuntoUnico(){
  FILE *p;
  bool leyo;
  int cod,cant=0,vec[36]={0};
  tintura tint;
  cant=tint.Contar_Registros();
  for(int i=0;i<cant;i++){
    leyo=tint.LeerDeDisco(i);
    if(leyo==true){
      cod=tint.get_codigo();
      vec[cod-100]++;
    }
  }
  PuntoUnicoMostrar(vec,36);
}
#endif // TINTURAS_H_INCLUDED
