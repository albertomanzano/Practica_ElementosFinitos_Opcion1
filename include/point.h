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
	
	void print_point();
	double producto_escalar(point punto2);
};
  


#endif
