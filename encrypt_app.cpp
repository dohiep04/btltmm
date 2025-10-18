#include <iostream>
#include <string>
#include <iomanip>
#include "rc4_library.h"

void print_hex(const std::string& s) {
    std::cout << std::hex << std::setfill('0');
    for (unsigned char c : s) {
        std::cout << std::setw(2) << static_cast<int>(c) << " ";
    }
    std::cout << std::dec << std::endl;
}

int main() {
    std::string key = "mysecretkey";
    std::string plaintext = "Hanoi University of Science and Technology";

    RC4 rc4_encrypt(key);
    std::string ciphertext = rc4_encrypt.crypt(plaintext);

    std::cout << "--- CHUONG TRINH MA HOA RC4 ---" << std::endl;
    std::cout << "Plaintext: " << plaintext << std::endl;
    std::cout << "Key:       " << key << std::endl;
    
    std::cout << "\nCiphertext (Hex): " << std::endl;
    print_hex(ciphertext);

    std::cout << "\nCiphertext (Raw bytes de copy):" << std::endl;
    std::cout << "\"";
    for (unsigned char c : ciphertext) {
         std::cout << "\\x" << std::hex << std::setw(2) << static_cast<int>(c);
    }
    std::cout << "\"" << std::dec << std::endl;

    return 0;
}
