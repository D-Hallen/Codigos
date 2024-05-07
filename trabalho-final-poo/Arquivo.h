#ifndef ARQUIVO_H
#define ARQUIVO_H
#include <iostream>
#include <vector>
#include "Item.h"


using namespace std;

class Arquivo
{
	public:
		void salvarItens(const string& nomeArquivo, const vector<Item*>& itens);
    	vector<Item*> carregarItens(const string& nomeArquivo);

	protected:
};

#endif
#ifndef ARQUIVO_H
#define ARQUIVO_H

class Arquivo
{
	public:
	protected:
};

#endif