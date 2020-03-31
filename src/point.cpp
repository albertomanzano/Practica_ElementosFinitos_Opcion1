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


point point::operator+(point const &p){
	point resultado;
	resultado.x = this->x+p.x;
	resultado.y = this->y+p.y;
	return resultado;
}

void point::calcula_punto_medio(const point &p1,const point &p2){
	this->x = (p1.x+p2.x)/2;
	this->y = (p1.y+p2.y)/2;
}

void point::print_point(){
    cout<<"("<<this->x<<","<<this->y<<")"<<"ind "<<this->ind<<" front "<<this->front<<endl; 
}

double point::producto_escalar(point &punto2){
	return this->x*punto2.x+this->y*punto2.y;
}

double determinante(const point &p1,const point &p2,const point &p3){
	double aux1 = p2.x*p3.y-p2.y*p3.x;
	double aux2 = p1.x*p3.y-p1.y*p3.x;
	double aux3 = p1.x*p2.y-p1.y*p2.x;
	return aux1-aux2+aux3;
}

double f(const point &p){
	return (p.x+p.y);
}
