#ifndef MIDIA_H
#define MIDIA_H

#include "Item.h"
enum TipoMidia{
	Fita =0, VHS = 1, CD = 2, DVD = 3
};

class Midia : public Item
{
	public:
		Midia();
		~Midia();
		
		int getDuracaoMin ();
		string getConteudo ();
		int getAno();
		string getProdutora();
		TipoMidia getTipo();
		
		void setDuracaoMin (int duracaoMin);
		void setConteudo (string conteudo);
		void setAno (int ano);
		void setProdutora (string produtora);
		void setTipo (TipoMidia tipo);
		
		void imprimeFichaTecnica();
		Midia* cadastra();
	private:
		int duracaoMin;
		string conteudo;
		int ano;
		string produtora;
		TipoMidia tipo;
		
};

#endif
#ifndef MIDIA_H
#define MIDIA_H

class Midia
{
	public:
	protected:
};

#endif