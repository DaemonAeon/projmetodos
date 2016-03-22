//gauss.h
#ifndef GAUSS_H
#define GAUSS_H

#include <string>
class gauss{
public:
	gauss();
	gauss(int, float, float, std::string);
	~gauss();
	double eval();
private:
	int n;//numero de puntos, 2-4 inclusive
	float a;//limite inferior
	float b;//limite superior
	std::string func;//función
	
	double integr2pts();
	double integr3pts();
	double integr4pts();
};
#endif
//gauss.h
