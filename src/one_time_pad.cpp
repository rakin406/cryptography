#include <iostream>
#include <random>
#include <string>

// Generate random integer in range
int generate_random(const int &min, const int &max) {
    static thread_local std::mt19937 generator;
    std::uniform_int_distribution<int> dist(min, max);
    return dist(generator);
}

// Generate random key with given length
std::string generate_key(int length) {
    std::string key = "";
    for (int i = 0; i < length; ++i) {
        key += (char)generate_random(33, 126);
    }
    return key;
}

int main() {
    std::cout << generate_key(3) << "\n";
    return 0;
}
