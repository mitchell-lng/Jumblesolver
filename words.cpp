//
// Created by mitch on 9/18/2020.
//

#include "words.h"

template<typename T>
int Words::countLetters(char c, T s)
{
    int counter = 0;

    for (char currentLetter: s) {
        if (currentLetter == c) counter++;
    }

    return counter;
}

void Words::readFile()
{
    // Read from
    // http://www.mieliestronk.com/wordlist.html

    string line;
    ifstream myFile("../words");

    if (myFile.is_open())
    {
        while ( getline(myFile, line) )
        {
            _currentWords.push_back(line);

        }
        myFile.close();
    } else {
        cout << "Unable to Open File" << endl;
    }

    _maxSize = _currentWords.size();
}

void Words::sameLength()
{
    cout << "Checking letters for length...";
    int i;
    for (i = 0; i < _currentWords.size(); i++)
    {
        string word = _currentWords.at(i);

        if (word.length() != _wordLetters.size())
        {
            _currentWords.erase(_currentWords.begin() + i);
            i--;
            continue;
        }
    }
};

// Checks to see if the characters in the words match
void Words::charMatch()
{
    cout << endl << "Finalizing List..." << endl;
    int i;

    // Check input from user against currentWord
    for (i = 0; i < _currentWords.size(); i++)
    {
        string word = _currentWords.at(i);
        for (char c: _wordLetters)
        {
            if (word.find(c) == string::npos)
            {
                _currentWords.erase(_currentWords.begin() + i);
                i--;
                break;
            }
        }
    }

    // Check currentWord against input from user
    for (i = 0; i < _currentWords.size(); i++)
    {
        string word = _currentWords.at(i);
        for (char c: word)
        {
            if (find(_wordLetters.begin(), _wordLetters.end(), c) == _wordLetters.end())
            {
                _currentWords.erase(_currentWords.begin() + i);
                i--;
                break;
            }
        }
    }

    // Checks to make sure if there are duplicates, that they are the right ones
    std::map<char, int> amountOfLetters;
    for (char c: _wordLetters)
    {
        amountOfLetters[c] = countLetters(c, _wordLetters);
    }

    for (i = 0; i < _currentWords.size(); i++)
    {
        string word = _currentWords.at(i);
        for (char c: word) {
            int count = countLetters(c, word);
            if (amountOfLetters[c] != count) {
                _currentWords.erase(_currentWords.begin() + i);
                i--;
                break;
            }
        }
    }
}

void Words::getFinalWords()
{
    cout << endl;
    for (string i: _currentWords)
    {
        cout << "--> " << i << endl;
    }
}

void Words::init()
{
    for (char letter: _word)
    {
        _wordLetters.push_back(letter);
    }

    readFile();
    sameLength();
    charMatch();
    getFinalWords();
}