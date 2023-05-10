// week 2.3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <algorithm>

bool isPalindrome(const std::string& s) {
    std::string lowerCaseS = s;
    std::transform(lowerCaseS.begin(), lowerCaseS.end(), lowerCaseS.begin(), ::tolower);
    return std::equal(lowerCaseS.begin(), lowerCaseS.begin() + lowerCaseS.size() / 2, lowerCaseS.rbegin());
}

int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::cin >> input;

    if (isPalindrome(input)) {
        std::cout << input << " is a palindrome" << std::endl;
    }
    else {
        std::cout << input << " is not a palindrome" << std::endl;
    }

    return 0;
}