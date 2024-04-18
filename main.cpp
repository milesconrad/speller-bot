#include <cmath>
#include <string>
#include <stdio.h>
#include <nuspell/dictionary.hxx>
#include <nuspell/finder.hxx>

// spelling bee parameters
int wordLength;
std::string letters;
char mainLetter;

std::string word;

void increment(int index) {
    if (word[index] == letters[letters.length() - 1]) {
        word[index] = letters[0];
        increment(index - 1);
    }
    else {
        word[index] = letters[letters.find(word[index]) + 1];
    }
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printf("Usage: ./speller <7-character bank> <main character> <word length>\n");
        return 0;
    }

    if (std::string(argv[1]).length() != 7 || std::string(argv[2]).length() != 1) {
        printf("Usage: ./speller <7-character bank> <main character> <word length>\n");
        return 0;
    }

    wordLength = std::stoi(argv[3]);
    letters = argv[1];
    mainLetter = argv[2][0];

    std::vector<std::filesystem::path> directory;
	nuspell::append_default_dir_paths(directory);
	auto dictPath = nuspell::search_dirs_for_one_dict(directory, "en_US");
    nuspell::Dictionary spellcheck;
    spellcheck.load_aff_dic(dictPath);


    for (int i = 0; i < wordLength; i++) {
        word += letters[0];
    }

    for (int i = 0; i < pow(letters.length(), wordLength) - 1; i++) {
        increment(wordLength - 1);

        if (spellcheck.spell(word)) {
            if (word.find(mainLetter) != std::string::npos) {
                printf("%s\n", word.c_str());
            }
        }
    }

    return 0;
}