#include "Item.h"

int Item::contador = 0;

Item::Item()
{
	this->id = ++contador;
	this->tags.clear();
	this->emprestado =0;
	this ->qtd = 1;
}

Item::~Item()
{
}

void Item::imprimeFichaTecnica(){
	int larguraCaixa =70;
	cout << "| Nome: " << setw(larguraCaixa - 10) << this->nome << " |" << endl;
	cout << "| Quantidade: " <<setw (larguraCaixa - 16) <<this->qtd <<" |" <<endl;
	cout << "| Id: " << setw(larguraCaixa - 8) << this->id << " |" << endl;
	cout << "| Tags: " ;
	for (const string& tag : tags) {
		cout<< tag << " - ";
	}
	cout << setw(larguraCaixa - 8 - calcularTamanhoTotalTags()) << "|" << endl;

	
}
void Item::setNome (string nome){
	this->nome = nome;
}
void Item::addTag (string tag){
	tags.push_back(tag);
}

string Item::getNome (){
	return nome;
}
int Item::getId(){
	return id;
}

int Item::getQtd(){
	return qtd;
}

void Item::setQtd(int qtd){
	this->qtd= qtd;
}

vector<string> Item::getTags (){
	return tags;
}

bool Item::foiEmprestado(){
	return emprestado;
}
void Item::setEmprestado(bool emprestado){
	this->emprestado = emprestado;
}

int Item::calcularTamanhoTotalTags() {
        int tamanhoTotal = 0;
        for (string& tag : tags) {
            tamanhoTotal += tag.size() + 3; // +1 para considerar o espaço entre as tags
        }
        return tamanhoTotal;
    }
    
/*string Item::salvar() const{
        ostringstream ss;
        ss << "TipoItem: " << static_cast<int>(obterTipo()) << "\n"; // Adiciona o identificador de tipo
        ss << "Nome: " << nome << "\n";
        ss << "ID: " << id << "\n";
        ss << "Tags: ";
        for (const auto& tag : tags) {
            ss << tag << " ";
        }
        ss << "\n";
        ss << "Emprestado: " << (emprestado ? "Sim" : "Não") << "\n";

        return ss.str();
    }
void Item::carregar(istringstream& dados) {
        string linha;

        while (getline(dados, linha)) {
            // Verifica cada linha para identificar e carregar os dados comuns do Item
            if (linha.find("Nome: ") != string::npos) {
                nome = linha.substr(6); // Tamanho de "Nome: "
            } else if (linha.find("ID: ") != string::npos) {
                id = stoi(linha.substr(4)); // Tamanho de "ID: "
            } else if (linha.find("Tags: ") != string::npos) {
                // Assume que as tags estão na mesma linha, separadas por espaço
                istringstream tagsStream(linha.substr(6));
                string tag;
                while (tagsStream >> tag) {
                    tags.push_back(tag);
                }
            } else if (linha.find("Emprestado: ") != string::npos) {
                emprestado = (linha.substr(12) == "Sim") ? true : false; // Tamanho de "Emprestado: "
            }
        }
   }*/



    


#include "Item.h"