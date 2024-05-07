#include "TCC.h"

TCC::TCC()
{
}

TCC::~TCC()
{
}

string TCC::getAutor (){
	return autor;
}
string TCC::getUniversidade (){
	return universidade;
}
string TCC::getCurso (){
	return curso;
}
int TCC::getAno (){
	return ano;
}
string TCC::getLocal(){
	return local;
}
TipoConclusao TCC::getTipo(){
	return tipo;
} 

void TCC::setAutor (string autor){
	this->autor = autor;
}
void TCC::setUniversidade (string universidade){
	this->universidade = universidade;
}
void TCC::setCurso (string curso){
	this->curso = curso;
}
void TCC::setAno (int ano){
	this->ano = ano;
}
void TCC::setLocal (string local){
	this->local = local;
}
void TCC::setTipo (TipoConclusao tipo){
	this->tipo = tipo;
}

void TCC::imprimeFichaTecnica(){
	int larguraCaixa = 70;
	cout  << endl << setfill('=')<< setw(larguraCaixa)<< "" << setfill(' ')<<endl;
		cout << "| TCC" << setw(larguraCaixa - 5) << " |" << endl;
	cout << "| Autor: " << setw(larguraCaixa - 11) << this->autor << " |" << endl;
	Item::imprimeFichaTecnica();
	cout << "| " << this->universidade << " - "<< this->local << " - " << this->ano<< setw(larguraCaixa - this->universidade.size() - this->local.size() - 12) << " |" << endl;
	cout << "| Curso: " << setw(larguraCaixa - 11) << this->curso << " |" << endl;
	if (this->tipo == 0){
		cout << "| Tipo: Monografia " << setw(larguraCaixa - 19) << " |" << endl;
	} else if (this->tipo ==1){
		cout << "| Tipo: Dissertacao " << setw(larguraCaixa - 20) << " |" << endl;
	} else if (this->tipo ==2){
		cout << "| Tipo: Tese " << setw(larguraCaixa - 13) << " |" << endl;
	}
	cout << setfill('=')<< setw(larguraCaixa)<< "" << setfill(' ')<<endl;
	
}
TCC* TCC::cadastra(){
	TCC *t = new TCC();
	string nome;
	
	string autor;
	string universidade;
	string curso;
	int ano;
	string local;
	int tipoin;
	int qtd;
	
	string tags;
	cin.ignore();
	cout<<"Insira um nome:"<<endl;
	getline (cin, nome);
	t->setNome(nome);
	cout<<"Insira o autor:"<<endl;
	getline (cin,autor);
	t->setAutor(autor);
	cout<<"Insira o curso:"<<endl;
	getline (cin,curso);
	t->setCurso(curso);
	cout<<"Insira a universidade:"<<endl;
	getline(cin, universidade);
	t->setUniversidade(universidade);
	cout <<"Insira o ano:"<<endl;
	cin >> ano;
	t->setAno(ano);
	cout<<"Insira o local:"<<endl;
	getline (cin, local);
	cout<<"Insira a quantidade:"<<endl;
	cin >>qtd;
	t->setQtd(qtd);
	cout <<"Insira o tipo 1- Monografia 2- Dissertassao 3- Tese" <<endl;
	cin>> tipoin;
	t->setTipo(static_cast<TipoConclusao>(tipoin-1));
	
	while (tags != "sair"){
		cin.ignore();
		cout<<"Insira uma tag: (ou escreva sair para encerrar)"<<endl;
		getline (cin, tags);
		if (tags !="sair"){
			t->addTag(tags);
		}
	}
	return t;
}

/*void TCC::carregar(istringstream& dados) {
        Item::carregar(dados);

        string linha;

        while (getline(dados, linha)) {
            // Verifica cada linha para identificar e carregar os dados específicos do Livro
            if (linha.find("Autor: ") != string::npos) {
                autor = stoi(linha.substr(7)); 
            } else if (linha.find("Curso: ") != string::npos) {
                curso = linha.substr(7); 
            } else if (linha.find("Universidade: ") != string::npos) {
                universidade = linha.substr(14); 
            } else if (linha.find("Ano: ") != string::npos) {
                ano = stoi(linha.substr(5)); 
            }else if (linha.find("Local: ") != string::npos) {
                local = stoi(linha.substr(7)); 
            } else if (linha.find("Tipo: ") != string::npos) {
                tipo = static_cast<TipoConclusao>(std::stoi(linha.substr(6)));
        	}
        }
    }

string TCC::salvar() const{
    const Item *itemTemp = this;
    
    // Chamar a função virtual salvar() do objeto temporário de Item
    string dadosItem = itemTemp->salvar();
    ostringstream ss;
    ss << dadosItem;
    ss << "Autor: " << autor << "\n";
    ss << "Curso: " << curso << "\n";
    ss << "Universidade: " << universidade << "\n";
    ss << "Local: " << local << "\n";
    ss << "Tipo: " << static_cast<int>(tipo) << "\n";

    return ss.str();
    }*/
#include "TCC.h"