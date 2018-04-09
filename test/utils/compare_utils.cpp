#include "compare_utils.h"


bool compareUTxOut(UnspentTxOut left, UnspentTxOut right) {
    bool all_pass = true;
    all_pass = all_pass && (left.GetId() == right.GetId());
    all_pass = all_pass && (left.GetAddress() == right.GetAddress());
    all_pass = all_pass && (left.GetIndex() == right.GetIndex());
    all_pass = all_pass && (left.GetAmount() == right.GetAmount());
    return all_pass;

}

bool compareTransaction(Transaction left, Transaction right) {
    bool all_pass = true;
    all_pass = all_pass && (compareTxInList(left.GetTxIns(),right.GetTxIns()));

    all_pass = all_pass && (compareTxOutList(left.GetTxOuts(), right.GetTxOuts()));
    return all_pass;
}

bool compareTxInList(std::vector<TxIn> left, std::vector<TxIn> right) {
    if(left.size() != right.size())
        return false;
    for(size_t i = 0; i < left.size(); i++) {
        if(!compareTxIn(left[i],right[i]))
          return false;  
    }
    return true;
}

bool compareTxOutList(std::vector<TxOut> left, std::vector<TxOut> right) {
    if(left.size() != right.size())
        return false;
    for(size_t i = 0; i < left.size(); i++) {
        if(!compareTxOut(left[i],right[i]))
            return false;
    }
    return true;
}

bool compareTxIn(TxIn left, TxIn right) {
    bool all_pass = true;
    all_pass = all_pass && (left.GetVal() == right.GetVal());
    all_pass = all_pass && (left.GetId() == right.GetId());
    all_pass = all_pass && (left.GetSignature() == right.GetSignature());
    all_pass = all_pass && (left.GetIndex() == right.GetIndex());
    return all_pass;
}

bool compareTxOut(TxOut left, TxOut right) {
    bool all_pass = true;
    all_pass = all_pass && (left.GetVal() == right.GetVal());
    all_pass = all_pass && (left.GetAddress() == right.GetAddress());
    all_pass = all_pass && (left.GetAmount() == right.GetAmount());
    return all_pass;
}