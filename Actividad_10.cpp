#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
const char *nombre_archivo = "notas.dat"; 
struct Estudiante 
{
	float nota1;
	float nota2;
	float nota3;
	int id;
	char nombres[50];
	char apellidos[50];
	float promedio;
    char resultado[10];
};

void leer();
void crear();
void Actualizar();
void Borrar();
main()
{
	
	crear();
   Actualizar();
	leer();
    Borrar();
	system ("pause");
}
void leer()
{
	system("cls");	
	FILE* archivo = fopen(nombre_archivo,"rb ");
	if (!archivo)
	{
	archivo = fopen(nombre_archivo,"w+b ");	
	}
	Estudiante estudiante;
	int id=0;
	fread(&estudiante,sizeof(Estudiante),1,archivo);
	cout<<"___________________________________________________"<<endl;
	cout<<"id"<<"|"<<"Nombres"<<"|"<<"Apellidos"<<"|"<<"Nota 1"<<"|"<<"Nota 2"<<"|"<<"Nota 3"<<"|"<<"Promedio"<<"|"<<"Resultado"<<endl;
	do
	{
		cout<<estudiante.id<<"|"<<estudiante.nombres<<"|"<<estudiante.apellidos<<"|"<<estudiante.nota1<<"|"<<estudiante.nota2<<"|"<<estudiante.nota3<<"|"<<estudiante.promedio<<"|"<<estudiante.resultado<<endl;
		fread(&estudiante,sizeof(Estudiante),1,archivo);	
	}while (feof(archivo)==0);
	fclose(archivo);
}
void crear()

{
FILE* archivo = fopen(nombre_archivo,"a+b");
char res;
Estudiante estudiante;
do
{
	fflush(stdin);
	cout<<"Ingrese ID: ";
	cin>>estudiante.id;
	cin.ignore();
	cout<<"Ingrese Nombres: ";
	cin.getline(estudiante.nombres,50);
	cout<<"Ingrese Apellidos: ";
	cin.getline(estudiante.apellidos,50);
	cout<<"Ingrese Nota 1: ";
	cin>>estudiante.nota1;
	cout<<"Ingrese Nota 2: ";
	cin>>estudiante.nota2;
	cout<<"Ingrese Nota 3: ";
	cin>>estudiante.nota3;
	fwrite(&estudiante,sizeof(Estudiante),1,archivo);
	cout <<"Desea ingresar otro estudiante (s/n):";
	cin>>res;
 estudiante.promedio = (estudiante.nota1 + estudiante.nota2 + estudiante.nota3)/3;
        if(estudiante.promedio >= 60){
            strcpy(estudiante.resultado, "APROBADO");
        }
        else{
            strcpy(estudiante.resultado, "REPROBADO");
        }
         ofstream archivo("notas.dat", ios::binary);
   
    
}while(res == 's'|| res == 'S');
fclose(archivo);
leer();
	system ("pause");
}
void Actualizar()
{
FILE* archivo = fopen(nombre_archivo,"r+b"); 
Estudiante estudiante;
	cout<<"Ingrese el ID que desea Modificar:";
	cin>>estudiante.id;
	fseek(archivo,estudiante.id * sizeof(Estudiante),SEEK_SET); 
	cout<<"Ingrese ID: ";
	cin>>estudiante.id;
	cin.ignore();
	cout<<"Ingrese Nombres: ";
	cin.getline(estudiante.nombres,50);
	cout<<"Ingrese Apellidos: ";
	cin.getline(estudiante.apellidos,50);
	cout<<"Ingrese Nota 1: ";
	cin>>estudiante.nota1;
	cout<<"Ingrese Nota 2: ";
	cin>>estudiante.nota2;
	cout<<"Ingrese Nota 3: ";
	cin>>estudiante.nota3;
	fwrite(&estudiante,sizeof(Estudiante),1,archivo);
	 estudiante.promedio = (estudiante.nota1 + estudiante.nota2 + estudiante.nota3)/3;
        if(estudiante.promedio >= 60){
            strcpy(estudiante.resultado, "APROBADO");
        }
        else{
            strcpy(estudiante.resultado, "REPROBADO");
        }
       
  
	cout <<"Desea ingresar otro estudiante (s/n):";
	

fclose(archivo);
leer();	
}
void Borrar()
{
	
	const char *nombre_archivo_temp = "archivo_temp.dat";
	system("cls");	
	FILE* archivo_temp = fopen(nombre_archivo_temp,"w+b");
	FILE* archivo = fopen(nombre_archivo,"rb ");
	Estudiante estudiante;
	cout<<"Ingrese el ID a eliminar:";
	cin>>estudiante.id;
	while(fread(&estudiante,sizeof(Estudiante),1,archivo))
	{
		if (estudiante.id!=estudiante.id)
		{ 
				fwrite(&estudiante,sizeof(Estudiante),1,archivo_temp);
		}
		
	} 
	fclose(archivo);
	fclose(archivo_temp);
	 archivo_temp = fopen(nombre_archivo_temp,"rb");
	 archivo = fopen(nombre_archivo,"wb ");
	 	while(fread(&estudiante,sizeof(Estudiante),1,archivo_temp))
	 	{
	 	  	fwrite(&estudiante,sizeof(Estudiante),1,archivo);
		 }
		 fclose(archivo);
	fclose(archivo_temp);
leer();	
}
