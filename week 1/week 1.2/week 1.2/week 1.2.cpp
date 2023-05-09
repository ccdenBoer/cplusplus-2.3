// week 1.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

// Return true if the card number is valid
bool isValid(const std::string& cardNumber);

// Get the result from Step 2
int sumOfDoubleEvenPlace(const std::string& cardNumber);

// Return this number if it is a single digit, otherwise,
// return the sum of the two digits
int getDigit(int number);

// Return sum of odd-place digits in the card number
int sumOfOddPlace(const std::string& cardNumber);

// Return true if substr is the prefix for cardNumber
bool startsWith(const std::string& cardNumber, const std::string& substr);


int main()
{
    std::string valid = "4388576018410707";
    std::string invalid = "4388576018402626";

    if (isValid(valid)) {
        std::cout << valid << " is valid\n";
    }
    else {
        std::cout << valid << " is invalid\n";
    }

    if (isValid(invalid)) {
        std::cout << invalid << " is valid\n";
    }
    else {
        std::cout << invalid << " is invalid\n";
    }
}

// Return true if the card number is valid
bool isValid(const std::string& cardNumber) {
    std::cout << "checking size\n";
    if (cardNumber.size() < 13 || cardNumber.size() > 16) {
        std::cout << "inproper size\n";
        return false;
    }

    std::cout << "checking start number\n";
    if (startsWith(cardNumber, "4") || startsWith(cardNumber, "5") || startsWith(cardNumber, "37") || startsWith(cardNumber, "6")) {} else{
        std::cout << "invalid start number\n";
        return false;
    }

    std::cout << "calculating evens\n";
    int evensum = sumOfDoubleEvenPlace(cardNumber);
    std::cout << "evens = " << evensum << "\n";
    std::cout << "calculating odds\n";
    int oddsum = sumOfOddPlace(cardNumber);
    std::cout << "odds = " << oddsum << "\n";

    if (((evensum + oddsum) % 10) == 0) {
        return true;
    }

    std::cout << "invalid code\n";
    return false;
}

// Get the result from Step 2
int sumOfDoubleEvenPlace(const std::string& cardNumber) {
    bool even = false;
    int sum = 0;

    for (int i = cardNumber.size(); i > 0; i--) {
        if (even) {
            int num = int(cardNumber.at(i-1)) - 48;
            num *= 2;

            num = getDigit(num);

            sum += num;
        }
        if (even) {
            even = false;
        }
        else {
            even = true;
        }
    }

    return sum;
}

// Return this number if it is a single digit, otherwise,
// return the sum of the two digits
int getDigit(int number) {
    if (number > 9) {
        number = (number % 10) + 1;
    }
    return number;
}

// Return sum of odd-place digits in the card number
int sumOfOddPlace(const std::string& cardNumber) {
    bool odd = true;
    int sum = 0;

    for (int i = cardNumber.size(); i > 0; i--) {
        if (odd) {
            int num = int(cardNumber.at(i-1)) - 48;

            sum += num;
        }
        if (odd) {
            odd = false;
        }
        else {
            odd = true;
        }
    }

    return sum;
}

// Return true if substr is the prefix for cardNumber
bool startsWith(const std::string& cardNumber, const std::string& substr) {
    if (substr.size() > cardNumber.size()) {
        return false;
    }

    for (int i = 0; i < substr.size(); i++) {
        if (substr.at(i) != cardNumber.at(i)) {
            return false;
        }
    }
    
    return true;
}

