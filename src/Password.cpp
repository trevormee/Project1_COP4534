/** @file Password.cpp
 *  @brief Contains function definitions for reading in a text file,
 *        generating random passwords, and writing the randomly
 *        generated passwords to a new text file
 * 
 * @author Trevor Mee
*/

#include "Headers/Password.hpp"

const char Password::alphabet[] = "abcdefghijklmnopqrstuvwxyz";

/*
    @brief reads in data.txt and extracts last names only
    @param file to read in (data.txt)
    @return none (void)
*/
void Password::ReadFile()
{
    std::ifstream fileRead(NAMES_TEXT);
    std::string line;

    while(std::getline(fileRead, line))
    {
        std::istringstream iss(line);
        iss >> userId;
        userIdPasswords.push_back({userId, ""});
    }
    
    fileRead.close();
}

/*
    @brief generates random passwords for each user ID
           in names.txt
    
    @return randomly generated password
*/
std::string Password::GenerateRandomPasswords()
{
    password.resize(PASSWORD_LENGTH);
    
    //std::srand(time(0));
    for(int i = 0; i < PASSWORD_LENGTH; i++)
    {
         int letter = std::rand() % (sizeof(alphabet) - 1);
         password[i] = alphabet[letter];
    }
    return password;
}

/*
    @brief populates the userIdPasswords vector by extracting the 
           the user's last name and generating a random password for
           said user
*/
void Password::PopulateUserIdPasswords()
{

    for(long unsigned int i = 0; i < userIdPasswords.size(); ++i)
    {
        userIdPasswords[i][1] = GenerateRandomPasswords(); 
    }
}


/*
    @brief writes the userId & randomly generated password combo. to rawdata.txt
*/
void Password::WritePasswordsToFile()
{
    ReadFile();
    PopulateUserIdPasswords();

    std::ofstream outputFile;
    outputFile.open("../rawdata.txt");
  
   for(long unsigned int i = 0; i < userIdPasswords.size(); ++i)
   {
        outputFile << userIdPasswords[i][0] << ", " << userIdPasswords[i][1] << "\n";
   }
  
    outputFile.close();
}