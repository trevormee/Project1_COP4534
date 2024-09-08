#include "Headers/Password.hpp"
#include "Headers/Cipher.hpp"
#include "Headers/Node.hpp"
#include "Headers/HashTable.hpp"

int main()
{
    Password p;
    //p.WritePasswordsToFile();

    Cipher c;
    //c.ReadFile();
    //c.VigenereCipher();
    //std::string s = c.Encrypt("zddewvcsu"); 
    //std::cout << s << std::endl;
    //std::cout << "---------------" << std::endl;
    //c.ReverseAlphabetMap();
    
   // c.WriteEncryptedPasswordsToFile();

    int tableSize = 10;
    HashTable ht(tableSize);

    Node n1, n2, n3;
    n1.userId = "user1";
    n1.encryptedPassword = "password1";
    n1.plaintextPassword = "plaintextpw1";
    
    n2.userId = "user2";
    n2.encryptedPassword = "password2";
    
    n3.userId = "user3";
    n3.encryptedPassword = "password3";
    ht.Insert(n1);
    ht.Insert(n2);
    ht.Insert(n3);

    ht.Lookup("user2");
    ht.Lookup("user4"); 

    return 0;   
}