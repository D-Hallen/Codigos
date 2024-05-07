#include "Menu.h"

Menu::Menu()
{
}

Menu::~Menu()
{
}

int Menu::inicial(){
	inicio:
	cout<<endl<<"Opcoes Disponiveis:" <<endl;
	cout<<"  1- Ver acervo" <<endl;
	cout<<"  2- Adicionar item ao acervo"<<endl;
	cout<<"  3- Cadastrar pessoa"<<endl;
	cout<<"  4- Pegar item emprestado"<<endl;
	cout<<"  5- Devolver item emprestado"<<endl;
	cout<<"  6- Fazer pesquisa no acervo"<<endl;
	cout<<"  7- Deletar item do acervo"<<endl;
	cout<<"  0- Sair da biblioteca"<<endl;
	cout<<"=>";
	int m;
	cin >> m;
	cin.ignore();
	if (m<0 || m>7){
		cout<<"Erro: Valor colocado invalido"<<endl;
		system("pause");
		goto inicio;
	}
	
	return m;
}

void Menu::pesquisaGeral(const vector<Item*>& acervo, const string& termoPesquisa){
	vector<Item*> resultados;
	for (const auto& item : acervo) { //procura no nome
        if (item->getNome().find(termoPesquisa) != string::npos) {
            resultados.push_back(item);
            continue;
        }
        for (const auto& tag : item->getTags()){ //procura nas tags
        	if (tag.find(termoPesquisa) != string::npos){
        		resultados.push_back(item);
        		break;
			}
		}	
    }
    for (size_t i = 0; i < resultados.size(); ++i) { // imprime resultados
            cout << i + 1 << ". ";
			resultados[i]->imprimeFichaTecnica();
			cout << endl;
        }
    if (resultados.size()==0){
    	cout <<"Termo nao encontrado no acervo!"<<endl;
	}    
}
Item* Menu::pesquisaItem(const vector<Item*>& acervo, const string& termoPesquisa) {
    vector<Item*> resultados;

    // Busca por itens que contenham o termo de pesquisa no nome
    for (const auto& item : acervo) {
        if (item->getNome().find(termoPesquisa) != string::npos) {
            resultados.push_back(item);
        }
    }

    // Caso nenhum resultado seja encontrado
    if (resultados.empty()) {
        cout << "Item desconhecido." << endl;
        return NULL;
    }
    // Caso haja apenas um resultado, imprime a ficha técnica
    else if (resultados.size() == 1) {
        return resultados[0];
    }
    // Caso haja mais de um resultado, imprime a ficha técnica de todos e pede para escolher
    else {
        cout << "Encontrados varios itens com o termo de pesquisa:" << endl;
        for (size_t i = 0; i < resultados.size(); ++i) {
            cout << i + 1 << ". " << resultados[i]->getNome() << endl;
        }

        cout << "Escolha um numero para visualizar a ficha tecnica do item correspondente: ";
        int escolha;
        cin >> escolha;

        if (escolha > 0 && escolha <= resultados.size()) {
            return resultados[escolha - 1];
        } else {
            cout << "Escolha invalida." << endl;
            return NULL;
        }
    }
}

Item* Menu::pesquisaItem(const vector<Item*>& acervo, const int& idPesquisa) {
    vector<Item*> resultados;

    // Busca por itens que contenham o termo de pesquisa no id
    for (const auto& item : acervo) {
        if (item->getId() == idPesquisa) {
            resultados.push_back(item);
        }
    }

    // Caso nenhum resultado seja encontrado
    if (resultados.empty()) {
        cout << "Item desconhecido." << endl;
        return NULL;
    }
    // Caso haja apenas um resultado, imprime a ficha técnica
    else if (resultados.size() == 1) {
        return resultados[0];
    }
    // Caso haja mais de um resultado, imprime a ficha técnica de todos e pede para escolher
    else {
        cout << "Encontrados varios itens com o termo de pesquisa:" << endl;
        for (size_t i = 0; i < resultados.size(); ++i) {
            cout << i + 1 << ". " << resultados[i]->getNome() << endl;
        }

        cout << "Escolha um numero para visualizar a ficha tecnica do item correspondente: ";
        int escolha;
        cin >> escolha;

        if (escolha > 0 && escolha <= resultados.size()) {
            return resultados[escolha - 1];
        } else {
            cout << "Escolha invalida." << endl;
			return NULL;
        }
    }
}
Pessoa* Menu::cadastraPessoa (){
	Pessoa *p = new Pessoa;
	cin.ignore();
	string nome;
	cout << "Insira o nome do usuario:" <<endl;
	getline (cin, nome);
	string dNasc;
	cout << "Insira a data de Nascimento:" <<endl;
	cin >> dNasc;
	getline (cin, dNasc);
	cout <<"Insira o CPF:" <<endl;
	string cpf;
	getline (cin, cpf);
	p->setNome(nome);
	p->setDataNascimento(dNasc);
	p->setCpf(cpf);
	return p;
}

