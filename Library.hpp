/*
CS1300 Spring 2018
Author: Timothy Lenahan
Recitation: 205 - Harshini Muthukrishnan
Cloud Workspace Editor Link: http://ide.c9.io/tblenahan/tl_csci_1300
Hmwk7 - partII
*/

#ifndef LIBRARY_HPP
#define LIBRARY_HPP
#include "Book.hpp"
#include "User.hpp"
using namespace std;

class Library
{
    private:
        Book books[60];
        int numBooks;
        User users[100];
        int numUsers;
        
    public:
        Library(Book nBooks[], int nNumBooks, User nUsers[], int nNumUsers);
        Library();
        Book getBookAt(int bookIdx);
        string setBookAt(Book addBook, int bookIdx);
        int getNumBooks();
        void setNumBooks(int nNumBooks);
        User getUserAt(int userIdx);
        string setUserAt(User setUser, int userIdx);
        void addUser(User addUser);
        int getNumUsers();
        void setNumUsers(int nNumUsers);
        void loadData(string booksFile, string usersFile);
        string Login(string name);
        char menu();
        void viewRatings(string curUserName);
        void rateBook(string curUserName);
        void getRecommendations(string curUserName);
        void quit();
        
};
#endif


