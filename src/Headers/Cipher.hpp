/***************************************************************
  Student Name: Trevor Mee
  File Name: Cipher.hpp
  Project 1

  @brief Contains function declarations for reading in a text file,
         encrypting user passwords using the Vigenere Cipher, and 
         writing the encrpyted passwords to a new text file
***************************************************************/


#ifndef CIPHER_HPP
#define CIPHER_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>

class Cipher
{
    private:
        const std::string KEY = "microsoft";
        const std::string RAW_DATA_TEXT = "../rawdata.txt";
        std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
        //std::vector<std::vector<std::string>> userIdEncryptedPasswords;
        std::string userId;
        std::string plaintextPw;
        std::string encryptedPw = "";

    public:
        std::vector<std::vector<std::string>> userIdEncryptedPasswords;
        std::unordered_map<char, int> alphabetMap;
        std::unordered_map<int, char> reverseAlphabetMap;
        const std::string ENCRYPTED_DATA_TEXT = "../encrypteddata.txt";

        // Reads in rawdata.txt
        void ReadFile();

        // Creates a hash map of the alphabet
        std::unordered_map<char, int> CreateAlphabetMap();

        // Creates a reversed alphabet map for encrypting passwords
        std::unordered_map<int, char> CreateReverseAlphabetMap();

        // Encrpyts the passwords using vigenere cipher logic
        std::string Encrypt(std::string plaintextPassword);

        // Decrypts the passwords
        std::string Decrypt(std::string encryptedPassword);
        
        // Populates a 2D vector with user id's and encrypted passwords
        void PopulateUserIdEncryptedPasswords();
        
        // Write encrypted passwords to "encrpyteddata.txt"
        void WriteEncryptedPasswordsToFile();
};
#endif