#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <vector>
#include "Livro.h"
#include "TCC.h"
#include "Pessoa.h"
#include "Periodico.h"
#include "Relatorio.h"
#include "Midia.h"
#include "Mapa.h"
#include "Cartaz.h"
#include "Pessoa.h"

using namespace std;
class Menu
{
	public:
		Menu();
		~Menu();
		int inicial();
		vector<Item*> carregaAcervo ();
		vector<Pessoa*> carregaCadastros();
		Item* pesquisaItem(const vector<Item*>& acervo, const string& termoPesquisa);
		Item* pesquisaItem(const vector<Item*>& acervo, const int& idPesquisa);
		void pesquisaGeral(const vector<Item*>& acervo, const string& idPesquisa);
		Pessoa* pesquisaPessoa (const vector<Pessoa*>& cadastros,const string& CPF);
		Pessoa* cadastraPessoa ();
		Item* cadastraItem ();
		
	protected:
};

#endif
#ifndef MENU_H
#define MENU_H

class Menu
{
	public:
	protected:
};

#endif