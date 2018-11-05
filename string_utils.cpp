#include "string_utils.h"
#include <iostream>
#include <functional>
#include <vector>
#include <sstream>

using namespace std;

static vector<string> getWords(const string &line) {
    vector<string> words;
    stringstream textStream(line);
    string currentWord;

    while (textStream >> currentWord) {
        words.push_back(currentWord);
    }

    return words;
}

