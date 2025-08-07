 #include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <openssl/sha.h>

std::string sha256(const std::string& str) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(reinterpret_cast<const unsigned char*>(str.c_str()), str.size(), hash);

    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i)
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    return ss.str();
}

std::string mineBlock(int difficulty, const std::string& data) {
    int nonce = 0;
    std::string prefix(difficulty, '0');
    std::string hash;

    do {
        std::stringstream ss;
        ss << data << nonce;
        hash = sha256(ss.str());
        nonce++;
    } while (hash.substr(0, difficulty) != prefix);

    std::cout << "Block mined: " << hash << "\n";
    return hash;
}
