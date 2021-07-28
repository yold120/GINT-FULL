#include <iostream>

#include <cstring>//Comandos complejos de cadena c

#include <windows.h>//libreria de windows, permite establecer time duracion

#include <time.h>//libreria para eltiempo, para dar salida a datos de time

#include <ctime> //para calcular el tiempo

#include <fstream>//E/S de datos txt

#include <conio.h>//libreria conio, para colocar en plano x/y

#include <stdio.h>

#include<locale.h>

#include <cstdlib>

#include <vector>


#define ENTER 13 
#define BACKSPACE 8

using namespace std;

//estructura con variables de tareas del empleado
struct tareas
{
	string nomtarea;
	string fitarea;
	string fftarea;
	string cliente;
	string abonotarea;
	string destarea;
	
};

//estructura con variables de ingresos del empleado
struct ingreso
{
    string cliente;
   	string servicio;
   	int noservicio;
   	double mservicio;	
	double mtotal;
};

//variables de servicios
	string serv;
	string tserv;
	string descripcionserv;
	double preciomin;
	double preciomax;
	string mserv;
	int noserv;
	
//variables de productos
	double id;
	string descripcion; 
	string categoria;
	double preciov;
	double precioc;
	string proveedor;

//variables de empleados

	string nomuser;
	string ced;
	string sex;//masculino o femenino
	string direc;
	string correo;
	string cel;
	string tel;
	string turno;//matutino o nocturno
	string cargo;
	string clave;
	string maquina;
	string mmaquina;
	string sueldoini;
	string edad;
	string user;
	string claveuser;
//variabl;es de admin
	string admin = "1";
	string nomadmin;
	string claveadmin = "1";
	string pseguridad;
	//variables de ayuda
	string s = "\n";
	string e=" ";

//declaracion universal de las variables de fstream
	ofstream Esc;
	ofstream espr;
	ofstream ess;
	ifstream Lec;
	
	
//para el login
	bool cuenta = false;
	
	string tuser;
	
    int count=0;
    
    int intentos=5;
    
    string administrador = "a";
    
    string usuario = "u";
    
    int contador;
    
    string tareamaquina;
    
    
//declaracion de variables, almacen de archivos txt
	string empleados = "Empleados.txt";
	string auxiliar = "auxiliar.txt";
	string tarea = "tareas.txt";
	
//otras variables

    time_t instanteInicial, instanteFinal;//variables de ctime para el; tiempo
    double tiempo;//variable para tiempo universal
    double ptiempo;//varaible para precio del tiempo
	string numeromaquina;//variable identificar usuario
	vector<double> v;//almacen de datos
	double suma = 0;

	
	
//metodos en orden
	void gotoxy();//invoca metodo de localizar

	void back();//invoca metodo de regresar
	
	void cleaner();//invoca metodo de limpiar

	void stylecu();//invoca metodo de el diseño de los cuadros

	void cuadro();//invoca cuadros

	void logogin();//invoca metodo de logotipo del programa

	void fechaactual();//invoca metodo de fecha y hora actual

	void menuprincipalt();//invoca metodo de titulo de un menu principal
	

	void direccionales();//invoca metodo de mover en el menu con flechas
	
	void loginuser();

/////////////////////////////////////////////////////////////	MENU ADMIN
/////////////////////////////////////////////////////////////	MENU ADMIN
/////////////////////////////////////////////////////////////	MENU ADMIN
	void regadmin();

	void regadmin(ofstream &es);
	
	void menuprincipaladmin();//invoca el menu central del admin 
	
	void agregarp(ofstream &es);//funcion  agrega personal
//////////////////////////////////////////////Productos
	void agregarpr(ofstream &es);//funcion  agrega productos
	
/////////////////////////////////////////////Servicios
	void agregars(ofstream &es);//funcion agregar servicio
	
	void menuuser();
	
	void historialempleado(ifstream &Lec);
	
/////////////////////////////////////////////////////////////	MENU USER
/////////////////////////////////////////////////////////////	MENU USER	
/////////////////////////////////////////////////////////////	MENU USER
	
	int menuprincipaluser()
	{
		
		system("cls");
		system("color f3");
		system("mode con: cols=80 lines=25");
		gotoxy(0,6);	//localizacion cuadro arriba
		fechaactual();
		gotoxy(0,0);
		stylecu();
		gotoxy (0,20);
		stylecu();
		int x;

		system("color F3");

		gotoxy (30,6);
		cout<<"===================="<<s;
		gotoxy (30,7);
		cout<<"   MENU EMPLEADO "<<s;
		gotoxy (30,8);	
		cout<<"===================="<<s;
		
		gotoxy (1,6);
		cout<<"==================="<<s;
		gotoxy (1,7);
		cout<<"   DATOS EMPLEADO "<<s;
		gotoxy (1,8);	
		cout<<"==================="<<s;
		
		gotoxy (58,6);
		cout<<"==================="<<s;
		gotoxy (58,7);
		cout<<"   UTILIZADES "<<s;
		gotoxy (58,8);	
		cout<<"==================="<<s;
		
		gotoxy (1,10);
		cout<<"|Usuario :"<<nomuser<<s;
		gotoxy (1,11);
		cout<<"|Maquina :"<<maquina<<s;
		gotoxy (1,12);
		cout<<"|Cargo   :"<<cargo<<s;
		cout<<"  __________________"<<s;
		
		gotoxy (1,16);
		cout<<"Cambiar usuario (7)"<<s;	
		
		gotoxy (21,10);	
		cout<<"|       | 1.Ingreso           |";
		gotoxy (21,11);	
		cout<<"|       | 2.Historial         |";
		gotoxy (21,12);
		cout<<"|       | 3.Manteniiento Tarea|";
		gotoxy (21,13);
		cout<<"         _____________________"<<s;

		
		
		gotoxy (56,10);
		cout<<"| 4.Tarea Pendiente   |";
		gotoxy (56,11);
		cout<<"| 5.Ver Productos     |";
		gotoxy (56,12);
		cout<<"| 6.Ver Servicios     |"<<s;
		gotoxy (56,13);
		cout<<" _____________________"<<s;

		
		gotoxy (60,16);
		cout<<"Salir (9)"<<s;
		
		gotoxy(30,15);
		cout<<"________________________"<<s;
		gotoxy(30,16);
		cout<<"Seleccione una opcion: ";cin>>x;
		gotoxy(30,17);
		cout<<"________________________"<<s;
		
		return x;
		
	}
	
	

	

//////////////////////////////////////////////MENU PRINCIPAL	
	
	
	
	int menuprincipal(){
	int x;
	
	system("mode con: cols=80 lines=25");

	menuprincipalt();
	
	//color(9)
	
	system("color 4f");
	int col(10);
	gotoxy(0,6);	//localizacion cuadro arriba
	fechaactual();
	gotoxy (22,12);
	cout<<"1. Ver Personal"<<endl;
	gotoxy (22,14);
	cout<<"2. ver Productos"<<endl;
	gotoxy (43,12);
	cout<<"3. ver Servicios"<<endl;
	gotoxy (43,14);
	cout<<"4. Mantenimiento"<<endl;
	gotoxy (65,13);
	cout<<"5. Ganancias"<<s;
	gotoxy (65,14);
	cout<<"de  Personal"<<endl;
	gotoxy (65,16);
	cout<<"7. Regresar"<<endl;
	gotoxy (65,17);
	cout<<"9. Salir"<<endl;
	cout<<s;
	gotoxy(22,17);
	cout<<"Seleccione una opcion__________ ";cin>>x;
	return x;
}

