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
#include <map>

using namespace std;

class Words {
public:
    explicit Words(string word) : _word(std::move(word)) {}

    void init();
    void readFile();
    void sameLength();
    void charMatch();
    void getFinalWords();

private:
    int _maxSize;
    vector<string> _currentWords;
    vector<char> _wordLetters;
    string _word;

    template<typename T>
    int countLetters(char c, T s);
};

#endif //JUMBLESOLVER_WORDS_H
