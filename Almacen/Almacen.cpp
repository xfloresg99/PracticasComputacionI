#include <iostream>
#include <string>
#include <array>

using namespace std;

// Incluimos las clases a ocupar
#include "Bodega.h"

//Declaraci�n de funciones
Bodega CrearBodega(int i);
string CrearArticulo(int i);
void AgregarArticuloABodega(string* artPtr, Bodega& bodega);


int main()
{
    const int numBodegas = 2, numArticulos = 3;
    // Arreglo que contendr� todas las bodegas
    array<Bodega, numBodegas> misBodegas;

    /*
     * Para cada bodega a crear le pedimos al usuario que nos d� la informaci�n
     * y la nueva instancia regresada la agregamos al final del vector misBodegas
    */
    for (int i = 0; i < numBodegas; i++)
        misBodegas[i] = CrearBodega(i);

    // Arreglo que contendr� todos los art�culos
    array<string, numArticulos> misArticulos;

    /*
     * Para cada art�culo a crear le pedimos al usuario que nos d� la informaci�n
     * y para cada nuevo art�culo le preguntamos al usuario si la desea agregar a
     * cada bodega, si el usuario quiere agregar el art�culo a la bodega la
     * agregamos PASANDO EL APUNTADOR A ESE ART�CULO y areg�ndolo a los art�culos
     * de la bodega seleccionada
    */
    
    int op;
    string nom;
    
    for (int i = 0; i < numArticulos; i++)
    {
    	nom=CrearAticulo(i);
    	
    	cout<<" Agregar "<<nom<<" a la bodega de "<< misBodegas[i].ObtenerNombre()<<" (1 si, 0 no): ";
    	cin>>op;
    	
    	if(op==1){
    	  
		  	misBodegas[i].AgregarArticuloABodega(nom,misBodegas B);
		}
		
		if(op==0){}
        
        cout<<" Agregar "<<nom<<"a la bodega de "<< misBodegas[i+1].ObtenerNombre()<<" (1 si, 0 no): ";
    	cin>>op;
    	
    	if(op==1){
    	   
    	   string 
    	   misBodegas[i+1].AgregarArticuloABodega(nom,misBodegas B);
		  	
		}
		
		if(op==0){}
    }

    // Imprimimos el inventario de cada bodega
    cout << endl;
    for (int i = 0; i < numBodegas; i++)
    {
        cout << "Inventario bodega " << misBodegas[i].ObtenerNombre() << endl;
        cout << misBodegas[i].ObtenerInventario() << endl;
    }

    // Si todo sali� bien, regresamos el valor cero
    return 0;
}


// Crea y regresa un string con el nombre de un articulo
string CrearArticulo(int i)
{
    string nombreArt;
    cout << "Nombre del articulo " << i << ": ";
    cin >> nombreArt;
    return nombreArt;
}


// Intenta agregar un art�culo a una bodega, si ese art�culo ya existe no lo agrega
void AgregarArticuloABodega(string* artPtr, Bodega& bodega)
{
    if (bodega.AgregarArticulo(artPtr))
        cout << "Articulo agregado exitosamente." << endl;
    else
        cout << "Articulo duplicado. No fue agregado." << endl;
}


// Crea y regresa una nueva bodega con los datos ingresados por el usuario
Bodega CrearBodega(int i)
{
    string nombreBodega;
    cout << "Nombre bodega " << i << ": ";
    cin >> nombreBodega;
    Bodega nuevaBodega(nombreBodega);
    return nuevaBodega;
}

