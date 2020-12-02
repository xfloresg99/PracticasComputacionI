#include "Bodega.h"

#include <iostream>

/*
 * Agrega un art�culo a la bodega, si se intenta agregar un art�culo
 * que ya existe regresa "false", de lo contrario agrega el apuntador
 * al art�culo al final del vecor de art�culos y regresa "true"
*/
bool Bodega::AgregarArticulo(string* artPtr)
{
	for (int i = 0, n = articulos.size(); i < n; i++)
	{
		if (articulos[i] == artPtr)
			return false;
	}
	articulos.push_back(artPtr);
	return true;
}

/*
 * Regresa un string con la descripci�n del inventario
 * de la forma `Articulo <i> es <nombreArticulo>`
 * para cada art�culo en la bodega
*/
string Bodega::ObtenerInventario()
{
	string inv = "";
	for (int i = 0, n = articulos.size(); i < n; i++)
	{
		inv.append("Articulo ");
		inv.append(to_string(i));
		inv.append(" es ");
		inv.append(ObtenerNombre());
	}
	return inv;
}

