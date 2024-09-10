/***************************************************************
  Student Name: Trevor Mee
  File Name: HashTable.hpp
  Project 1

  @brief 
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
        //Node* Table[TABLE_SIZE];
        //Node* Table;
        int size;
        const int PRIME = 65599;  // High Prime Number to reduce collisions
        
    public:
        Node* Table[TABLE_SIZE];
        // Parameterized constructor
        HashTable();

        // Destructor
        //~HashTable();
        
        // Insert/Add a new item to hash table
        void Insert(Node n);

        // Search for a given password given a user id
        int Lookup(std::string key);

        // Hash function
        int Hash(std::string key);
};
#endif