/*******************************************************************************
*                                                                              *
*                        Trabalho de Estrutura de Dados                        *
*                         Criado por Oswaldo Schermach                         *
*                                                                              *
*******************************************************************************/

#include <iostream>
#include <stdlib.h>
#include <fstream> //biblioteca utilizada para ler um arquivo txt externo
#include <time.h> //contem as funções para marcar o tempo de execução
#include "Lista.h" //header da classe utilizada
#include "ListaSequencial.h"

void printTime(time_t inicio, time_t fim); //prototipo da funcao que imprime o tempo de execuçao

/**********************FUNÇÃO PRINCIPAL***************************/
int main(int argc, char *argv[]){

    Lista l;
    int escolha, id;
    time_t inicio, fim;
    string dado;
    string nomeArquivo;
    int tam;

/*****************INICIO DO MENU***************************/
    cout << "\t\t\t\tEscolha o arquivo a ser carregado\n\n\n";
    cout << "1 Para carregar uma lista com 10 elementos" <<endl;
    cout << "2 Para carregar uma lista com 50 elementos" <<endl;
    cout << "3 Para carregar uma lista com 100 elementos" <<endl;
    cout << "4 Para carregar uma lista com 1 mil elementos" <<endl;
    cout << "5 Para carregar uma lista com 10 mil elementos" <<endl;
    cout << "6 Para carregar uma lista com 1 milhao de elementos" <<endl;
    cout << "7 Para carregar uma lista com 10 milhoes de elementos" <<endl;
    cin >> escolha;
    inicio = time(NULL);
    switch(escolha){
        case 1: l.loadFile("NomeRG10.txt"); tam = 10; nomeArquivo = "SaidaLista10.txt";  break;
        case 2: l.loadFile("NomeRG50.txt"); tam = 50; nomeArquivo = "SaidaLista50.txt"; break;
        case 3: l.loadFile("NomeRG100.txt"); tam = 100; nomeArquivo = "SaidaLista100.txt"; break;
        case 4: l.loadFile("NomeRG1K.txt"); tam = 1000; nomeArquivo = "SaidaLista1000.txt"; break;
        case 5: l.loadFile("NomeRG10K.txt"); tam = 10000; nomeArquivo = "SaidaLista10000.txt"; break;
        case 6: l.loadFile("NomeRG1M.txt"); tam = 1000000; nomeArquivo = "SaidaLista1000000.txt"; break;
        case 7: l.loadFile("NomeRG10M.txt"); tam = 11748444; nomeArquivo = "SaidaLista11748444.txt"; break;
    }
    fim = time(NULL);
    printTime(inicio, fim);

    inicio = time(NULL);
    ListaSequencial *lista = criarLista(tam);
    switch(escolha){
        case 1: carregarArquivo(lista, "NomeRG10.txt"); break;
        case 2: carregarArquivo(lista,"NomeRG50.txt"); break;
        case 3: carregarArquivo(lista,"NomeRG100.txt"); break;
        case 4: carregarArquivo(lista,"NomeRG1K.txt"); break;
        case 5: carregarArquivo(lista,"NomeRG10K.txt"); break;
        case 6: carregarArquivo(lista,"NomeRG1M.txt"); break;
        case 7: carregarArquivo(lista,"NomeRG10M.txt"); break;
    }
    fim = time(NULL);
    printTime(inicio, fim);

    do{
        cout << "\t\t\t\tMENU\n\n\n";
        cout << "Digite 1 para imprimir a lista\n\n";
        cout << "Digite 2 para fazer uma busca de elementos\n\n";
        cout << "Digite 3 para inserir um elemento no inicio da lista\n\n";
        cout << "Digite 4 para inserir um elemento no fim da lista\n\n";
        cout << "Digite 5 para saber o tamanho da lista\n\n";
        cout << "Digite 6 para inserir um dado em um indice especifico\n\n";
        cout << "Digite 7 para remover um dado do fim da lista\n\n";
        cout << "Digite 8 para remover um dado de um indice especifico\n\n";
        cout << "Digite 9 para remover um dado do inicio da lista\n\n";
        cout << "Digite 10 para salvar a lista em um TXT\n\n";
        cout << "Digite 0 para sair\n\n";
        cin  >> escolha;

        system("cls");

        switch(escolha){

            case 1:
                inicio = time(NULL);
                l.showList();
                fim = time(NULL);
                printTime(inicio, fim);
                inicio = time(NULL);
                imprimirLista(lista);
                fim = time(NULL);
                printTime(inicio, fim);
            break;

            case 2:{
                string element;
                cout << "Insira o elemento a ser buscado na lista\n";
                cin >> element;

                inicio = time(NULL);
                l.busca(element);
                fim = time(NULL);
                printTime(inicio, fim);
                inicio = time(NULL);
                buscaNaLista(lista, element);
                fim = time(NULL);
                printTime(inicio, fim);

            }break;

            case 3:{
                string element;
                cout << "Insira o elemento no INICIO lista\n";
                cin >> element;
                inicio = time(NULL);
                l.insertIni(element);
                fim = time(NULL);
                printTime(inicio, fim);
                inicio = time(NULL);
                inserirNoIndice(lista, 0, element);
                fim = time(NULL);
                printTime(inicio, fim);

            }break;

            case 4:{
                string element;
                cout << "Insira o elemento no FIM lista\n";
                cin >> element;
                inicio = time(NULL);
                l.insertFinal(element);
                fim = time(NULL);
                printTime(inicio, fim);
                inicio = time(NULL);
                if(cheia(lista))
                    cout << "Lista cheia\n";
                else
                    inserirFinal(lista, element);
                fim = time(NULL);
                printTime(inicio, fim);
            }break;

            case 5:
                inicio = time(NULL);
                cout << "\n\n\n\n\n" << "\t\t\t\tTamanho da lista (encadeada): " << l.getTamanho() << "\n\n\n\n\n";
                cout << "\n\n\n\n\n" << "\t\t\t\tTamanho da lista (sequencial): " << lista->tail + 1 << "\n\n\n\n\n";
                fim = time(NULL);
                printTime(inicio, fim);
            break;

            case 6:
                cout << "Insira o dado\n";
                cin >> dado; cout << "Insira o indice\n";
                cin >> id;
                inicio = time(NULL);
                l.insertIndex(dado, id);
                fim = time(NULL);
                printTime(inicio, fim);
                inicio = time(NULL);
                inserirNoIndice(lista, id, dado);
                fim = time(NULL);
                printTime(inicio, fim);

            break;

            case 7:
                inicio = time(NULL);
                l.remover();
                fim = time(NULL);
                printTime(inicio, fim);
                inicio = time(NULL);
                removerFinal(lista);
                fim = time(NULL);
                printTime(inicio, fim);
            break;

            case 8:
                cout << "Insira o indice\n";
                cin >> id;
                inicio = time(NULL);
                l.removeIndex(id);
                fim = time(NULL);
                printTime(inicio, fim);
                inicio = time(NULL);
                removerDoIndice(lista, id);
                fim = time(NULL);
                printTime(inicio, fim);

            break;

            case 9:
                inicio = time(NULL);
                l.removeIndex(0);
                fim = time(NULL);
                printTime(inicio, fim);
                inicio = time(NULL);
                removerDoIndice(lista, 0);
                fim = time(NULL);
                printTime(inicio, fim);
            break;
            case 10:
                l.saveFile(nomeArquivo);
            break;
        }
    }while(escolha != 0);
    cout << "\n\n\n\t\t\tvoce escolheu sair\n\n";
    /*****************FIM DO MENU*******************************/

    destruirLista(lista);

	return 0;
}
void printTime(time_t inicio, time_t fim){ //imprime o tempo de execuçao
    fprintf(stdout, "\n\n\n\n\t\t\t\tO tempo de execucao em segundos e %0.1f\n\n\n\n\n", difftime(fim, inicio));
    system("pause");
    system("cls");
}
