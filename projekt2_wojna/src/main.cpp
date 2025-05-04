#include "funkcje.hpp"
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;




int main() 
{
    string cos;
    srand(time(NULL));
    vector <karta> talia;
    vector <karta> talia_tas;
    queue <karta> gracz1;
    queue <karta> gracz2;
    stack <karta> bitka1;
    stack <karta> bitka2;
    int tura=1;
    string nom1;
    string nom2;
    
    tworzenie_talii(talia,talia_tas);
    rozdawanie(talia_tas, gracz1, gracz2);

    while(gracz1.empty() != true && gracz2.empty() != true)
    {
        string cos;
        bitka1.push(gracz1.front());
        gracz1.pop();
        bitka2.push(gracz2.front());
        gracz2.pop();

        pokaz_stol(gracz1,gracz2,bitka1,bitka2,nom1,nom2,tura); 
        if (bitka1.top().nom>bitka2.top().nom)
        {
            while(bitka1.empty()!=true)
            {
                gracz1.push(bitka1.top());
                bitka1.pop();
                gracz1.push(bitka2.top());
                bitka2.pop();
                tura++;
            }
        }
        else if (bitka1.top().nom<bitka2.top().nom)
        {
            while(bitka1.empty()!=true)
            {
                gracz2.push(bitka1.top());
                bitka1.pop();
                gracz2.push(bitka2.top());
                bitka2.pop();
                tura++;
            }
        }
        else
        {
            bitka1.push(gracz1.front());
            gracz1.pop();
            bitka2.push(gracz2.front());
            gracz2.pop();
        }

           
        cin >> cos;
        if (cos=="koniec")
            break;

    }

    cout << endl << endl << endl << "         KONIEC GRY" << endl << endl << endl; 
    return 0; 
}

