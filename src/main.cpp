#include "Headers/Password.hpp"
#include "Headers/Cipher.hpp"

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
    
    c.WriteEncryptedPasswordsToFile();
    return 0;   
}