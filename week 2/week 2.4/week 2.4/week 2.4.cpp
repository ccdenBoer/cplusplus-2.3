// week 2.4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream> 
#include <string> 
#include <algorithm> 
#include <vector>
#include <ctime>
#include <cstdlib>

int main()
{
    std::vector<std::string> words = { "write", "that", "school", "pirate", "king"};
    srand(time(0));
    bool playing = true;

    while (playing) {
        std::string word = words.at(rand() % words.size());
        int wrongGuesses = 0;

        std::string guesWord = "";
        for (int i = 0; i < word.size(); i++) {
            guesWord.append("*");
        }

        std::vector<char> guesses = {};
        char input;

        while (!guesWord._Equal(word) && wrongGuesses < 10) {
            std::cout << "Guess: " << guesWord << std::endl << "Wrong guesses: " << wrongGuesses << std::endl << "Used letters: " << std::endl;
            for (int i = 0; i < guesses.size(); i++) {
                std::cout << guesses.at(i) << ", ";
            }
            std::cout << std::endl;

            bool newLetter = false;
            while (!newLetter) {
                std::cout << "Guess a letter\n";
                std::cin >> input;
                input = std::tolower(input);
                if (!std::count(guesses.begin(), guesses.end(), input)) {
                    guesses.push_back(input);
                    newLetter = true;
                }
            }
            bool correct = false;
            for (int i = 0; i < word.size(); i++) {
                if (word.at(i) == input) {
                    guesWord[i] = input;
                    correct = true;
                }
            }
            if (!correct) {
                wrongGuesses++;
            }
        }

        if (wrongGuesses >= 10) {
            std::cout << "You got send to the gallows, the word was: " << word << std::endl;
        }
        else {
            std::cout << "YOU DID IT WOOO" << std::endl;
        }

        std::cout << "Would you like to retry? y or n" << std::endl;
        std::cin >> input;
        input = std::tolower(input);
        if (input == 'n') {
            playing = false;
        }

    }
}

