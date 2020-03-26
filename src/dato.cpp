
#include "header.h"
#include "dato.h"

/*
 * Lectura de fichero de configuracion de la simulacion
 * En este caso solo leemos los ficheros que almacenan la malla
 */
void dato::leedatos(){
 
   ifstream fichdatos ("datos.dat");
   if (fichdatos.is_open())
  {

      fichdatos>>this->mallado.nodos;
      cout<<"Fiechero de nodos: "<<this->mallado.nodos<<endl;
      fichdatos>>this->mallado.conect;
      fichdatos>>this->mallado.boundary;

    
  }
}



