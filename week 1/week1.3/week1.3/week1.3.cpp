// week1.3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cctype>

void count(const char s[], int counts[]);
int totalOccurance(const char s[], char occured);

int main()
{
    std::cout << "please enter a string\n";
    std::string a;
    std::getline(std::cin, a);
    int counts[26];
    count(a.c_str(), counts);
}

void count(const char s[], int counts[]) {
    for (int i = 0; i < 26; i++) {
        int occured = totalOccurance(s, 65 + i);
        counts[i] = occured;
        if (occured > 0) {
            std::cout << (char)(65 + i) << " occured " << occured << " times\n";
        }
    }
}

int totalOccurance(const char s[], char occured) {
    int count = 0;
    int i = 0;
    char current = s[i];
    while (current != NULL) {
        if (current == occured || current == tolower(occured)) {
            count++;
        }
        i++;
        current = s[i];
    }
    return count;
}



