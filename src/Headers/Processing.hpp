/***************************************************************
  Student Name: Trevor Mee
  File Name: Cipher.hpp
  Project 1

  @brief Contains function declarations for reading in 'encrypteddata.txt';
         populating the hash table with user Id's, encrypted passwords, and 
         plaintext passwords; and a 5 legal and a 5 illegal user id and password
         combination function for testing
***************************************************************/
#ifndef PROCESSING_HPP
#define PROCESSING_HPP

#include "Cipher.hpp"
#include "HashTable.hpp"

class Processing
{
    private:

    public:
        // Reads in encrypteddata.txt
        void ReadEncryptedData(HashTable& h);

        // Populates hash table with user id's and passwords
        void PopulateHashTable();

        // 5 Legal Passwords Check
        void FiveLegal();

        // 5 Illegal Passwords Check function
        void FiveIllegal();

};
#endif