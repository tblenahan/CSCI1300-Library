/*
CS1300 Spring 2018
Author: Timothy Lenahan
Recitation: 205 - Harshini Muthukrishnan
Cloud Workspace Editor Link: http://ide.c9.io/tblenahan/tl_csci_1300
Hmwk7 - Question #1
*/

#ifndef BOOK_HPP
#define BOOK_HPP
#include <string>
using namespace std;

class Book
{
    private:
        std::string title;
        std::string author;
        
    public:
        Book(std::string inTitle, std::string inAuthor);
        Book();
        ~Book();
        std::string getTitle();
        void setTitle(std::string);
        std::string getAuthor();
        void setAuthor(std::string);
};
#endif