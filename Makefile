CXX=clang++
CXXFLAGS=-std=c++17 -Wall -Wextra -Wformat-security -Wundef -Wconversion \
		 -Wpedantic -Wformat=2 -O3 -fdelete-null-pointer-checks

all: caesar_cipher vigenere_cipher xor

caesar_cipher: src/caesar_cipher.cpp
	$(CXX) src/caesar_cipher.cpp $(CXXFLAGS) -o build/caesar_cipher

vigenere_cipher: src/vigenere_cipher.cpp
	$(CXX) src/vigenere_cipher.cpp $(CXXFLAGS) -o build/vigenere_cipher

xor: src/xor.cpp
	$(CXX) src/xor.cpp $(CXXFLAGS) -o build/xor

clean:
	rm build/caesar_cipher build/vigenere_cipher build/xor
