//
// Created by mitch on 9/19/2020.
//

#ifndef JUMBLESOLVER_FORMAT_H
#define JUMBLESOLVER_FORMAT_H

#include "words.h"

class format {
public:
    string percentage(Words &words);
    string wordsLeft(Words &words);

private:
    static const int _totalLength = 20;
};

#endif //JUMBLESOLVER_FORMAT_H
