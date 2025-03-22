// var 25
// исходный контейнер deque, класс вклад, поля: название, сумма, валюта, ставка.
// сортировка по ставке
// контейнер для копирования

#include <iostream>
#include "vklad.h"
#include <deque>
#include <list>
#include <fstream>
#include <iostream>
#include <algorithm>
#include<unordered_set>
#include<set>

using namespace std;

int main()
{
    std::ifstream input;
    input.open("input.txt");
    int n;
    input >> n;
    std::set<vklad> Set;
    std::unordered_set<vklad, vklad_hasher> u_Set;
    for (int i = 0; i < n; i++)
    {
        std::string name; int sum; std::string type; double stavka;
        input >> name; input >> sum; input >> type; input >> stavka;
        vklad a(name, sum, type, stavka);
        Set.insert(a);
        u_Set.insert(a);
    }

    std::ofstream output;
    output.open("output.txt");

    output << "set:\n";
    for (auto i : Set)
    {
        output << i;
    }
    output << "unordered_set:\n";
    for (auto i : u_Set)
    {
        output << i;
    }
}
