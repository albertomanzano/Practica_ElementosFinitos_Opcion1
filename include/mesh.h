/*
 * 
 *          CLASE MALLA
 * 
 * 
 * Clase malla generica con templates
 * 
 * Lnode: Vector de nodos del mallado
 * Lfinel: Lista de elementos finitos (poligonos) del mallado
 * 
 * 
 * /


/* 
 * Una malla de elementos finitos es una lista de elementos finitos T
 * FIJATE: T puede ser cualquier cosa: cuadrados Q1,  triangulos P1, etc
 * 
 * Lo bueno de usar una lista es que la podemos modificar facilmente: añadir, eliminar elementos, etc
 * MUY adecuado para hacer refinamiento dinamico de mallados
 */ 
#include"header.h"
#include <list>
#include <vector>
#include "point.h"
#include "qelfin.h" // Si quisiesemos usar Q1
#include "pelfin.h"
#include "dato.h"

using namespace std;


class dato;

template < typename T >
class Mfinel{


public :
    friend class dato;
    static int Nnodes;  // Num de nodos
    static int Nfinel; //Num de els finitos
    vector<point*> Lnode; // lista de  nodos 
    list<T> Lfinel; // lista de elementos 
    MatrixXd matriz_global;
    
    // Metodos
    Mfinel(); // constructor por defecto
    void fill_mesh(dato& datos); // rellena la malla
    void print_nodes();
    void print_elements(); 
    void solve();
    void construye_matriz_global();  
	
};


template < typename T >
Mfinel<T>::Mfinel(){
  vector<point*> Lnode;
}


/*
 * Definicion de miebros estaticos
 */
template <typename T> int Mfinel<T>::Nnodes;  
template <typename T> int Mfinel<T>::Nfinel;

/*
 * Un metodo que rellena la malla a partir de datos provenientes
 * de un fichero generado por un mallador o a partir de nuestro propio código de mallado
 * 
 * El nombre de fichero debería estar almacenado en una estructura datos del problema
 * 
 * 
 */
template < typename T >
void Mfinel<T>::fill_mesh(dato& datos){
   //  Rellenamos el vector de nodos
  this->Nnodes=0;
  ifstream myfile (datos.mallado.nodos.c_str()); // ojo!: es necesario convertir el string a pointeer de char con c_str
  if (myfile.is_open())
  {
 int control; 
while (true)  {
	myfile>>control;
	if (myfile.eof()) break;
       point *node=new point();              // creo nuevo nodo
       node->x = control;
	myfile>>node->y;  // asigno coordenadas
       this->Nnodes++;          // incrementamos el numero de nodos
       // cout<<node.x<<" "<<node.y<<endl; // Imprimir a medida que leemos
       this->Lnode.push_back( node); // insertamos nodo en lista-nodos
}

    myfile.close();
  }

 this->Nfinel=0.;

 // Rellenamos la lista de elementos
 
myfile.open("mesh/mesh_tnode.dat"); 
bool control = 0;
if (myfile.is_open()){
	while ( myfile.good() ){
		T Elmt=T();  // creamos nuevo elemento temporali
		for(int k=0;k<Elmt.N;k++){ // Leemos conectividades
			int conect;
			myfile>>conect;
			if (myfile.eof()){
				control = 1;
				break;
			}
			Elmt.V[k]=this->Lnode[conect-1]; // asigno REFERENCIA al punto correspondiente
			this->Nfinel++;
		}
		if (control==1) break;
		this->Lfinel.emplace_back(Elmt); // insertamos el elemento en la lista de elementos
	}
	myfile.close();
}
 
myfile.open("mesh/mesh_bnd_node.dat"); 
int front = 0;
if (myfile.is_open()){
	while (true){
		myfile>>front;
		if (myfile.eof()) break;
		cout<<"Nodo frontera "<<front<<endl;
		this->Lnode[front-1]->front = 1;
		
	}
	myfile.close();
}
  
}


// Impresion de lista de nodos de la malla
template < typename T >
void Mfinel<T>::print_nodes(){
   cout<<"Imprimimos los puntos desde la lista del mallado"<<endl;
   vector<point*>::iterator it; // iterator de lista de nodos
   for(it=this->Lnode.begin(); it != this->Lnode.end(); ++it){        
       (*it)->print_point(); // alternativamente  (*(*it)).print_points();
   }
   
}


// Impresion de lista de nodos de la malla
template < typename T >
void Mfinel<T>::print_elements(){
   cout<<"Imprimimos los elementos del mallado"<<endl;
   int i=0;
    // list<T>::iterator it; // MAL: iterator de lista de els. No conoce T
   typename list<T>::iterator it; // cuidado con el typename- si no lo ponemos no se entera en el iterador
   for(it=this->Lfinel.begin(); it != this->Lfinel.end(); ++it){  
       cout<<"ELEMENTO "<<i<<endl;
       it->print_finel(); // alternativamente  (*(*it)).print_points();
       i++;
   }
   
}
template <typename T>
void Mfinel<T>::construye_matriz_global(){
   cout<<"Imprimimos los elementos del mallado"<<endl;
   int i=0;
   Matrix3d m;
   matriz_global.resize(this->Nnodes,this->Nnodes);
   matriz_global.setZero();
   cout<<matriz_global<<endl;
    // list<T>::iterator it; // MAL: iterator de lista de els. No conoce T
   point *p = new point[3];
   typename list<P1>::iterator it; // cuidado con el typename- si no lo ponemos no se entera en el iterador
   for(it=this->Lfinel.begin(); it !=this->Lfinel.end(); ++it){  
       cout<<"ELEMENTO "<<i<<endl;
       it->print_finel(); // alternativamente  (*(*it)).print_points();
       cout<<"Matriz de productos escalares"<<endl;
       it->calcula_matriz_local(p,m); 
       cout<<m<<endl;
       cout<<"Matriz global"<<endl;
       it->asigna_matriz_global(m,matriz_global);
       cout<<matriz_global<<endl;
       cout<<endl;
       i++;
   }
}

/*
template < typename T >
void Mfinel<T>::solve(){
   Matrix3f A;
   Vector3f b;
   A << 1,2,3,  4,5,6,  7,8,10;
   b << 3, 3, 4;
   cout << "Here is the matrix A:\n" << A << endl;
   cout << "Here is the vector b:\n" << b << endl;
   Vector3f x = A.colPivHouseholderQr().solve(b);
   cout << "The solution is:\n" << x << endl;
}*/
