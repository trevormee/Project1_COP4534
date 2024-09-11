/***************************************************************
  Student Name: Trevor Mee
  File Name: main.cpp
  Project 1

  @brief Contains main method for running program
***************************************************************/

#include "Headers/Password.hpp"
#include "Headers/Cipher.hpp"
#include "Headers/Node.hpp"
#include "Headers/HashTable.hpp"
#include "Headers/Processing.hpp"

int main()
{
    Password p;
    Cipher c;
    Processing pr;
    HashTable h;
    //pr.PopulateHashTable(h);
    pr.FiveLegal();
    pr.FiveIllegal();
    
   return 0;   
}