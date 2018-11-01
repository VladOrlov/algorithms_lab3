#include <iostream>
#include <functional>
#include <vector>
#include <sstream>

using namespace std;

vector<string> getWords(const string &line) {
    vector<string> words;
    stringstream textStream(line);
    string currentWord;

    while (textStream >> currentWord) {
        words.push_back(currentWord);
    }

    return words;
}

void printInOrder(vector<char> chars) {
    cout << "Print in order:" << endl;
    for (int i = 0; i < chars.size(); i++) {
        cout << chars[i] << " ";
    }
    cout << "" << endl;
}

void printInReverseOrder(vector<char> chars) {
    cout << "Print in reversed order:" << endl;
    for (int i = chars.size(); i >= 0; i--) {
        cout << chars[i] << " ";
    }
    cout << "" << endl;
}


int main() {
    string input = "";

    cout << "Please enter a valid sentence (with spaces):\n>";
    getline(cin, input);
    vector<string> words = getWords(input);

    if (words.size() > 0) {
        string firstWord = words[0];
        vector<char> chars(firstWord.begin(), firstWord.end());
        printInOrder(chars);
        printInReverseOrder(chars);
    } else {
        cout << "You entered no words" << input << endl << endl;
    }

    return 0;
}