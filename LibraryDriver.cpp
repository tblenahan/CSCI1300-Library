/*
CS1300 Spring 2018
Author: Timothy Lenahan
Recitation: 205 - Harshini Muthukrishnan
Cloud Workspace Editor Link: http://ide.c9.io/tblenahan/tl_csci_1300
Hmwk7 - Main
*/

#include <iostream>
#include "Library.hpp"
using namespace std;

int main()
{
	// strings to keep track of the user input and the current user's name
    string inputUserName, curUserName;
   	
	// construct the Library
    Library theLibrary;
    
	// load data to Library
    theLibrary.loadData("books.txt", "ratings.txt");
    
	// welcom message and prompt
    cout << "Welcome to the Library, What is your name?:" << endl;
	
	// get name of the current user
    getline(cin, inputUserName);
	
	// login the current user by seeing if they are in the database or adding them
    curUserName = theLibrary.Login(inputUserName);
    
    
    // boolean variable keep track if current user quit program or not
    bool notDone = true;
	
	// character to keep track user's choice in the menu
    char choice;
    
    while (notDone)
    {
		// get user's choice from menu function
        choice = theLibrary.menu();
        
		// based on user's choice execute one of the following funtions until the choose to quit
        if (choice == 'v')
        {
            theLibrary.viewRatings(curUserName);
        }
        else if (choice == 'r')
        {
            theLibrary.rateBook(curUserName);
        }
        else if (choice == 'g')
        {
            theLibrary.getRecommendations(curUserName);
        }
        else if (choice == 'q')
        {
            theLibrary.quit();
            notDone = false;
        }
    }
    
    return 0;
}

