#include <iostream>
#include <functional>
#include <vector>
#include <sstream>
#include "string_utils.h"

using namespace std;

void transformWords(vector<string> words) {

    for (int i = 0; i < words.size(); i++) {
        vector<char> chars(words[i].begin(), words[i].end());
        char char_to_remove = chars[0];

        vector<char> transformedWord;
        transformedWord.push_back(char_to_remove);

        for (int j = 1; j < chars.size(); j++) {
            if (char_to_remove != chars[j]) {
                transformedWord.push_back(chars[j]);
            }
        }

        string str(transformedWord.begin(), transformedWord.end());
        words[i] = str;
    }
}


int main() {
    string input = "";

    cout << "Please enter a valid sentence (with comma between words and "
            "point at the end):\n>";
    getline(cin, input);

    vector<string> words = string_utils::get_words(input);

    if (words.size() == 0) {
        cout << "You entered no words" << input << endl << endl;
        return -1;
    }

    string last_word = words[words.size() - 1];
    if (!string_utils::contains_char(last_word, '.')) {
        cout << "Invalid input! Point is missing!" << input << endl << endl;
        return -1;
    }

    for (int i = 0; i < words.size() - 1; i++) {
        if (!string_utils::contains_char(words[i], ',')) {
            cout << "Invalid input! Comma is missing for word: \n" + words[i] + "\nInput string:\n"
                 << input << endl << endl;
            return -1;
        }
    }

    transformWords(words);
    cout << "Some" << endl << endl;

    return 0;
}