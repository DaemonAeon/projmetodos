//main.cpp
#include <iostream>
#include "newton.h"
#include "pluq.h"
#include "gauss.h"
#include "diferencia.h"

using namespace std;

int main(int argc, char* argv[]){
		cout << "********************Proyecto de Métodos Numéricos********************" << endl;
		cout << "Integrantes: " << endl;
		cout << "David Discua" << endl;
		cout << "Katherine Lozano" << endl;
		cout << "Carlos Morazán" << endl;
		cout << "*********************************************************************" << endl;
	while(true){
		cout << endl << endl;
		cout << "1) Newton-Raphson para sistemas" << endl;
		cout << "2) Inversa de una matriz por PLUQ" << endl;
		cout << "3) Cuadratura de Gauss" << endl;
		cout << "4) Diferencia finita" << endl;
		char c;
		cin >> c;
		switch(c){
			case '1':{
				//Newton-Raphson
			}
			break;
			case '2':{
				//PLUQ
			}
			break;
			case '3':{
				//Cuadratura de Gauss
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
