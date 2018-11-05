#include <iostream>
#include <functional>
#include <vector>
#include <sstream>
#include <string_utils.h>

using namespace std;

vector<string> transformWords(vector<string> words) {
    for (int i = 0; i < chars.size(); i++) {
        vector<char> chars(words[i].begin(), words[i].end());
        char char_to_remove = chars[0];
    }
}

void printInOrder(vector<char> chars) {
    cout << "Print in order:" << endl;
    for (int i = 0; i < chars.size(); i++) {
        cout << chars[i] << " ";
    }
    cout << "" << endl;
}


int main() {
    string input = "";

    cout << "Please enter a valid sentence (with spaces):\n>";
    getline(cin, input);
    vector<string> words = string_utlis::getWords(input);

    if (words.size() > 0) {
        transformWords(words);
    } else {
        cout << "You entered no words" << input << endl << endl;
    }

    return 0;
}