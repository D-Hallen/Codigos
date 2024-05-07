#include "Midia.h"

Midia::Midia()
{
}

Midia::~Midia()
{
}

int Midia::getDuracaoMin (){
	return duracaoMin;
}
string Midia::getConteudo (){
	return conteudo;
}
int Midia::getAno(){
	return ano;
}
string Midia::getProdutora (){
	return produtora;
}
TipoMidia Midia::getTipo(){
	return tipo;
}

void Midia::setDuracaoMin (int duracaoMin){
	this->duracaoMin = duracaoMin;
}
void Midia::setConteudo (string conteudo){
	this->conteudo = conteudo;
}
void Midia::setAno (int ano){
	this->ano = ano;
}
void Midia::setProdutora (string produtora){
	this->produtora = produtora;
}
void Midia::setTipo(TipoMidia tipo){
	this->tipo = tipo;
}

void Midia::imprimeFichaTecnica(){
	int larguraCaixa = 70;
	cout  << endl << setfill('=')<< setw(larguraCaixa)<< "" << setfill(' ')<<endl;
	cout << "| Midia " << setw(larguraCaixa - 8) << " |" << endl;
	Item::imprimeFichaTecnica();
	cout << "| Duracao: " << setw(larguraCaixa - 17) << this->duracaoMin << " min" << " |" << endl;
	if (this->tipo == 0){
		cout << "| Tipo: Fita " << setw(larguraCaixa - 13) << " |" << endl;
	} else if (this->tipo ==1){
		cout << "| Tipo: VHS " << setw(larguraCaixa - 12) << " |" << endl;
	} else if (this->tipo ==2){
		cout << "| Tipo: CD " << setw(larguraCaixa - 11) << " |" << endl;
	} else if (this->tipo ==3){
		cout << "| Tipo: DVD " << setw(larguraCaixa - 12) << " |" << endl;
	}
	cout << "| Conteudo: " << setw(larguraCaixa - 14) << this->conteudo<< " |" << endl;
	cout << "| Ano: " << setw(larguraCaixa - 9) << this->ano << " |" << endl;
	cout << "| Produtora: " << setw(larguraCaixa - 15) << this->produtora << " |" << endl;
	cout << setfill('=')<< setw(larguraCaixa)<< "" << setfill(' ')<<endl;
}
Midia* Midia::cadastra(){
	Midia *m = new Midia();
	string nome; 
	int duracaoMin; 
	string conteudo; 
	int ano; 
	string produtora; 
	int tipoin;
	int qtd;
	TipoMidia tipo;
	string tags;
	cin.ignore();
	cout<<"Insira um nome:"<<endl;
	getline (cin, nome);
	m->setNome(nome);
	cout<<"Insira o conteudo:"<<endl;
	getline (cin,conteudo);
	m->setConteudo(conteudo);
	cout<<"Insira a produtora:"<<endl;
	getline (cin,produtora);
	m->setProdutora(produtora);
	cout <<"Insira a duracao em minutos:"<<endl;
	cin >>duracaoMin;
	m->setDuracaoMin(duracaoMin);
	cout <<"Insira o ano:"<<endl;
	cin>> ano;
	m->setAno(ano);
	cout<<"Insira a quantidade:"<<endl;
	cin >>qtd;
	m->setQtd(qtd);
	cout <<"Insira o tipo 1- Fita 2- VHS 3- CD 4- DVD" <<endl;
	cin>> tipoin;
	m->setTipo(static_cast<TipoMidia>(tipoin-1));

	while (tags != "sair"){
		cin.ignore();
		cout<<"Insira uma tag: (ou escreva sair para encerrar)"<<endl;
		getline (cin, tags);
		if (tags !="sair"){
			m->addTag(tags);
		}
	}
	return m;
}
#include "Midia.h"