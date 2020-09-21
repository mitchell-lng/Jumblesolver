//
// Created by mitch on 9/18/2020.
//

#ifndef JUMBLESOLVER_WORDS_H
#define JUMBLESOLVER_WORDS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <memory>
#include <algorithm>

using namespace std;

class Words {
public:
    explicit Words(string word) : _word(std::move(word)) {}
    /*
    ~Words() {
        delete _currentWords;
    };


    Words(const Words &old) {
        _word = old._word;
        _wordLetters = old._wordLetters;

        _currentWords = old._currentWords;
        delete old._currentWords;
    }

    Words(const Words &&old) {
        _word = old._word;
        _wordLetters = old._wordLetters;

        _currentWords = old._currentWords;
        delete old._currentWords;
    }

    Words& operator=(const Words &old) {
        if (&old != this)
        {
            _currentWords = old._currentWords;
            delete old._currentWords;
        }

        _word = old._word;
        _wordLetters = old._wordLetters;

        return *this;
    }

    Words& operator=(const Words &&old) {
        if (&old != this)
        {
            _currentWords = old._currentWords;
            delete old._currentWords;
        }

        _word = old._word;
        _wordLetters = old._wordLetters;

        return *this;
    }
     */

    void init();
    void readFile();
    void sameLength();
    void charMatch();

    int getWordsLeft() { return _currentWords.size(); }
    double getPercentage(int index);
    void getFinalWords();

private:
    int _maxSize;
    vector<string> _currentWords;
    vector<char> _wordLetters;
    string _word;
};

#endif //JUMBLESOLVER_WORDS_H
