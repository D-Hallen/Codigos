#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <vector>
#include <iomanip>
#include <locale>
#include <sstream>

using namespace std;

enum class TipoItem {
        Desconhecido,
        Livro,
        TCC
    };

class Item
{
	public:
		Item();
		~Item();
		
		void setNome (string nome);
		void addTag (string tag);
		void setEmprestado(bool emprestado);
		void setQtd(int qtd);
		
		string getNome ();
		int getId();
		vector<string> getTags ();
		bool foiEmprestado ();
		int getQtd();
		
		virtual void imprimeFichaTecnica();
		
		
		
	protected:
		string nome;
		int id;
		vector<string> tags;
		bool emprestado;
		int qtd;
	private:
		static int contador;
		
		int calcularTamanhoTotalTags();
};

#endif

#ifndef ITEM_H
#define ITEM_H

class Item
{
	public:
	protected:
};

#endif