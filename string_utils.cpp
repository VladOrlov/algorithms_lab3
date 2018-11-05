#include <functional>
#include <vector>
#include <iostream>
#include <functional>
#include <vector>
#include <sstream>
#include "string_utils.h"

#ifndef ALGORITHMS_LAB3_STRINGUTILS_H
#define ALGORITHMS_LAB3_STRINGUTILS_H

using namespace std;

namespace string_utils {

public:
    vector<string> getWords(string line) {
        static vector<string> words;
        stringstream textStream(line);
        string currentWord;

        while (textStream >> currentWord) {
            words.push_back(currentWord);
        }

        return words;
    }

};


#endif //ALGORITHMS_LAB3_STRINGUTILS_H
