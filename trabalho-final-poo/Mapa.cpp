#include "Mapa.h"

Mapa::Mapa()
{
}

Mapa::~Mapa()
{
}

string Mapa::getEscala(){
	return escala;
}
string Mapa::getLocal(){
	return local;
}

void Mapa::setEscala (string escala){
	this->escala= escala;
}
void Mapa::setLocal (string local){
	this->local = local;
}
Mapa* Mapa::cadastra(){
	Mapa *m = new Mapa();
	string nome;
	string escala;
	string local;
	string tags;
	int qtd;
	cin.ignore();
	cout<<"Insira um nome:"<<endl;
	getline (cin, nome);
	m->setNome(nome);
	cout<<"Insira um escala:"<<endl;
	getline (cin,escala);
	m->setEscala(escala);
	cout<<"Insira um local:"<<endl;
	getline (cin,local);
	m->setLocal(local);
	cout<<"Insira a quantidade:"<<endl;
	cin >>qtd;
	m->setQtd(qtd);
	cin.ignore();
	while (tags != "sair"){
		cout<<"Insira uma tag: (ou escreva sair para encerrar)"<<endl;
		getline (cin, tags);
		cin.clear();
		fflush(stdin);
		if (tags !="sair"){
			m->addTag(tags);
		}
	}
	return m;
}

void Mapa::imprimeFichaTecnica(){
	int larguraCaixa = 70;
	cout  << endl << setfill('=')<< setw(larguraCaixa)<< "" << setfill(' ')<<endl;
	cout << "| Mapa " << setw(larguraCaixa - 7) << " |" << endl;
	Item::imprimeFichaTecnica();
	cout << "| Local: " << setw(larguraCaixa - 11) << this->local  << " |" << endl;
	cout << "| Escala: " << setw(larguraCaixa - 12) << this->escala<< " |" << endl;
	cout << setfill('=')<< setw(larguraCaixa)<< "" << setfill(' ')<<endl;
}
#include "Mapa.h"