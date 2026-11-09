#ifndef COUNTWORDS_HPP
#define COUNTWORDS_HPP

#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>
#include <cctype>
#include <iostream>

using namespace std;

class CountWords {
private:
    unordered_map<string, vector<int>> wordIndex;
    unordered_set<string> ignoreWords = {"a", "an", "the", "and", "or",
        "but", "is", "are", "was", "were", "in", "on", "at", "to", "of",
        "you", "he", "she", "it", "they", "we", "us", "them", "they're",
        "you're", "i'm", "i've", "i'll", "i'd", "he's", "she's"};

public:
    void addWord(const string& word, int position) {
        if (ignoreWords.find(word) == ignoreWords.end()) {
            wordIndex[word].push_back(position);
        }
    }

    string lowercase(const string& word) {
        string lowerWord;
        for (char c : word) {
            c = tolower(c);
            lowerWord += c;
        }
        return lowerWord;
    }
  string noPunctuation(const string& word) const {

    string result;
    for (char c : word) {
        if (c != '.' && c != ',' && c != '!' && c != '?' && c != '"' && c != ';' && c != ':') {
            result += tolower(c);
        }
    }
    return result;
}


};

#endif
