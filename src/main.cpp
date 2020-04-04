
#include "header.h"
#include "dato.h"
#include <stdlib.h>

#include "point.h"

#include "pelfin.h"


#include "mesh.h"
#include "Eigen/Dense"
using Eigen::Matrix3d;
using Eigen::Vector3d;

int main() {
/*
	point punto1 = point(1,0);
	punto1.print_point();

	point punto2 = point(0,1);
	punto2.print_point();
		
	point punto3 = point(1,1);
	punto3.print_point();

	P1 prueba;
	prueba.V[0] = &punto1;
	prueba.V[1] = &punto2;
	prueba.V[2] = &punto3;

	P1 triangulo = P1(prueba);
	
	point* p = new point[3];
	Vector3d v;
	triangulo.calcula_vector_local(p,v,f);
	cout<<"Las coordenadas puntos medios son: "<<endl;
	for (int i=0;i<3;i++) p[i].print_point();
	cout<<"Los valores calculados son: "<<endl;
	cout<<v<<endl;
	
	// cout<<punto1.producto_escalar(punto2)<<endl;
	*/
	dato datos;
	datos.leedatos();

	Mfinel <P1> malla; // Elijo EN ESTE MOMENTO el tipo de Elemento finito, P1
	   
	malla.fill_mesh(datos); // lee los mallados desde fichero

	//malla.print_nodes(); // Imprimimos los nodos
	  
	   
	// malla.print_elements(); // Imprimimos los elementos
	malla.construye_matriz_global();
        malla.boundary_conditions();	
	cout<<"Calculando solucion del sistema"<<endl;
    	malla.solve();

}


                