//////////////////////////////////////////////////// PROGRAMA///////////////////////////
//////////////////////////////////////////////////// PROGRAMA///////////////////////////
//////////////////////////////////////////////////// PROGRAMA///////////////////////////
	int main()
	{
		struct tareas pendientes; 

		ofstream Esc;
		//azulcielo con fondo blanco 
		//system("color f3");
		//color original 
		system("color 4f");		 


		//llamando almodo tama;o de ventana
		system("mode con: cols=80 lines=25");
		//mostrando la fecha  pantalla
		gotoxy(0,6);	//localizacion cuadro arriba
		fechaactual();
		//creandobarra griss de dise;o
		//system ("cls");	//borrando 
		gotoxy(0,0);	//localizacion cuadro arriba
		stylecu();
		logogin();	//invocando logo
		gotoxy (0,20);	//localizacion cuadro abajo
		stylecu();
		getch();
		system ("cls");
		
		//system ("cls");
		//llamando al logo de inicio
	
		//	opc1();
		direccionales();
		loginuser();
		menuuser();
	
		system ("pause");

		return 0;
	}

	void gotoxy(int x,int y) // funcion para localizar
	{  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);
      if (bool clean = true)
     {
     	x = 0;  
    	y = 0;
	 }

	};

	void cleaner()  //funcion para borrar una parte de pantalla

	{


	for (int i=0; i<10; i++)
		printf("\n");

	}

	void stylecu()	//creador de cuadro de estilo
	{
		const int icuadro=0;
		int style;
		for (int icuadro=0; icuadro<480;  icuadro++)
	{
		
		printf("%c", 219);

	}
		icuadro == 480;

	};

	void cuadro()	//almacen de localizacion de cuadros
	{

		gotoxy(0,1);	//localizacion cuadro arriba
		stylecu();

		gotoxy (0,20);	//localizacion cuadro abajo
		stylecu();

	};

	void logogin()	//logo del programa
	{
////////////////////////////////////////////////////////////// funcion logo GINTD
		for (int logo = 0;logo<1;logo++)
	{

		gotoxy(18,9);
		cout << "**********************************************"<<endl;
		Sleep (110);
		gotoxy(18,10);
		cout << "  _______  __ .__   __..___________. _______  "<<endl;
		Sleep (110);
		gotoxy(18,11);
		cout << " /  _____||  ||  \\ |  ||           ||       \\ "<<endl;
		Sleep (120);
		gotoxy(18,12);
		cout << "|  |  __  |  ||   \\|  |`---|  |----`|  .--.  |"<<endl;
		Sleep (130);
		gotoxy(18,13);
		cout << "|  | |_ | |  ||  . `  |    |  |     |  |  |  |"<<endl;
		Sleep (110);
		gotoxy(18,14);
		cout << "|  |__| | |  ||  |\\   |    |  |     |  '--'  |"<<endl;
		Sleep (120);
		gotoxy(18,15);
		cout << " \\______| |__||__| \\__|    |__|     |_______/ "<<endl;
		Sleep (130);
		gotoxy(18,17);
		cout << "**********************************************"<<endl;
		gotoxy(18,16);
		cout << ""<<endl;	
		
		gotoxy(30,18);
		cout<<"Por que el tiempo, es oro";
		cout<< endl; cout<<endl;

		}	

	};
	
//////////////////////////////////////////////////////////// FECHA
	void fechaactual()	//fecha actual del sistema
	{
		char fecha[25];//ctime devuelve 26 caracteres pero tambien se podría usar un puntero de char
	    time_t current_time;
	    current_time=time(NULL);
	    ctime(&current_time);
	    strcpy(fecha, ctime(&current_time));
	    printf("%s", fecha); 
	};

	void menuprincipalt()	//Titulo menu
	{
		cuadro();	//invocando cuadro nuevamente
		gotoxy(28,8);
		cout << "*************************"<<endl;
		gotoxy(28,9);
		cout << "*     MENU PRINCIPAL    *"<<endl;
		gotoxy(28,10);
		cout << "*************************"<<endl;
	};
	
	void logot()	//Titulo menu
	{
		cuadro();	//invocando cuadro nuevamente
		gotoxy(28,8);
		cout << "*************************"<<endl;
		gotoxy(28,9);
		cout << "*          LOGIN        *"<<endl;
		gotoxy(28,10);
		cout << "*************************"<<endl;
	};
	
	
	void loginuser()
	{
			system("cls");
			
           	bool encontrado=false;
           	contador = 1;
           	int reg = 5;
           	
           	int repetir = 1;
			do{
			
			
            	system("cls");
				
				Lec.open("Empleados.txt");
               if(Lec.is_open())
               {
               	
               	system("cls");

			   	menuprincipalt();
			   	
			   	gotoxy (28,12);
			   	cout<<"Enter Username: ";
			   	cin>>ws;
               	getline(cin,user);
               	char caracter;
               	gotoxy (28,14);
               	cout<<"Enter Clave: ";
               	caracter = getch();
        
        claveuser = "";
        
        while (caracter != ENTER) {
        
            if (caracter != BACKSPACE) {
                claveuser.push_back(caracter);
                cout << "*";
                
            } else {
                if (claveuser.length() > 0) {
                    cout << "\b \b";
                    claveuser = claveuser.substr(0, claveuser.length() - 1);
                }
            }
            
            caracter = getch();
        }
				
			   	while(!Lec.eof()&& !encontrado)
			   	{
			   		
				getline(Lec,nomuser,'\n');
			   	getline(Lec, direc,'\n');	
				getline(Lec, ced,'\n');	
				getline(Lec, cel,'\n');	
				getline(Lec, tel,'\n');	
				getline(Lec, cargo,'\n');	
				getline(Lec, edad,'\n');	
				getline(Lec, sex,'\n');	
				getline(Lec, turno,'\n');	
				getline(Lec, correo,'\n');	
				getline(Lec, sueldoini,'\n');	
				getline(Lec, maquina,'\n');	
				getline(Lec, clave,'\n');	
				getline(Lec, tuser,'\n');	
				
				if (user == nomuser&& claveuser== clave && administrador == tuser)
                {	
					         		
               		encontrado = true;
               		return menuprincipaladmin();	
               			
           		}
           		
           		
           		
           		if (user == nomuser&& claveuser== clave && usuario == tuser)
                {	
               		encontrado = true;
               		return menuuser();

           		}
           		
           		}
           		
           		if (encontrado == false) 
					{
						
               			gotoxy (28,16);
			            cout << "El usuario y/o password son incorrectos" << endl;
               			gotoxy (28,17);
			            cout << "Intentos Permitidos: "<<reg-contador << endl;
			            //cout<<"nombre :"<<nomuser;
			            //cout<<direc;
			            //cout<<"clave :"<<clave;
			            cin.get();
			            contador++;
			            
			        }
			        
			    if (!encontrado && contador > 5) 
				{
					
					system("cls");
               		gotoxy (28,14);
			        cout << "ERROR, Favor consultar informacion" << endl;
			                       		gotoxy (28,14);
               		gotoxy (28,15);
               		exit(0);
			        system("pause");
			    }
           		
           		
           		
           		
           		
				Lec.close();
			   }

           }while(repetir == 1);
				   	
			   
	}

///////////////////////////////////////////////////////////DIRECCIONALES
	void direccionales()
	{
		system("cls");
		system("color f3");
		logot();
		gotoxy (0,0);
		stylecu();

		//arriba = 22472 
		//abajo = 22480
		//izq = 22475
		//der = 22477
		/*system ("cls");
		*/

		int y=12;
		char c;
		gotoxy(27,y);
		cout<<">";
		gotoxy(28,12);
		cout<<"	Ingresar"<<endl;
		gotoxy(28,14);
		cout<<"	Informacion"<<endl;
		gotoxy(28,16);
		cout<<"	Salir"<<endl;

		do 
		{			
			c=getch();
			if (c==-32)//para saber si es direccional
			{
				gotoxy(27,y);
				cout<<" ";
				c=getch();
				if (c==72)//arriba
					if (y==12)	//posicion actual
						{
							y=16;	//regresa a la posicion
						}
					else
						{
							 y=y-2;	//cantidad a avanzar
								//y++;
						}
					if (c==80)//abajo
							if (y==16)	//posicion actual
								{
									y=12;//regresa a la posicion
								}
							else
								{
									y=y+2; //cantidad a avanzar
								}

					gotoxy(27,y);
					cout<<">";
			}		

			if (c==13)
				{
				

				///// casos de menus

				do 
			
				{
					

					switch(y) 
					{
					case 12: //Ingresar
						{
							loginuser();
						}
     		
					break;
					case 14: //Acceder sin registro
						{
							system("cls");
							cout<<"Programador : Yoldany De Los Santos Contreras "<<s;
							cout<<"No. Contacto: 809-451-7400 "<<s;
							cout<<"Correo      : yctecnology@gmail.com "<<s<<s<<s;
							cout<<"para acceder por primera vez:"<<s;
							cout<<"Usuario: admin, Clave admin";
							cout<<"recordar ese usuario admin y esa clave";
							
							getch();
							return;
							
						}
					break;
					case 16: 
					
					exit(0);


					break;
					default: 
					cout<<"Seleccione una opcion";
					break;
					}

				}

				while (y>2);

				}

			}

		 while (1);					
		}

