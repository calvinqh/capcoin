#include "gtest/gtest.h"
#include "serialize.h"
#include <iostream>
#include "test_serial_utils.h"

namespace {

TEST(SerialTest,UnspentTxOut) {
    EXPECT_TRUE(test_good_unspent_serial());
    EXPECT_FALSE(test_bad_unspent_serial());
}

TEST(SerialTest,Transaction) {
    EXPECT_TRUE(test_good_transaction_serial());
    EXPECT_FALSE(test_bad_transaction_serial());
}

TEST(BlockVerificationTest,Invalid) {
    
}

}
