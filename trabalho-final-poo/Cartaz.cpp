#include "Cartaz.h"

Cartaz::Cartaz()
{
}

Cartaz::~Cartaz()
{
}

string Cartaz::getAssunto (){
	return assunto;
}
string Cartaz::getAutor (){
	return autor;
}

void Cartaz::setAssunto (string assunto){
	this->assunto = assunto;
}
void Cartaz::setAutor (string Autor){
	this->autor = autor;
}
Cartaz* Cartaz::cadastra(){
	Cartaz *c = new Cartaz();
	string nome;
	string assunto;
	string autor;
	string tags;
	int qtd;
	cin.ignore();
	cout<<"Insira um nome:"<<endl;
	getline (cin, nome);
	c->setNome(nome);
	cout<<"Insira um assunto:"<<endl;
	getline (cin,assunto);
	c->setAssunto(assunto);
	cout<<"Insira um autor:"<<endl;
	getline (cin,autor);
	c->setAutor(autor);
	cout<<"Insira a quantidade:"<<endl;
	cin >>qtd;
	c->setQtd(qtd);
	while (tags != "sair"){
		cin.ignore();
		cout<<"Insira uma tag: (ou escreva sair para encerrar)"<<endl;
		getline (cin, tags);
		if (tags !="sair"){
			c->addTag(tags);
		}
	}
	return c;
}


void Cartaz::imprimeFichaTecnica(){
	int larguraCaixa = 70;
	cout  << endl << setfill('=')<< setw(larguraCaixa)<< "" << setfill(' ')<<endl;
	cout << "| Cartaz " << setw(larguraCaixa - 9) << " |" << endl;
	Item::imprimeFichaTecnica();
	cout << "| Autor: " << setw(larguraCaixa - 11) << this->autor  << " |" << endl;
	cout << "| Assunto: " << setw(larguraCaixa - 13) << this->assunto<< " |" << endl;
	cout << setfill('=')<< setw(larguraCaixa)<< "" << setfill(' ')<<endl;
}
#include "Cartaz.h"