/////////////////////////////////////////////////funcion de pantalla incicio
	
/////////////////////////////////////////////					PERSONAL
/////////////////////////////////////////////					PERSONAL
/////////////////////////////////////////////					PERSONAL


//funcion para agregar empleados o personal

void agregarp(ofstream &es)
{	
	system("mode con: cols=40 lines=25");
	system("color 4f");

	string e=" ";

	system ("cls");

	es.open("Empleados.txt",ios::out|ios::app);

	if(es.is_open())
	{
	cout<<"========================"<<s;
	cout<<"    Ingresar Personal   "<<s;
	cout<<"========================"<<s;
	
	cout<<"Nombre----: ";
	cin>>ws;
	getline(cin,nomuser,'\n');
	cout<<"Direccion-: ";
	getline(cin,direc,'\n');
	cout<<"Cedula----: ";
	getline(cin,ced,'\n');
	cout<<"Celular---: ";
	getline(cin,cel,'\n');
	cout<<"Telefono--: ";
	getline(cin,tel,'\n');
	cout<<"Cargo-----: ";
	getline(cin,cargo,'\n');
	cout<<"Edad------: ";
	getline(cin,edad,'\n');
	cout<<"Sexo(M/F)-: ";
	getline(cin,sex,'\n');
	cout<<"Turno(M/T): ";
	getline(cin,turno,'\n');
	cout<<"Correo----: ";
	getline(cin,correo,'\n');
	cout<<"Sueldo----: ";
	getline(cin,sueldoini,'\n');
	cout<<"Maquina---: ";
	getline(cin,maquina,'\n');
	cout<<"Clave-----: ";
	getline(cin,clave);
	cout<<"Tipo User-: ";
	getline(cin,tuser,'\n');
	
	//if(verifica(ced))
	
	es<< nomuser;
	es<<'\n';
	es<<direc;
	es<<'\n';
	es<<ced;
	es<<'\n';
	es<<cel;
	es<<'\n';
	es<<tel;
	es<<'\n'; 
	es<<cargo;
	es<<'\n'; 
	es<<edad;
	es<<'\n';
	es<<sex;
	es<<'\n';
	es<<turno;
	es<<'\n';
	es<<correo;
	es<<'\n';
	es<<sueldoini;
	es<<'\n';
	es<<maquina;
	es<<'\n';
	es<<clave;
	es<<'\n';
	es<<tuser;
	es<<endl;	

	es.close();
	}

	else
		cout<<"El archivo no se pudo abrir"<<s;
}


// funcion para ver personal

void verp(ifstream &Lec)
{		
	system("mode con: cols=40 lines=500");
	system ("cls");
	system("color 4f");
	Lec.open("Empleados.txt",ios::in);

	if(Lec.is_open())
	{
	cout<<"========================"<<s;
	cout<<"Personal de la empresa"<<s;
	cout<<"========================"<<s;
	
	getline(Lec, nomuser,'\n');	

	while(!Lec.eof())
	{
	getline(Lec, direc,'\n');	
	getline(Lec, ced,'\n');	
	getline(Lec, cel,'\n');	
	getline(Lec, tel,'\n');	
	getline(Lec, cargo,'\n');	
	getline(Lec, edad,'\n');	
	getline(Lec, sex,'\n');	
	getline(Lec, turno,'\n');	
	getline(Lec, correo,'\n');	
	getline(Lec, sueldoini,'\n');	
	getline(Lec, maquina,'\n');	
	getline(Lec, clave,'\n');	
	getline(Lec, tuser,'\n');	

	cout<<"Nombre-----:"<<nomuser<<endl;
	cout<<"Direccion--:"<<direc<<endl;
	cout<<"Cedula-----:"<<ced<<endl;  
	cout<<"Celular----:"<<cel<<endl;  
	cout<<"Telefono---:"<<tel<<endl;  
	cout<<"Cargo------:"<<cargo<<endl;
	cout<<"edad-------:"<<edad<<endl; 
	cout<<"Sexo-------:"<<sex<<endl;  
	cout<<"Turno------:"<<turno<<endl;
	cout<<"correo-----:"<<correo<<endl;
	cout<<"Sueldo-----:"<<sueldoini<<endl;
	cout<<"Maquina----:"<<maquina<<endl;
	cout<<"Clave------:"<<clave<<endl;
	cout<<"t. user----:"<<tuser<<endl;
    cout<<"=========================="<<endl;

    getline(Lec, nomuser,'\n');
	}
	Lec.close();
	}

	else
	cout<<"El archivo no se pudo abrir"<<s;
	system ("pause");
	
	
	
	
	
}



//funcion para buscar personal
void buscarp(ifstream &Lec)
{	
	system("color 4f");
	system("mode con: cols=40 lines=25");

	system("cls");
	
	Lec.open("Empleados.txt",ios::in);
	
	string mmaquina;
	bool encontrado = false;
	
	cout<<"Digite No. Maquina: ";
	cin.ignore();
	getline(cin,mmaquina);
	
	
	getline(Lec, nomuser,'\n');	

	while(!Lec.eof() && !encontrado)
	{
	getline(Lec, direc,'\n');	
	getline(Lec, ced,'\n');	
	getline(Lec, cel,'\n');	
	getline(Lec, tel,'\n');	
	getline(Lec, cargo,'\n');	
	getline(Lec, edad,'\n');	
	getline(Lec, sex,'\n');	
	getline(Lec, turno,'\n');	
	getline(Lec, correo,'\n');	
	getline(Lec, sueldoini,'\n');	
	getline(Lec, maquina,'\n');	
	getline(Lec, clave,'\n');	
	getline(Lec, tuser,'\n');

		if (maquina == mmaquina)
		{
			cout<<"Nombre-----:"<<nomuser<<endl;
			cout<<"Direccion--:"<<direc<<endl;
			cout<<"Cedula-----:"<<ced<<endl;  
			cout<<"Celular----:"<<cel<<endl;  
			cout<<"Telefono---:"<<tel<<endl;  
			cout<<"Cargo------:"<<cargo<<endl;
			cout<<"edad-------:"<<edad<<endl; 
			cout<<"Sexo-------:"<<sex<<endl;  
			cout<<"Turno------:"<<turno<<endl;
			cout<<"correo-----:"<<correo<<endl;
			cout<<"Sueldo-----:"<<sueldoini<<endl;
			cout<<"Maquina----:"<<maquina<<endl;
			cout<<"Clave------:"<<clave<<endl;
			cout<<"t. user----:"<<tuser<<endl;

			encontrado = true;
		}
		
		getline(Lec, nomuser,'\n');	

	}
		Lec.close();
	if(!encontrado)
	{
	cout<<"dato no encontrado"<<s;
	}
	system("pause");
	}


// funcion para modificar personal
	void modificarp(ifstream &Lec)
	{
	system("color 4f");

	system("mode con: cols=40 lines=25");

		system("cls");
		string nomaux;
		string mcorreo;
		string mcargo;
		string mmaquina;
		string mnivel;
		string msueldo;
		
		Lec.close();
		Esc.close();

		Lec.open(empleados.c_str());		
				
		ofstream aux;
		aux.open(auxiliar.c_str ());
		if (Lec.is_open())
		{
			cout<<"Maquina---:";
			cin.ignore();
			getline(cin,mmaquina);
			
			
			getline(Lec, nomuser,'\n');	

			while(!Lec.eof())
			{
				getline(Lec, direc,'\n');	
				getline(Lec, ced,'\n');	
				getline(Lec, cel,'\n');	
				getline(Lec, tel,'\n');	
				getline(Lec, cargo,'\n');	
				getline(Lec, edad,'\n');	
				getline(Lec, sex,'\n');	
				getline(Lec, turno,'\n');	
				getline(Lec, correo,'\n');	
				getline(Lec, sueldoini,'\n');
				getline(Lec, maquina,'\n');		
				getline(Lec, clave,'\n');	
				getline(Lec, tuser,'\n');
			
				if (maquina==mmaquina)
				{
					
					cout<<"Nuevo Nombre---:";
					cin>>ws;
					getline(cin, nomaux,'\n');	
					
					aux<<nomaux;
					aux<<'\n';
					aux<<direc;
					aux<<'\n';
					aux<<ced;
					aux<<'\n';
					aux<<cel;
					aux<<'\n';
					aux<<tel;
					aux<<'\n'; 
					aux<<cargo;
					aux<<'\n'; 
					aux<<edad;
					aux<<'\n';
					aux<<sex;
					aux<<'\n';
					aux<<turno;
					aux<<'\n';
					aux<<correo;
					aux<<'\n';
					aux<<sueldoini;
					aux<<'\n';
					aux<<maquina;
					aux<<'\n';
					aux<<clave;
					aux<<'\n';
					aux<<tuser;
					aux<<endl;
							
				}
				else
				{
					aux<< nomuser;
					aux<<'\n';
					aux<<direc;
					aux<<'\n';
					aux<<ced;
					aux<<'\n';
					aux<<cel;
					aux<<'\n';
					aux<<tel;
					aux<<'\n'; 
					aux<<cargo;
					aux<<'\n'; 
					aux<<edad;
					aux<<'\n';
					aux<<sex;
					aux<<'\n';
					aux<<turno;
					aux<<'\n';
					aux<<correo;
					aux<<'\n';
					aux<<sueldoini;
					aux<<'\n';
					aux<<maquina;
					aux<<'\n';
					aux<<clave;
					aux<<'\n';
					aux<<tuser;
					aux<<endl;
				}
			
				getline(Lec, nomuser,'\n');	
			}
			
			
		}
		
		else
		{
		cout<<"ERROR"<<s;
		}
		
		Lec.close();
		Esc.close();
		aux.close();
		
		remove(empleados.c_str ());
		rename(auxiliar.c_str (),empleados.c_str ());	
		
	}


