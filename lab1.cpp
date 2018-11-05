#include <iostream>
#include <functional>
#include <vector>
#include <sstream>
#include <string_utils.h>

using namespace std;

//vector<string> getWords(const string &line) {
//    vector<string> words;
//    stringstream textStream(line);
//    string currentWord;
//
//    while (textStream >> currentWord) {
//        words.push_back(currentWord);
//    }
//
//    return words;
//}

//transformWords(vector<string> words){
//
// vector<char> chars(firstWord.begin(), firstWord.end());
//}
//
//void printInOrder(vector<char> chars) {
//    cout << "Print in order:" << endl;
//    for (int i = 0; i < chars.size(); i++) {
//        cout << chars[i] << " ";
//    }
//    cout << "" << endl;
//}
//
//
//int main() {
//    string input = "";
//
//    cout << "Please enter a valid sentence (with spaces):\n>";
//    getline(cin, input);
//    vector<string> words = string_utlis::getWords(input);
//
//    if (words.size() > 0) {
//        string firstWord = words[0];
//        vector<char> chars(firstWord.begin(), firstWord.end());
//
//    } else {
//        cout << "You entered no words" << input << endl << endl;
//    }
//
//    return 0;
//}