#include <iostream>
#include <ctime>
#include <windows.h>
#include <fstream>
#include <string>
using namespace std; 


string time(){

    time_t now = time(0);
    char* dt = ctime(&now);
    return dt;     }

int main(){

    // Booleano para o menu inicial permanecer aberto
    bool Start = false;

    // Recebe a string que o usuario digital
    string Buscar_Palavra = "";

    // Retorna o tamanho da palavra em int para comparacao
    int Palavra_lenght; 

    // Sera usado no final do codigo para otimização de memoria
    // Quantos segundos de pausa temos a cada iteração
    float Segundos;


    // MENU PRINCIPAL 
    while (Start == false){
        cout<<"Qual palavra deseja buscar?";
        cin>>Buscar_Palavra;
        
        // Retorna o tamanho da palavra em int para comparacao
        Palavra_lenght = Buscar_Palavra.length();

        cout<<"\nSegundos a cada palavra\nUsar 0 caso deseje sem pausa"<<endl;
        cout<<"Ou numeros quebrados para otimizacao de uso"<<endl;
        cin>>Segundos;

        Start = true;   }


    // Tanto de combinacoes tentadas antes da palavra procurada
    long long Iterates = 0; 
    

    // ofstream é uma definiçao de variavel da biblioteca ofstream
    // ela é responsavel por criar e exportar arquivos
    // estou usando essa variavel para exportar um LOG de informações relevantes
    ofstream Time_Elapsed;

    // Variavel que recebe o tempo inicial da nossa classe "TIME"
    // A classe time retorna a utf-8 da data e hora que foi chamada
    string Start_UTF = time();

    srand(time(0));

    // Array com todas as letras que queremos procurar por
    char alphabet[] = {"abcdefghijklmnopqrstubwxyz"};

    // Variavel que vai segurar a palavra e depois se destruir
    // Essa variavel é a responsavel por segurar todas as tentativas 
    // Depois passar para SOut
    string SHolder = "";

    // É a variavel que recebe a String da SHolder
    // É a variavel que var ser comparada para encontrar a palavra final
    string SOut = "";

        
    while(true){

        
        for (int i = 0; i < Palavra_lenght; i++){
            
            // Iterate trough time to generate random numbers
            int Random = ( rand() % 27 ) - 1;

            // Add Char to SHolder 
            SHolder += alphabet[Random];    }

            // Add SHolder to SOut; 
            SOut += SHolder; 
            
            // Clear SHolder String 
            SHolder.clear();

            // Mostrar os resultados de SOut
            cout<<"\n"<<SOut<<endl;



            if (SOut == Buscar_Palavra){

                
                // Declaramos o nome e o tipo do arquivo que sera 
                // Exportado
                Time_Elapsed.open("InfiniMonkey Log.txt");

                // Usamos a variavel como um cout
                // Nesse caso estamos escrevendo uma linha dentro do arquivo
                Time_Elapsed<<"Start Time : "<<Start_UTF;
                Time_Elapsed<<endl<<"Content : "<<SOut<<endl;
                Time_Elapsed<<"\nTimes Iterated : "<<Iterates<<endl;
                
                // Declaramos a variavel que recebe o tempo final do programa
                string End_UTF = time();

                // Printando tempo final do programa
                Time_Elapsed<<"\nEnd Time : "<<End_UTF;
               
                // Fechando o arquivo para exporta-lo finalmente
                Time_Elapsed.close();
                
                cout<<endl<<"Feito!"<<endl;
                
                // Sair do programa
                exit(1);    }

            // Se Sout não for igual a palavra que estamos buscando
            // Sout é deletado e o programa recomeça
            if (SOut != Buscar_Palavra){
                SOut.clear(); }

        // Todas as vezes que o programa reinicia iterate ganha +1  
        Iterates ++;
        Sleep(Segundos*1000);  }


    // Sintaxe padrão para retornar 0 caso esteja tudo certo no codigo
    // Não é realmente necessario
    return 0;   }