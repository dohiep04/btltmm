#pragma once

#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

class RC4 {
private:
    unsigned char S[256];
    int i, j;

    void ksa(const std::vector<unsigned char>& key) {
        std::iota(S, S + 256, 0); 
        
        j = 0;
        for (i = 0; i < 256; ++i) {
            j = (j + S[i] + key[i % key.size()]) % 256;
            std::swap(S[i], S[j]);
        }
        
        i = 0;
        j = 0;
    }

    unsigned char prga() {
        i = (i + 1) % 256;
        j = (j + S[i]) % 256;
        std::swap(S[i], S[j]);
        return S[(S[i] + S[j]) % 256];
    }

public:
    RC4(const std::string& key) {
        std::vector<unsigned char> key_bytes(key.begin(), key.end());
        ksa(key_bytes);
    }

    std::string crypt(const std::string& data) {
        std::string output = data;
        for (size_t k = 0; k < data.length(); ++k) {
            output[k] = data[k] ^ prga();
        }
        return output;
    }
};
