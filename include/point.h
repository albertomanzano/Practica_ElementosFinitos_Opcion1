#ifndef __POINT_
#define __POINT_

#include <iostream>
using namespace std;
extern int  puntos_creados;

class point{
    public:
	// Atributos  
        double x;
        double y;
        int ind;
	int front;
	double sol;
	
	point();
	point(double x,double y);
	point operator+(point const &punto);	

	void print_point();
	double producto_escalar(point &punto2);
	double  producto_gradientes(point &punto2);
	void calcula_punto_medio(const point &punto1,const point &punto2);
};

double determinante(const point &p1,const point &p2,const point &p3);
double f(const point &p);

#endif
