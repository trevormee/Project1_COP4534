/***************************************************************
  Student Name: Trevor Mee
  File Name: main.cpp
  Project 1

  @brief Contains main method for running program
***************************************************************/

#include "Headers/Password.hpp"
#include "Headers/Cipher.hpp"
#include "Headers/Node.hpp"
#include "Headers/HashTable.hpp"
#include "Headers/Processing.hpp"

int main()
{
    Password pw;
    Cipher c;
    Processing pr;
    HashTable h;

    // Read in names.txt & write out user id/passwords to rawdata.txt
    std::cout << "Reading names.txt, generating random passwords, writing to rawdata.txt..." << std::endl;
    pw.WritePasswordsToFile();

    // Read in rawdata.txt, encrypt passwords, write encrypted passwords to encrypteddata.txt
    std::cout << "Reading rawdata.txt, encrypting, writing to encrypteddata.txt..." << std::endl;
    c.WriteEncryptedPasswordsToFile();

    // Populate Hash Table
    std::cout << "Populating hash table..." << std::endl;
    pr.PopulateHashTable(h);

    // 5 Legal & 5 Illegal Password Check
    std::cout << "Five Legal & Five Illegal Check..." << std::endl;
    pr.FiveLegal(h);
    pr.FiveIllegal(h);
    
   return 0;   
}