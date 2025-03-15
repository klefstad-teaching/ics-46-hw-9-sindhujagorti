#include "ladder.h"

#define my_assert(e) {cout << #e << ((e) ? " passed": " failed") << endl;}

void verify_word_ladder() { // from professor's homework instructions

    set<string> word_list;

    load_words(word_list, "/home/sgorti1/ICS46/ics-46-hw-9-sindhujagorti/src/words.txt");

    my_assert(generate_word_ladder("cat", "dog", word_list).size() == 4);

    my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);

    my_assert(generate_word_ladder("code", "data", word_list).size() == 6);

    my_assert(generate_word_ladder("work", "play", word_list).size() == 6);

    my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);

    my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);

}


void error(string word1, string word2, string msg) {
    cerr << "Error: " << msg << " (" << word1 << " -> " << word2 << ")";
}

bool edit_distance_within(const string& str1, const string& str2, int d) {
    if (str1.length() != str2.length()) return false;
    int diff_count = 0;
    for (size_t i = 0; i < str1.length(); ++i) {
        if (str1[i] != str2[i]) {
            diff_count++;
            if (diff_count > d) return false;
        }
    }
    return diff_count <= d;
}

bool is_adjacent(const string& word1, const string& word2) {
    if (word1.length() == word2.length()) {
        return edit_distance_within(word1, word2, 1);
    }
    
    if (abs((int)word1.length() - (int)word2.length()) == 1) {
        const string& shorter = (word1.length() < word2.length()) ? word1 : word2;
        const string& longer = (word1.length() > word2.length()) ? word1 : word2;
        
        for (size_t i = 0; i < longer.length(); i++) {
            string temp = longer;
            temp.erase(i, 1);
            if (temp == shorter) return true;
        }
    }
    
    return false;
}

void load_words(set<string>& word_list, const string& file_name) {
    ifstream file(file_name);
    if (!file.is_open()) {
        cerr << "Error: Could not open file '" << file_name << "'" << endl;
        return;
    }
    string word;
    while (file >> word) {
        word_list.insert(word);
    }
}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list) { // using professor's pseudocode
    if (begin_word == end_word) {
        error(begin_word, end_word, "Start and end words must be different");
        return {};
    }
    
    queue<vector<string>> ladder_queue;
    ladder_queue.push({begin_word});
    set<string> visited;
    visited.insert(begin_word);

    while (!ladder_queue.empty()) {
        vector<string> ladder = ladder_queue.front();
        ladder_queue.pop();
        string last_word = ladder.back();

        for (const string& word : word_list) {
            if (is_adjacent(last_word, word)) {
                if (visited.find(word) == visited.end()) {
                    visited.insert(word);
                    vector<string> new_ladder = ladder;
                    new_ladder.push_back(word);
                    if (word == end_word) {
                        return new_ladder;
                    }
                    ladder_queue.push(new_ladder);
                }
            }
        }
    }
    
    return {};  
}

void print_word_ladder(const vector<string>& ladder) {
    if (ladder.empty()) {
        cout << "No word ladder found." << endl;
    } else {
        for (size_t i = 0; i < ladder.size(); ++i) {
            cout << ladder[i];
            if (i < ladder.size() - 1) {cout << " -> ";}
        }
    }
}