C++FLAG = -g -Wall -std=c++14
CC = gcc

Transaction_OBJ = src/transaction.o src/txin.o src/txout.o src/transactionpool.o\
				  src/utxout.o src/utxoutpool.o
Block_OBJ = src/block.o src/blockchain.o
Merkle_OBJ = src/merkle.o
Network_OBJ = src/network.o src/socket.o
FullNode_OBJ = src/fullNode.o
Serialize_OBJ = src/serialize.o
Wallet_OBJ = src/wallet.o
ECC_OBJ = src/ecc.o

#Compiles the main capcoin program and its prerequisutes
Capcoin_OBJ = src/capcoin.o $(Wallet_OBJ) $(ECC_OBJ) $(Transaction_OBJ) $(Block_OBJ) $(Serialize_OBJ) \
$(Network_OBJ) $(FullNode_OBJ)

#Where to store all drivers
EXEC_DIR = ./bin

#Tells compiler where to find headers
#Useful for importing header files (instead of listing full relative path)
INCLUDES = -I ./lib/ -I ./test/utils -I ./test/googletest/googletest/

#Compiles all cpp files listed in the given OBJ variable
.cpp.o:
	g++ $(C++FLAG) -c $< -o $@ $(INCLUDES)
.c.o:
	$(CC) -c $< -o $@ $(INCLUDES)


#Capcoin Main Driver
CAPCOIN=capcoin.o #Executable name
$(CAPCOIN): $(Capcoin_OBJ) #Rule to compile capcoin
	g++ $(C++FLAG) -o $(EXEC_DIR)/$@ $(Capcoin_OBJ) -lpthread

#General Rules to compile drivers
all: capcoin


#Specific Rules to compile specific drivers
capcoin:
	make $(CAPCOIN)

#Removes all executable objects from root, bin, and tests
clean:
	(rm -f *.o;)
	(rm -f bin/*.o;)
	(rm -f src/*.o;)
	(rm -f test/*.o;)
	(rm -f test/gtest.a test/gtest_main.a;)
