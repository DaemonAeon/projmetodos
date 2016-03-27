//newton.cpp
#include "newton.h"
#include "exprtk.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <cmath> 
#include <iomanip>
#include <string.h> 

using namespace std;

newton::newton(){

}

newton::newton(double xo, double tol, std:: string f, std:: string g){
	this->xo = xo;
	this->tol = tol;
	this->f = f;
	this->g = g;
}

double newton::eval(){
	typedef exprtk::symbol_table<double> symbol_table_t;
	typedef exprtk::expression<double> expression_t;
	typedef exprtk::parser<double> parser_t;

	symbol_table_t symbol_table;
	expression_t expression;
	parser_t parser;
	
	int n = 0;
	std::vector<double> nrEval;
	std::vector<double> nrTol; 
	double evalTol, evalXo, valorRetorno;

	std::string equation;  

	equation = "x-" +  f + '/' + g;
	cout << endl << "Ecuación Newton-Raphson: " << equation << endl;
	cout << endl << setw(5) << "n" << setw(20) << "Xn" << setw(20) << "|Xn - Xn-1|" << endl;
		
	do {
		
		symbol_table.clear();
		
		if (n == 0) {

			symbol_table.add_variable("x", xo);
			expression.register_symbol_table(symbol_table);
			parser.compile(equation,expression);

			nrEval.push_back(expression.value());
			nrTol.push_back(0);
			evalTol = 0;

		} else {

			double tempX = nrEval[n-1];
		
			symbol_table.add_variable("x", tempX);
			expression.register_symbol_table(symbol_table);
			parser.compile(equation,expression);

			nrEval.push_back(expression.value());
			evalTol = abs((nrEval[n])-(nrEval[n-1]));
			nrTol.push_back(evalTol);
		}
		cout.precision(8);
		cout << setw(5) << n+1 << setw(20) << nrEval[n] << setw(20) << nrTol[n] << endl;
		
		n++;
		
	} while (evalTol > tol || evalTol == 0);
	
	valorRetorno = nrEval[n-1];

	return valorRetorno;

}

newton::~newton(){
}