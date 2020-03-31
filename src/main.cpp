
#include "header.h"
#include "dato.h"
#include <stdlib.h>

#include "point.h"

#include "pelfin.h"


#include "mesh.h"
#include "Eigen/Dense"
using Eigen::Matrix3d;

int main() {
point punto1 = point(1,0);
punto1.print_point();

point punto2 = point(0,1);
punto2.print_point();
	
point punto3 = point(1,1);
punto3.print_point();

cout<<determinante(punto1,punto2,punto3)<<endl;
P1 prueba;
prueba.V[0] = &punto1;
prueba.V[1] = &punto2;
prueba.V[2] = &punto3;
P1 triangulo = P1(prueba);
point* p = new point[3];
double resultado = triangulo.calcula_integral(p,f);
cout<<"El resultado de la integral es: "<<resultado<<endl;
cout<<"El numero de puntos creados es: "<< puntos_creados<<endl;
// cout<<punto1.producto_escalar(punto2)<<endl;
	/*
dato datos;
datos.leedatos();

Mfinel <P1> malla; // Elijo EN ESTE MOMENTO el tipo de Elemento finito, P1
   
malla.fill_mesh(datos); // lee los mallados desde fichero
   
malla.print_nodes(); // Imprimimos los nodos
  
   
   // malla.print_elements(); // Imprimimos los elementos
malla.construye_matriz_global(); 

   //Malla.solve();
*/
}


                
