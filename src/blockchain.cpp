#include "../lib/blockchain.h"
#include "../lib/block.h"
#include "../lib/transaction.h"

Blockchain::Blockchain(){
    //initialize the chain with the genesis block. 
    //Change addresses and hashes in future
    TxIn GenIn("", "", 0);
    TxOut GenOut("32ba5334aafcd8e7266e47076996b55", 50);
    std::vector<TxIn> TxIns{GenIn};
    std::vector<TxOut> TxOuts{GenOut};
    Transaction GenTxn(TxIns, TxOuts);
    std::vector<Transaction> GenTxns{GenTxn};
    Block Genesis(0, 1521001712, 0, 0, "cd4321ce128c5aab080299604b9ba347", "", GenTxns);
}


Block Blockchain::GetLastBlock(){
    return blocks_[length-1];
}

Block Blockchain::GenerateNextBlock(vector <Transaction>& data){
    size_t index = blocks_[length-1].index_ + 1;
    time_t timestamp = time(0);
    size_t difficulty = GetDifficulty();
    size_t nonce = 0;
    std::string hash_;
    std::string prevHash = blocks_[length-1].hash_;
    while (true) {
        hash = CalculateHash(index, prevHash, timestamp, data, difficulty, nonce);
        if (HashMatchesDifficulty(hash, difficulty)) {
            break;
        }
        nonce++;
    }
    Block newBlock(index, timestamp, difficulty, nonce, hash, prevHash, data);
    newBlock.Validate();
    blocks_.push_back(newBlock);
    //Broadcast new block
}

