#ifndef PERIODICO_H
#define PERIODICO_H

#include <vector>
#include "Item.h"
enum Tipo {
			Revista  = 0 , Jornal = 1
		};
class Periodico : public Item
{
	public:
		
		
		
		Periodico();
		~Periodico();
		
		int getEdicao ();
		string getEditora ();
		int getAno ();
		int getNumPags();
		string getISSN ();
		vector<string> getNoticias();
		Tipo getTipo ();
		
		void imprimeFichaTecnica();
		
		void setEdicao(int edicao);
		void setEditora(string editora);
		void setAno (int ano);
		void setNumPags (int numPags);
		void setISSN (string ISSN);
		void setNoticias (vector<string>);
		void setTipo (Tipo tipo);
		
		void addNoticias (string noticia);
		Periodico* cadastra ();
		
	private:
		int edicao;
		string editora;
		int ano;
		int numPags;
		string ISSN;
		vector<string> noticias;
		Tipo tipo;
		
		bool validarISSN (string &ISSN);
};

#endif
#ifndef PERIODICO_H
#define PERIODICO_H

class Periodico
{
	public:
	protected:
};

#endif