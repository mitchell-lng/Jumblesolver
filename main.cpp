#include <iostream>
#include <curses.h>

#include "words.h"

using namespace std;

int main() {
    Words words("sogeo");
    words.init();

    return 0;
}