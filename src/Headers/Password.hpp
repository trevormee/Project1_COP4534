/***************************************************************
  Student Name: Trevor Mee
  File Name: Password.hpp
  Project 1

 @brief Contains function declarations for reading in a text file,
        generating random passwords, and writing the generated
        generated passwords to a new text file
***************************************************************/

#ifndef PASSWORD_HPP
#define PASSWORD_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <time.h>

class Password
{
    private:
        std::string userId;
        std::string password;
        std::vector<std::vector<std::string>> userIdPasswords;

    public:
        const std::string NAMES_TEXT = "../names.txt";
        const int PASSWORD_LENGTH = 9;
        static const char alphabet[];

        // Read in names.txt
        void ReadFile();

        // Generate random passwords
        std::string GenerateRandomPasswords();

        // Populates the userIdPasswords vector
        void PopulateUserIdPasswords();

        // Write Passwords to "rawdata.txt"
        void WritePasswordsToFile();
};
#endif