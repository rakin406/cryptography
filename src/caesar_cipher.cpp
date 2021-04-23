#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

// Encrypt and decrypt text using caesar cipher
std::string caesar_cipher(std::string text, int shifts = 3) {
    // TODO: Does not work for some letters such as 't'
    std::string result;

    for (int i = 0; i < text.size(); ++i) {
        if (std::isalpha(text[i]) != 0) {
            char mod_char = text[i] + (char)shifts;
            if (((std::islower(text[i]) != 0) && mod_char <= 'z') ||
                ((std::isupper(text[i]) != 0) && mod_char <= 'Z')) {
                result += mod_char;
            } else {
                if (std::isupper(text[i]) != 0) {
                    result +=
                        std::to_string((int)'A' + (mod_char - (int)'Z') - 1);
                } else {
                    result +=
                        std::to_string((int)'a' + (mod_char - (int)'z') - 1);
                }
            }
        } else {
            result += text[i];
        }
    }

    return result;
}

int main() {
    std::string ciphertext = caesar_cipher("Caesar cipher", 6);
    std::cout << ciphertext << "\n";

    // Brute force caesar cipher decryption
    for (int i = 1; i < 26; ++i) {
        std::cout << caesar_cipher(ciphertext, i) << "\n";
    }

    return 0;
}
