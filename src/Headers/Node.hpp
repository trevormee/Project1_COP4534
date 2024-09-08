/***************************************************************
  Student Name: Trevor Mee
  File Name: Node.hpp
  Project 1

  @brief Simple node class to be used for linked list data structure
***************************************************************/
#ifndef NODE_HPP
#define NODE_HPP

#include <string>

class Node
{
    public:
        std::string userId;
        std::string encryptedPassword;
        std::string plaintextPassword;
        Node* next;

    //public:
        // Default constructor to set private variables to default values
        Node() { 
          this->userId = userId;
          this->encryptedPassword = encryptedPassword;
          this->plaintextPassword = plaintextPassword;
          next = nullptr;
        }

        // Getter for the user id
        std::string getUserId() { return userId; }

        // Getter for the password
        std::string getEncryptedPw() { return encryptedPassword; }

        std::string getPlainTextPw() { return plaintextPassword; }
};
#endif