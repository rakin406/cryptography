#include <iostream>
#include <random>
#include <string>
#include <utility>

// Generate random integer in range
int generate_random(int min, int max) {
    std::random_device rd;        // obtain a random number from hardware
    std::mt19937 generator(rd()); // seed the generator
    std::uniform_int_distribution<> dist(min, max); // define the range
    return dist(generator);
}

// Generate random key with given length
std::string generate_key(int length) {
    std::string key;
    for (int i = 0; i < length; ++i) {
        key += (char)generate_random(33, 126);
    }
    return key;
}

// Encrypt and decrypt text with XOR cipher technique
std::string xor_cipher(std::string text, std::string key) {
    std::string result = std::move(text);
    for (int i = 0; i < result.size(); ++i) {
        result[i] ^= key[i % key.size()];
    }
    return result;
}

int main() {
    std::string text = "Hello World";
    std::string key = generate_key(text.size());
    std::cout << key << "\n";
    std::cout << xor_cipher(text, key) << "\n";
    // std::cout << xor_cipher("Hello", "KEY") << "\n";
    // std::cout << xor_cipher(" 5'*", "KEY") << "\n";
    return 0;
}
