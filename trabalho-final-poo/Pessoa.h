#ifndef PESSOA_H
#define PESSOA_H
#include <iostream>
#include <vector>
using namespace std;

class Pessoa
{
	public:
		Pessoa();
		~Pessoa();
		string getNome ();
		string getCpf ();
		string getDataNascimento ();
		vector<int> getItensPegos ();
		
		void setNome (string nome);
		void setCpf (string cpf);
		void setDataNascimento (string dataNascimento);

		void pegaItem (int itemId);
		bool estaCom (int itemId);
		void removeItem (int itemId);
		
	private:
		string nome;
		string cpf;
		string dataNascimento;
		vector<int> itensPegos;
};

#endif
#ifndef PESSOA_H
#define PESSOA_H

class Pessoa
{
	public:
	protected:
};

#endif