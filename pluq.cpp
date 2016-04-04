//pluq.cpp
#include "pluq.h"
#include <iostream>
#include <cmath> 
#include <iomanip>

using namespace std;

pluq::pluq(){

}

pluq::pluq(int n){
	this->n=n;
	this->A = new double*[n];
	this->AInversa = new double*[n];
	this->P = new double*[n];
	this->Q = new double*[n];
	this->L = new double*[n];
	this->U = new double*[n];
	for (int i = 0; i < n; i++){
		A[i] = new double[n];
		AInversa[i] = new double[n];
		P[i] = new double[n];
		Q[i] = new double[n];
		L[i] = new double[n];
		U[i] = new double[n];
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cout << "Ingrese el elemento " << i << ", " << j << ": ";
			cin >> A[i][j];
			double num;
			num = A[i][j];
			U[i][j]=num;
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (i==j){
				P[i][j]=1;
				Q[i][j]=1;
				L[i][j]=1;
			} else {
				P[i][j]=0;
				Q[i][j]=0;
				L[i][j]=0;
			}
		}
	}
}
void pluq::calculate(){
	for (int i = 0; i < n; i++){
		//Encontrar el maximo de la matriz
		double max=U[i][i];
		int f=i;
		int c=i;
		for (int j = i; j < n; j++){
			for (int k = 0; k < n; k++){
				if (U[j][k]>max){
					max=U[j][k];
					f=j;
					c=k;
				}
			}
		}

		// P y Q
		double temp;
		for (int j = 0; j < n; j++){
			temp=P[i][j];
			P[i][j]=P[f][j];
			P[f][j]=temp;
		}
		for (int j = 0; j < n; j++){
			temp=Q[j][i];
			Q[j][i]=Q[j][c];
			Q[j][c]=temp;
		}
		//Intercambio U
		for (int j = 0; j < n; j++){
			temp=U[i][j];
			U[i][j]=U[f][j];
			U[f][j]=temp;
		}
		for (int j = 0; j < n; j++){
			temp=U[j][i];
			U[j][i]=U[j][c];
			U[j][c]=temp;
		}

		//L y U
		for (int j = i+1; j < n; j++){
			if (((U[j][i]*-1)/U[i][i])>0){
				L[j][i]=U[j][i]/U[i][i];
				L[j][i]=L[j][i]*-1;
			} else {
				L[j][i]=U[j][i]/U[i][i];
			}
			for (int k = 0; k < n; k++){
				U[j][k]=U[j][k]+U[i][k]*((U[j][i]*-1)/U[i][i]);
			}
		}

		cout << setw(15) << "U" << endl;
		for (int j = 0; j < n; j++){
			for (int k = 0; k < n; k++){
				cout << setw(5) << setprecision(2) << U[j][k];
			}
			cout << endl;
		}
		cout << endl;

	}
	//Inversa
	for (int i = 0; i < n; i++){
		double* D = new double[n];
		double* I = new double[n];
		for (int j = 0; j < n; j++){
			if (j==i){
				I[j]=1;
			} else {
				I[j]=0;
			}
		}
		//LX=Ii
		//Sustitución hacia adelante
		D[0]=I[0];
		for (int j = 1; j < n; j++){
			double sum = 0;
			for (int k = 0; k < j; k++){
				sum+=L[j][k]*D[k];
			}
			D[j] = I[j]-sum;
		}

		//UY=X
		//Sustitución hacia atrás
		AInversa[n-1][i]=D[n-1];
		for (int j = n-2; j > 0; j--){
			double sum = 0;
			for (int k = n-1; k > j; k--){
				sum+=U[j][k]*AInversa[k][j];
			}
			AInversa[j][i] = (D[j]-sum)/U[j][j];
		}
	}
	//Imprimir las matrices
	cout << setw(15) << "P" << endl;
	for (int j = 0; j < n; j++){
		for (int k = 0; k < n; k++){
			cout << setw(5) << setprecision(2) << P[j][k];
		}
		cout << endl;
	}
	cout << endl;
	cout << setw(15) << "A" << endl;
	for (int j = 0; j < n; j++){
		for (int k = 0; k < n; k++){
			cout << setw(5) << setprecision(2) << A[j][k];
		}
		cout << endl;
	}
	cout << endl;
	cout << setw(15) << "Q" << endl;
	for (int j = 0; j < n; j++){
		for (int k = 0; k < n; k++){
			cout << setw(5) << setprecision(2) << Q[j][k];
		}
		cout << endl;
	}
	cout << endl;
	cout << setw(15) << "L" << endl;
	for (int j = 0; j < n; j++){
		for (int k = 0; k < n; k++){
			cout << setw(5) << setprecision(2) << L[j][k];
		}
		cout << endl;
	}
	cout << endl;
	cout << setw(15) << "U" << endl;
	for (int j = 0; j < n; j++){
		for (int k = 0; k < n; k++){
			cout << setw(5) << setprecision(2) << U[j][k];
		}
		cout << endl;
	}
	cout << endl;
	cout << setw(15) << "A Inversa" << endl;
	for (int j = 0; j < n; j++){
		for (int k = 0; k < n; k++){
			cout << setw(5) << setprecision(2) << AInversa[j][k];
		}
		cout << endl;
	}
	cout << endl;
}

pluq::~pluq(){
	for (int i = 0; i < n; i++){
		delete[] P[i];
	}
	delete[] P;
	for (int i = 0; i < n; i++){
		delete[] A[i];
	}
	delete[] A;
	for (int i = 0; i < n; i++){
		delete[] Q[i];
	}
	delete[] Q;
	for (int i = 0; i < n; i++){
		delete[] L[i];
	}
	delete[] L;
	for (int i = 0; i < n; i++){
		delete[] U[i];
	}
	delete[] U;
	for (int i = 0; i < n; i++){
		delete[] AInversa[i];
	}
	delete[] AInversa;
}
//pluq.cpp
