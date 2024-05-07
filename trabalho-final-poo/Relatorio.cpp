#include "Relatorio.h"

Relatorio::Relatorio()
{
}

Relatorio::~Relatorio()
{
}

string Relatorio::getData (){
	return data;
}
string Relatorio::getCidade (){
	return cidade;
}
string Relatorio::getAutor (){
	return autor;
}
string Relatorio::getDescricao (){
	return descricao;
}

void Relatorio::setData (string data){
	this->data = data;
}
void Relatorio::setCidade (string cidade){
	this->cidade = cidade;
}
void Relatorio::setDescricao (string descricao){
	this->descricao = descricao;
}
void Relatorio::setAutor (string autor){
	this->autor = autor;
}
void Relatorio::imprimeFichaTecnica(){
	int larguraCaixa = 70;
	cout  << endl << setfill('=')<< setw(larguraCaixa)<< "" << setfill(' ')<<endl;
	cout << "| Relatorio " << setw(larguraCaixa - 12) << " |" << endl;
	Item::imprimeFichaTecnica();
	imprimirRelatorio(larguraCaixa);
	cout << "| " << setw(larguraCaixa - 2)<< " |" << endl;
	cout << "| Autor: " << setw(larguraCaixa - 11) << this->autor << " |" << endl;
	cout << "| "<< this->data <<" , " << this->cidade <<setw(larguraCaixa - 5 - this->data.size() - this->cidade.size()) <<" |" <<endl;
	cout << setfill('=')<< setw(larguraCaixa)<< "" << setfill(' ')<<endl;
	
}

vector<string> Relatorio::dividirEmLinhas (int larguraMax){
	vector<string> linhas;
        istringstream iss(this->descricao);

        string palavra;
        string linhaAtual;

        while (iss >> palavra) {
            if (linhaAtual.size() + palavra.size() + 1 <= larguraMax) {
                // Adiciona a palavra à linha atual
                if (!linhaAtual.empty()) {
                    linhaAtual += " ";
                }
                linhaAtual += palavra;
            } else {
                // Adiciona a linha atual ao vetor de linhas
                linhas.push_back(linhaAtual);
                // Reinicia a linha atual com a palavra atual
                linhaAtual = palavra;
            }
        }

        // Adiciona a última linha ao vetor de linhas
        linhas.push_back(linhaAtual);

        return linhas;
}
void Relatorio::imprimirRelatorio(int larguraDaCaixa){
	int larguraMaxLinha = larguraDaCaixa - 4;
    // Dividir o texto em linhas
    vector<string> linhas = dividirEmLinhas(larguraMaxLinha);

    // Imprimir cada linha dentro da caixa
    for (string& linha : linhas) {
        cout << "| " << setw(larguraMaxLinha) << linha << " |" <<  endl;
    }

}

Relatorio* Relatorio::cadastra (){
	Relatorio *r = new Relatorio();
	string nome;
	string data;
	string cidade;
	string autor;
	string descricao;
	string tags;
	int qtd;
	cin.ignore();
	cout<<"Insira um nome:"<<endl;
	getline (cin, nome);
	r->setNome(nome);
	cout<<"Insira a data:"<<endl;
	getline (cin,data);
	r->setData(data);
	cout<<"Insira a cidade:"<<endl;
	getline (cin,cidade);
	r->setCidade(cidade);
	cout<<"Insira o autor:"<<endl;
	getline (cin,autor);
	r->setAutor(autor);
	cout<<"Insira a quantidade:"<<endl;
	cin >>qtd;
	r->setQtd(qtd);
	cout<<"Insira a descricao:"<<endl;
	getline (cin,descricao);
	r->setDescricao(descricao);
	while (tags != "sair"){
		cin.ignore();
		cout<<"Insira uma tag: (ou escreva sair para encerrar)"<<endl;
		getline (cin, tags);
		if (tags !="sair"){
			r->addTag(tags);
		}
	}
	return r;
}
#include "Relatorio.h"