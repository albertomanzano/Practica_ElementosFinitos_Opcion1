
#ifndef __DATO_
#define __DATO_

#include "header.h"

struct fich_mesh{
 
  string nodos;
  string conect;
  string boundary; // COMPLETAR!!
  
};

class dato{
  public:
    fich_mesh mallado;
    void leedatos();
  
};
#endif
