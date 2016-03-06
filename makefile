all:
	g++ main.cpp newton.cpp pluq.cpp gauss.cpp diferencia.cpp && ./a.out
clean:
	rm *.out
