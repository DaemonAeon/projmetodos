//euler.cpp
#include "euler.h"
#include "exprtk.hpp"
#include <string>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;


euler::euler(){

}
euler::euler(double X_inicial,double Y_inicial,double X_n,double H,string Funcion){

  this->X_inicial = X_inicial;
  this->Y_inicial = Y_inicial;
  this->X_n = X_n;
  this->H = H;
  this->Funcion = Funcion;
  this->Resultado=EDPO(X_inicial,Y_inicial,X_n,H,Funcion);

}

euler::~euler(){

}


double euler::EDPO(double X_inicial,double Y_inicial,double X_n,double H,string Funcion){

  cout<<"\t"<<"Xn"<<"\t"<<"Yn"<<endl;
  for (int i = 0; i <X_n; i++) {
    Y_inicial= Y_inicial +(H*Evaluar_O(X_inicial,Y_inicial,Funcion));
    cout<<"\t"<<X_inicial<<"\t"<<Y_inicial<<endl;
    X_inicial = X_inicial + H;
  }
    return Y_inicial;
}

double euler::EDPO_2(double X_inicial,double Y_inicial,double X_n,double H,string Funcion){
  double Y_siguiente =0.0,result=0.0;
  cout<<"\t"<<"Xn"<<"\t"<<"Yn"<<"\t"<<"Y(n+1)*"<<"\t"<<"Y(n+1)"<<endl;

  for (int i = 0; i <X_n; i++) {
    Y_inicial= Y_inicial +(H*Evaluar_O(X_inicial,Y_inicial,Funcion));
    Y_siguiente = Y_inicial + (H*Evaluar_O(X_inicial+H,Y_inicial,Funcion));
    result = Y_siguiente + ((H/2)*(Evaluar_O(X_inicial,Y_inicial+H,Funcion)+Y_siguiente));
    cout<<"\t"<<X_inicial<<"\t"<<Y_inicial<<"\t"<<Y_siguiente<<"\t"<<result<<endl;
    X_inicial = X_inicial + H;
  }
    return result;
}



double euler::Evaluar_O(double X,double Y,string Funcion){
  typedef exprtk::symbol_table<double> symbol_table_t;
     typedef exprtk::expression<double> expression_t;
     typedef exprtk::parser<double> parser_t;
     typedef exprtk::parser_error::type error_t;

     std::string expression_str = Funcion;

     double x = X;
     double y = Y;
     double e = exp (1);
     double ln = log(Y)/(double)(log(e));
     symbol_table_t symbol_table;
     symbol_table.add_constants();
     symbol_table.add_variable("x",x);
     symbol_table.add_variable("y",y);
     symbol_table.add_variable("e",e);
     symbol_table.add_variable("ln",ln);

     expression_t expression;
     expression.register_symbol_table(symbol_table);
     parser_t parser;

     if (!parser.compile(expression_str,expression))
     {
        printf("Error: %s\tExpression: %s\n",
               parser.error().c_str(),
               expression_str.c_str());

        for (std::size_t i = 0; i < parser.error_count(); ++i)
        {
           error_t error = parser.get_error(i);
           printf("Error: %02d Position: %02d Type: [%s] Msg: %s Expr: %s\n",
                  static_cast<int>(i),
                  static_cast<int>(error.token.position),
                  exprtk::parser_error::to_str(error.mode).c_str(),
                  error.diagnostic.c_str(),
                  expression_str.c_str());
        }

        return 1;
     }

    double result = expression.value();
    return result;
}

double euler::getResultado(){

    return Resultado;
}

	double euler::Calcular_Error(double Resultado,double Solucion){
    return abs((Solucion-Resultado)/(double)(Solucion));
  }
