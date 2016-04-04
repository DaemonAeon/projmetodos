//pluq.h
#ifndef PLUQ_H
#define PLUQ_H

class pluq{
public:
	pluq();
	pluq(int);
	~pluq();
	void calculate();
private:
	double** P;
	double** A;
	double** Q;
	double** L;
	double** U;
	double** AInversa;
	int n;
	void lu();
};
#endif
//pluq.h
