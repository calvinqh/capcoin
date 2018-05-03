C++FLAG = -g -std=c++14

Transaction_OBJ = src/transaction.o src/txin.o src/txout.o src/utxout.o src/utxoutpool.o
Block_OBJ = src/block.o src/blockchain.o
Merkle_OBJ = src/merkle.o
Network_OBJ = src/network.o src/socket.o
FullNode_OBJ = src/fullNode.o
Serialize_OBJ = src/serialize.o

#Compiles the main capcoin program and its prerequisutes
Capcoin_OBJ = src/capcoin.o $(Transaction_OBJ) $(Block_OBJ) $(Serialize_OBJ)

NET_TEST_OBJ = network_test.o $(Transaction_OBJ) $(Block_OBJ) $(Serialize_OBJ)

#Where to store all drivers
EXEC_DIR = ./bin

#Tells compiler where to find headers
#Useful for importing header files (instead of listing full relative path)
INCLUDES = -I ./lib/ -I ./test/utils -I ./modules/Breep/include

#Libaries paths' flag
LIBSDIR = -L ./modules/Breep/bin

LINKS = -pthread -lboost_system

#Compiles all cpp files listed in the given OBJ variable
.cpp.o:
	g++ $(C++FLAG) -c $< -o $@ $(INCLUDES) $(LIBSDIR) $(LINKS)


#Capcoin Main Driver
CAPCOIN=capcoin.o #Executable name
$(CAPCOIN): $(Capcoin_OBJ) #Rule to compile capcoin
	g++ $(C++FLAG) -o $(EXEC_DIR)/$@ $(Capcoin_OBJ) $(LINKS) 

NET_TEST=net_test.o#Executable name
$(NET_TEST): $(NET_TEST_OBJ) #Rule to compile capcoin
	g++ $(C++FLAG) -o $(EXEC_DIR)/$@ $(NET_TEST_OBJ) $(LINKS)



#General Rules to compile drivers
all: capcoin

net_test:
	make $(NET_TEST)

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
