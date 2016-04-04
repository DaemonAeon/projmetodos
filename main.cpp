//main.cpp
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "newton.h"
#include "pluq.h"
#include "gauss.h"
#include "diferencia.h"

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
