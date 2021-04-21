#include <algorithm>
#include <iostream>
#include <string>

// Encrypt text using caesar cipher
std::string encrypt_caesar_cipher(std::string text, int shifts = 3) {
    std::string letters = "abcdefghijklmnopqrstuvwxyz";
    std::transform(text.begin(), text.end(), text.begin(), ::tolower);

    for (int i = 0; i < text.size(); ++i) {
        for (int j = 0; j < letters.size(); ++j) {
            if (text[i] == letters[j]) {
                // Check last three letters in english alphabet
                if (letters[j] == 'x') {
                    text[i] = 'a';
                } else if (letters[j] == 'y') {
                    text[i] = 'b';
                } else if (letters[j] == 'z') {
                    text[i] = 'c';
                } else {
                    // Replace letter with third next letter
                    text[i] = letters[j + shifts];
                }
                break;
            }
        }
    }

    return text;
}

// Decrypt text using caesar cipher
std::string decrypt_caesar_cipher(std::string text, int shifts = 3) {
    std::string letters = "abcdefghijklmnopqrstuvwxyz";
    std::transform(text.begin(), text.end(), text.begin(), ::tolower);

    for (int i = 0; i < text.size(); ++i) {
        for (int j = 0; j < letters.size(); ++j) {
            if (text[i] == letters[j]) {
                // Check first three letters in english alphabet
                if (letters[j] == 'a') {
                    text[i] = 'x';
                } else if (letters[j] == 'b') {
                    text[i] = 'y';
                } else if (letters[j] == 'c') {
                    text[i] = 'z';
                } else {
                    // Replace letter with third previous letter
                    text[i] = letters[j - shifts];
                }
                break;
            }
        }
    }

    return text;
}

int main() {
    // std::cout << encrypt_caesar_cipher("good job") << "\n";
    std::cout << decrypt_caesar_cipher("jrrg mre") << "\n";
    return 0;
}