// funcion para borrar empleados
	void borrarp(ifstream &Lec)
	{

system("color 4f");
system("mode con: cols=40 lines=25");


		system("cls");
		string nomaux;
		string mcorreo;
		string mcargo;
		string mmaquina;
		string mnivel;
		string msueldo;
		
		Lec.close();
		Esc.close();

		Lec.open(empleados.c_str(),ios::in);		
				
		ofstream aux;
		aux.open(auxiliar.c_str (),ios::out);
		if (Lec.is_open())
		{
			cout<<"Maquina---:";
			cin.ignore();
			getline(cin,mmaquina,'\n');
			
			getline(Lec, nomuser,'\n');	
			while(!Lec.eof())
			{
				getline(Lec, direc,'\n');	
				getline(Lec, ced,'\n');	
				getline(Lec, cel,'\n');	
				getline(Lec, tel,'\n');	
				getline(Lec, cargo,'\n');	
				getline(Lec, edad,'\n');	
				getline(Lec, sex,'\n');	
				getline(Lec, turno,'\n');	
				getline(Lec, correo,'\n');	
				getline(Lec, sueldoini,'\n');	
				getline(Lec, maquina,'\n');	
				getline(Lec, clave,'\n');	
				getline(Lec, tuser,'\n');

				if (maquina==mmaquina)
				{
					cout<<"Borrando......";
					Sleep(2000);
				}
				else
				{

					aux<< nomuser;
					aux<<'\n';
					aux<<direc;
					aux<<'\n';
					aux<<ced;
					aux<<'\n';
					aux<<cel;
					aux<<'\n';
					aux<<tel;
					aux<<'\n'; 
					aux<<cargo;
					aux<<'\n'; 
					aux<<edad;
					aux<<'\n';
					aux<<sex;
					aux<<'\n';
					aux<<turno;
					aux<<'\n';
					aux<<correo;
					aux<<'\n';
					aux<<sueldoini;
					aux<<'\n';
					aux<<maquina;
					aux<<'\n';
					aux<<clave;
					aux<<'\n';
					aux<<tuser;
					aux<<endl;	

				}

				getline(Lec, nomuser,'\n');	
			}
			
		}
		else
		{
		
		cout<<"ERROR"<<s;
		}
		
		Lec.close();
		Esc.close();
		aux.close();
		remove(empleados.c_str ());
		rename(auxiliar.c_str (),empleados.c_str ());
		

	}

////////////////////////////////////////////////PRODUCTOS
////////////////////////////////////////////////PRODUCTOS
////////////////////////////////////////////////PRODUCTOS
	
	void agregarpr(ofstream &espr)
	{
system("color 4f");
system("mode con: cols=40 lines=25");

	string e=" ";

	system ("cls");

	espr.open("Productos.txt",ios::out|ios::app);

	if(espr.is_open())
	{
	cout<<"========================"<<s;
	cout<<"    Ingresar Productos  "<<s;
	cout<<"========================"<<s;

	//para ignorar la ultima instruccion del getline

	/////////////////////////////ENTRADA DE DATOS RELACIONADOS CON EL PRODUCTO/////////////////////////
	cout<<"Producto-------:";
	cin>>descripcion;
	cout<<"Codigo---------:";
	cin>>id;     
	cout<<"Categoria------:";
	cin>>categoria;
	cout<<"Precio Venta---:";
	cin>>preciov;  
	cout<<"Precion Compra-:";
	cin>>precioc;  
	cout<<"Proveedor------:";
	cin>>proveedor;
	//////////////////////////////////////////////////////////////////////////////////////////////////

	//if(verifica(ced))	
	espr<<descripcion<<s;
	espr<<id<<s;     
	espr<<categoria<<s;
	espr<<preciov<<s;  
	espr<<precioc<<s;  
	espr<<proveedor<<s;
	espr.close();
	}

	else
	{
		cout<<"El archivo no se pudo abrir"<<s;
	}
		system ("pause");

	}
	
	
	void verpr(ifstream &Lec)
	{
system("color 4f");
system("mode con: cols=40 lines=1000");

		system ("cls");

	Lec.open("Productos.txt",ios::in);

	if(Lec.is_open())
	{
	cout<<"========================"<<s;
	cout<<"Productos de la Empresa"<<s;
	cout<<"========================"<<s;
	
	Lec>>descripcion;     
	while(!Lec.eof())
	{
	/////////////////////////////////////////////////INTRODUCIENDO DATOS DE PRODUCTOS NUEVAMENTE//////////////////
	Lec>>id;
	Lec>>categoria;
	Lec>>preciov;  
	Lec>>precioc;  
	Lec>>proveedor;	
	/////////////////////////////////////////////////ACCEDIENDO A DATOS DE desprcripcion/////////////////////////////////////

	cout<<"Codigo---------:"<<id<<s;
	cout<<"Producto-------:"<<descripcion<<s;
	cout<<"Categoria------:"<<categoria<<s;
	cout<<"Precio Venta---:"<<preciov<<s;
	cout<<"Precion Compra-:"<<precioc<<s;
	cout<<"Proveedor------:"<<proveedor<<s;

    cout<<"=========================="<<endl;
    Lec>>descripcion;

	}

	Lec.close();
	}

	else
	{
	
	cout<<"El archivo no se pudo abrir"<<s;
	}
		system ("pause");

	}
	
	
	void buscarpr(ifstream &Lec)
	{
		
system("color 4f");
system("mode con: cols=40 lines=25");

		system("cls");

	Lec.open("Productos.txt",ios::in);
	int mid;
	bool encontrado = false;
	cout<<"Digite No. id: ";
	cin>>mid;
			
	Lec>>descripcion;
	while(!Lec.eof() && !encontrado)
	{
		Lec>>id;     
		Lec>>categoria;
		Lec>>preciov;  
		Lec>>precioc;  
		Lec>>proveedor;


		if (id == mid)
		{
			cout<<"Producto-------:"<<descripcion<<s;
			cout<<"Codigo---------:"<<id<<s;
			cout<<"Categoria------:"<<categoria<<s;
			cout<<"Precio Venta---:"<<preciov<<s;
			cout<<"Precion Compra-:"<<precioc<<s;
			cout<<"Proveedor------:"<<proveedor<<s;
			encontrado = true;
		}

		Lec>>descripcion;

	}
	Lec.close();
	if(!encontrado)
	{
	
	cout<<"dato no encontrado"<<s;
	}
	system("pause");	
	}
	
	void modificarpr(ifstream &Lec)
	{
system("color 4f");
system("mode con: cols=40 lines=25");

	system("cls");
		string nomaux;
		int mid;

		Lec.open("Productos.txt",ios::in);
		ofstream aux("auxiliar.txt",ios::out);
		if (Lec.is_open())
		{
			cout<<"id---:";
			cin>>mid;
			Lec>>descripcion;
			while(!Lec.eof())
			{
				Lec>>id;     
				Lec>>categoria;
				Lec>>preciov;  
				Lec>>precioc;  
				Lec>>proveedor;

				if (id==mid)
				{
					cout<<"Nuevo Nombre---:";
					cin>>nomaux;
					aux<<nomaux<<s<<id<<s<<categoria<<s<<preciov<<s<<precioc<<s<<proveedor<<s;
				}
				else
				{
					aux<<descripcion<<s<<id<<s<<categoria<<s<<preciov<<s<<precioc<<s<<proveedor<<s;

				}

				Lec>>descripcion;
			}
			Lec.close();
			aux.close();
		}
		else
		{
		cout<<"ERROR"<<s;
		}
		remove("Productos.txt");
		rename("auxiliar.txt","Productos.txt");	
		
		system ("pause");

		
	}
	
	void borrarpr(ifstream &Lec)
	{
		
system("color 4f");
system("mode con: cols=40 lines=25");

		system("cls");
		string nomaux;
		string mcorreo;
		string mcargo;
		int mid;
		string mnivel;
		string msueldo;

		Lec.open("Productos.txt",ios::in);
		ofstream aux("auxiliar.txt",ios::out);
		if (Lec.is_open())
		{
			cout<<"id---:";
			cin>>mid;
			Lec>>descripcion;
			while(!Lec.eof())
			{
				Lec>>id;     
				Lec>>categoria;
				Lec>>preciov;  
				Lec>>precioc;  
				Lec>>proveedor;


				if (id==mid)
				{
					cout<<"Borrando......";
					Sleep(2000);
				}
				else
				{
					aux<<descripcion<<s<<id<<s<<categoria<<s<<preciov<<s<<precioc<<s<<proveedor<<s;

				}

				Lec>>descripcion;
			}
			Lec.close();
			aux.close();
		}
		else
		{
		cout<<"ERROR"<<s;
		}
		remove("Productos.txt");
		rename("auxiliar.txt","Productos.txt");
		
			system ("pause");

		
	}
	
