#include "ladder.h"

int main() {
    set<string> word_list;
    load_words(word_list, "/home/sgorti1/ICS46/ics-46-hw-9-sindhujagorti/src/words.txt");

    string start_word, end_word;
    cout << "Enter start word: ";
    cin >> start_word;
    cout << "Enter end word: ";
    cin >> end_word;

    vector<string> ladder = generate_word_ladder(start_word, end_word, word_list);
    print_word_ladder(ladder);

    cout << "\nverifiying:\n";
    verify_word_ladder();

    return 0;
}