Item* Menu::cadastraItem (){
	inicio:
	cout <<"Lista de itens disponivel:"<<endl;
	cout << "1 - Cartaz" << endl;
    cout << "2 - Livro" << endl;
    cout << "3 - Midia" << endl;
    cout << "4 - Mapa" << endl;
    cout << "5 - Periodico" << endl;
    cout << "6 - Relatorio" << endl;
    cout << "7 - TCC" << endl;
    cout <<"=>";
    int m;
    cin >> m;
    if (m<0 || m>7){
    	cout<<"Valor invalido!"<<endl;
    	goto inicio;
	}
    switch (m) {
	    case 1: {
	        Cartaz *c = new Cartaz();
	        c = c->cadastra();
	        return c;
	    }
	    case 2: {
	        Livro *l = new Livro();
	        l = l->cadastra();
	        return l;
	    }
	    case 3: {
	        Midia *mi = new Midia();
	        mi = mi->cadastra();
	        return mi;
	    }
	    case 4: {
	        Mapa *mp = new Mapa();
	        mp = mp->cadastra();
	        return mp;
	    }
	    case 5: {
	        Periodico *p = new Periodico();
	        p = p->cadastra();
	        return p;
	    }
	    case 6: {
	        Relatorio *r = new Relatorio();
	        r = r->cadastra();
	        return r;
	    }
	    case 7: {
	        TCC *t = new TCC();
	        t = t->cadastra();
	        return t;
	    }
	    default:
	        // Lógica para lidar com casos não esperados
	        return nullptr; // ou lançar uma exceção, dependendo dos requisitos do seu programa
	}

}

Pessoa* Menu::pesquisaPessoa (const vector<Pessoa*>& cadastros,const string& CPF){
	for (const auto& pessoa : cadastros) {
        if (pessoa->getCpf().find(CPF) != string::npos) {
           	return pessoa;
        }
    }
    cout <<"Cadastro nao localizado"<<endl;
    return NULL;
}