///////////////////////////////////////////////			SERVICIOS
///////////////////////////////////////////////			SERVICIOS
///////////////////////////////////////////////			SERVICIOS
	
	void agregars(ofstream &Lec)
	{
	
system("color 4f");
system("mode con: cols=40 lines=25");

	string e=" ";

	system ("cls");

	ess.open("Servicios.txt",ios::out|ios::app);

	if(ess.is_open())
	{
	cout<<"========================"<<s;
	cout<<"    Ingresar Servicios   "<<s;
	cout<<"========================"<<s;

	//para ignorar la ultima instruccion del getline

	/////////////////////////////ENTRADA DE DATOS RELACIONADOS CON EL PRODUCTO/////////////////////////
	cout<<"Servicio-----------: ";
	cin>>serv;
	cout<<"Numero Servicio----: ";
	cin>>noserv;	
	cout<<"Tipo de servicio---: ";
	cin>>tserv;	
	cout<<"Precio/Tiempo(s)---: ";
	cin>>ptiempo;
	cout<<"Precio Minimo------: ";
	cin>>preciomin;  
	cout<<"Precio Maximo------: ";
	cin>>preciomax;
	//////////////////////////////////////////////////////////////////////////////////////////////////

	//if(verifica(ced))	
	ess<<serv<<s;
	ess<<noserv<<s;     
	ess<<tserv<<s;
	ess<<ptiempo<<s;
	ess<<preciomin<<s;  
	ess<<preciomax<<s;  
	ess.close();
	}

	else
	{
		cout<<"El archivo no se pudo abrir"<<s;
	}
	
		system("pause");
	
	}
	
	
	void vers(ifstream &Lec)
	{
system("color 4f");
system("mode con: cols=40 lines=500");
		system ("cls");

	Lec.open("Servicios.txt",ios::in);

	if(Lec.is_open())
	{
	cout<<"========================"<<s;
	cout<<"Servicios de la Empresa "<<s;
	cout<<"========================"<<s;

	Lec>>serv;
	while(!Lec.eof())
	{
	/////////////////////////////////////////////////INTRODUCIENDO DATOS DE PRODUCTOS NUEVAMENTE//////////////////
	
	Lec>>noserv;     
	Lec>>tserv;
	Lec>>ptiempo;
	Lec>>preciomin;
	Lec>>preciomax;  
	/////////////////////////////////////////////////ACCEDIENDO A DATOS DE desprcripcion/////////////////////////////////////

	cout<<"Servicio---------: "<<serv<<s;
	cout<<"No. de servicio--: "<<noserv<<s;
	cout<<"Tipo de Servicio-: "<<tserv<<s;
	cout<<"Precio/Tiempo(s)-: "<<ptiempo<<s;
	cout<<"Precio Minimo----: "<<preciomin<<s;
	cout<<"Precio Maximo----: "<<preciomax<<s;

    cout<<"=========================="<<endl;
    Lec>>serv;

	}
	Lec.close();
	}

	else
	{
	cout<<"El archivo no se pudo abrir"<<s;
	}
		system ("pause");
	}
	
	
	
	void buscars(ifstream &Lec)
	{
system("color 4f");
system("mode con: cols=40 lines=25");
		system("cls");

	Lec.open("Servicios.txt",ios::in);
	int bnserv;
	
	bool encontrado = false;
	
	cout<<"Digite No. de Servicio: ";
	cin>>bnserv;
	
	Lec>>serv;
	while(!Lec.eof() && !encontrado)
	{

		Lec>>noserv;
		Lec>>tserv;  
		Lec>>ptiempo;   
		Lec>>preciomin;
		Lec>>preciomax;

		if (noserv == bnserv)
		{
			cout<<"servicio---------:"<<serv<<s;
			cout<<"No. de servicio--:"<<noserv<<s;
			cout<<"tipo de Servicio-:"<<tserv<<s;
			cout<<"Precio/Tiempo(s)-: ";
			cout<<"Precio minimo----:"<<preciomin<<s;
			cout<<"Precion maximo---:"<<preciomax<<s;
			encontrado = true;
		}

		Lec>>serv;

	}
	Lec.close();
	if(!encontrado)
	{
	cout<<"dato no encontrado"<<s;
	}
	system("pause");	

	}
	
	
	
	
	void modificars(ifstream &Lec)
	{
system("color 4f");
system("mode con: cols=40 lines=25");
	system("cls");
		string nomaux;
		int bnserv;
		
		Lec.open("Servicios.txt",ios::in);
		ofstream aux("auxiliar.txt",ios::out);
		if (Lec.is_open())
		{ 
			cout<<"No. Servio---:";
			cin>>bnserv;
			Lec>>serv;
			while(!Lec.eof())
			{
				Lec>>noserv;
				Lec>>tserv; 
				Lec>>ptiempo;    
				Lec>>preciomin;
				Lec>>preciomax;	
					
				if (noserv==bnserv)
				{
					cout<<"Nuevo Nombre---:";
					cin>>nomaux;
					aux<<nomaux<<s<<noserv<<s<<tserv<<s<<ptiempo<<s<<preciomin<<s<<preciomax<<s;
				}
				else
				{
					aux<<serv<<s<<noserv<<s<<tserv<<s<<ptiempo<<s<<preciomin<<s<<preciomax<<s;
				}

				Lec>>serv;
			}
			Lec.close();
			aux.close();
		}
		else
		{
		cout<<"ERROR"<<s;
		}
		remove("Servicios.txt");
		rename("auxiliar.txt","Servicios.txt");	
		system ("pause");
	}
	
	
	
	void borrars(ifstream &Lec)
	{
system("color 4f");
system("mode con: cols=40 lines=25");
		system("cls");
		string nomaux;
		int bnserv;
		Lec.open("Servicios.txt",ios::in);
		ofstream aux("auxiliar.txt",ios::out);
		if (Lec.is_open())
		{
			cout<<"No. de Servicio---:";
			cin>>bnserv;
			
			Lec>>serv;
			while(!Lec.eof())
			{
				Lec>>noserv;
				Lec>>tserv;  
				Lec>>ptiempo;   
				Lec>>preciomin;  
				Lec>>preciomax;  


				if (noserv==bnserv)
				{
					cout<<"Borrando......";
					Sleep(2000);
				}
				else
				{
					aux<<serv<<s<<noserv<<s<<tserv<<s<<ptiempo<<s<<preciomin<<s<<preciomax<<s;
					
				}     

				Lec>>serv;
			}
			Lec.close();
			aux.close();
		}
		else
		{
		cout<<"ERROR"<<s;
		}
		remove("Servicios.txt");
		rename("auxiliar.txt","Servicios.txt");
		
	}
	
	
	
	void versuser()
	{
		Lec.open("Servicios.txt",ios::in);
						if(Lec.is_open())
						{
						cout<<"========================="<<s;
						cout<<"Servicios de la Empresa "<<s;
						cout<<"========================="<<s;
					
						Lec>>serv;
						while(!Lec.eof())
						{
							Lec>>noserv;  
							Lec>>tserv;
							Lec>>preciomin;
							Lec>>preciomax; 
							cout<<"No. de servicio--:"<<noserv<<s;
							cout<<"Servicio---------:"<<serv<<s;
							cout<<"=========================="<<endl;
						Lec>>serv;

						}
						Lec.close();
							
						}
						
						else
							{
							cout<<"El archivo no se pudo abrir"<<s;
							}
	}

	void verganancias(ifstream &Lec)///////////ganancias general empleados
	{
						system("mode con: cols=40 lines=500");
						system ("cls");
						system("color f3");
						struct ingreso empleado; 
						bool encontrado = false;
						suma = 0;
						
						Lec.open("ingresos.txt",ios::in);
						cout<<endl;
						cout<<endl;
						cout<<endl;
						cout<<"==============================="<<s;
						cout<<"            Historial          "<<s;
						cout<<"==============================="<<s;
						
						if(Lec.is_open())
						{
						
						Lec>>empleado.cliente,'\n';
						while(!Lec.eof())
						{
						//se agrega la lectura de la maquina para determinar de quien son los datos
						Lec>>empleado.servicio,'\n';
						Lec>>empleado.mservicio,'\n';
						Lec>>empleado.mtotal,'\n';
						Lec>>numeromaquina,'\n';
					
						cout<<"Nombre Cliente-----: "<<empleado.cliente<<endl;
						cout<<"Servicio realizado-: "<<empleado.servicio<<endl; 
						cout<<"Monto Total--------: "<<empleado.mtotal<<endl;							
						v.push_back(empleado.mtotal) ;

							
						cout<<"==============================="<<endl;
							
							
						
						
						Lec>>empleado.cliente,'\n';
 

						}
						
						
				
						
						Lec.close();
						//almacen sumando los datos de el vector
						for(double i = 0; i < v.size(); i++)
							{
							suma += v[i];
							
							}
							
						v.clear();
						gotoxy(1,1);	
						cout<<"Ganancia x Dia--------: "<<suma<<s;
						
						}
						
						getch();
						system ("pause");
		
	}

	
	
	
	void historialempleado (ifstream &Lec)/////////////////////////////Historial
	{
		
						system("mode con: cols=40 lines=500");
						system ("cls");
						system("color f3");
						struct ingreso empleado; 
						bool encontrado = false;
						suma = 0;
						
						
						Lec.open("ingresos.txt",ios::in);
						cout<<endl;
						cout<<endl;
						cout<<endl;
						cout<<"==============================="<<s;
						cout<<"            Historial          "<<s;
						cout<<"==============================="<<s;
						
						if(Lec.is_open())
						{
						
						Lec>>empleado.cliente,'\n';
						while(!Lec.eof())
						{
						//se agrega la lectura de la maquina para determinar de quien son los datos
						Lec>>empleado.servicio,'\n';
						Lec>>empleado.mservicio,'\n';
						Lec>>empleado.mtotal,'\n';
						Lec>>numeromaquina,'\n';
						
						if (numeromaquina == maquina)
						{
							
							cout<<"Nombre Cliente-----: "<<empleado.cliente<<endl;
							cout<<"Servicio realizado-: "<<empleado.servicio<<endl; 
							cout<<"Monto Servicio-----: "<<empleado.mservicio<<endl;
							cout<<"Monto Total--------: "<<empleado.mtotal<<endl;							
							v.push_back(empleado.mtotal);

							
							cout<<"==============================="<<endl;
							
							
							
						}
						
						
						
							Lec>>empleado.cliente,'\n';


						}
						
										
						
						
						for(double i = 0; i < v.size(); i++)
							{
								suma += v[i];
							}

							v.clear();

						
						//almacen sumando los datos de el vector
						
						
						}
						
						
						gotoxy(1,1);	
						cout<<"Ganancia Real--------: "<<suma*0.6<<s;
						cout<<"Ganancia Total-------: "<<suma<<s;
						
					 	 

						Lec.close();

						system ("pause");
						
		
	}
