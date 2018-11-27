#include <iostream>
#include <functional>
#include <vector>
#include <sstream>
#include "string_utils.h"
#include "lab3.h"

using namespace std;

namespace lab3 {

    void printInOrder(vector<char> chars) {
        for (int i = 0; i < chars.size(); i++) {
            cout << chars[i] << " ";
        }
    }

    void printInOrderRecursively(vector<char> chars, int element) {
        if (element >= chars.size()) {
            return;
        }
        cout << chars[element] << " ";
        printInOrderRecursively(chars, ++element);
    }

    void printInReverseOrder(vector<char> chars) {
        for (int i = chars.size() - 1; i >= 0; i--) {
            cout << chars[i] << " ";
        }
    }

    void printInReverseOrderRecursively(vector<char> chars, int element) {
        if (element < 0) {
            return;
        }
        cout << chars[element] << " ";
        printInReverseOrderRecursively(chars, --element);
    }

    void printInReverseOrderRecursivelyTail(vector<char> chars, int element) {
        if (element >= chars.size()) {
            return;
        }
        int nextElement = element + 1;
        printInReverseOrderRecursivelyTail(chars, nextElement);

        cout << chars[element] << " ";
    }

    int execute() {
        string input = "";

        cout << "Please enter a valid sentence (with spaces):\n>";
        getline(cin, input);

        vector<string> words = string_utils::get_words(input);

        if (!words.empty()) {
            string firstWord = words[0];
            vector<char> chars(firstWord.begin(), firstWord.end());

            cout << "Print in order:" << endl;
            printInOrder(chars);
            cout << "" << endl;

            cout << "Print in reversed order:" << endl;
            printInReverseOrder(chars);
            cout << "" << endl;

            cout << "Print in order recursively:" << endl;
            printInOrderRecursively(chars, 0);
            cout << "" << endl;

            cout << "Print in reversed order recursively:" << endl;
            printInReverseOrderRecursively(chars, chars.size() - 1);
            cout << "" << endl;

            cout << "Print in order recursively tail:" << endl;
            printInReverseOrderRecursivelyTail(chars, 0);
            cout << "" << endl;

            return 0;
        } else {
            cout << "You entered no words" << input << endl << endl;

            return -1;
        }
    }

}