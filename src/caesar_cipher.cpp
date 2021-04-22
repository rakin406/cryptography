#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

// Encrypt text using caesar cipher
std::string encrypt_caesar_cipher(std::string plaintext, int shifts = 3) {
    std::string ciphertext = "";

    for (int i = 0; i < plaintext.size(); ++i) {
        if (std::isalpha(plaintext[i])) {
            char mod_char = plaintext[i] + (char)shifts;
            if ((std::islower(plaintext[i]) && mod_char <= 'z') ||
                (std::isupper(plaintext[i]) && mod_char <= 'Z')) {
                ciphertext += mod_char;
            } else {
                if (std::isupper(plaintext[i])) {
                    ciphertext += (int)'A' + (mod_char - (int)'Z') - 1;
                } else {
                    ciphertext += (int)'a' + (mod_char - (int)'z') - 1;
                }
            }
        } else {
            ciphertext += plaintext[i];
        }
    }

    return ciphertext;
}

// Decrypt text using caesar cipher
std::string decrypt_caesar_cipher(std::string ciphertext, int shifts = 3) {
    std::string plaintext = "";

    for (int i = 0; i < ciphertext.size(); ++i) {
        if (std::isalpha(ciphertext[i])) {
            char mod_char = ciphertext[i] - (char)shifts;
            if ((std::islower(ciphertext[i]) && mod_char >= 'a') ||
                (std::isupper(ciphertext[i]) && mod_char >= 'A')) {
                plaintext += mod_char;
            } else {
                if (std::isupper(ciphertext[i])) {
                    plaintext += (int)'Z' - ((int)'A' - mod_char) + 1;
                } else {
                    plaintext += (int)'z' - ((int)'a' - mod_char) + 1;
                }
            }
        } else {
            plaintext += ciphertext[i];
        }
    }

    return plaintext;
}

int main() {
    std::cout << encrypt_caesar_cipher("Zebra") << "\n";
    std::cout << decrypt_caesar_cipher("Cheud") << "\n";
    return 0;
}
