
class Grupo;
class Molecula{
	
	private:
		  string nombre;
		  int i;
		  float pk[2]; //Guardar los pka de los grupos
		  
	public:
		   Molecula(string);
		   void agregarGrupo(Grupo g);
		   float CalcularPuntoIsoelectrico();
		
};
