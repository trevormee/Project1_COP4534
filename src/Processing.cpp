/***************************************************************
  Student Name: Trevor Mee
  File Name: Processing.cpp
  Project 1

  @brief Contains function definitons for reading in 'encrypteddata.txt';
         populating the hash table with user Id's, encrypted passwords, and 
         plaintext passwords; and a 5 legal and a 5 illegal user id and password
         combination function for testing
***************************************************************/
#include "Headers/Processing.hpp"

/*
    @brief populates hash table with user id/encrypted password pairs
    @param reference to HashTable class
*/
void Processing::PopulateHashTable(HashTable &h)
{
    Node n;
    Cipher c;
    c.PopulateUserIdEncryptedPasswords();

    for(long unsigned int i = 0; i < c.userIdEncryptedPasswords.size(); i++)
    {
        n.userId = c.userIdEncryptedPasswords[i][0];
        n.encryptedPassword = c.userIdEncryptedPasswords[i][1];
        h.Insert(n);
    }
}

/*
    @brief 5 legal password check as per Project 1 requirements
    @param reference to HashTable class
*/
void Processing::FiveLegal(HashTable &h)
{
    std::cout << "Legal:" << std::endl;
    std::cout << std::setw(20) << "Userid" << std::setw(20) << "Password(file)" << std::setw(20) << "Password(table/un)" << std::setw(10) << "Result" << std::endl;
    std::ifstream fileRead(RAW_DATA_TEXT);
    std::string line;
    int entry = 1;
    std::vector<int> indexes = {1,3,5,7,9};
    long unsigned int currIndex = 0;
    Cipher c;
    while(std::getline(fileRead, line))
    {   
        if(entry == indexes[currIndex]) {
            std::istringstream iss(line);
            std::string userId, plainTextPw, encryptedPw, encryptedPwDecrypted;
            iss >> userId >> plainTextPw;
            
            encryptedPw = c.Encrypt(plainTextPw);

            int index = h.Lookup(userId);

            if(index != -1){ 
                Node* n = h.Table[index];
                while(n != nullptr)
                {
                    if(n->getUserId() == userId)
                    {
                        if(n->getEncryptedPw() == encryptedPw)
                        {
                            encryptedPwDecrypted = c.Decrypt(n->getEncryptedPw());
                            std::cout << std::setw(20) << userId << std::setw(20) << plainTextPw << std::setw(20) << encryptedPwDecrypted << std::setw(10) << "match" << std::endl;
                        }else{
                            std::cout << std::setw(20) << userId << std::setw(20) << plainTextPw << std::setw(20) << encryptedPwDecrypted << std::setw(10) << "no match" << std::endl;
                        }
                        
                        break;
                    }
                    n = n -> next;
                }
            }

            currIndex++;
            if(currIndex > indexes.size()){
                break;
            }
        }
        entry++;
        if(entry > 9){
            break;
        }
        
    }

    fileRead.close();
}

/*
    @brief 5 illegal passwords check as per Project 1 Requirements
    @param reference to HashTable class
*/
void Processing::FiveIllegal(HashTable &h)
{
    std::cout << "Illegal:" << std::endl;
    std::cout << std::setw(20) << "Userid" << std::setw(20) << "Password(mod)" << std::setw(20) << "Password(table/un)" << std::setw(10) << "Result" << std::endl;
    std::ifstream fileRead(RAW_DATA_TEXT);
    std::string line;
    int entry = 1;
    std::vector<int> indexes = {1,3,5,7,9};
    long unsigned int currIndex = 0;
    Cipher c;
    while(std::getline(fileRead, line))
    {   
        if(entry == indexes[currIndex]) {
            std::istringstream iss(line);
            std::string userId, plainTextPw, modPw, encryptedPwDecrypted;
            iss >> userId >> plainTextPw;

            modPw = c.Encrypt(plainTextPw);
            modPw[0] = '*';   // Modified password

            int index = h.Lookup(userId);

            if(index != -1){ 
                Node* n = h.Table[index];
                while(n != nullptr)
                {
                    if(n->getUserId() == userId)
                    {
                        encryptedPwDecrypted = c.Decrypt(n->getEncryptedPw());
                        if(n->getEncryptedPw() == modPw)
                        {
                            std::cout << std::setw(20) << userId << std::setw(20) << plainTextPw << std::setw(20) << encryptedPwDecrypted << std::setw(10) << "match" << std::endl;
                        }else{
                            std::cout << std::setw(20) << userId << std::setw(20) << modPw << std::setw(20) << encryptedPwDecrypted << std::setw(10) << "no match" << std::endl;
                        }
                        
                        break;
                    }
                    n = n -> next;
                }
            }

            currIndex++;
            if(currIndex > indexes.size()){
                break;
            }
        }
        entry++;
        if(entry > 9){
            break;
        }
        
    }

    fileRead.close();
}