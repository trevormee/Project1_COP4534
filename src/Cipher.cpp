/***************************************************************
  Student Name: Trevor Mee
  File Name: Cipher.cpp
  Project 1

  @brief Contains function definitions for reading in a text file,
         encrypting user passwords using the Vigenere Cipher, and 
         writing the encrpyted passwords to a new text file
***************************************************************/
#include "Headers/Cipher.hpp"

/*
    @brief reads in rawdata.txt and pushes the user id
           and plaintext password to a vector
*/
void Cipher::ReadFile()
{
    std::ifstream fileRead(RAW_DATA_TEXT);
    std::string line;

    while(std::getline(fileRead, line))
    {
        std::istringstream iss(line);
        iss >> userId >> plaintextPw;
        userIdEncryptedPasswords.push_back({userId, plaintextPw});
    }
    fileRead.close();
}

/*
    @brief helper function for Encrypt() to create a 
           alphabet hash map for vigenere cipher logic
    @returns hash map of the alphabet
*/
std::unordered_map<char, int> Cipher::CreateAlphabetMap()
{
    for(long unsigned int i = 0; i < alphabet.size(); ++i)
    {
        alphabetMap.insert({alphabet[i], i + 1});
    }

    return alphabetMap;
}

/*
    @brief helper function for Encrypt() to create a 
           reversed alphabet hash map
    @returns reversed alphabet hash map
*/
std::unordered_map<int, char> Cipher::CreateReverseAlphabetMap()
{
    for(long unsigned int i = 0; i < alphabet.size(); ++i)
    {
        reverseAlphabetMap.insert({i + 1, alphabet[i]});
    }

    return reverseAlphabetMap;
}

/*
    @brief encrypts the plaintext passwords
           Math: C_i = (P_i + K_i) mod 26 
    @param plain text password we are looking to encrypt
    @returns encrypted password
*/
std::string Cipher::Encrypt(std::string plaintextPassword)
{
    encryptedPw.clear();
    CreateAlphabetMap();
    CreateReverseAlphabetMap();
    for(long unsigned int i = 0; i < plaintextPassword.size(); i++)
    {
        char plainTextCurrLetter = plaintextPassword[i];
        char keyCurrLetter = KEY[i];
        if(alphabetMap.find(plainTextCurrLetter) != alphabetMap.end()){
            
            int plainTextLetterToInt = alphabetMap[plainTextCurrLetter];
            int keyToInt = alphabetMap[keyCurrLetter];
            int encryptedLetterToInt = (plainTextLetterToInt + keyToInt + alphabet.size()) % alphabet.size();

            if(encryptedLetterToInt == 0)
            {
                encryptedLetterToInt = 1;
            }

            if(reverseAlphabetMap.find(encryptedLetterToInt) != reverseAlphabetMap.end())
            {
                encryptedPw += reverseAlphabetMap[encryptedLetterToInt];
            }
        }
    }
    if(encryptedPw.size() != 9)
    {
        std::cout << "Encrypted Password length not equal to 9 characters!" << std::endl;
    }

    return encryptedPw;
    
}

/*
    @brief Decrypts an ecnrypted password
    @param encrypted password to decode
    @returns decrypted password
*/
std::string Cipher::Decrypt(std::string encryptedPassword)
{
    plaintextPw.clear();
    CreateAlphabetMap();
    CreateReverseAlphabetMap();
    for(long unsigned int i = 0; i < encryptedPassword.size(); i++)
    {
        char encryptedPwCurrLetter = encryptedPassword[i];
        char keyCurrLetter = KEY[i];
        if(alphabetMap.find(encryptedPwCurrLetter) != alphabetMap.end())
        {
            int encryptedLetterToInt = alphabetMap[encryptedPwCurrLetter];
            int keyToInt = alphabetMap[keyCurrLetter];
            int plainTextLetterToInt = (encryptedLetterToInt - keyToInt + alphabet.size()) % alphabet.size();
            if(plainTextLetterToInt == 0)
            {
                plainTextLetterToInt = 1;
            }

            if(reverseAlphabetMap.find(plainTextLetterToInt) != reverseAlphabetMap.end())
            {
                plaintextPw += reverseAlphabetMap[plainTextLetterToInt];
            }
        }
    }

    if(plaintextPw.size() != 9)
    {
        std::cout << "Decrypted password length not equal to 9 characters!" << std::endl;
    }
    return plaintextPw;

}

/*
    @brief Populates the 2D vector 'userIdEncrypedPasswords' with
           encryped passwords 
*/
void Cipher::PopulateUserIdEncryptedPasswords()
{
    ReadFile();

    for(long unsigned int i = 0; i < userIdEncryptedPasswords.size(); ++i)
    {
        userIdEncryptedPasswords[i][1] = Encrypt(userIdEncryptedPasswords[i][1]);
    }
}

/*
    @brief writes user ids and encrypted data to "encrypeddata.txt"
*/
void Cipher::WriteEncryptedPasswordsToFile()
{
    PopulateUserIdEncryptedPasswords();

    std::ofstream outputFile;
    outputFile.open(ENCRYPTED_DATA_TEXT);

    for(long unsigned int i = 0; i < userIdEncryptedPasswords.size(); ++i)
    {
        outputFile << userIdEncryptedPasswords[i][0] << " " << userIdEncryptedPasswords[i][1] << "\n";
    }

    outputFile.close();
}
