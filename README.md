# jumblesolver

>Solves Newspaper Jumbles

Example:

```
Enter in you word: kaaill
Checking letters for length...
Finalizing List...

--> alkali
```

## Build

```bash
mkdir build && cd build
cmake ..
make
./jumblesolver
```

## Criteria

#### The project reads data from a file and process the data, or the program writes data to a file.
words.cpp; readFile(); Line: 25

#### The project accepts user input and processes the input.
main.cpp; main(); Line: 11

#### The project uses Object Oriented Programming techniques.
words.cpp && words.h

#### Classes abstract implementation details from their interfaces.
words.cpp

#### Templates generalize functions in the project.
words.cpp; countLetters(); Line: 8