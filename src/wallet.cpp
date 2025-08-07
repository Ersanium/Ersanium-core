 #include "wallet.h"
#include <fstream>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>

Wallet::Wallet() {
    generateKeys();
}

std::string Wallet::getPublicKey() const {
    return publicKey;
}

std::string Wallet::getPrivateKey() const {
    return privateKey;
}

void Wallet::saveKeysToFile(const std::string& filename) const {
    std::ofstream out(filename);
    out << "Public Key:\n" << publicKey << "\n";
    out << "Private Key:\n" << privateKey << "\n";
    out.close();
}

void Wallet::generateKeys() {
    RSA* rsa = RSA_new();
    BIGNUM* bn = BN_new();
    BN_set_word(bn, RSA_F4);
    RSA_generate_key_ex(rsa, 2048, bn, nullptr);

    BIO* pri = BIO_new(BIO_s_mem());
    PEM_write_bio_RSAPrivateKey(pri, rsa, nullptr, nullptr, 0, nullptr, nullptr);
    char* pri_key_cstr;
    long pri_len = BIO_get_mem_data(pri, &pri_key_cstr);
    privateKey.assign(pri_key_cstr, pri_len);

    BIO* pub = BIO_new(BIO_s_mem());
    PEM_write_bio_RSAPublicKey(pub, rsa);
    char* pub_key_cstr;
    long pub_len = BIO_get_mem_data(pub, &pub_key_cstr);
    publicKey.assign(pub_key_cstr, pub_len);

    BIO_free_all(pub);
    BIO_free_all(pri);
    RSA_free(rsa);
    BN_free(bn);
}
