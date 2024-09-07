CXX = g++ 
CXXFLAGS = -std=c++11 -Wall

OBJS = main.o Password.o Cipher.o

proj1 : ${OBJS}
	 ${CXX} $(CXXFLAGS) -o $@ ${OBJS}

main.o : main.cpp
	${CXX} ${CXXFLAGS} -c main.cpp Headers/Password.hpp Headers/Cipher.hpp

Password.o : Password.cpp Headers/Password.hpp
	${CXX} ${CXXFLAGS} -c Password.cpp    

Cipher.o : Cipher.cpp Headers/Cipher.hpp
	${CXX} ${CXXFLAGS} -c Cipher.cpp 

clean : 
	rm ${OBJS}