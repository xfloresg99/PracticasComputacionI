# PracticasComputacionI


#include <iostream>
#include <array>
#include <string>

// Incluimos nuestra clase Grupo
#include "Grupo.h"



using namespace std;

// Declaraci�n de funciones
void PedirpH(float& ph);
Grupo CrearGrupo(int numGrupo);

template <typename grupos>
int CalcularCargaApH(float& ph, grupos todosGrupos);


int main()
{
    // Indicamos el n�mero de grupos que va a tener nuestra mol�cula
    const int numGrupos = 3;
    float phMolecula; // pH al que va a estar sometida la mol�cula
    string nombreMolecula;

    // Pedimos al usuario el nombre de la mol�cula
    cout << "Nombre de la molecula: ";
    cin >> nombreMolecula;

    // Creamos un arreglo de 'Grupos' para los grupos de la mol�cula
    array <Grupo, numGrupos> todosGrupos;
    // Pedimos informaci�n de cada grupo al usuario
    for (int i = 0; i < numGrupos; i++)
        todosGrupos[i] = CrearGrupo(i);

    // Pedimos al usuario indicar el pH al que est� la mol�cula
    PedirpH(phMolecula);

    // Calculamos la carga neta de la mol�cula a un cierto pH
    int cargaMolecula = CalcularCargaApH(phMolecula, todosGrupos);
    cout << "Carga neta de la molecula: " << cargaMolecula << endl;

    // Si terminamos correctamente la ejecuci�n del programa, regresamos 0
    return 0;
}

// Crea un nuevo 'Grupo' con la informaci�n ingresada por el usuario
Grupo CrearGrupo(int i)
{
    string nombreGrupo;
    float pkGrupo;
    int cargaGrupo;
    cout << "Nombre grupo " << i << ": ";
    cin >> nombreGrupo;
    cout << "pK del grupo " << nombreGrupo << ": ";
    cin >> pkGrupo;
    cout << "Carga del grupo " << nombreGrupo << " a pH mayor a " << pkGrupo << ": ";
    cin >> cargaGrupo;
    Grupo miGrupo(nombreGrupo, pkGrupo, cargaGrupo);
    return miGrupo;
}

// Solicita al usuario el valor de pH
void PedirpH(float& ph)
{
    cout << "pH de la solucion (buffer): ";
    cin >> ph;
}

/* Calcula y regresa la carga el�ctrica de la mol�cula dependiendo de la
 * carga el�ctrica de cada uno de sus grupos a un cierto pH.
*/
template <typename grupos>
int CalcularCargaApH(float& ph,grupos todosGrupos)
{
	int CargaA,pk;
	

	
             CargaA=todosGrupos[0].cargaGrupo+todosGrupos[1].cargaGrupo+todosGrupos[2].cargaGrupo;
             
	
	return CargaA;
             
             
     	
    //TODO
}


#include "Grupo.h"

Grupo::Grupo(string nG,float p,int c){
	
	nomG=nG;
	pka=p;
	carga=c;
}






class Grupo{
	
	 public:
	 	     string nomG;
	 	     float pka;
	 	     int carga;
	public:
	       Grupo(string,float,int);
	
};






