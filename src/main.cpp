
#include "header.h"
#include "dato.h"
#include <stdlib.h>

#include "point.h"

#include "pelfin.h"


#include "mesh.h"



int main() {/*
point punto1 = point(3,2);
punto1.print_point();

point punto2 = point(3,2);
punto2.print_point();
	
point punto3 = point(0,1);
punto3.print_point();


P1 prueba = P1(3);
prueba.V[0] = &punto1;
prueba.V[1] = &punto2;
prueba.V[2] = &punto3;


cout<<punto1.producto_escalar(punto2)<<endl;
*/
dato datos;
datos.leedatos();

Mfinel <P1> malla; // Elijo EN ESTE MOMENTO el tipo de Elemento finito, P1
   
   malla.fill_mesh(datos); // lee los mallados desde fichero
   
   malla.print_nodes(); // Imprimimos los nodos
  
   
   malla.print_elements(); // Imprimimos los elementos

   cout<<"El numero de puntos creados es: "<< puntos_creados<<endl;

   //Malla.solve();

}


                
