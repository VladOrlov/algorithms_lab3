#include <iostream>
#include <functional>
#include "string_utils.h"
#include "lab1.h"

using namespace std;

//Remove all chars in word that matched first one and additional chars in set
void transformWords(vector<string> &words, set<char> chars_to_remove) {

    for (int i = 0; i < words.size(); i++) {
        vector<char> chars(words[i].begin(), words[i].end());
        char first_char = chars[0];

        vector<char> transformedWord;
        transformedWord.push_back(first_char);

        for (int j = 1; j < chars.size(); j++) {
            if (first_char != chars[j] &&
                chars_to_remove.find(chars[j]) == chars_to_remove.end()) {

                transformedWord.push_back(chars[j]);
            }
        }

        string str(transformedWord.begin(), transformedWord.end());
        words[i] = str;
    }
}


int lab1::execute() {
    string input = "";

    cout << "Please enter a valid sentence (with comma between words and "
            "point at the end):\n>";
    getline(cin, input);

    static vector<string> words = string_utils::get_words(input);

    if (words.size() == 0) {
        cout << "You entered no words" << input << endl;
        return -1;
    }

    string last_word = words[words.size() - 1];
    if (!string_utils::contains_char(last_word, '.')) {
        cout << "Invalid input! Point is missing!" << input << endl;
        return -1;
    }

    for (int i = 0; i < words.size() - 1; i++) {
        if (!string_utils::contains_char(words[i], ',')) {
            cout << "Invalid input! Comma is missing for word: \n" + words[i] + "\nInput string:\n"
                 << input << endl;
            return -1;
        }
    }

    set<char> to_remove = {{'.', ','}};

    transformWords(words, to_remove);

    string last_word_without_dot = string_utils::remove_char(last_word, ".");

    for (int i = 0; i < words.size(); i++) {
        if (last_word_without_dot.compare(words[i]) != 0) {
            cout << words[i] << endl;
        }
    }

    return 0;
}

