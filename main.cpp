//main.cpp
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "newton.h"
#include "pluq.h"
#include "gauss.h"
#include "diferencia.h"
#include "euler.h"

using namespace std;

int main(int argc, char* argv[]){
		cout << "********************Proyecto de Métodos Numéricos********************" << endl;
		cout << "Integrantes:" << endl;
		cout << "David Discua" << endl;
		cout << "Gisselle Lagos" << endl;
		cout << "Katherine Lozano" << endl;
		cout << "Carlos Morazán" << endl;
		cout << "*********************************************************************" << endl;
	while(true){
		cout << endl << endl;
		cout << "1. Newton-Raphson para sistemas" << endl;
		cout << "2. Inversa de una matriz por PLUQ" << endl;
		cout << "3. Cuadratura de Gauss" << endl;
		cout << "4. Diferencia finita" << endl;
		cout << "5. Salir" << endl;
		cout << "Opción seleccionada: ";
		char c;
		cin >> c;
		switch(c){
			case '1':{
				//Newton-Raphson
				string f, g;
				double xo, tol, x;
				cout << endl;
				cout << "Ingrese f(x): ";
				cin >> f;
				cout << "Ingrese f'(x): ";
				cin >> g;
				cout << "Ingrese Xo: ";
				cin >> xo;
				cout << "Ingrese la toleracia deseada: ";
				cin >> tol;
				cout << endl;
				newton nR(xo, tol, f, g);
				x = nR.eval();
				cout.precision(6);
				cout << endl << "Valor de x: " << x << endl;	
			}
			break;
			case '2':{
				//PLUQ
			}
			break;
			case '3':{
				//Cuadratura de Gauss
				int n;
				string func;
				string a;
				string b;

				cout << "Ingrese cantidad de puntos (2-4): ";
				cin >> n;
				cout << "Ingrese función: ";
				cin >> func;
				cout << "Ingrese el límite superior: ";
				cin >> b;
				cout << "Ingrese el límite inferior: ";
				cin >> a;

				gauss g(n, a, b, func);
				cout << "Resultado: " << g.eval();
			}
			break;
			case '4':{
				//Diferencia finita
					//metodo de euler
					int Eq_orden = 0;
					int cal_e =0;
					string Ecuacion_Dif = "";
					string Ecuacion_Exacta = "";
					double C = 1.0;
					double X_E = 0.0;
					double X_inicial=0;
					double Y_inicial=0;
					int X_n=0;
					double H = 0;
					cout<<"Ingrese el método a utlizar 1:Euler , 2:Euler Mejorado"<<endl;
					cin>>Eq_orden;
					if(Eq_orden==1){
							cout<<"Método de Euler"<<endl;
							cout<< "Ingrese la ecuacion diferencial (Y'= y -x^2 +10)"<<endl;
							cin>>Ecuacion_Dif;
							cout<<"Ingrese el valor inicial de X : "<<endl;
							cin>>X_inicial;
							cout<<"Ingrese Y("<<X_inicial<<") : "<<endl;
							cin>>Y_inicial;
							cout<<"Ingrese el espaciamiento H : "<<endl;
							cin>>H;
							cout<<"Ingrese el X_n que desea calcular :"<<endl;
							cin>>X_n;
							cout<<"¿Desea calcular el error real? SI:1 NO:2"<<endl;
							cin>>cal_e;

							if(cal_e==1){
									X_E = X_n*H;
									C = Y_inicial;
								cout<<"====Datos para calular el error==="<<endl;
								cout<<"Ingrese la solucion a la ecuacion "<<endl;
								cin>>Ecuacion_Exacta;
								euler E(X_inicial,Y_inicial,X_n,H,Ecuacion_Dif);
								cout<< "Resultado : "<<E.getResultado()<<endl;
								double Solucion = E.Evaluar_O(X_E,C,Ecuacion_Exacta);
								cout<<"Solucion Real :"<<Solucion<<endl;
								cout<<"Error : "<<E.Calcular_Error(E.getResultado(),Solucion)<<endl;

							}else{
								euler E(X_inicial,Y_inicial,X_n,H,Ecuacion_Dif);
								cout<< "Resultado : "<<E.getResultado()<<endl;
							}

					}else if(Eq_orden==2){
						cout<<"Metodo de Euler Mejorado"<<endl;
						cout<< "Ingrese la ecuacion diferencial (Y'= y -x^2 +10)"<<endl;
						cin>>Ecuacion_Dif;
						cout<<"Ingrese el valor inicial de X : "<<endl;
						cin>>X_inicial;
						cout<<"Ingrese Y("<<X_inicial<<") : "<<endl;
						cin>>Y_inicial;
						cout<<"Ingrese el espaciamiento H : "<<endl;
						cin>>H;
						cout<<"Ingrese el X_n que desea calcular :"<<endl;
						cin>>X_n;
						cout<<"¿Desea calcular el error real? SI:1 NO:2"<<endl;
						cin>>cal_e;

						if(cal_e==1){
								X_E = X_n*H;
								C = Y_inicial;
							cout<<"====Datos para calular el error==="<<endl;
							cout<<"Ingrese la solucion a la ecuacion "<<endl;
							cin>>Ecuacion_Exacta;
							euler E;
							double result = E.EDPO_2(X_inicial,Y_inicial,X_n,H,Ecuacion_Dif);
							cout<< "Resultado : "<<result<<endl;
							double Solucion = E.Evaluar_O(X_E,C,Ecuacion_Exacta);
							cout<<"Solucion Real :"<<Solucion<<endl;
							cout<<"Error : "<<E.Calcular_Error(result,Solucion)<<endl;

						}else{
							euler E;
							double result = E.EDPO_2(X_inicial,Y_inicial,X_n,H,Ecuacion_Dif);
							cout<< "Resultado : "<<result<<endl;
						}



					}else{
							cout<<"Orden no econtrado"<<endl;
					}

			}
			break;
			default:{
				return 0;
			}
			break;
		}
	}

	return 0;
}
//main.cpp
