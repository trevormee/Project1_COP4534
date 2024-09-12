CXX = g++ 
CXXFLAGS = -std=c++11 -Wall

OBJS = main.o Password.o Cipher.o HashTable.o Processing.o
GCH = Headers/Cipher.hpp.gch Headers/Password.hpp.gch Headers/HashTable.hpp.gch Headers/Node.hpp.gch Headers/Processing.hpp.gch
TXTFILES = ../rawdata.txt ../encrypteddata.txt

proj1 : ${OBJS}
	 ${CXX} $(CXXFLAGS) -o $@ ${OBJS}

main.o : main.cpp
	${CXX} ${CXXFLAGS} -c main.cpp Headers/Password.hpp Headers/Cipher.hpp Headers/Node.hpp Headers/HashTable.hpp Headers/Processing.hpp

Password.o : Password.cpp Headers/Password.hpp
	${CXX} ${CXXFLAGS} -c Password.cpp    

Cipher.o : Cipher.cpp Headers/Cipher.hpp
	${CXX} ${CXXFLAGS} -c Cipher.cpp 

Node.o : Node.cpp Headers/Node.hpp
	${CXX} ${CXXFLAGS} -c Node.cpp

HashTable.o : HashTable.cpp Headers/HashTable.hpp
	${CXX} ${CXXFLAGS} -c HashTable.cpp

Processing.o : Processing.cpp Headers/Processing.hpp
	${CXX} ${CXXFLAGS} -c Processing.cpp 

clean : 
	rm ${OBJS} ${GCH} ${TXTFILES}