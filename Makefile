CXX=clang++
CXXFLAGS=-std=c++17 -Wall -Wextra -Wformat-security -Wundef -Wconversion \
		 -Wpedantic -Wformat=2 -O3 -fdelete-null-pointer-checks

all: caesar_cipher vigenere_cipher one_time_pad xor

caesar_cipher: src/caesar_cipher.cpp
	$(CXX) src/caesar_cipher.cpp $(CXXFLAGS) -o build/caesar_cipher

vigenere_cipher: src/vigenere_cipher.cpp
	$(CXX) src/vigenere_cipher.cpp $(CXXFLAGS) -o build/vigenere_cipher

one_time_pad: src/one_time_pad.cpp
	$(CXX) src/one_time_pad.cpp $(CXXFLAGS) -o build/one_time_pad

xor: src/xor.cpp
	$(CXX) src/xor.cpp $(CXXFLAGS) -o build/xor

clean:
	rm build/caesar_cipher build/vigenere_cipher build/one_time_pad build/xor
