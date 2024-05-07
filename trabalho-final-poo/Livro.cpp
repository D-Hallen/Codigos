#include <locale>
#include "Livro.h"

Livro::Livro()
{
	this->ISBN= "NULL";
}

Livro::~Livro()
{
}

bool Livro::validarISBN(string &isbn) {
    if (isbn.length() != 13) {
        return false; // ISBN-13 deve ter exatamente 13 dígitos
    }

    int soma = 0;

    for (int i = 0; i < 12; ++i) {
        int digito = isbn[i] - '0';

        // Alterna entre multiplicar por 1 e por 3
        soma += (i % 2 == 0) ? digito : 3 * digito;
    }

    int digitoVerificador = (10 - (soma % 10)) % 10;
    return (digitoVerificador == isbn[12] - '0');
}

int Livro::getEdicao (){
	return this->edicao;
}
string Livro::getEditora (){
	return this->editora;
}
string Livro::getAutor (){
	return this->autor;
}
int Livro::getNumPags(){
	return this->numPags;
}
string Livro::getISBN (){
	return this->ISBN;
}
void Livro::setEdicao(int edicao){
	this->edicao=edicao;
}
void Livro::setEditora(string editora){
	this->editora=editora;
}
void Livro::setAutor (string autor){
	this->autor=autor;
}
void Livro::setNumPags (int numPags){
	this->numPags=numPags;
}
void Livro::setISBN (string ISBN){
	if (validarISBN(ISBN)){
		this->ISBN=ISBN;
	} else {
		cout <<"O valor da ISBN dado nao e valido, por favor inserir um valor diferente"<<endl;	
	}
}

void Livro::imprimeFichaTecnica(){
	locale::global(std::locale(""));
	int larguraCaixa = 70;
	cout  << endl << setfill('=')<< setw(larguraCaixa)<< "" << setfill(' ')<<endl;
	cout << "| Livro " << setw(larguraCaixa - 8) << " |" << endl;
	cout << "| Autor: " << setw(larguraCaixa - 11) << this->autor << " |" << endl;
	Item::imprimeFichaTecnica();
	cout <<"| Editora: " << setw(larguraCaixa - 13) << this->editora << " |" << endl;
	cout << "| "<< this->edicao <<"o Edicao"<<setw(larguraCaixa - 11) << " |" << endl;
	cout << "| "<< this->numPags <<" Paginas"<<setw(larguraCaixa - 13) << " |" << endl;
	cout <<"| ISBN: " << setw(larguraCaixa - 10) << this->ISBN << " |" << endl;
	cout << setfill('=')<< setw(larguraCaixa)<< "" << setfill(' ')<<endl;	
}

Livro* Livro::cadastra(){
	Livro *l = new Livro();
	string nome;
	
	int edicao;
	string editora;
	string autor;
	int numPags;
	string ISBN;
	int qtd;
	string tags;
	cin.ignore();
	cout<<"Insira um nome:"<<endl;
	getline (cin, nome);
	l->setNome(nome);
	cout<<"Insira a editora:"<<endl;
	getline (cin,editora);
	l->setEditora(editora);
	cout<<"Insira o numero de paginas:"<<endl;
	cin >> numPags;
	l->setNumPags(numPags);
	cout<<"Insira a edicao:"<<endl;
	cin >> edicao;
	l->setEdicao(edicao);
	cout<<"Insira o autor:"<<endl;
	getline (cin,autor);
	l->setAutor(autor);
	cout<<"Insira a quantidade:"<<endl;
	cin >>qtd;
	l->setQtd(qtd);
	
	while (l->ISBN == "NULL"){
		cout <<"Insira o codigo ISBN"<<endl;
		getline (cin, ISBN);
		l->setISBN(ISBN);
	}
	
	while (tags != "sair"){
		cin.ignore();
		cout<<"Insira uma tag: (ou escreva sair para encerrar)"<<endl;
		getline (cin, tags);
		if (tags !="sair"){
			l->addTag(tags);
		}
	}
	return l;
}
#include "Livro.h"