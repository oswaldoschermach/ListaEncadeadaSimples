#ifndef LISTASEQUENCIAL_H_INCLUDED
#define LISTASEQUENCIAL_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

typedef struct ListaSequencial{
  int tamanho;
  int head;
  int tail;
  string* vetor;
}ListaSequencial;

bool cheia(ListaSequencial* l);
void inserirFinal(ListaSequencial* l, string elemento);
void removerFinal(ListaSequencial* l);
bool vazia(ListaSequencial* l);
void removerPrimeiro(ListaSequencial* l);
void imprimirLista(ListaSequencial* l);
ListaSequencial* criarLista(int tamanho);
void inserirNoIndice(ListaSequencial* l, int indice, string elemento);
void removerDoIndice(ListaSequencial* l, int indice);
void buscaNaLista(ListaSequencial* l, string dado);
void destruirLista(ListaSequencial* l);
int buscaString(string frase, string palavra);
char* converteString(string frase);

void carregarArquivo(ListaSequencial* l, string arquivo){ //função para carregar o arquivo com a lista
    ifstream file;
    string line;
    file.open(arquivo);
    if(file.is_open()){
            cout << "Carregando (Lista sequencial)\n";
        while(getline(file, line)){
            inserirFinal(l, line);
        }
        cout << "finalizado \n";
        system("cls");
    }else{
        cout << "Nao foi possivel abrir o arquivo" << endl;
    }
}
void buscaNaLista(ListaSequencial* l, string dado){
    int ocorrencias = 0;
    int Ifs = 0;
    for(int i = 0; i <= l->tail; i++){
        if(buscaString(l->vetor[i], dado) == 0){
            cout << "Elemento encontrado: " << i << " " << l->vetor[i] << endl;
            ocorrencias++;
        }
        Ifs++;
    }
    if(ocorrencias == 0)
        cout << "Elemento " << dado << " nao existe na lista\n";
    cout << "\n\n\n\n\t\t\t\tNumero de IFs executados(Lista sequencial): " << Ifs << endl;
}
void removerDoIndice(ListaSequencial* l, int indice){
    int copias = 0;
    int IFs = 0;
    IFs++;
    if(vazia(l)){
        cout << "Lista Vazia\n";
    }else if(indice > l->tail || indice < l->head){
        cout << "Fora dos limites da lista\n";
    }else{
        for(int i = l->head; i <= l->tail; i++){
            IFs++;
            if(indice == i){
                for(int j = i; j <= l->tail - 1; j++){
                    l->vetor[j] = l->vetor[j + 1];
                    copias++;
                }
                break;
            }
        }
    }
        l->tail--;
    cout << "\n\n\n\n\t\t\t\tNumero de IFs executados(Lista sequencial): " << IFs << " Numero de copias(Lista sequencial): " << copias << endl;
}
void inserirNoIndice(ListaSequencial* l, int indice, string elemento){
    int copias = 0;
    int IFs = 0;
    IFs++;
    if(cheia(l)){
        cout << "Lista cheia!" << endl;
    }
    else{
        if(indice > l->tail || indice < l->head){
            cout << "Fora dos limites da lista\n";
        }else{
            for(int i = l->head; i <= l->tail; i++){
                IFs++;
                if(indice == i){
                    string troca;
                    string aux;
                    aux = l->vetor[i];
                    copias++;
                    l->vetor[i] = elemento;
                    copias++;
                    for(int j = i; j <= l->tail - 1; j++){
                        troca = l->vetor[j + 1];
                        copias++;
                        l->vetor[j + 1] = aux;
                        copias++;
                        aux = troca;
                        copias++;
                    }
                    break;
                }
            }
        if(l->tail < l->tamanho-1)
            l->tail++;
        }
    }
    cout << "\n\n\n\n\t\t\t\tNumero de IFs executados(Lista sequencial): " << IFs << " Numero de copias(Lista sequencial): " << copias << endl;
}

bool cheia (ListaSequencial *l) {
  return (l->tail == l->tamanho - 1);
}

void inserirFinal(ListaSequencial *l, string elemento) {
  //if (cheia(l) == false) {
    if(l->tail < l->tamanho - 1)
        l->tail++;
    l->vetor[l->tail] = elemento;
  //}else{
      //cout << "Lista cheia!";
  //}
}

bool vazia (ListaSequencial *l){
  return (l->tail == l->head);
}

void removerPrimeiro(ListaSequencial *l) {
    int copias = 0;
    int IFs = 0;
    IFs++;
  if (vazia(l)) {
    printf ("Lista vazia\n");
  }else{
    for(int i = l->head; i != l->tail; i=(i+1)%l->tamanho){
        l->vetor[i] = l->vetor[i + 1];
        copias++;
    }
    l->tail--;
  }
  cout << "\n\n\n\n\t\t\t\tNumero de IFs executados(Lista sequencial): " << IFs << " Numero de copias(Lista sequencial): " << copias << endl;
}

void removerFinal(ListaSequencial* l){
    if(vazia(l) != true)
        l->tail--;
}

void imprimirLista (ListaSequencial* l){

    if(vazia(l)){
        cout << "Lista vazia!\n";
    }else{
        cout << "________________LISTA SEQUENCIAL_________________\n\n" << endl;
        for (int i = l->head; i <= l->tail; i++) {
            cout << i << " " << l->vetor[i] << endl;
        }
    }

}

ListaSequencial* criarLista(int tamanho) {
  ListaSequencial* l = (ListaSequencial *)malloc(sizeof(ListaSequencial));
  l->tamanho = tamanho + 20;
  l->head = 0;
  l->tail = -1;
  l->vetor = new string[tamanho + 20];
  return l;
}

void destruirLista(ListaSequencial* l){
    delete [] l->vetor;
    free(l);
}

char* converteString(string frase){
    char* data = new char[frase.size() + 1];
    copy(frase.begin(), frase.end(), data);
    data[frase.size()] = '\0';
    return data;
    delete data;
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



#endif // LISTASEQUENCIAL_H_INCLUDED
