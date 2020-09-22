//
// Created by mitch on 9/18/2020.
//

#include "words.h"

double Words::getPercentage(int index)
{
    float percentage = double(index) / double(_maxSize);
    cout << "Index: " << index << "; Max List Size: " << _maxSize << "; Total Percentage: " << percentage << endl;
    return percentage;
}

void Words::readFile()
{
    // Read from
    // http://www.mieliestronk.com/wordlist.html

    string line;
    ifstream myFile("C:\\Users\\mitch\\CLionProjects\\jumblesolver\\words");

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

void Words::charMatch()
{
    cout << endl << "Finalizing List..." << endl;
    int i;
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