/////////////////////////////////////////		MENU PRINCIPAL USER
/////////////////////////////////////////		MENU PRINCIPAL USER
/////////////////////////////////////////		MENU PRINCIPAL USER

	void menuuser()
	{
		system("color f3");
		system("mode con: cols=80 lines=25");
		ifstream Lec;
		double emptotal;

		
		int opuser;
		
		do {
			system("cls");
			opuser = menuprincipaluser();
			
		switch (opuser)
			{	
				case 1:
				{
					
					instanteInicial = time(0);//tiempo inicial
					ingresoserv:
					system("cls");
					system("color f3");
					system("mode con: cols=80 lines=25");
					bool encontrado = false;
					Lec.open("Servicios.txt",ios::in);

					struct ingreso empleado; 
					
					ofstream in("ingresos.txt",ios::out|ios::app);
					
					if(in.is_open())
					{
					
					cout<<"\t========================"<<s;
					cout<<"\t   	INGRESOS		 "<<s;
					cout<<"\t========================"<<s;
					cout<<s;
					cout<<"Consultar Servicios(y/n)";
					string cs;
					
	
					cin>>cs;
					if (cs == "y")
					{
						system("cls");
						cout<<"Servicios";
						system("Serviciosapp.exe");
						goto ingresoserv;

					}
					
					else
					cout<<"Cliente--------------: ";
					cin>>empleado.cliente;
					cout<<"No. de Servicio------: ";
					cin>>empleado.noservicio;
					
					/////////////////////Prueba servicio
					
					Lec>>serv;
					while(!Lec.eof() && !encontrado)
					{
				
						Lec>>noserv;
						Lec>>tserv;     
						Lec>>ptiempo;
						Lec>>preciomin;
						Lec>>preciomax;
				
						if (noserv == empleado.noservicio)
						{
							cout<<"Servicio---------: "<<serv<<s;
							cout<<"tipo de Servicio-: "<<tserv<<s;
							cout<<"Precio Tiempo----: "<<ptiempo<<s;
							cout<<"Monto minimo-----: "<<preciomin<<s;
							cout<<"Monto maximo-----: "<<preciomax<<s;
							encontrado = true;
						}
				
						Lec>>serv;
				
					}
						Lec.close();
						
					if(!encontrado)
					{
					cout<<"No se ha encontrado el servicio"<<s;
					}
						
					/////////////////////Prueba servicio
					
					numeromaquina = maquina;

					cout<<"maquina"<<numeromaquina<<s;
					cout<<"Monto Servicio---: ";
					cin>>empleado.mservicio;
					empleado.servicio = serv;
					bool precioservicio = false;
					
					instanteFinal = time(0);
					while (empleado.mservicio > preciomin && empleado.mservicio < preciomax)
					{
					
					double tiempo = instanteFinal - instanteInicial;
					double pttiempo = tiempo*ptiempo;
					
					

					empleado.mtotal= empleado.mservicio + pttiempo;
					cout << "Tiempo: : " <<tiempo << "s"<<s;


					cout<<"Monto total------: "<<empleado.mtotal;
					cout<<s;
					//tiempo final

					//se agrega la maquina para identificar la tarea dada
					
					in<<empleado.cliente;
					in<<'\n';
					in<<empleado.servicio;
					in<<'\n';
					in<<empleado.mservicio;
					in<<'\n';
					in<<empleado.mtotal;
					in<<'\n';
					in<<numeromaquina;
					in<<endl;
					in.close();
					
					break;

					}
					
					}
					
					else
					cout<<"El archivo no se pudo abrir"<<s;	
					
					system("pause");

					}
					
					break;
					
				case 2://///////////////////////Historial
					
					{
						historialempleado(Lec);
						
					}
					
					break;
				case 3:////////////////M. Tareas
					{
						system ("cls");
						system("mode con: cols=80 lines=25");
						system("color f3");
						int z;
						gotoxy(0,0);
						stylecu();
						gotoxy (0,20);
						stylecu();
						gotoxy(28,8);
						
						gotoxy(28,9);
						cout<<"========================"<<s;
						gotoxy(28,10);
						cout<<"------M. TAREAS----"<<s;
						gotoxy(28,11);
						cout<<"========================"<<s;
						gotoxy(28,12);
						cout<<"1.	Agregar tarea"<<s;
						gotoxy(28,13);
						cout<<"2.	Borrar tarea"<<s;
						gotoxy(28,15);
						cout<<"Seleccione una opcion: ";cin>>z;
		
	switch (z)
	{
					case 1:////////////////Agregar Tarea
						{
						system("cls");
						system("mode con: cols=40 lines=25");
						system("color 4f");
								struct tareas pendientes; 
						ofstream es;
						es.open("tareas.txt",ios::out|ios::app);
						
						cout<<"\t========================"<<s;
						cout<<"\t   Agregar Pendientes   "<<s;
						cout<<"\t========================"<<s;
						cout<<s;
					
					if(es.is_open())
					{
						
					
					cout<<"Tarea----------: ";
					cin>>ws;
					getline(cin,pendientes.nomtarea,'\n');
					cout<<"Fecha inicio---: ";
					getline(cin,pendientes.fitarea,'\n');
					cout<<"Fecha entrega--: ";
					getline(cin,pendientes.fftarea,'\n');
					cout<<"Cliente--------: ";
					getline(cin,pendientes.cliente,'\n');
					cout<<"Abono----------: ";
					getline(cin,pendientes.abonotarea,'\n');
					cout<<"Descripcion----: ";
					getline(cin,pendientes.destarea,'\n');
					
					numeromaquina = maquina;
					
					//se agrega la maquina para identificar la tarea dada
					
					es<<pendientes.nomtarea;
					es<<'\n';
					es<<pendientes.fitarea;
					es<<'\n';
					es<<pendientes.fftarea;
					es<<'\n';
					es<<pendientes.cliente;
					es<<'\n';
					es<<pendientes.abonotarea;
					es<<'\n';
					es<<pendientes.destarea;
					es<<'\n';
					es<<numeromaquina;
					es<<endl;
					
					es.close();
					
					}
					
					else
					cout<<"El archivo no se pudo abrir"<<s;
					
					}
								
				
					break;
					case 2://///////////Borrar Tarea
								
					{
									
						system("color f3");
						system("mode con: cols=40 lines=25");
						system("cls");
						string btarea;
						struct tareas pendientes;
						
						Lec.open(tarea.c_str(),ios::in);		
				
						ofstream aux;
						aux.open(auxiliar.c_str (),ios::out);
						
									if (Lec.is_open())
									{												
										cout<<"Tarea---:";
										cin.ignore();
										getline(cin,btarea,'\n');
										getline(Lec, pendientes.nomtarea,'\n');
											while(!Lec.eof())
											{
												getline(Lec,pendientes.fitarea,'\n');	
												getline(Lec,pendientes.fftarea,'\n');
												getline(Lec,pendientes.cliente,'\n');
												getline(Lec,pendientes.abonotarea,'\n');	
												getline(Lec,pendientes.destarea,'\n');
												getline(Lec,numeromaquina,'\n');
	                     
												
												if (btarea==pendientes.nomtarea)
												{
													cout<<"Borrando......";
													Sleep(2000);
												}
												
												else
												{
                      
													aux<<pendientes.nomtarea;
													aux<<'\n';
													aux<<pendientes.fitarea;
													aux<<'\n';
													aux<<pendientes.fftarea;
													aux<<'\n';
													aux<<pendientes.cliente;
													aux<<'\n';
													aux<<pendientes.abonotarea;
													aux<<'\n';
													aux<<pendientes.destarea;
													aux<<'\n';
													aux<<numeromaquina;
													aux<<endl;
														
								        
												}
													getline(Lec, pendientes.nomtarea,'\n');

											}
															
									
									}
									
									
									else 
										{
											cout<<"ERROR "<<s;
										}	
									Lec.close();
									Esc.close();
									aux.close();
									remove(tarea.c_str ());
									rename(auxiliar.c_str (),tarea.c_str ());		
									
									
									
									
								}
							
							
							
							
							
								
								
							break;
							default:
							break;
						
		}
					
				}	
					
				break;
				
				case 4://ver tareas pendientes
					{
						system("mode con: cols=40 lines=500");
						system ("cls");
						system("color 4f");
						struct tareas pendientes; 
						bool encontrado = false;
						
						Lec.open("tareas.txt",ios::in);
						
						cout<<"========================"<<s;
						cout<<"    Tareas pendientes   "<<s;
						cout<<"========================"<<s;
						
						if(Lec.is_open())
						{

						
						
						getline(Lec, pendientes.nomtarea,'\n');
						while(!Lec.eof())
						{
						//se agrega la lectura de la maquina para determinar de quien son los datos
						getline(Lec, pendientes.fitarea,'\n');	
						getline(Lec, pendientes.fftarea,'\n');
						getline(Lec, pendientes.cliente,'\n');
						getline(Lec,pendientes.abonotarea,'\n');
						getline(Lec, pendientes.destarea,'\n');
						getline(Lec,numeromaquina,'\n');	

						if (numeromaquina == maquina)
						{
						
						cout<<"Nombre tarea-----:"<<pendientes.nomtarea<<endl;
						cout<<"Fecha inicial----:"<<pendientes.fitarea<<endl;
						cout<<"Fecha final------:"<<pendientes.fftarea<<endl; 
						cout<<"Abono realizado--:"<<pendientes.cliente<<endl; 
						cout<<"Abono realizado--:"<<pendientes.abonotarea<<endl; 
						cout<<"Descripcion------:"<<pendientes.destarea<<endl;  
						
					
						cout<<"==============================="<<endl;
						
						}

						getline(Lec, pendientes.nomtarea,'\n');
						

						}
						
						Lec.close();
						
						}
						
						system ("pause");
						
					}
					
				break;
				case 5:
					
					{
						Lec.open("Productos.txt");
						if (Lec.is_open())
						{
							system("cls");
							system("color 3f");
							system("mode con: cols=25 lines=500");
							

							   
							cout<<"========================="<<s;
							cout<<"Productos de la Empresa"<<s;
							cout<<"========================="<<s;
							
							Lec>>descripcion;
							while (!Lec.eof())
							{
								Lec>>id;
								Lec>>categoria;
								Lec>>preciov;
								Lec>>precioc;
								Lec>>proveedor;
								cout<<"Codigo---------: "<<id<<s;
								cout<<"Producto-------: "<<descripcion<<s;
								cout<<"Precio Venta---: "<<preciov<<s;
								cout<<"========================="<<endl;
    						Lec>>descripcion;
							}
							
							Lec.close();
							
							
	
						}
						
						
						else
							{
							
							cout<<"El archivo no se pudo abrir"<<s;
							}
						system("pause");
					}
					
				break;
				case 6:
					{
						system("color 3f");
						system("mode con: cols=40 lines=500");
						system ("cls");

						Lec.open("Servicios.txt",ios::in);
						if(Lec.is_open())
						{
						cout<<"========================"<<s;
						cout<<"Servicios de la Empresa "<<s;
						cout<<"========================"<<s;
					
						Lec>>serv;
						while(!Lec.eof())
						{
							Lec>>noserv;  
							Lec>>tserv;
							Lec>>ptiempo;
							Lec>>preciomin;
							Lec>>preciomax; 
							cout<<"No. de servicio--: "<<noserv<<s;
							cout<<"Servicio---------: "<<serv<<s;
							cout<<"Precio Minimo----: "<<preciomin<<s;
							cout<<"Precio Maximo----: "<<preciomax<<s;
							cout<<"=========================="<<endl;
						Lec>>serv;

						}
						Lec.close();
							
						}
						
						else
							{
							cout<<"El archivo no se pudo abrir"<<s;
							}
								system ("pause");
						
						
					}
				break;
				case 7:
					direccionales();
				break;
				case 9:
					system("cls");
					exit(0);
				break;
				default:
				break;
			}
		}
		while (opuser);
		
		
	}
	




