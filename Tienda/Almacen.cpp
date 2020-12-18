#include "Almacen.h"

bool Almacen::ModificarInventarioArticulo(Articulo* artPtr, int cantidad)
{
		// TODO
		int resta=cantidad-artPtr.cantidad;
		
			return resta;
		
}

string ObtenerNombre() const
{
	return nombre;
}

string Almacen::ObtenerInventario() const
{
	string invStr = "";
	invStr.append("\nArticulo\tCantidad\n");
	for (int i = 0, n = articulos.size(); i < n; i++)
	{
		invStr.append(articulos[i].articulo->nombre);
		invStr.append("\t");
		invStr.append(to_string(articulos[i].cantidad));
		invStr.append("\n");
	}
	return invStr;
}
