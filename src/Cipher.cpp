#include "Headers/Cipher.hpp"

/*
    @brief reads in rawdata.txt and pushes the user id
           and plaintext pw to a vector
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
       //std::cout << "UserId:" << userId << " pw: " << plaintextPw << std::endl;
    }
    std::cout << std::endl;

    fileRead.close();
}

/*
    @brief helper function for Encrypt() to create a 
           alphabet hash map for vigenere cipher logic
    @returns hash map of the alphabet
*/
std::unordered_map<char, int> Cipher::CreateAlphabetMap()
{
    //std::cout << "Alphabet size -> "<< alphabet.size() << std::endl;
    for(long unsigned int i = 0; i < alphabet.size(); ++i)
    {
        alphabetMap.insert({alphabet[i], i + 1});
    }
/*
    for (const auto& pair : alphabetMap)
    {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }
*/
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
/*
    for (const auto& pair : reverseAlphabetMap)
    {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }
*/
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
    //std::cout << "Plaintxt Pw:  " << plaintextPassword << std::endl;
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
        std::cout << "NO SUCCESS" << std::endl;
    }

    //std::cout << "Encrypted Pw:  " << encryptedPw << std::endl;
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
        std::cout << "INVALID NUMBER OF CHARACTERS!" << std::endl;
    }
    return plaintextPw;

}

/*
    @brief Populates the 2D vector 'userIdEncrypedPasswords' with
           encryped passwords 
*/
void Cipher::PopulateUserIdEncryptedPasswords()
{
    //ReadFile();

    for(long unsigned int i = 0; i < userIdEncryptedPasswords.size(); ++i)
    {
        userIdEncryptedPasswords[i][1] = Encrypt(userIdEncryptedPasswords[i][1]);
    }
}

/*
    @brief writes user ids and encryped data to "encrypeddata.txt"
*/
void Cipher::WriteEncryptedPasswordsToFile()
{
    ReadFile();
    PopulateUserIdEncryptedPasswords();

    std::ofstream outputFile;
    outputFile.open(ENCRYPTED_DATA_TEXT);

    for(long unsigned int i = 0; i < userIdEncryptedPasswords.size(); ++i)
    {
        outputFile << userIdEncryptedPasswords[i][0] << " " << userIdEncryptedPasswords[i][1] << "\n";
    }

    outputFile.close();
}
