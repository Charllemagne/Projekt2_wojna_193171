#include "funkcje.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

void tworzenie_talii(vector<karta>& talia, vector<karta>& talia_tas) {
    vector<string> kolory = {"kier", "karo", "pik", "trefl"};
    for (int n = 0; n < 4; n++)
        for (int i = 2; i < 15; i++)
            talia.push_back({i, kolory[n]});

    srand(time(NULL));
    while (!talia.empty()) {
        int n = rand() % talia.size();
        talia_tas.push_back(talia[n]);
        talia.erase(talia.begin() + n);
    }
}

void rozdawanie(vector<karta>& talia_tas, queue<karta>& gracz1, queue<karta>& gracz2) {
    for (int i = 0; i < 26; i++) {
        gracz1.push(talia_tas.front());
        talia_tas.erase(talia_tas.begin());
        gracz2.push(talia_tas.front());
        talia_tas.erase(talia_tas.begin());
    }
}

void nominal(stack<karta>& bitka1, stack<karta>& bitka2, string& nom1, string& nom2) {
    auto nazwa = [](int n) -> string {
        if (n <= 10) return to_string(n);
        if (n == 11) return "walet";
        if (n == 12) return "dama";
        if (n == 13) return "krol";
        return "as";
    };

    nom1 = nazwa(bitka1.top().nom);
    nom2 = nazwa(bitka2.top().nom);
}

void pokaz_stol(queue<karta>& gracz1, queue<karta>& gracz2, stack<karta>& bitka1, stack<karta>& bitka2, string& nom1, string& nom2, int& tura) {
    nominal(bitka1, bitka2, nom1, nom2);
    cout << "\n\n\n\n\n\n\n";
    cout << "##############################\n";
    cout << "                              \n";
    cout << "           tura " << tura << "              \n";
    cout << "                              \n";
    cout << "gracz 1        gracz 2     \n";
    cout << gracz1.size() << " kart(-y)     " << gracz2.size() << " kart(-y) \n";
    cout << "                              \n";
    cout << "     " << nom1 << " " << bitka1.top().kol << "      " << nom2 << " " << bitka2.top().kol << "        \n";

    if (bitka1.top().nom == bitka2.top().nom)
        cout << "          WOJNA!!!            \n";
    else
        cout << "                              \n";

    cout << "##############################\n";
}
