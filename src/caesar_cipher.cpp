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
            if (mod_char > 64 && mod_char < 123) {
                result += mod_char;
            } else {
                result += (char)64 + (mod_char - (char)122);
            }
        } else {
            result += text[i];
        }
    }

    return result;
}

// Decrypt text using caesar cipher
std::string decrypt_caesar_cipher(std::string text, int shifts = 3) {
    std::transform(text.begin(), text.end(), text.begin(), ::tolower);

    for (int i = 0; i < text.size(); ++i) {
    }

    return text;
}

int main() {
    std::cout << encrypt_caesar_cipher("zebra") << "\n";
    // std::cout << encrypt_caesar_cipher("good JOB") << "\n";
    // std::cout << encrypt_caesar_cipher(" ") << "\n";
    // std::cout << decrypt_caesar_cipher("jrrg mre") << "\n";
    return 0;
}
