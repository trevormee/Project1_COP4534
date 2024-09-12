/***************************************************************
  Student Name: Trevor Mee
  File Name: HashTable.cpp
  Project 1

  @brief Contains function definitions for various hash table
         operations such as creating the table, inserting a new 
         entry, and looking up an entry.
***************************************************************/
#include "Headers/HashTable.hpp"

/*
    @brief Default constructor to allocate memory 
            for the table and init. each bucket as null
*/
HashTable::HashTable()
{
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        Table[i] = nullptr;
    }
}


/*
    @brief inserts a new entry into the hash table
    @param element to be inserted
*/        
void HashTable::Insert(Node n)
{
    int index = Hash(n.getUserId());
    
    Node* curr = Table[index];
    while(curr != nullptr)
    {
        if(curr->getUserId() == n.getUserId())
        {
            std::cout << "Key already in table... skipping insert";
            return;
        }
        curr = curr->next;
    }
    
    Node* newNode = new Node();
    newNode->userId = n.userId;
    newNode->encryptedPassword = n.encryptedPassword;
    newNode->next = Table[index];
    Table[index] = newNode;
}

/*
    @brief searches for a password given a users id
    @param user id to search for
    @returns index of user id password pair
*/
int HashTable::Lookup(std::string key)
{
    int index = Hash(key);

    Node* curr = Table[index];
    while(curr != nullptr)
    {
        if(curr->userId == key)
        {
            return index;
        }
        curr = curr -> next;
    } 
    std::cout << "User ID: " << key << " not found in table!" << std::endl;
    return -1;
}
  
/*
    @brief hash function using Horner's rule
    @param user id to hash by
    @return index where user id is located at
*/        
int HashTable::Hash(std::string key)
{
    int hashValue = 0;
    for(long unsigned int i = 0; i < key.length(); i++)
    {
        char c = key[i];
        hashValue = hashValue *  PRIME + c;
    }

    return std::abs(hashValue % TABLE_SIZE) ;
}

