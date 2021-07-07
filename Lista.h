#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

/*******************************************************************************
*                                                                              *
*                                                                              *
*                        Arquivo que cont�m as classes                         *
*                                                                              *
*                                                                              *
*******************************************************************************/

#include <iostream>
#include <stdlib.h>
#include <fstream> //biblioteca utilizada para ler um arquivo txt externo
#include <time.h>
#include <string.h>

using namespace std;
/********************************CLASSE NODE********************************/
/**classe utilizada para criar um novo n� dentro da lista, cont�m todas as opera��es necess�rias**/
class Node{
private:
    string data; //dado que a lista vai conter
    Node* next; //ponteiro que recebe o pr�ximo n� da Lista
    int index; //campo que cont�m o indice da lista, como um endere�o, semelhante a um array
    int rg;
public:
    Node(string data){ //construtor da classe Node, cria um novo n�
        this->data = data; //inicializa o campo data com um valor
        this->next = NULL; //inicializa o proximo n� como nulo
    }
    int getRg(){
        return rg;
    }
    void setRg(int rg){
        this->rg = rg;
    }
    int getIndex(){ //fun��o para retornar o indice do elemento na lista
        return index;
    }
    void setIndex(int i){ //seta o indice do elemento
        index = i;
    }
    string getData(){ //fun�ao utilizada para obter o dado
        return data;
    }
    void setData(string data){
        this->data = data;
    }
    Node* getNext(){ //fun�ao para obter o proximo n�
        return next;
    }
    void setNext(Node* p){ //seta o pr�ximo n�
        next = p; //o pr�ximo n� recebe uma nova refer�ncia
    }
};
/********************************CLASSE LISTA********************************/
/*classe que cont�m todas as opera��es da lista, bem como a cria��o da mesma*/
class Lista{
private:
    Node* head; //ponteiro para o primeiro elemento da lista
    Node* tail; //ponteiro para o ultimo elemento da lista
    int tamanho = 0; //campo que guarda o tamanho da lista
public:
    Lista(){ //construtor da lista, caso o usu�rio crie a lista sem passar nenhum dado
        head = NULL;
        tail = NULL; //o come�o e o fim da lista recebem nulo, pois ainda nao foram incluidos nenhum elemento
    }
    Lista(string data){ //construtor para caso o usuario j� comece a lista com um elemento
        head = new Node(data); //� criado um novo n� no inicio da lista, este n� recebe um dado
        tail = head; //a cauda � igual a cabe�a, pois s� foi incluido 1 elemento
    }
    int getTamanho(){
        return tamanho; //retorna o tamanho da lista
    }
    virtual ~Lista(){
        delete head;
    }
    bool vazia(){ //fun��o para verificar se a lista esta vazia, caso a cabe�a seja null, a lista esta vazia
        return (head == NULL); ///retorna true para lista vazia
    }
/*******************FUN��O PARA FAZER UMA BUSCA SEQUENCIAL NA LISTA*********************/
    void busca(string data){
        Node* aux = head; //inicializa um pointer auxiliar recebendo a cabe�a da lista
        int occurrences = 0; //variavel auxiliar, serve para ter um controle do numero de ocorrencias da busca
        int IFs = 0; //para calcular o numero de compara��es executadas
        while(aux){ //repete enquanto aux � diferente de NULL, aux no caso � um ponteiro
            IFs++;
            if(buscaString(aux->getData(), data) == 0){ //se o dado contido no campo for igual ao fornecido ele faz a impress�o
                cout << aux->getIndex() << " " << aux->getData() << endl; //imprime indice e o elemento da lista
                occurrences++; //incrementa o numero de ocorrencias deste elemento dentro da lista
            }
                aux = aux->getNext(); //percorre toda a lista, getNext() serve para pegar o proximo n�
        }
        if(occurrences == 0) //se as ocorrencias forem zero, entao o elemento buscado nao existe na lista
            cout << "Elemento nao existe na lista\n";

    cout << "Numero de IFs executados(Lista encadeada): " << IFs << endl;
    }
/*******************FUN��O PARA MOSTRAR A LISTA*********************/
    void showList(){ //imprime a lista na tela
        cout << "__________________LISTA ENCADEADA_________________\n\n\n";
        Node* aux = head;  //inicializa um pointer auxiliar recebendo a cabe�a da lista
        if(vazia()) //verifica se a lista esta vazia, se estiver, imprime uma mensagem de lista vazia
            cout << "Lista vazia\n";
        else       //caso contrario, faz a impress�o da lista no terminal
            while(aux){ //repete enquanto aux � diferente de nulo
                cout << aux->getIndex() << " " << aux->getData() << endl; //imprime o indice e o dado que esta armazenado
                aux = aux->getNext(); //percorre toda a lista, getNext() serve para pegar o proximo n�
            }
    }
/*******************FUN��O PARA INSERIR UM ELEMENTO NO INICIO DA LISTA*********************/
    void insertIni(string data){
        Node* newNode = new Node(data); //faz a cria�ao de um novo n�, passando um dado como parametro
        int id = 0; //identificador do inicio da lista
        int IFs = 0;
        int copias = 0;
        newNode->setNext(head); //seta o proximo n�
        newNode->setIndex(id); //o n� cabe�a recebe o indice 0
        head = newNode; //como esta sendo inserido no inicio, o no cabe�a recebe o novo n� criado
        copias++;
        tamanho++; //o tamanho da lista � incrementado

        //reorganiza o indice dos elementos
        Node* aux = head;
        IFs++;
        if(vazia())
            cout << "Lista vazia\n";
        else
            while(aux){ //repete enquanto aux � diferente de nulo
                aux->setIndex(id); //seta o proximo indice da lista
                aux = aux->getNext(); //perc orre a lista, sempre pegando o proximo n�
                id++; //incrementa o id do indice, depois este id e atribuido ao proximo elemento, re organizando tudo
                copias++;
            }
    cout << "\n\n\n\n\t\t\t\tNumero de IFs executados(Lista encadeada): " << IFs << " Numero de copias(Lista encadeada): " << copias << endl;
    }
/*******************FUN��O PARA INSERIR UM ELEMENTO DO FIM DA LISTA*********************/
    void insertFinal(string data){
        Node* newNode = new Node(data); //faz a cria�ao de um novo n�, passando um dado como parametro
        int IFs = 0;
        int copias = 0;
        IFs++;
        if(vazia()){ //verifica se a lista esta vazia, caso esteja, entao o ultimo � o primeiro
            head = newNode; //tanto a cabe�a quanto a calda recebem o novo n�
            copias++;
            tail = newNode;
            copias++;
            tail->setIndex(tamanho); //seta o endere�o deste novo n�, utiliza o tamanho como endere�o (neste caso seria 1)
            tamanho++; //incrementa o tamanho da lista
        }
        else{ //caso contrario a cabe�a estara com um elemento, entao insere no fim da lista
            tail->setNext(newNode); //seta o proximo ponteiro como o novo n�
            tail = newNode; //entao a calda recebe o novo n� criado
            copias++;
            tail->setIndex(tamanho); //ent�o o tamanho � utilizado como parametro para atribuir um indice a este n�
            tamanho++; //o tamanho � incrementado
        }

    }
/*************************FUN��O PARA REMOVER UM ELEMENTO EM UM INDICE ESPECIFICADO*********************/
    void removeIndex(int id){ ///recebe o indice do dado a ser removido
        Node* c = head; ///variavel inicializada com o inicio da lista
        int IFs = 0;
        int copias = 0;
        IFs++;
        if(id >= 0 && id <= tail->getIndex()){///Testa se o indice digitado esta dentro dos limites da lista
            for(int i = 0; i <= tail->getIndex(); i++){///faz a busca pelo indice digitado
                IFs++;
                if(id == c->getIndex()){ ///se o indice digitado for igual ao do n�, ent�o realiza as opera�oes
                    string aux; ///variaveis auxiliares para realizar as copias
                    string troca;
                    Node* p;
                    IFs++;
                    if(id == tail->getIndex()){
                        remover();
                        break;
                    }
                    while(id <= tail->getIndex()){
                        p = c;
                        copias++;
                        p = p->getNext();
                        copias++;
                        aux = p->getData();
                        copias++;
                        c->setData(aux);  ///aqui acontecem as copias
                        c = c->getNext();
                        copias++;
                        IFs++;
                        if(c == tail){ ///quando chegar no fim da lista, deleta o ultimo n�
                            remover();
                            break;
                        }
                        id++; //incrementa o indice
                    }
                    break;
                }
                c = c->getNext(); //percorre a lista ate encontrar o id digitado
            }
        }
        else
            cout << "Fora dos limites da lista\n";
    cout << "\n\n\n\n\t\t\t\tNumero de IFs executados(Lista encadeada): " << IFs << " Numero de copias(Lista encadeada): " << copias << endl;
    }
/*************************FUN��O PARA INSERIR UM ELEMENTO EM UM INDICE ESPECIFICADO*********************/
    void insertIndex(string data, int id){ ///recebe o dado a ser inserido e o indice onde o dado sera inserido
        Node* c = head; ///variavel inicializada com o inicio da lista
        int IFs = 0;
        int copias = 0;
        IFs++;
        if(id >= 0 && id <= tail->getIndex()){ ///Testa se o indice digitado esta dentro dos limites da lista
            for(int i = 1; i <= tail->getIndex(); i++){ ///faz a busca pelo indice digitado
                IFs++;
                if(id == c->getIndex()){ ///se o indice digitado for igual ao do n�, ent�o realiza as opera�oes
                    string aux; ///variaveis auxiliares para realizar as copias
                    string troca;
                    aux = c->getData(); ///salva o dado que sera sobrescrito pelo dado digitado
                    c->setData(data);
                    copias++;
                    IFs++;
                    if(id == tail->getIndex()){
                        insertFinal(aux);
                        break;
                    }
                    while(id <= tail->getIndex()){
                        c = c->getNext(); ///percorre a lista
                        copias++;
                        troca = c->getData();
                        copias++;
                        c->setData(aux);
                        aux = troca;       ///aqui acontecem as copias
                        copias++;
                        IFs++;
                        if(c == tail){ ///quando chegar no fim da lista, cria um novo n� e faz a insersao do ultimo dado
                            insertFinal(aux);
                            break;
                        }
                        id++; //incrementa o indice
                    }
                    break;
                }
                c = c->getNext(); //percorre a lista ate encontrar o id digitado
            }
        }
        else
            cout << "Fora dos limites da lista\n";
    cout << "\n\n\n\n\t\t\t\tNumero de IFs executados(Lista encadeada): " << IFs << " Numero de copias(Lista encadeada): " << copias << endl;
    }
/*******************FUN��O PARA REMOVER UM ELEMENTO DO FIM DA LISTA*********************/
	void remover(){
	    int IFs = 0;
        int copias = 0;
        IFs++;
		if(!vazia()){
			// se houver s� 1 elemento
			IFs++;
			if(head->getNext() == NULL){
                delete head;
                head = NULL; //caso haja apenas um elemento na lista, este elemento sera a cabe�a, entao seta cabe�a como NULL
                tamanho--;
			}
			else if(head->getNext()->getNext() == NULL){ //testa se o terceiro ponteiro � NULL
				delete head->getNext();
				head->setNext(NULL); //caso haja dois elementos na lista, � so pegar o proximo a partir da cabe�a e setar como NULL
				tamanho--;
			}
			else // > 2 elementos
			{
				Node* ant_ant = head; ///ponteiro criado para guardar o inicio da lista
				Node* ant = head->getNext();///usado para guardar o proximo elemento a partir da cabe�a
				Node* current = head->getNext()->getNext();///guarda o terceiro elemento

				while(current){
                    /** Faz trocas para obter o ultimo elemento
                    como s� podemos ir para frente na lista, precisamos salvar o penultimo  */
					Node* aux = ant;
					copias++;
					ant = current;
					copias++;
					ant_ant = aux;
					copias++;
					current = current->getNext(); ///percorre a lista
					copias++;
				}
				delete ant_ant->getNext(); // ant_ant passa a ser o penultimo, entao libera a memoria do proximo, que � o ultimo
				ant_ant->setNext(NULL); // seta o prox como NULL
				tail = ant_ant; // atualiza a cauda
				copias++;
				tamanho--;
			}
		}
    cout << "\n\n\n\n\t\t\t\tNumero de IFs executados(Lista encadeada): " << IFs << " Numero de copias(Lista encadeada): " << copias << endl;
	}
/*******************FUN��O PARA CARREGAR UM .TXT COM A LISTA*********************/
	void loadFile(string arquivo){ //fun��o para carregar o arquivo com a lista
        ifstream file;
        string line;
        file.open(arquivo);
        if(file.is_open()){
                cout << "Carregando (lista encadeada)\n";
            while(getline(file, line)){
                insertFinal(line);
            }
            cout << "finalizado \n";
            system("cls");
        }else{
            cout << "Nao foi possivel abrir o arquivo" << endl;
        }
	}
	void saveFile(string name){
        cout << "__________________Salvando_________________\n\n\n";
        Node* aux = head;  //inicializa um pointer auxiliar recebendo a cabe�a da lista
        ofstream file;
        file.open(name, ios::app);
        if(vazia()) //verifica se a lista esta vazia, se estiver, imprime uma mensagem de lista vazia
            cout << "Lista vazia\n";
        else
            while(aux){ //repete enquanto aux � diferente de nulo
                file << aux->getData() << "\n";
                aux = aux->getNext(); //percorre toda a lista, getNext() serve para pegar o proximo n�
            }
        cout << "__________________Finalizado_________________\n\n\n";
        system("cls");
	}
	char* converteString(string frase){
        char* data = new char[frase.size() + 1];
        copy(frase.begin(), frase.end(), data);
        data[frase.size()] = '\0';
        return data;
    }
    int buscaString(string frase, string palavra){

        int teste = 0;
        int position = 0;

        char *string1;
        char *string2;

        string1 = converteString(frase);
        string2 = converteString(palavra);

        while(teste < 48 || teste > 57){
            teste = (int)string1[position];
            position++;
        }
        position--;

        char *stringAux = (char *) malloc(strlen(string1) - position * sizeof(char));

        strncpy(stringAux, string1 + position, strlen(string1));

        return strcmp(string2, stringAux);
    }

};

#endif // LISTA_H_INCLUDED
