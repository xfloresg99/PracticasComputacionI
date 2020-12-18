# include <iostream>
#include<array>
#include <string>

// Incluimos la clase Almacen
#include "Almacen.h"

// Definimos el n�mero de almacenes y de art�culos que va a haber
#define NUM_ALMACENES 2
#define NUM_ARTICULOS 3

using namespace std;

// Declaraciones de funciones
void CrearAlmacenes(array<Almacen, NUM_ALMACENES>& todosAlmacenes);
void CrearArticulos(array<Articulo, NUM_ARTICULOS>& todosArticulos);
void ModificarInventariosArticulos(array<Articulo, NUM_ARTICULOS>& todosArticulos, array<Almacen, NUM_ALMACENES>& todosAlmacenes);
void AgregarArticuloAAlmacenes(Articulo* articuloPtr, array<Almacen, NUM_ALMACENES>& todosAlmacenes);


int main()
{
	// Crear y llenar almacenes con la informaci�n ingresada por el usuario
	array<Almacen, NUM_ALMACENES> todosAlmacenes;
	CrearAlmacenes(todosAlmacenes);

	// Crear y llenar articulos con la informaci�n ingresada por el usuario
	array<Articulo, NUM_ARTICULOS> todosArticulos;
	CrearArticulos(todosArticulos);

	int accion;
	// Si ingresa 1 va a actualizar el inventario de un art�culo, si ingresa 0 termina
	do {
		cout << endl << "Accion (1 modificar inventario articulo, 0 para salir): ";
		cin >> accion;
		if (accion == 1)
			ModificarInventariosArticulos(todosArticulos, todosAlmacenes);
	} while (accion);

	cout << endl; // Para darle mejor formato
	// Imprimimos el inventario de cada almacen
	for (int i = 0; i < NUM_ALMACENES; i++)
	{
		cout << "Inventario almacen " << todosAlmacenes[i].ObtenerNombre() << endl;
		cout << todosAlmacenes[i].ObtenerInventario() << endl;
	}

	// Si todo sali� bien, salimos con c�digo 0
	return 0;
}

// Crea los almacenes con la informacipon ingresada por el usuario
void CrearAlmacenes(array<Almacen, NUM_ALMACENES>& todosAlmacenes)
{
	string nombre;
	for (int i = 0; i < NUM_ALMACENES; i++)
	{
		cout << "Nombre almacen " << i << ": ";
		cin >> nombre;
		Almacen miAlmacen(nombre); // Crea una nueva instancia con los datos
		todosAlmacenes[i] = miAlmacen; // La agrega al i-�simo elemento del arreglo
	}
}

// Crea los art�culos con la informaci�n ingresada por el usuario
void CrearArticulos(array<Articulo, NUM_ARTICULOS>& todosArticulos)
{
	for (int i = 0; i < NUM_ARTICULOS; i++)
	{
		Articulo nuevoArticulo; // Crea una nueva instancia vac�a
		cout << "Nombre articulo " << i << ": ";
		cin >> nuevoArticulo.nombre; // LLena el nombre del art�culo
		cout << "Fabricante: ";
		cin >> nuevoArticulo.fabricante; // LLena el farbicante del art�culo
		cout << "Precio: $";
		cin >> nuevoArticulo.precio; // LLena el precio del art�culo
		todosArticulos[i] = nuevoArticulo; // Agrega al arreglo la instancia del nuevo art�culo
	}
}

// Pide al usuario seleccionar uno de los art�culos existentes para modificar su inventario
void ModificarInventariosArticulos(array<Articulo, NUM_ARTICULOS>& todosArticulos, array<Almacen, NUM_ALMACENES>& todosAlmacenes)
{
	int IDArticulo;
	// Pedir el ID del art�culo a modificar hasta ingresar uno v�lido
	do {
		cout << "Lista de articulos" << endl;
		cout << "ID\tArticulo" << endl;
		for (int i = 0; i < NUM_ARTICULOS; i++)
			cout << i << "\t" << todosArticulos[i].nombre << endl;
		cout << endl << "Ingresa el ID del articulo a modificar: ";
		cin >> IDArticulo;
	} while (IDArticulo < 0 || IDArticulo > NUM_ARTICULOS - 1);

	// Para el art�culo seleccionado, preguntar qu� almacenes se van a modificar
	AgregarArticuloAAlmacenes(&(todosArticulos[IDArticulo]), todosAlmacenes);
}

/*
 * Pide al usuario seleccionar en qu� almacenes desea modificar la cantidad de art�culos.
 * Si ingresa una cantidad no v�lida (que resulte en un inventario negativo) le informa que
 * no se pudo realizar la operaci�n, en caso contrario actualiza el inventario del art�culo
 * al que apunta `articuloPtr` en los almacenes indicados.
 */
void AgregarArticuloAAlmacenes(Articulo* articuloPtr, array<Almacen, NUM_ALMACENES>& todosAlmacenes)
{
	int decision, cantidad;
	for (int i = 0; i < NUM_ALMACENES; i++)
	{
		// Preguntamos al usuario si desea actualizar el inventario del art�culo en el �-�simo almacen
		do {
			cout << "Agregar " << articuloPtr->nombre << " al almacen " << todosAlmacenes[i].ObtenerNombre() << " (1 si, 0 no): ";
			cin >> decision;
		} while (decision != 0 && decision != 1);
		// Si pidi� actualizar, le pedimos la cantidad de art�culos a actualizar (puede ser tanto positiva como negativa)
		if (decision)
		{
			cout << "Cantidad (puede ser negativo): ";
			cin >> cantidad;
			// Le informamos si la cantidad ingresada es v�lida (no genera inventarios negativos) y se llev� a cabo la operaci�n
			if (todosAlmacenes[i].ModificarInventarioArticulo(articuloPtr, cantidad))
				cout << "Operacion exitosa" <<endl;
			else
				cout << "Operacion fallida" << endl;
		}
	}
}
