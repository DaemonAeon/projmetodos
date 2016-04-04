//euler.h
#ifndef EULER_H
#define EULER_H
#include <string>
#include <vector>
#include <string>
using namespace std;
class euler{
public:
	euler();
	euler(double X_inicial,double Y_inicial,double X_n,double H,string Funcion);
	~euler();

	private :
	string Funcion;
	double X_inicial;
	double Y_inicial;
	double X_n;
	double Resultado;
	double H;
	double EDPO(double X_inicial,double Y_inicial,double X_n,double H,string Funcion);
	public :
	double Calcular_Error(double Resultado,double Solucion);
	double Evaluar_O(double X,double Y,string Funcion);
	double EDPO_2(double X_inicial,double Y_inicial,double X_n,double H,string Funcion);
	double getResultado();
};
#endif
