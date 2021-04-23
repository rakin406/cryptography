#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

// TODO: Add decryption function

// Encrypt text using vigenere cipher
std::string vigenere_cipher(std::string plaintext, std::string key) {
    std::string ciphertext;
    const std::string LETTERS = "abcdefghijklmnopqrstuvwxyz";
    std::transform(key.begin(), key.end(), key.begin(), ::tolower);
    int cur_index = -1;

    for (int i = 0; i < plaintext.size(); ++i) {
        if (std::isalpha(plaintext[i]) != 0) {
            if (cur_index == key.size()) {
                cur_index = 0;
            } else {
                ++cur_index;
            }
            int cur_char_of_key = LETTERS.find(key[cur_index]);

            char shifted_char = plaintext[i] + (char)cur_char_of_key;
            if (((std::islower(plaintext[i]) != 0) && shifted_char <= 'z') ||
                ((std::isupper(plaintext[i]) != 0) && shifted_char <= 'Z')) {
                ciphertext += shifted_char;
            } else {
                if (std::isupper(plaintext[i]) != 0) {
                    ciphertext += std::to_string(
                        (int)'A' + (shifted_char - (int)'Z') - 1);
                } else {
                    ciphertext += std::to_string(
                        (int)'a' + (shifted_char - (int)'z') - 1);
                }
            }
        } else {
            ciphertext += plaintext[i];
        }
    }

    return ciphertext;
}

int main() {
    std::string ciphertext = vigenere_cipher("Vigenere cipher", "ABC");
    std::cout << ciphertext << "\n";

    return 0;
}
