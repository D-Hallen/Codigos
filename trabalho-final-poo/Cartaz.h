#ifndef CARTAZ_H
#define CARTAZ_H

#include "Item.h"

class Cartaz : public Item
{
	public:
		Cartaz();
		~Cartaz();
		string getAssunto ();
		string getAutor ();
		
		void setAssunto (string assunto);
		void setAutor (string Autor);
		
		void imprimeFichaTecnica();
		Cartaz* cadastra();
	private:
		string assunto;
		string autor;
		
};

#endif
#ifndef CARTAZ_H
#define CARTAZ_H

class Cartaz
{
	public:
	protected:
};

#endif