/*
 * Elemento finito P1
 */

#ifndef __P1_
#define __P1_

class P1{
	private:
		void calcula_area();
   	public:
        // Atributos
	    int N;        // numero de vertives
        point** V;    // puntero de puntero a vertices del el finito: contiene tres punteros
	double area;	      // que guardan la direccion de memoria de los vertices, ya creados
        // Metodos de la clase Q1
        P1();
	P1(const P1 &triangulo);
	~P1();

        void print_finel();
};

#endif
