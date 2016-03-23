//gauss.h
#ifndef GAUSS_H
#define GAUSS_H

#include <string>
class gauss{
public:
	gauss();
	gauss(int, std::string, std::string, std::string);
	~gauss();
	double eval();
private:
	int n;//numero de puntos, 2-4 inclusive
	std::string a;//limite inferior
	std::string b;//limite superior
	std::string func;//función

	double outerConstant;//para el método
	double innerConstant;//para el método
	
	double integr2pts();
	double integr3pts();
	double integr4pts();
};
#endif
//gauss.h
