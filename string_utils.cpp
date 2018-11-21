#include <functional>
#include <vector>
#include <iostream>
#include <functional>
#include <vector>
#include <sstream>
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
            if(c == chars[i]){
                contains = true;
                break;
            }
        }
        return contains;
    }

    string remove_char(string str, char* chars...){

        set<char> chars_to_remove;

        for (int i = 0; i < sizeof(chars); i++) {
            chars_to_remove.insert(chars[i]);
        }

        vector<char> str_chars(str.begin(), str.end());

        for (int j = 1; j < str_chars.size(); j++) {
            //if (chars_to_remove.find(chars[j])) {
                //transformedWord.push_back(chars[j]);
            //}
        }
    }

};
