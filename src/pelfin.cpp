#include "point.h"
#include "pelfin.h"

P1::P1(){
    
 this->N=3;
 this->V=new point*[3];
 this->area=0; 
}



P1::~P1(){
	delete[] this->V;
}
P1::P1(const P1 &triangulo){
	this->N = triangulo.N;
	this->V=new point*[3];
	this->V[0] = triangulo.V[0];
	this->V[1] = triangulo.V[1];
	this->V[2] = triangulo.V[2];
	this->calcula_area();
}	

void P1::print_finel(){
    cout<<"---------------"<<endl;
    for (int k=0;k<(this->N);k++){
        this->V[k]->print_point();
    }
    cout<<"Area: "<<this->area<<endl;
    cout<<"---------------"<<endl;
}

void P1::calcula_area(){
	double aux1 = (this->V[0]->x)*(this->V[1]->y-this->V[2]->y);
	double aux2 = (this->V[1]->x)*(this->V[2]->y-this->V[0]->y);
	double aux3 = (this->V[2]->x)*(this->V[0]->y-this->V[1]->y);
	this->area = 0.5*(aux1+aux2+aux3);
}

