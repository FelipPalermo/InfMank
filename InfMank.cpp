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

    long long Iterates = 0; 
    
    ofstream Time_Elapsed;
    string Start_UTF = time();


    srand(time(0));
    char alphabet[] = {"abcdefghijklmnopqrstubwxyz"};
    string SHolder = "";
    string SOut = "";

    // YAMOMEDEVE1000 = 14 Char
        
    while(true){

        for (int i = 0; i < 7; i++){
            
            // Iterate trough time to generate random numbers
            int Random = ( rand() % 26 );

            // Add Char to SHolder 
            SHolder += alphabet[Random];    }

            // Add SHolder to SOut; 
            SOut += SHolder; 
            
            // Clear SHolder String 
            SHolder.clear();

            // Mostrar os resultados de SOut
            cout<<"\n"<<SOut<<endl;



            if (SOut == "maconha"){

                
                Time_Elapsed.open("InfiniMonkey Paradox.txt");
               
                Time_Elapsed<<"Start Time : "<<Start_UTF;
                Time_Elapsed<<endl<<"Content : "<<SOut<<endl;
                Time_Elapsed<<"\nTimes Iterated : "<<Iterates;
                string End_UTF = time();
                Time_Elapsed<<"\nEnd Time : "<<End_UTF;
               
                Time_Elapsed.close();
                
                cout<<endl<<"Feito!"<<endl;
                exit(1);    }


            if (SOut != ""){
                SOut.clear(); }
        Iterates ++;
        Sleep(0);  }

    return 0; 
}