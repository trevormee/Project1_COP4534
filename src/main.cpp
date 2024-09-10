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
    //c.PopulateUserIdEncryptedPasswords();
    Processing pr;
    HashTable h;
    //pr.ReadEncryptedData(h);
   // pr.PopulateHashTable(h);
    pr.FiveLegal();
    //pr.FiveLegal();
    //c.WriteEncryptedPasswordsToFile();
    //c.Encrypt("mmgwloryo");
    //c.Decrypt("nkfvtyvnc");
    /*

    int tableSize = 44001;
    HashTable ht(tableSize);

    Node n1, n2, n3;
    n1.userId = "user1";
    n1.encryptedPassword = "password1";
    n1.plaintextPassword = "plaintextpw1";
    
    n2.userId = "user2";
    n2.encryptedPassword = "password2";
    
    n3.userId = "user3";
    n3.encryptedPassword = "password3";
    //ht.Insert(n1);
    //ht.Insert(n2);
    //ht.Insert(n3);

    //ht.Lookup("user2");
    //ht.Lookup("user4"); 
*/
   return 0;   
}