# User's Manual

## Project Overview
The overall goal of this project was to create a user ID and password storage system using an externally chained hash table. First, the project reads in 'names.txt' and generates random passwords for each user ID. The user ID's and randomly generated passwords are then written to 'rawdata.txt'. Next, the project reads in 'rawdata.txt' and encrypts the passwords using the Vigenere Cipher logic. The user ID and encrypted passwords are then written to 'encrypteddata.txt'. Once the user ID and encrypted password pairs are populated in the hash table, the project does a "Five Legal Password" and "Five Illegal Password" check on the hash table to ensure passwords have been succsessfully encrypted and to ensure the hash table does not encounter any collisions.

## How to Compile
The project already has a Makefile to compile all the code for you. 
Simply run the following command from the command line:
```bash
make
```
Once the project has been successfully compiled, run the following command:
```bash
./proj1
```
