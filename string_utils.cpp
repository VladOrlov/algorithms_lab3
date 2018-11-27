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
        for (char i : chars) {
            if (c == i) {
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
        for (char str_char : str_chars) {
            if (chars_to_remove.find(str_char) == chars_to_remove.end()) {
                transformedWord.push_back(str_char);
            }
        }

        string new_str(transformedWord.begin(), transformedWord.end());

        return new_str;
    }

    vector<int> get_unique_numbers(vector<string> str_numbers) {
        set<int> numbers;
        for (const string &str_num : str_numbers) {
            try {
                int number = std::stoi(str_num);
                numbers.insert(number);
            } catch (exception &e) {
                cout << "Invalid value: " + str_num + ". Ignored." << endl;
            }
        }

        vector<int> v(numbers.begin(), numbers.end());
        return v;
    }

};
