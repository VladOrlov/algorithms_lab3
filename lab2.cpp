#include <iostream>
#include <functional>
#include <vector>
#include <sstream>
#include "string_utils.h"
#include "lab2.h"

using namespace std;

enum sortType {
    asc, desc
};

template<class T>
void print_out(vector<T> sortedArray) {
    for (int i = 0; i < sortedArray.size(); i++) {
        cout << sortedArray[i] << ", ";
    }
    cout << "" << endl;
}

template<typename T, sortType e>
void bubble_sort(vector<T> arrayToSort) {

    function<bool(T, T)> needToSwap;

    switch (e) {
        case asc:
            needToSwap = [](T x, T y) { return x > y; };
            break;
        case desc:
            needToSwap = [](T x, T y) { return x < y; };
            break;
    }

    for (int i = 0; i < arrayToSort.size() - 1; i++) {
        for (int j = 0; j < arrayToSort.size() - 1 - i; j++) {
            if (needToSwap(arrayToSort[j], arrayToSort[j + 1])) {
                T temp = arrayToSort[j + 1];
                arrayToSort[j + 1] = arrayToSort[j];
                arrayToSort[j] = temp;
            }
        }
    }

    print_out(arrayToSort);
}


int lab2::execute() {

    string input;

    cout << "Please enter numbers to sort:\n>";
    getline(cin, input);

    static vector<string> words = string_utils::get_words(input);

    if (words.empty()) {
        cout << "You entered no words" << input << endl;
        return -1;
    }

    const vector<int> &numbers = string_utils::get_unique_numbers(words);
    bubble_sort<int, asc>(numbers);

    return 1;
}