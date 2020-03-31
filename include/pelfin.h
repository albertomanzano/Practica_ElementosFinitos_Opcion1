#include <Eigen/Dense>
using Eigen::Matrix3d;
using Eigen::MatrixXd;
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
	void calcula_gradientes(point* &p);
	void calcula_puntos_medios(point* &p);
	double calcula_integral(point* &p,double (*funcion)(const point&));
	void calcula_matriz_local(point* &p,Matrix3d &m);
	void asigna_matriz_global(Matrix3d &m,MatrixXd &matriz_global);
};

#endif
