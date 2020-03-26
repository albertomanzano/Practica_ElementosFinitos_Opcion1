#include "point.h"
int puntos_creados = 0;

point::point(){
	this->x = 8;
	this->y = 0;
	puntos_creados++; 
	this->ind = puntos_creados;
	this->front = 0;
	this->sol = 0;
}

point::point(double x,double y){
	this->x = x;
	this->y = y;
	puntos_creados++;
	this->ind = puntos_creados;
	this->front = 0;
	this->sol = 0;
}

void point::print_point(){
    cout<<"("<<this->x<<","<<this->y<<")"<<"ind "<<this->ind<<" front "<<this->front<<endl; 
}

double point::producto_escalar(point punto2){
	return this->x*punto2.x+this->y*punto2.y;
}
