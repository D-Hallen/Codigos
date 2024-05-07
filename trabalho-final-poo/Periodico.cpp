#include "Periodico.h"

Periodico::Periodico()
{
	this->noticias.clear();
	this->ISSN = "NULL";
}

Periodico::~Periodico()
{
}


bool Periodico::validarISSN(string &codigo) {
    if (codigo.length() != 8) {
            return false; // ISSN deve ter exatamente 8 dígitos
        }

        int soma = 0;

        for (int i = 0; i < 7; ++i) {
            if (isdigit(codigo[i])) {
                soma += (codigo[i] - '0') * (8 - i);
            } else {
                return false; // Se algum caractere não for um dígito, o ISSN é inválido
            }
        }

        int digitoVerificador = 11 - (soma % 11);
        if (digitoVerificador == 10) {
            return (codigo[7] == 'X');
        } else {
            return (isdigit(codigo[7]) && (digitoVerificador == (codigo[7] - '0')));
        }
    }

int Periodico::getEdicao (){
	return this->edicao;
}
string Periodico::getEditora (){
	return this->editora;
}
int Periodico::getNumPags(){
	return this->numPags;
}
string Periodico::getISSN (){
	return this->ISSN;
}
vector<string> Periodico::getNoticias(){
	return this->noticias;
}

Tipo Periodico::getTipo(){
	return this->tipo;
}

int Periodico::getAno(){
	return this->ano;
}

void Periodico::setEdicao(int edicao){
	this->edicao=edicao;
}
void Periodico::setEditora(string editora){
	this->editora=editora;
}
void Periodico::setNumPags (int numPags){
	this->numPags=numPags;
}
void Periodico::setISSN (string ISSN){
	if (validarISSN(ISSN)){
		this->ISSN=ISSN;
	} else {
		cout <<"O valor da ISSN dado nao e valido, por favor inserir um valor diferente"<<endl;	
		this->ISSN = "NULL";
	}
}

void Periodico::setTipo (Tipo tipo){
	this->tipo = tipo;
}
void Periodico::setAno (int ano){
	this->ano = ano;
}
void Periodico::addNoticias (string noticia){
	noticias.push_back(noticia);
}

void Periodico::imprimeFichaTecnica(){
	int larguraCaixa = 70;
	cout  << endl << setfill('=')<< setw(larguraCaixa)<< "" << setfill(' ')<<endl;
	cout <<"| Periodico " << setw(larguraCaixa - 14) << this->editora << " |" << endl;	
	if (this->tipo == 0){
		cout <<"| Revista " <<this->nome << setw(larguraCaixa - 10 - this->nome.size())<< " |" << endl;	
	} else if (this->tipo == 1){
		cout <<"| Jornal " <<this->nome << setw(larguraCaixa - 9 - this->nome.size())<< " |" << endl;
	}
	Item::imprimeFichaTecnica();
	cout <<"| Editora: " << setw(larguraCaixa - 13) << this->editora << " |" << endl;
	cout << "| "<< this->edicao <<"o Edicao - ("<<this->ano<<")" << setw(larguraCaixa - 20) << " |" << endl;
	cout << "| "<< this->numPags <<" Paginas"<<setw(larguraCaixa - 13) << " |" << endl;
	cout <<"| ISSN: " << setw(larguraCaixa - 10) << this->ISSN << " |" << endl;
	cout <<"| Assuntos: " << setw(larguraCaixa - 12) << " |" << endl;
	for (const string& news : noticias) {
		cout << "| "<< news <<setw(larguraCaixa - news.size() -2) << " |" << endl;
	}
	cout << setfill('=')<< setw(larguraCaixa)<< "" << setfill(' ')<<endl;
	
}

Periodico* Periodico::cadastra(){
	Periodico *p = new Periodico();
	string nome;
	int edicao;
	string editora;
	int ano;
	int numPags;
	string ISSN;
	string noticia;
	int tipo;
	int qtd;
	string tags;
	
	cin.ignore();
	cout<<"Insira um nome:"<<endl;
	getline (cin, nome);
	p->setNome(nome);
	cout<<"Insira a edicao:"<<endl;
	cin >> edicao;
	p->setEdicao(edicao);
	cout<<"Insira a editora:"<<endl;
	getline (cin,editora);
	p->setEditora(editora);
	cout <<"Insira o ano"<<endl;
	cin >> ano;
	p->setAno(ano);
	cout<<"Insira a quantidade:"<<endl;
	cin >>qtd;
	p->setQtd(qtd);
	cout <<"Insira o Numero de Paginas"<<endl;
	cin >>numPags;
	p->setNumPags(numPags);
	while (p->ISSN == "NULL"){
		cout <<"Insira o codigo ISSN"<<endl;
		getline (cin, ISSN);
		p->setISSN(ISSN);
	}
	while (noticia != "sair"){
		cout<<"Insira uma noticia: (ou escreva sair para encerrar)"<<endl;
		getline (cin, noticia);
		if (noticia !="sair"){
			p->addNoticias(noticia);
		}
	}
	cout <<"Insira o tipo 1- Revista 2- Jornal" <<endl;
	cin>> tipo;
	p->setTipo(static_cast<Tipo>(tipo-1));
		
	while (tags != "sair"){
		cin.ignore();
		cout<<"Insira uma tag: (ou escreva sair para encerrar)"<<endl;
		getline (cin, tags);
		if (tags !="sair"){
			p->addTag(tags);
		}
	}
	return p;
}
#include "Periodico.h"