#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

// Encrypt text using caesar cipher
std::string encrypt_caesar_cipher(std::string text, int shifts = 3) {
    std::string result = "";

    for (int i = 0; i < text.size(); ++i) {
        if (std::isalpha(text[i])) {
            char mod_char = text[i] + (char)shifts;
            if ((std::islower(text[i]) && mod_char <= 'z') ||
                (std::isupper(text[i]) && mod_char <= 'Z')) {
                result += mod_char;
            } else {
                if (std::isupper(text[i])) {
                    result += (int)'A' + (mod_char - (int)'Z') - 1;
                } else {
                    result += (int)'a' + (mod_char - (int)'z') - 1;
                }
            }
        } else {
            result += text[i];
        }
    }

    return result;
}

// Decrypt text using caesar cipher
std::string decrypt_caesar_cipher(std::string text, int shifts = 3) {
    std::string result = "";

    for (int i = 0; i < text.size(); ++i) {
        if (std::isalpha(text[i])) {
            char mod_char = text[i] - (char)shifts;
            if ((std::islower(text[i]) && mod_char >= 'a') ||
                (std::isupper(text[i]) && mod_char >= 'A')) {
                result += mod_char;
            } else {
                if (std::isupper(text[i])) {
                    result += (int)'Z' - ((int)'A' - mod_char) - 1;
                } else {
                    result += (int)'z' - ((int)'a' - mod_char) - 1;
                }
            }
        } else {
            result += text[i];
        }
    }

    return result;
}

int main() {
    // std::cout << encrypt_caesar_cipher("zebra") << "\n";
    // std::cout << encrypt_caesar_cipher("good JOB") << "\n";
    // std::cout << encrypt_caesar_cipher(" ") << "\n";
    std::cout << decrypt_caesar_cipher("jrrg mre") << "\n";
    std::cout << decrypt_caesar_cipher("JRRG MRE") << "\n";
    std::cout << decrypt_caesar_cipher(" .") << "\n";
    return 0;
}
