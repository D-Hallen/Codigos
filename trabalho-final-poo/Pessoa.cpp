#include "Pessoa.h"
#include <algorithm>

Pessoa::Pessoa()
{
	itensPegos.clear();
}

Pessoa::~Pessoa()
{
}

string Pessoa::getNome (){
	return nome;
}
string Pessoa::getCpf (){
	return cpf;
}
string Pessoa::getDataNascimento (){
	return dataNascimento;
}

void Pessoa::setNome (string nome){
	this->nome = nome;
}
void Pessoa::setCpf (string cpf){
	this->cpf = cpf;
}
void Pessoa::setDataNascimento (string dataNascimento){
	this->dataNascimento = dataNascimento;
}

vector<int> Pessoa::getItensPegos (){
	return itensPegos;
}
void Pessoa::pegaItem (int itemId){
	itensPegos.push_back(itemId);
}
bool Pessoa::estaCom (int itemId){
	for (auto i= itensPegos.begin(); i!= itensPegos.end() ;i++){
		if (*i == itemId){
			return true;
		}
	}
	return false;
}

void Pessoa::removeItem (int itemId){
    auto it = std::find_if(itensPegos.begin(), itensPegos.end(), [itemId](int i) { return i == itemId; }); //tenta localizar o id do item

    if (it != itensPegos.end()) { //se localizou o item
        itensPegos.erase(it); //apaga ele
    }
}
#include "Pessoa.h"