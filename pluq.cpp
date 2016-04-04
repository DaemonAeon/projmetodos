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
		int h = 0;
		bool pos=false;
		for (int j = i+1; j < n; j++){
			double l = U[j][i]/U[i][i];
			if (l<0){
				L[j][i]=l;
				L[j][i]=L[j][i]*-1;
				pos=false;
			} else {
				L[j][i]=l;
				pos=true;
			}
			for (int k = j - h; k < n; k++){
				U[j][k]=U[j][k]+U[i][k]*((U[j][i]*-1)/U[i][i]);
			}
			U[j][i] = 0;
			h++;
		}

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
			for (int k = 0; k < j-1; k++){
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
				sum+=U[j][k]*AInversa[k][i];
			}
			AInversa[j][i] = (D[j]-sum)/U[j][j];
		}
	}
	//Imprimir las matrices
	cout << setw(15) << "P" << endl;
	for (int j = 0; j < n; j++){
		for (int k = 0; k < n; k++){
			cout << setw(10) << setprecision(2) << P[j][k];
		}
		cout << endl;
	}
	cout << endl;
	cout << setw(15) << "A" << endl;
	for (int j = 0; j < n; j++){
		for (int k = 0; k < n; k++){
			cout << setw(10) << setprecision(2) << A[j][k];
		}
		cout << endl;
	}
	cout << endl;
	cout << setw(15) << "Q" << endl;
	for (int j = 0; j < n; j++){
		for (int k = 0; k < n; k++){
			cout << setw(10) << setprecision(2) << Q[j][k];
		}
		cout << endl;
	}
	cout << endl;
	cout << setw(15) << "L" << endl;
	for (int j = 0; j < n; j++){
		for (int k = 0; k < n; k++){
			cout << setw(10) << setprecision(2) << L[j][k];
		}
		cout << endl;
	}
	cout << endl;
	cout << setw(15) << "U" << endl;
	for (int j = 0; j < n; j++){
		for (int k = 0; k < n; k++){
			cout << setw(10) << setprecision(2) << U[j][k];
		}
		cout << endl;
	}
	cout << endl;
	cout << setw(15) << "A Inversa" << endl;
	for (int j = 0; j < n; j++){
		for (int k = 0; k < n; k++){
			cout << setw(10) << setprecision(2) << AInversa[j][k];
		}
		cout << endl;
	}
	cout << endl;
}

void pluq::lu(){
	int i = 0, j = 0, k = 0;

	double** Atemp = new double*[n];
	for (int a = 0; a < n; a++){
		Atemp[a] = new double[n];
	}
	for (int a = 0; a < n; a++){
		for (int b = 0; b < n; b++){
			Atemp[a][b] = A[a][b];
		}
	}

	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++){
			Atemp[i][j] = U[i][j];
			U[i][j] = 0;
		}

	for(k=0;k<n;k++) {
		
		L[k][k]=1;
	 
		for(j=k;j<n;j++) {
			long double sum=0;
			for(int s=0;s<=k-1;s++) {
			    sum+= L[k][s]*U[s][j];
			}
			U[k][j]=Atemp[k][j]-sum;
		}
	 
		for(i=k+1;i<n;i++) {
			long double sum=0;
			for(int s=0;s<=k-1;s++) {
			    sum+=L[i][s]*U[s][k];
			}
			L[i][k]=(Atemp[i][k]-sum)/U[k][k];
		}
	}

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
