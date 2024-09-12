/***************************************************************
  Student Name: Trevor Mee
  File Name: Processing.hpp
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
#include <iomanip>

class Processing
{
    private:
      const std::string RAW_DATA_TEXT = "../rawdata.txt";

    public:
        // Populates hash table with user id's and passwords
        void PopulateHashTable(HashTable &h);

        // 5 Legal Passwords Check
        void FiveLegal(HashTable &h);

        // 5 Illegal Passwords Check 
        void FiveIllegal(HashTable &h);
};
#endif