vector<Item*> Menu::carregaAcervo(){
	vector<Item*> acervo;
	Livro *meuLivro = new Livro();
	meuLivro->setNome("Fahrenheit 451");
	meuLivro->setQtd(15);
	meuLivro->setAutor("Ray Bradbury");
	meuLivro->setEdicao(2);
	meuLivro->setEditora("Biblioteca Azul");
	meuLivro->setNumPags(215);
	meuLivro->setISBN("9788525052247");
	meuLivro->addTag("Distopia");
	meuLivro->addTag("Suspense");
	//meuLivro->imprimeFichaTecnica();
	acervo.push_back(meuLivro);
	Livro *meuLivro2 = new Livro();
	meuLivro2->setNome("Fahrenheit 451");
	meuLivro2->setQtd(18);
	meuLivro2->setAutor("Ray Bradbury");
	meuLivro2->setEdicao(2);
	meuLivro2->setEditora("Biblioteca Azul");
	meuLivro2->setNumPags(215);
	meuLivro2->setISBN("9788525052247");
	meuLivro2->addTag("Distopia");
	meuLivro2->addTag("Suspense");
	acervo.push_back(meuLivro2);
	
	TCC *meuTCC = new TCC();
	meuTCC->setAno(2025);
	meuTCC->setQtd(3);
	meuTCC->setAutor("Daniel Hallen de Paulo Passos");
	meuTCC->setCurso("Engenharia da Computacao");
	meuTCC->setLocal("Divinopolis");
	meuTCC->setNome("Desenvolvimento de DOOM 2 o inimigo agora e outro");
	meuTCC->setUniversidade("Universidade do Estado de Minas Gerais");
	meuTCC->addTag("Informatica");
	meuTCC->addTag("Jogos");
	meuTCC->setTipo (Tese);
	//meuTCC->imprimeFichaTecnica();
	acervo.push_back(meuTCC);
	
	Periodico *meuP = new Periodico();
	meuP ->setAno (2015);
	meuP ->setNome ("Periodico Bacana");
	meuP ->setEdicao (3);
	meuP->setQtd(5);
	meuP ->setEditora ("Ciencia+");
	meuP ->setNumPags (170);
	meuP ->setISSN ("17129842");
	meuP ->setTipo (Jornal);
	meuP ->addNoticias ("Desenvolvimento do PlayStation 6 terminou");
	meuP ->addTag("Ciencia");
	meuP ->addTag ("Inovacao");
	meuP ->addNoticias("Criacao de empregadas robos no japao") ;
	meuP ->addNoticias("Queda do Imperio Americano");
	//meuP ->imprimeFichaTecnica();
	acervo.push_back(meuP);
	
	Relatorio *meuRel = new Relatorio();
	meuRel->setNome("Relatorio Muito Importante Nacional");
	meuRel->setQtd(8);
	meuRel->setCidade("Divinopolis");
	meuRel->setData("28 de Novembro de 2023");
	meuRel->setDescricao("Esse grande relatorio e de demasiada importancia para o funcionamento do parlamento brasileiro de forma que seja necessaria a leitura por todos");
	meuRel->setAutor("Daniel Hallen");
	meuRel->addTag("Governo");
	meuRel->addTag("Publico");
	meuRel->addTag("Parlamento");
	//meuRel->imprimeFichaTecnica();
	acervo.push_back(meuRel);
	
	Midia *meuFilme = new Midia();
	meuFilme->setAno(2012);
	meuFilme->setConteudo("Filme");
	meuFilme->setDuracaoMin(130);
	meuFilme->setNome("Vingadores");
	meuFilme->setProdutora("Marvel");
	meuFilme->setTipo(DVD);
	meuFilme->addTag("Cinema");
	meuFilme->addTag("Acao");
	meuFilme->addTag("Marvel");
	//meuFilme->imprimeFichaTecnica();
	acervo.push_back(meuFilme);
	
	Mapa *meuMapa = new Mapa();
	meuMapa->setNome("Densidade Geografica Brasileira");
	meuMapa->setEscala("1/100");
	meuMapa->setLocal("Brasil");
	meuMapa->addTag("Geografia");
	meuMapa->addTag("IBGE");
	meuMapa->addTag("Governo");
	//meuMapa->imprimeFichaTecnica();
	acervo.push_back(meuMapa);
	
	Cartaz *meuCartaz = new Cartaz();
	meuCartaz->setAssunto("Prevencao do COVID");
	meuCartaz->setAutor("Ministerio da Saude");
	meuCartaz->setNome("Cartaz da Campanha de Prevencao do Covid (2023)");
	meuCartaz->addTag("Saude");
	meuCartaz->addTag("Governo");
	meuCartaz->addTag("Publico");
	//meuCartaz->imprimeFichaTecnica();
	acervo.push_back(meuCartaz);
	return acervo;
}
vector<Pessoa*> Menu::carregaCadastros(){
	vector<Pessoa*> cadastros;
	Pessoa *pessoa1 = new Pessoa();
	pessoa1->setCpf("12345678901");
	pessoa1->setDataNascimento("25/05/2004");
	pessoa1->setNome("Daniel Hallen de Paulo Passos");
	cadastros.push_back(pessoa1);
	return cadastros;
}
#include "Menu.h"