//gauss.cpp
#include "gauss.h"
#include "exprtk.hpp"
#include <iostream>
gauss::gauss(){

}

gauss::gauss(int n, std::string a, std::string b, std::string func){
	this->n = n;
	this->a = a;
	this->b = b;
	this->func = func;


	typedef exprtk::symbol_table<double> symbol_table_t;
	typedef exprtk::expression<double> expression_t;
	typedef exprtk::parser<double> parser_t;

	symbol_table_t symbol_table1, symbol_table2;
	expression_t expression1, expression2;
	parser_t parser;

	double upper = 0;
	double lower = 0;

	symbol_table1.add_variable("b", upper);
	symbol_table2.add_variable("a", lower);

	expression1.register_symbol_table(symbol_table1);
	expression2.register_symbol_table(symbol_table2);

	parser.compile(b, expression1);
	upper = expression1.value();
	
	parser.compile(a, expression2);
	lower = expression2.value();

	outerConstant = (upper - lower) / 2;
	innerConstant = (upper + lower) / 2;

	std::cout << "outer:" << outerConstant << std::endl;
	std::cout << "inner:" << innerConstant << std::endl;

}

gauss::~gauss(){

}

double gauss::integr2pts(){
	typedef exprtk::symbol_table<double> symbol_table_t;
	typedef exprtk::expression<double> expression_t;
	typedef exprtk::parser<double> parser_t;

	symbol_table_t symbol_table;
	expression_t expression;
	parser_t parser;

	double eval1 = (outerConstant * -0.5773502691896257) + innerConstant;
	double eval2 = (outerConstant * 0.5773502691896257) + innerConstant;

	symbol_table.add_variable("x", eval1);

	expression.register_symbol_table(symbol_table);

	parser.compile(func,expression);
	
	double ret1 = outerConstant * expression.value();

	eval1 = eval2;

	return ret1 + outerConstant * expression.value();
	
}

double gauss::integr3pts(){
	typedef exprtk::symbol_table<double> symbol_table_t;
	typedef exprtk::expression<double> expression_t;
	typedef exprtk::parser<double> parser_t;

	symbol_table_t symbol_table;
	expression_t expression;
	parser_t parser;

	double eval1 = innerConstant;
	double eval2 = (outerConstant * -0.7745966692414834) + innerConstant;
	double eval3 = (outerConstant *	0.7745966692414834) + innerConstant;

	symbol_table.add_variable("x", eval1);

	expression.register_symbol_table(symbol_table);

	parser.compile(func,expression);
	
	double ret1 = 0.8888888888888888 * (outerConstant * expression.value());

	eval1 = eval2;

	double ret2 = 0.5555555555555556 * (outerConstant * expression.value());

	eval1 = eval3;	

	return ret1 + ret2 + 0.5555555555555556 * (outerConstant * expression.value());
}


double gauss::integr4pts(){
	typedef exprtk::symbol_table<double> symbol_table_t;
	typedef exprtk::expression<double> expression_t;
	typedef exprtk::parser<double> parser_t;

	symbol_table_t symbol_table;
	expression_t expression;
	parser_t parser;

	double eval1 = (outerConstant * -0.3399810435848563) + innerConstant;
	double eval2 = (outerConstant * 0.3399810435848563) + innerConstant;
	double eval3 = (outerConstant *	-0.8611363115940526) + innerConstant;
	double eval4 = (outerConstant *	0.8611363115940526) + innerConstant;

	symbol_table.add_variable("x", eval1);

	expression.register_symbol_table(symbol_table);

	parser.compile(func,expression);
	
	double ret1 = 0.6521451548625461 * (outerConstant * expression.value());

	eval1 = eval2;

	double ret2 = 0.6521451548625461 * (outerConstant * expression.value());

	eval1 = eval3;

	double ret3 = 0.3478548451374538 * (outerConstant * expression.value());

	eval1 = eval4;	

	return ret1 + ret2 + ret3 + 0.3478548451374538 * (outerConstant * expression.value());
}

double gauss::eval(){
	double retVal = 0.0;
	switch(n){
		case 2:{
			retVal = integr2pts();
		}
		break;

		case 3:{
			retVal = integr3pts();
		}
		break;

		case 4:{
			retVal = integr4pts();
		}
		break;

		default:{
			//ERROR
		}
		break;
	}
	return retVal;
}

//gauss.cpp
