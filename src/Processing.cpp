#include "Headers/Processing.hpp"

void Processing::ReadEncryptedData(HashTable& h)
{
    std::ifstream fileRead("../encrypteddata.txt");
    std::string line;
    Cipher c;
    int numUsers = 0;
    while(std::getline(fileRead, line))
    {
        std::istringstream iss(line);
        Node n;
        iss >> n.userId >> n.encryptedPassword;
        std::cout << "UserId:" << n.userId << " Encrypted pw: " << n.encryptedPassword;
        
        n.plaintextPassword = c.Decrypt(n.encryptedPassword);
        //std::cout << " Plaintext pw: " << n.plaintextPassword << std::endl;
        h.Insert(n);
        numUsers++;
        std::cout << "\ncount = " << numUsers << std::endl;
    }
    std::cout << "Num Users: " << numUsers << std::endl;
    std::cout << std::endl;

    fileRead.close();
}