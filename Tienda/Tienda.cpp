# include <iostream>
#include<array>
#include <string>

// Incluimos la clase Almacen
#include "Almacen.h"

// Definimos el número de almacenes y de artículos que va a haber
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
	// Crear y llenar almacenes con la información ingresada por el usuario
	array<Almacen, NUM_ALMACENES> todosAlmacenes;
	CrearAlmacenes(todosAlmacenes);

	// Crear y llenar articulos con la información ingresada por el usuario
	array<Articulo, NUM_ARTICULOS> todosArticulos;
	CrearArticulos(todosArticulos);

	int accion;
	// Si ingresa 1 va a actualizar el inventario de un artículo, si ingresa 0 termina
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

	// Si todo salió bien, salimos con código 0
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
		todosAlmacenes[i] = miAlmacen; // La agrega al i-ésimo elemento del arreglo
	}
}

// Crea los artículos con la información ingresada por el usuario
void CrearArticulos(array<Articulo, NUM_ARTICULOS>& todosArticulos)
{
	for (int i = 0; i < NUM_ARTICULOS; i++)
	{
		Articulo nuevoArticulo; // Crea una nueva instancia vacía
		cout << "Nombre articulo " << i << ": ";
		cin >> nuevoArticulo.nombre; // LLena el nombre del artículo
		cout << "Fabricante: ";
		cin >> nuevoArticulo.fabricante; // LLena el farbicante del artículo
		cout << "Precio: $";
		cin >> nuevoArticulo.precio; // LLena el precio del artículo
		todosArticulos[i] = nuevoArticulo; // Agrega al arreglo la instancia del nuevo artículo
	}
}

// Pide al usuario seleccionar uno de los artículos existentes para modificar su inventario
void ModificarInventariosArticulos(array<Articulo, NUM_ARTICULOS>& todosArticulos, array<Almacen, NUM_ALMACENES>& todosAlmacenes)
{
	int IDArticulo;
	// Pedir el ID del artículo a modificar hasta ingresar uno válido
	do {
		cout << "Lista de articulos" << endl;
		cout << "ID\tArticulo" << endl;
		for (int i = 0; i < NUM_ARTICULOS; i++)
			cout << i << "\t" << todosArticulos[i].nombre << endl;
		cout << endl << "Ingresa el ID del articulo a modificar: ";
		cin >> IDArticulo;
	} while (IDArticulo < 0 || IDArticulo > NUM_ARTICULOS - 1);

	// Para el artículo seleccionado, preguntar qué almacenes se van a modificar
	AgregarArticuloAAlmacenes(&(todosArticulos[IDArticulo]), todosAlmacenes);
}

/*
 * Pide al usuario seleccionar en qué almacenes desea modificar la cantidad de artículos.
 * Si ingresa una cantidad no válida (que resulte en un inventario negativo) le informa que
 * no se pudo realizar la operación, en caso contrario actualiza el inventario del artículo
 * al que apunta `articuloPtr` en los almacenes indicados.
 */
void AgregarArticuloAAlmacenes(Articulo* articuloPtr, array<Almacen, NUM_ALMACENES>& todosAlmacenes)
{
	int decision, cantidad;
	for (int i = 0; i < NUM_ALMACENES; i++)
	{
		// Preguntamos al usuario si desea actualizar el inventario del artículo en el í-ésimo almacen
		do {
			cout << "Agregar " << articuloPtr->nombre << " al almacen " << todosAlmacenes[i].ObtenerNombre() << " (1 si, 0 no): ";
			cin >> decision;
		} while (decision != 0 && decision != 1);
		// Si pidió actualizar, le pedimos la cantidad de artículos a actualizar (puede ser tanto positiva como negativa)
		if (decision)
		{
			cout << "Cantidad (puede ser negativo): ";
			cin >> cantidad;
			// Le informamos si la cantidad ingresada es válida (no genera inventarios negativos) y se llevó a cabo la operación
			if (todosAlmacenes[i].ModificarInventarioArticulo(articuloPtr, cantidad))
				cout << "Operacion exitosa" <<endl;
			else
				cout << "Operacion fallida" << endl;
		}
	}
}
