#include "Molecula.h"

Molecula::Molecula(string n){
	
	nombre=n;
	i=0;
}

void Molecula::agregarGrupo(Grupo g){
	
	
	pk[i]=g.pkGrupo;
	
	
	i++;
}


float Molecula::CalcularPuntoIsoelectrico(){

     float punto;
     
     
     
     for(int n=1;n<i;n++){
     	
     	suma=suma=pk[n];  //Sumando los ultimos pka 
	                }
	                
	punto=suma/2;   //Calculando el punto Isoelectrico
     
     
    return punto;
	
	
}
