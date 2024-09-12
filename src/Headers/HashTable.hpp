/***************************************************************
  Student Name: Trevor Mee
  File Name: HashTable.hpp
  Project 1

  @brief Contains function declarations for various hash table
         operations such as creating the table, inserting a new 
         entry, and looking up an entry.
***************************************************************/

#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include "Node.hpp"
#include <iostream>
#include <vector>

class HashTable
{
    private:
        const static int TABLE_SIZE = 44001;
        const int PRIME = 65599;  // High Prime # to reduce collisions
        
    public:
        Node* Table[TABLE_SIZE];

        // Default constructor
        HashTable();
        
        // Insert/Add a new item to hash table
        void Insert(Node n);

        // Search for a given password given a user id
        int Lookup(std::string key);

        // Hash function
        int Hash(std::string key);
};
#endif