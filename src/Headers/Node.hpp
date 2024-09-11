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
        Node* next;

        // Default constructor
        Node() { 
          this->userId = userId;
          this->encryptedPassword = encryptedPassword;
          next = nullptr;
        }

        // Getter for the user id
        std::string getUserId() { return userId; }

        // Getter for the password
        std::string getEncryptedPw() { return encryptedPassword; }
};
#endif