/*
CS1300 Spring 2018
Author: Timothy Lenahan
Recitation: 205 - Harshini Muthukrishnan
Cloud Workspace Editor Link: http://ide.c9.io/tblenahan/tl_csci_1300
Hmwk7 - Question #2
*/

#ifndef USER_HPP
#define USER_HPP
#include <string>

class User
{
    private:
        std::string userName;
        int ratings[55];
        int numRatings;
		int numRated;
        
    public:
        User(std::string nUserName, int nRatings[], int nNumRatings);
        User();
        std::string getName();
        void setName(std::string);
        int getRatingAt(int);
        int setRatingAt(int, int);
        int getNumRatings();
        void setNumRatings(int);
		int getNumRated();
		void setNumRated(int);
};
#endif
