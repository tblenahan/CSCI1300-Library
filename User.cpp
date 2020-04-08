/*
CS1300 Spring 2018
Author: Timothy Lenahan
Recitation: 205 - Harshini Muthukrishnan
Cloud Workspace Editor Link: http://ide.c9.io/tblenahan/tl_csci_1300
Hmwk7 - Question #2
*/

#include "User.hpp"
#include <iostream>
using namespace std;

User::User(string nUserName, int userRatings[], int nNumRatings)
{
    userName = nUserName;
    numRatings = nNumRatings;
    for (int i = 0; i < numRatings; i++)
    {
        ratings[i] = userRatings[i];
    }
}

User::User()
{
    userName = "NONE";
    numRatings = 55;
	numRated = 0;
    for (int i = 0; i < numRatings; i++)
    {
        ratings[i] = 0;
    }
}

string User::getName()
{
    return userName;
}

void User::setName(string nName)
{
    userName = nName;
}

// get user's rating at the given index 
int User::getRatingAt(int rIdx)
{
	// if the given index isn't valid return "-1000"
    if (rIdx >= numRatings)
        return -1000;
    
    else
        return ratings[rIdx];
        
}

// sets the rating at a specific index in the user's ratings array
int User::setRatingAt(int rIdx, int rating)
{
	// if the input rating is not valid output a message and return "-1"
    if (rating != -5 && rating != -3 && rating != -1 && rating != 1 && rating != 3 && rating != 5)
    {    
        cout << "Invalid Input!" << endl;
        return -1;
    }
    
    else
    {
		// if the given index is not valid return "-1000"
        if (rIdx >= numRatings)
             return -1000;
        
        else
        {
            ratings[rIdx] = rating;
            cout << "Success!" << endl;
            return 0;
        }
    }
}

int User::getNumRatings()
{
	return numRatings;
}

void User::setNumRatings(int nNumRatings)
{
    numRatings = nNumRatings;
}

// this gets the number of actual ratings that the user has made since "0" indicates no rating
int User::getNumRated()
{
	for(int i = 0; i < numRatings; i++)
	{
		if (ratings[i] != 0)
		{
			numRated++;
		}
	}
	return numRated;
}

void User::setNumRated(int nNumRated)
{
	numRated = nNumRated;
}

