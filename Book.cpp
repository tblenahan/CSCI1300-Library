#include "Book.hpp"
#include <iostream>
using namespace std;

Book::Book(string inAuthor, string inTitle)
{
    title = inTitle;
    author = inAuthor;
}

Book::Book()
{
    title = "NONE";
    author = "NONE";
}

Book::~Book()
{
    // destructor
}

string Book::getTitle()
{
    return title;
}

void Book::setTitle(string nTitle)
{
    title = nTitle;    
}

string Book::getAuthor()
{
    return author;
}

void Book::setAuthor(string nAuthor)
{
    author = nAuthor;
}
