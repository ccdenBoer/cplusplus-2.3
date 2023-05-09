// week 1.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

bool search(std::string& s, char& key);


int main()
{
    std::cout << "please enter a string\n";
    std::string a;
    std::getline(std::cin, a);

    std::cout << "please enter a character to search in the string\n";
    char b;
    std::cin >> b;

    if (search(a, b)) {
        std::cout << "found \'" << b << "\' in \"" << a << "\"\n";
    }
    else {
        std::cout << "didnt find \'" << b << "\' in \"" << a << "\"\n";
    }
    
}

bool search(std::string& s, char& key) {
    for (int i = 0; i < s.size(); i++) {
        if (s.at(i) == key) {
            return true;
        }
    }
    return false;

}

