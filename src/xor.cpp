#include <iostream>
#include <string>

// Encrypt and decrypt text with XOR cipher technique
std::string xor_cipher(std::string text, std::string key) {
    std::string result = text;
    for (int i = 0; i < text.size(); ++i) {
        result[i] = text[i] ^ key[i % key.size()];
    }
    return result;
}

int main() {
    std::cout << xor_cipher("hackerman", "KEY") << "\n";
    std::cout << xor_cipher("#$:  +&$7", "KEY") << "\n";
    return 0;
}
