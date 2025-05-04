#ifndef FUNKCJE_HPP
#define FUNKCJE_HPP

#include <vector>
#include <queue>
#include <stack>
#include <string>

using namespace std;

struct karta {
    int nom;
    string kol;
};

void tworzenie_talii(vector<karta>& talia, vector<karta>& talia_tas);
void rozdawanie(vector<karta>& talia_tas, queue<karta>& gracz1, queue<karta>& gracz2);
void nominal(stack<karta>& bitka1, stack<karta>& bitka2, string& nom1, string& nom2);
void pokaz_stol(queue<karta>& gracz1, queue<karta>& gracz2, stack<karta>& bitka1, stack<karta>& bitka2, string& nom1, string& nom2, int& tura);

#endif
