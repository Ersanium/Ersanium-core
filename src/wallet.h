 #ifndef WALLET_H
#define WALLET_H

#include <string>

class Wallet {
public:
    Wallet();
    std::string getPublicKey() const;
    std::string getPrivateKey() const;
    void saveKeysToFile(const std::string& filename) const;

private:
    std::string privateKey;
    std::string publicKey;

    void generateKeys();
};

#endif
