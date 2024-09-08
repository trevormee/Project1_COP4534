#include "Headers/HashTable.hpp"

/*
    @brief Parameterized constructor to allocate memory 
            for the table and init. each bucket as null
    @param sizeo f table
*/
HashTable::HashTable(int size)
{
    this -> size = size;
    //Table = new Node*[size];
    for(int i = 0; i < size; i++)
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
    newNode->plaintextPassword = n.plaintextPassword;
    newNode->next = Table[index];
    Table[index] = newNode;
}

/*
    @brief searches for a password given a users id
    @param user id to search for
    @returns index of user id password pair
}
*/
int HashTable::Lookup(std::string key)
{
    int index = Hash(key);
    Node* curr = Table[index];

    while(curr != nullptr)
    {
        if(curr->userId == key)
        {
            std::cout << "Key found! UserId == " << curr->getUserId() << std::endl;
            return index;
        }
        curr = curr -> next;
    } 
    std::cout << "key not found :(" << std::endl;
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

    return hashValue % size;
}

