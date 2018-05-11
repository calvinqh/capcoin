#ifndef WALLET_H
#define WALLET_H

#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <memory>
#include <string>
#include <stdint.h>

#include "picosha2.h"
#include "transaction.h"
#include "utxoutpool.h"

class Wallet{

public:

    ~Wallet();
    Wallet(UnspentTxOutPool* UTXO);
    void send(double ccAmt, std::string toCCAddresses);
    bool isWalletActive();
    std::string GetAddress();
    double Balance();
    //void Wallet::shutdownWallet();

    // originally private
    Transaction * createTransaction(std::string& ccAddress, double& ccAmt);
    void test();

private:

    bool valid;
    bool walletFileIsValid();

    std::string myAddress;

    void makeKeyPair();
    void validateKeyPairs();

    std::string makeSignature(std::string hash);
    bool        validateSignature(std::string publicKey, std::string hash, std::string sig);


    void initWallet();


    // returns 1 if unspentBal >= 0, and enough vtxOut were found to send ccAmt; returns 0 otherwise
    int getUnspentTx(const double& ccAmt, std::vector<UnspentTxOut>& vtxOut, double& unspentBal);

    void setTxInput(std::vector<TxIn> &txinputs, std::vector<UnspentTxOut> &txoutput);
    void setTxOutput(std::vector<TxOut> &txoutputs, std::string& ccAddress, double& ccAmt, double& unspentBal);

    void updateWalletBalance();
    void writeWalletToDisk();
    UnspentTxOutPool* UTXO_pool;

    std::pair<std::string, std::string> keyPair;
    double balance_;

};

#endif //WALLET_H
