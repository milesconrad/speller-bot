from spellchecker import SpellChecker
from math import pow

speller = SpellChecker()

word_length = 8
letters = ['o', 'a', 'r', 'i', 't', 'c', 'm']
main_letter = 'm'

word = [letters[0]] * word_length

def increment(index):
    if word[index] == letters[len(letters) - 1]:
        word[index] = letters[0]
        increment(index - 1)
    else:
        word[index] = letters[letters.index(word[index]) + 1]

for _ in range(int(pow(len(letters), word_length))):
    increment(word_length - 1)

    if ''.join(word) in speller:
        if main_letter in word:
            print(''.join(word))