/////////////////////////////////////////		MENU PRINCIPAL ADMIN
/////////////////////////////////////////		MENU PRINCIPAL ADMIN
/////////////////////////////////////////		MENU PRINCIPAL ADMIN

	void menuprincipaladmin()
	{
	gotoxy(0,6);	//localizacion cuadro arriba
	fechaactual();	
	ifstream Lec;
	system("color 4f");



	menup:
	int op;
	int repetir = 1;
	do
	{
		system ("cls");
		op = menuprincipal();
		switch(op)
		{
			
			case 1:
				verp(Lec);

			break;
			case 2:
				verpr(Lec);
			break;
			case 3:
				vers(Lec);
			break;
			case 4:
				personal:
				system ("cls");
				int x;
				
						gotoxy(0,0);
						stylecu();
						gotoxy (0,20);
						stylecu();
						gotoxy(28,8);
						cout<<"========================"<<s;
						gotoxy(28,9);
						cout<<"------Mantenimientos----"<<s;
						gotoxy(28,10);
						cout<<"========================"<<s;
						gotoxy(28,11);
						cout<<"1.	Ajuste Personal"<<s;
						gotoxy(28,12);
						cout<<"2.	Ajuste Productos"<<s;
						gotoxy(28,13);
						cout<<"3.	Ajuste Servicios"<<s;
						
						gotoxy (60,15);
						cout<<"7. Regresar"<<endl;
						gotoxy (60,16);
						cout<<"9. Salir"<<endl;
						gotoxy(28,16);
						cout<<"Seleccione una opcion: ";cin>>x;
						
						
						
						
				switch (x)
				{	
					case 1: //personal
						system ("cls");

						gotoxy(0,0);
						stylecu();
						gotoxy (0,20);
						stylecu();
						gotoxy(28,8);
						
						gotoxy(28,9);
						cout<<"========================"<<s;
						gotoxy(28,10);
						cout<<"------M. PERSONAL----"<<s;
						gotoxy(28,11);
						cout<<"========================"<<s;
						gotoxy(28,12);
						cout<<"1.	Agregar personal"<<s;
						gotoxy(28,13);
						cout<<"2.	Buscar Personal"<<s;
						gotoxy(28,14);
						cout<<"3.	Modificar personal"<<s;
						gotoxy(28,15);
						cout<<"4.	Borrar Personal"<<s;
						gotoxy (60,15);
						cout<<"7. Regresar"<<endl;
						gotoxy (60,16);
						cout<<"9. Salir"<<endl;
						
						gotoxy(28,16);
						cout<<"Seleccione una opcion: ";cin>>x;
		
						switch (x)
						{
							case 1:
								agregarp(Esc);
							break;
							case 2:
								buscarp(Lec);
							break;
							case 3:
								modificarp(Lec);
							break;
							case 4: 
								borrarp(Lec);
							break;
							case 7:				
								goto personal;
							break;
							case 9:
								system("cls");
								exit(0);
							break;
						}
					break;
												
					case 2: // productos
						
						system ("cls");
						gotoxy(0,0);
						stylecu();
						gotoxy (0,20);
						stylecu();
						gotoxy(28,8);
					
						gotoxy(28,8);
						cout<<"========================"<<s;
						gotoxy(28,9);
						cout<<"------M. PRODUCTOS----"<<s;
						gotoxy(28,10);
						cout<<"========================"<<s;
						gotoxy(28,11);
						cout<<"1.	Agregar productos"<<s;
						gotoxy(28,12);
						cout<<"2.	Buscar productos"<<s;
						gotoxy(28,13);
						cout<<"3.	Modificar productos"<<s;
						gotoxy(28,14);
						cout<<"4.	Borrar productos"<<s;
						gotoxy (60,15);
						cout<<"7. Regresar"<<endl;
						gotoxy (60,16);
						cout<<"9. Salir"<<endl;
						gotoxy(28,16);
						cout<<"Seleccione una opcion: ";cin>>x;	
											
						switch (x)
						{

							case 1:
								agregarpr(Esc);

							break;
							case 2:
								buscarpr(Lec);
							break;
							case 3:
								modificarpr(Lec);
							break;
							case 4: 
								borrarpr(Lec);
							break;
							
							case 7:				
								goto personal;
							break;
							case 9:
								system("cls");
								exit(0);
							break;
						}
					break;
					
					case 3:// SERVICIOS
						system ("cls");
						gotoxy(0,0);
						stylecu();
						gotoxy (0,20);
						stylecu();
						gotoxy(28,8);
					
						gotoxy(28,8);
						cout<<"========================"<<s;
						gotoxy(28,9);
						cout<<"------M. SERVICIOS----"<<s;
						gotoxy(28,10);
						cout<<"========================"<<s;
						gotoxy(28,11);
						cout<<"1.	Agregar Servicio"<<s;
						gotoxy(28,12);
						cout<<"2.	Buscar Servicio"<<s;
						gotoxy(28,13);
						cout<<"3.	Modificar Servicio"<<s;
						gotoxy(28,14);
						cout<<"4.	Borrar Servicio"<<s;
						gotoxy (60,15);
						cout<<"7. Regresar"<<endl;
						gotoxy (60,16);
						cout<<"9. Salir"<<endl;
						gotoxy(28,16);
						cout<<"Seleccione una opcion: ";cin>>x;
						
						
		
						switch (x)
						{
							case 1:
								agregars(Esc);
							break;
							case 2:
								buscars(Lec);
							break;
							case 3:
								modificars(Lec);
							break;
							case 4: 
								borrars(Lec);
							break;
							
							case 7:				
								goto personal;
							break;
							case 9:
								system("cls");
								exit(0);
							break;
														
						}
					break;
					
				}	
			break;
			case 5:
				{
						suma = 0;
						system ("cls");
						gotoxy(0,0);
						stylecu();
						gotoxy (0,20);
						stylecu();
						gotoxy(28,8);
					
						gotoxy(28,8);
						cout<<"========================"<<s;
						gotoxy(28,9);
						cout<<"--GANANCIAS / PERSONAL--"<<s;
						gotoxy(28,10);
						cout<<"========================"<<s;
						
						
						
						
						gotoxy(28,11);
						cout<<"1.	Empleados ganancia General"<<s;
						gotoxy(28,12);
						cout<<"2.	Ganancias por Empleados"<<s;
						gotoxy(28,13);
						cout<<"9. Salir"<<endl;
						gotoxy(28,16);
						cout<<"Seleccione una opcion: ";cin>>x;
						
						switch (x)
						{
							case 1:
								verganancias(Lec);
							break;
							case 2:
								
								{
									
						system("mode con: cols=40 lines=500");
						system ("cls");
						system("color f3");
						struct ingreso empleado; 
						string nomaquina;
						suma = 0;
						
						cout<<endl;
						cout<<endl;
						cout<<endl;
						cout<<"==============================="<<s;
						cout<<"            Historial          "<<s;
						cout<<"==============================="<<s;
						
						
						cout<<"Ingresar Maquina"<<s;
						cin>>nomaquina;
						
						
						
						Lec.open("ingresos.txt",ios::in);
					
							if(Lec.is_open())
						{
					
						Lec>>empleado.cliente,'\n';
						while(!Lec.eof())
						{
						//se agrega la lectura de la maquina para determinar de quien son los datos
						Lec>>empleado.servicio,'\n';
						Lec>>empleado.mservicio,'\n';
						Lec>>empleado.mtotal,'\n';
						Lec>>numeromaquina,'\n';
						
						
						if ( numeromaquina==nomaquina)
						{
							
							cout<<"Nombre Cliente-----: "<<empleado.cliente<<endl;
							cout<<"Servicio realizado-: "<<empleado.servicio<<endl; 
							cout<<"Monto Servicio-----: "<<empleado.mservicio<<endl;
							cout<<"Monto Total--------: "<<empleado.mtotal<<endl;							
							v.push_back(empleado.mtotal);

							
							cout<<"==============================="<<endl;
							
							
						}
						
							Lec>>empleado.cliente,'\n';
 

						}
							
		
						
						
						Lec.close();
						//almacen sumando los datos de el vector
						for(double i = 0; i < v.size(); i++)
							{
							suma += v[i];
							
							}
							v.clear();

						gotoxy(1,1);	
						cout<<"Ganancia x Dia--------: "<<suma<<s;
						
						}
						
						getch();
						system ("pause");
									
								}
							break;
							
							case 9:
								system("cls");
								exit(0);
							break;
														
						}
						
						
						
						
						
						
				}
			break;
			case 7:
				loginuser();
			break;
			case 9:
				system("cls");
				exit(0);
			break;
		}
	}
	while(repetir == 1);
}
