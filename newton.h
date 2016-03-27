//newton.h
#ifndef NEWTON_H
#define NEWTON_H

#include <string>

class newton{
public:
	newton();
	newton(double, double, std::string, std::string);
	double eval();
	~newton();

private:
	double xo, tol;
	std::string f;
	std::string g;
};
#endif
//newton.h
