#include "Headers/Password.hpp"
#include "Headers/Cipher.hpp"
#include "Headers/Node.hpp"
#include "Headers/HashTable.hpp"
#include "Headers/Processing.hpp"

int main()
{
    Password p;
    //p.WritePasswordsToFile();
    Cipher c;
    Processing pr;
    HashTable h(88001);
    pr.ReadEncryptedData(h);
    //c.WriteEncryptedPasswordsToFile();
    //c.Encrypt("mmgwloryo");
    //c.Decrypt("nkfvtyvnc");
    
/*
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
*/

   //Processing pr;
   //pr.ReadEncryptedData();

   return 0;   
}