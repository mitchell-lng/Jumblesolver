#include <iostream>
#include <curses.h>

#include "words.h"

using namespace std;

int main() {
    string input;
    cout << "Enter in you word: ";
    cin >> input;

    Words words(input);
    words.init();

    return 0;
}