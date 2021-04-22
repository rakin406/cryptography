#include <iostream>
#include <random>
#include <string>

// Generate random integer in range
int generate_random(int min, int max) {
    std::random_device rd;        // obtain a random number from hardware
    std::mt19937 generator(rd()); // seed the generator
    std::uniform_int_distribution<> dist(min, max); // define the range
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
