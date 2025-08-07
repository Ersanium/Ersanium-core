 #include "wallet.h"
#include <iostream>

int main() {
    std::cout << "--- ERSANIUM WALLET ---" << std::endl;

    Wallet myWallet;

    std::cout << "\nÖffentlicher Schlüssel (Public Key):\n" << myWallet.getPublicKey() << std::endl;
    std::cout << "\nPrivater Schlüssel (Private Key):\n" << myWallet.getPrivateKey() << std::endl;

    myWallet.saveKeysToFile("ersanium_wallet.txt");

    std::cout << "\nWallet wurde erfolgreich erstellt und gespeichert.\n";
    return 0;
}
