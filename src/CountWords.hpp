#ifndef COUNTWORDS_HPP
#define COUNTWORDS_HPP

#include <map>
#include <unordered_set>
#include <string>
#include <vector>
#include <cctype>
#include <iostream>
#include <fstream>

using namespace std;

class CountWords {
private:
    map<string, vector<int>> wordIndex;
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
bool fileinside(const string& filename) {

        ifstream in(filename);

        if (!in.is_open()) {
            return false;
        }

        string word;
        int position = 0;
        while (in >> word) {
            word = noPunctuation(word);
            if (!word.empty()) {
                addWord(word, position);
                position++;
            }
        }
    
    in.close();
    return true;
    }

    void diskprint(const string& filename) {
        ofstream out(filename);
        if (!out.is_open()) {
            cerr << "Error opening file for writing: " << filename << endl;
            return;
        }

        for (const auto& entry : wordIndex) {
            out << entry.first << ": ";
            for (size_t i = 0; i < entry.second.size(); ++i) {
                out << entry.second[i];
                if (i < entry.second.size() - 1) {
                    out << ", ";
                }
            }
            out << endl;
        }

        out.close();
    }

};

#endif
