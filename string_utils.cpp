#include <functional>
#include <vector>
#include <iostream>
#include <functional>
#include <vector>
#include <sstream>
#include <cstring>
#include "string_utils.h"

using namespace std;

namespace string_utils {

    vector<string> get_words(string line) {
        static vector<string> words;
        stringstream textStream(line);
        string currentWord;

        while (textStream >> currentWord) {
            words.push_back(currentWord);
        }

        return words;
    }

    vector<char> get_chars(string line) {
        static vector<char> last_word(line.begin(), line.end());
        return last_word;
    }

    bool contains_char(string str, char c) {
        vector<char> chars(str.begin(), str.end());

        bool contains = false;
        for (int i = 0; i < chars.size(); i++) {
            if (c == chars[i]) {
                contains = true;
                break;
            }
        }
        return contains;
    }

    string remove_char(string str, char *chars...) {

        set<char> chars_to_remove;

        string str1(chars);

        for (int i = 0; i < get_chars(str1).size(); i++) {
            chars_to_remove.insert(chars[i]);
        }

        vector<char> transformedWord;

        vector<char> str_chars(str.begin(), str.end());
        for (int j = 0; j < str_chars.size(); j++) {
            if (chars_to_remove.find(str_chars[j]) == chars_to_remove.end()) {
                transformedWord.push_back(str_chars[j]);
            }
        }

        string new_str(transformedWord.begin(), transformedWord.end());

        return new_str;
    }

};
