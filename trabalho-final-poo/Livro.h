#ifndef LIVRO_H
#define LIVRO_H

#include "Item.h"

class Livro : public Item
{
	public:
		Livro();
		~Livro();
		
		int getEdicao ();
		string getEditora ();
		string getAutor ();
		int getNumPags();
		string getISBN ();
		
		void imprimeFichaTecnica() override;
		
		void setEdicao(int edicao);
		void setEditora(string editora);
		void setAutor (string autor);
		void setNumPags (int numPags);
		void setISBN (string ISBN);
		Livro* cadastra ();

    	
	protected:
	
	private:
		int edicao;
		string editora;
		string autor;
		int numPags;
		string ISBN;
		
		bool validarISBN(string &isbn);
};

#endif
#ifndef LIVRO_H
#define LIVRO_H

class Livro
{
	public:
	protected:
};

#endif