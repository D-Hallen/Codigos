#ifndef RELATORIO_H
#define RELATORIO_H

#include "Item.h"
class Relatorio : public Item
{
	public:
		Relatorio();
		~Relatorio();
		
		string getData ();
		string getCidade ();
		string getAutor ();
		string getDescricao ();
		
		void setData (string data);
		void setCidade (string cidade);
		void setDescricao (string descricao);
		void setAutor (string autor);
		
		void imprimeFichaTecnica();
		Relatorio* cadastra ();
	private:
		string data;
		string cidade;
		string autor;
		string descricao;
		
		vector<string> dividirEmLinhas (int larguraMax);
		void imprimirRelatorio (int larguraDaCaixa);
		
};

#endif
#ifndef RELATORIO_H
#define RELATORIO_H

class Relatorio
{
	public:
	protected:
};

#endif