#include "Headers/Processing.hpp"

/*
void Processing::ReadEncryptedData(HashTable &h)
{
    std::ifstream fileRead("../encrypteddata.txt");
    std::string line;
    //Cipher c;
    int numUsers = 0;
    while(std::getline(fileRead, line))
    {
        std::istringstream iss(line);
        Node n;
        iss >> n.userId >> n.encryptedPassword;
        std::cout << "UserId:" << n.userId << " Encrypted pw: " << n.encryptedPassword << std::endl;;
        
        //n.plaintextPassword = c.Decrypt(n.encryptedPassword);
        //std::cout << " Plaintext pw: " << n.plaintextPassword << std::endl;
        h.Insert(n);
        numUsers++;
        //if(numUsers > 10)
        //    break;
    }
    std::cout << "!!Num users= " << numUsers << std::endl;
    std::cout << std::endl;
    fileRead.close();
}
*/

void Processing::PopulateHashTable(HashTable &h)
{
    Node n;
    Cipher c;
    c.PopulateUserIdEncryptedPasswords();
    //std::cout << c.userIdEncryptedPasswords.size() << std::endl;

    //for(int i = 0; i < c.userIdEncryptedPasswords.size(); i++)
    for(int i = 0; i < 10; i++)
    {
        n.userId = c.userIdEncryptedPasswords[i][0];
        n.encryptedPassword = c.userIdEncryptedPasswords[i][1];
        //std::cout << n.userId << " " << n.encryptedPassword << std::endl;
        h.Insert(n);
    }
    h.Lookup("SMITH,");
    h.Lookup("WILLIAMS,");
    //std::cout << c.userIdEncryptedPasswords.size() << std::endl;
    std::cout << "Function complete" << std::endl;
}


void Processing::FiveLegal()
{
    HashTable h;
    //ReadEncryptedData(h);
    PopulateHashTable(h);
    std::cout << "Legal:" << std::endl;
    std::cout << std::setw(20) << "Userid" << std::setw(20) << "Password(file)" << std::setw(20) << "Password(table/un)" << std::setw(10) << "Result" << std::endl;
    std::ifstream fileRead("../rawdata.txt");
    std::string line;
    int entry = 1;
    std::vector<int> indexes = {1,3,5,7,9};
    int currIndex = 0;
    Cipher c;
    //HashTable h;
    while(std::getline(fileRead, line))
    {   
        if(entry == indexes[currIndex]) {
            std::istringstream iss(line);
            std::string userId, plainTextPw, encryptedPw, encryptedPwDecrypted;
            iss >> userId >> plainTextPw;

            std::cout << "Userid = " << userId << " Plain Text Pw = " << plainTextPw << std::endl;
            //userId += ",";
            //std::cout << "new user id= " << userId << std::endl;
            encryptedPw = c.Encrypt(plainTextPw);
            int index = h.Lookup(userId);

            if(index != -1){ //Key found
                Node* n = h.Table[index];
                while(n != nullptr)
                {
                    if(n->getUserId() == userId)
                    {
                        std::cout << "Ok!  " << userId << std::endl;
                        
                        if(n->getEncryptedPw() == encryptedPw)
                        {
                            encryptedPwDecrypted = c.Decrypt(n->getEncryptedPw());
                            std::cout << std::setw(20) << userId << std::setw(20) << plainTextPw << std::setw(20) << encryptedPwDecrypted << std::setw(10) << "match" << std::endl;
                        }else{
                            std::cout << std::setw(20) << userId << std::setw(20) << plainTextPw << std::setw(20) << encryptedPwDecrypted << std::setw(10) << "no match" << std::endl;
                        }
                        
                        break;
                    }
                    n = n -> next;
                }
            }

            currIndex++;
            if(currIndex > indexes.size()){
                break;
            }
        }
        entry++;
        if(entry > 9){
            break;
        }
        
    }

    fileRead.close();
}

/*
void Processing::FiveLegal()
{
    std::cout << "Legal:" << std::endl;
    std::cout << std::setw(20) << "Userid" << std::setw(20) << "Password(file)" << std::setw(20) << "Password(table/un)" << std::setw(10) << "Result" << std::endl;
    std::ifstream fileRead("../rawdata.txt");
    std::string line;
    int entry = 1;
    std::vector<int> indexes = {1,3,5,7,9};
    int currIndex = 0;
    Cipher c;
    HashTable h;
    while(std::getline(fileRead, line))
    {
        std::istringstream iss(line);
        std::string userId, plainTextPw, encryptedPw, encryptedPwDecrypted;
        iss >> userId >> plainTextPw;

        encryptedPw = c.Encrypt(plainTextPw);
        int index = h.Lookup(userId);

        if(index != -1)
        {
            Node* n = h.Table[index];
            while(n != nullptr)
            {
                if(n -> getUserId() == userId && n -> getEncryptedPw() == encryptedPw)
                {
                    encryptedPwDecrypted = c.Decrypt(n->getEncryptedPw());
                    std::cout << std::setw(20) << userId << std::setw(20) << plainTextPw << std::setw(20) << encryptedPwDecrypted << std::setw(10) << "match" << std::endl;
                }else{  // index not found
                    std::cout << std::setw(20) << userId << std::setw(20) << plainTextPw << std::setw(20) << encryptedPwDecrypted << std::setw(10) << "no match" << std::endl;
                }   
                break;
            }
            n = n -> next;
        }

    }

    currIndex++;
    if(currIndex > indexes.size())
    {
        break;
    }

    entry++;
    if(entry > 9)
    {
        break;
    }

    fileRead.close();

}
*/
void Processing::FiveIllegal()
{

}