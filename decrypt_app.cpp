#include <iostream>
#include <string>
#include "rc4_library.h"

int main() {
    std::string key = "mysecretkey"; 

    std::string ciphertext = 
        "\xd1\x9c\x53\x1c\x1b\x11\xd8\x48\x2c\x18\xb5\x13\x48\x37\x3c\x1a"
        "\x9f\x4f\x33\x2b\x43\x0f\x98\x14\x36\xb1\xc4\x15\x5c\x08\x3f\x22"
        "\x21\x02\xc7\x54\x62\x2e\x41\x84";

    RC4 rc4_decrypt(key);
    std::string decrypted_text = rc4_decrypt.crypt(ciphertext);

    std::cout << "--- CHUONG TRINH GIAI MA RC4 ---" << std::endl;
    std::cout << "Key:            " << key << std::endl;
    
    std::cout << "\nDecrypted Text: " << decrypted_text << std::endl;

    if (decrypted_text == "Hanoi University of Science and Technology") {
        std::cout << "\nSUCCESS: Giai ma thanh cong!" << std::endl;
    } else {
        std::cout << "\nFAILURE: Giai ma that bai!" << std::endl;
    }

    return 0;
}
