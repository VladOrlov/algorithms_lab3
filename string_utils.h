#ifndef ALGORITHMS_LAB3_STRINGUTILS_H
#define ALGORITHMS_LAB3_STRINGUTILS_H

#include <functional>
#include <vector>
#include <iostream>
#include <functional>
#include <vector>
#include <sstream>
#include <set>

using namespace std;

namespace string_utils {

    vector<string> get_words(string line);

    vector<char> get_chars(string line);

    bool contains_char(string str, char c);

    string remove_char(string str, char* chars...);

};


#endif //ALGORITHMS_LAB3_STRINGUTILS_H
