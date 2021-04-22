#include <iostream>
#include <string>

// Encrypt text with XOR encryption technique
std::string encrypt_xor(std::string text, std::string key) {
    std::string result = text;
    for (int i = 0; i < text.size(); ++i) {
        result[i] = text[i] ^ key[i % key.size() - 1];
    }
    return result;
}

// Decrypt encrypted XOR cipher
// std::string decrypt_xor(std::string text) {
// }

int main() {
    std::cout << encrypt_xor("This is amazing", "hackerman") << "\n";
    return 0;
}
