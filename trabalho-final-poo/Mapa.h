#ifndef MAPA_H
#define MAPA_H

#include "Item.h"

class Mapa : public Item
{
	public:
		Mapa();
		~Mapa();
		string getEscala();
		string getLocal();
		
		void setEscala (string escala);
		void setLocal (string local);
		
		void imprimeFichaTecnica();
		Mapa* cadastra();
	private:
		string escala;
		string local;
};

#endif
#ifndef MAPA_H
#define MAPA_H

class Mapa
{
	public:
	protected:
};

#endif