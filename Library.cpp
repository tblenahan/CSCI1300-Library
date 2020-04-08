/*
CS1300 Spring 2018
Author: Timothy Lenahan
Recitation: 205 - Harshini Muthukrishnan
Cloud Workspace Editor Link: http://ide.c9.io/tblenahan/tl_csci_1300
Hmwk7 - partII
*/

#include "Library.hpp"
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
using namespace std;

int Split(string a_string, char sChar, string words[], int wLength)
{
    
    int wordsEl(0), subStrS(0), numWords(0); // variable initiations and assignments
    
    if(a_string == "") // if the a_string is empty execute the following statement
    
        return 0; // return statement
    
    for (int i = 0; i <= a_string.length(); i++) // for i less than or equal to a_string's length execute the following statetments then increment i
    {
        if (a_string[i] == sChar || a_string[i] == '\0') // if a_string's character i is the seperation character or a_string's character i is the \0 character
        {
            
            words[wordsEl] = a_string.substr(subStrS, (i - subStrS)); // array element assignment and sub string operation
            
            wordsEl++; // variable increment
            
            subStrS = i + 1; // variable assignment
            
            numWords++; // variable increment
            
        }
        
    }
    
    return numWords; // return statement
        
}


// This constructor initiates the Library object with given array of Users and Books
Library::Library(Book nBooks[], int nNumBooks, User nUsers[], int nNumUsers)
{
    numBooks = nNumUsers;
    for (int i = 0; i < numBooks; i++)
    {
        books[i] = nBooks[i];
    }
    numUsers = nNumUsers;
    for (int i = 0; i < numUsers; i++)
    {
        users[i] = nUsers[i];
    }
}

// This default contructor initiates a empty Library
Library::Library()
{
    Book emptyBook;
    books[0] = emptyBook;
    numBooks = 1;
    User emptyUser;
    users[0] = emptyUser;
    numUsers = 1;
}

// given a index for a book in the Library's Books array this returns that book object
Book Library::getBookAt(int bookIdx)
{
    if (bookIdx > numBooks)
    {
        cout << "ERROR!" << endl;
    }
    else
    {
        return books[bookIdx];
    }
}

// given a Book argument and an index in the Library's Books array this adds or replaces the book at that index
string Library::setBookAt(Book addBook, int bookIdx)
{
    if (bookIdx > numBooks)
    {
        return "ERROR!";
    }
    else
    {
        books[bookIdx] = addBook;
        return "SUCCESS!";
    }
}

// This returns the total number of books in the Library
int Library::getNumBooks()
{
    return numBooks;
}

// This sets the number of books the Library has
void Library::setNumBooks(int nNumBooks)
{
    numBooks = nNumBooks;
}

// given an index in the Library's User array this returns the user at that index
User Library::getUserAt(int userIdx)
{
    if (userIdx >= numUsers)
    {
        cout << "ERROR!" << endl;
    }
    else
    {
        return users[userIdx];
    }
}

// given a user object and an index in the Library's User array this replaces a user
string Library::setUserAt(User setUser, int userIdx)
{
    if (userIdx >= numUsers)
    {
        return "ERROR!";
    }
    else
    {
        users[userIdx] = setUser;
        return "SUCCESS!";
    }
}

// given a User object to add this adds a user to the Library's User array
void Library::addUser(User addUser)
{
	// make a variable for the new number of users
    int newNumUsers = getNumUsers() + 1;
	
	// make an array with that has the size to hold total number of users including the new one
    User allUsers[newNumUsers];
	
	// copy original users from Library's user array into new array
    for (int i = 0; i < getNumUsers(); i++)
    {
        allUsers[i] = users[i];
    }
	// add the new user at the end of the new array
    allUsers[getNumUsers()] = addUser;

	// copy the new array into the Library's User array
    for (int i = 0; i < newNumUsers; i++)
    {
        users[i] = allUsers[i];
    }
    
}

// returns total number of users in the Library
int Library::getNumUsers()
{
    return numUsers;
}

// given a number for the number of user updates the number of users in the Library
void Library::setNumUsers(int nNumUsers)
{
    numUsers = nNumUsers;
}

// given a string with the book text file name and the user text file name loads the relavent data for the Library into it's Book and User arrays
void Library::loadData(string booksFile, string usersFile)
{
    ifstream in_file;
    in_file.open(booksFile);
    
    ifstream in_file1;
    in_file1.open(usersFile);
    
    // if one or the other file does not open give error message
	if (!in_file.is_open() || !in_file1.is_open())
    {
        cout << "Launch unsuccessful" << endl;
        cout << "Error! books or ratings could not be found." << endl;
    }
    
    // initialize variable to keep track of number of books in the library
	int curBookNum(0);
    
    // while the end of the books.txt file has not been reached execute the following
	while (!in_file.eof())
    {
        // string variable for each line
		string line;
		// get the next line in the file
        getline(in_file, line);
        
		// if the line is not an empty string execute the following
        if (line != "")
        {

            for (int i = 0; i < line.length(); i++)
            {
                line[i] = tolower(line[i]);
            }

			
			// since the current line is not empty increment the number of books
            curBookNum++;
			// use the class function to set the class object's number of books to the new number 
            setNumBooks(curBookNum);
			// create an array that will split the author and title into two different stirngs
            string splitArray[2];
			// use the split function to split the words
            Split(line, ',', splitArray, 2);
			// create a title string and use substr and the "-1" to make sure no newline characters are included
            string title = splitArray[1].substr(0, splitArray[1].length()-1);
			// make a Book class object to store the info for the book on this line in the file
            Book curBook(splitArray[0], title);
			// add the new book to the Library objects Book object array (ADD TO THE LIBRARY), "-1" since we incremented the book number already
            setBookAt(curBook, (curBookNum-1));
        }
        
    }
    
	// initiate variable to keep track of the current number of users and the number of ratings that user has
    int curUserNum(0), nNumRatings(0);
    
	
	// while the end of the ratings.txt file has not been reached execute the following
    while (!in_file1.eof())
    {
		// iniate a ratings array to keep track of the ratings for the user on this line of the file
        int ratings[70];
        // iniate variable to keep track of the current user's total number of ratings, including "0" which are books they haven't rated
		int numRatings(0);
		// iniate a variable to keep track of the total number of actual ratings for the current user not including "0" which are books they haven't rated
        int actRating(0);
		// iniate string variable to keep track of each line in file
        string line;
		// get the next line in the file
        getline(in_file1, line);
        
        // if the current line is not empty execute the following
        if (line != "")
        {
			
            for (int i = 0; i < line.length(); i++)
            {
                line[i] = tolower(line[i]);
            }

            // since line is not empty increment the number of users
			curUserNum++;
			// use the Library class function to set the total number of users to the new number
            setNumUsers(curUserNum);
            
			// iniate an array variable to split the user's name and all their ratings into two different strings
            string splitArray[2];
			// initiate and array to split string that has all the ratings into strings with the individual ratings
            string splitArray1[70];
			// use split function to split username and ratings
            Split(line, ',', splitArray, 2);
			// use split function to split ratings into individual strings
            Split(splitArray[1], ' ', splitArray1, 70);
			
            for (int i = 0; i <70; i++)
            {
				
                if (splitArray1[i] != "")
                {
                    ratings[numRatings] = stoi(splitArray1[i]);
                    numRatings++;
                }
                    
            }
			//cout << numRatings << endl;
            User curUser(splitArray[0], ratings, numRatings);
            setUserAt(curUser, (curUserNum-1));
        }

        
    }
    
    cout << "Data Loaded successfully!" << endl;
    
    in_file.close();
    in_file1.close();
}

// This function is call whenever the Library is started and the data has loaded successfully
string Library::Login(string name)
{
    string welcome, usersName;
	
	usersName = name;
    
	// if the person using the Library does not enter anything for their name prompt them to try again
    while (usersName == "")
    {
        cout << "You provided an empty user name, Please provide a valid user name to login or register:" << endl;
        cout << "Enter your name again:" << endl;
        getline(cin, usersName);
        
    }
    
    // create a variable which will hold the user's entered name in lowercase so the database which is in lowercase can be searched
	string userToLow = usersName;
    
	// use a for loop to convert the input username to lowercase
    for (int i = 0; i < userToLow.length(); i++)
    {
        userToLow[i] = tolower(userToLow[i]);
    }
    
	// use a for loop to search the database for the user's input name
    for (int i = 0; i < getNumUsers(); i++)
    {
        User compUser = getUserAt(i);
        string curUserName = compUser.getName();
        if (curUserName == userToLow)
        {
			// if the user's name is found welcome them back and return their name terminating the function
            cout << "Welcome back, " << name << endl;
            return userToLow;
        }
    }
    
	// if the user's input name is not found the following will execute
	
	// create a new User object for the new user
    User userToAdd;
    
	// user the lowercase version of the entered name to set the new User object's name
    userToAdd.setName(userToLow);
    
	// add the new User object to the Library
    addUser(userToAdd);
    
    // update the number of users in the Library
    setNumUsers(getNumUsers() + 1);
    
	// welcome the new user to the Library
    cout << "Welcome to the Library, " << usersName << endl;
    
	// return the new user's name
    return userToLow;
}


// this is the main menu of the Library which displays the optional uses of the Library
char Library::menu()
{
    // this variable keeps track of the users input
    char userChoice;
	// this variable keeps track of weather the users input is valid
    bool valid = false;

	// while now valid input is given by the user display the following
    while (valid == false)
    {
        // assume input is valid
		valid = true;
        
        cout << "Would you like to (v)iew your ratings, (r)ate a book, (g)et recommendations, or (q)uit?:" << endl;
        // get input from user
		cin >> userChoice;
        
		// if input is not valid, ignore and clear
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Please input a valid choice" << endl;
            // note that input is not valid
			valid = false;    
        }
		// if input is valid check what the input
        else
        {
			// change input to lowercase so it isn't case sensitive
            userChoice = tolower(userChoice);
            
			// if the input is not one of the given choices ignore and clear
            if (userChoice != 'v' && userChoice != 'r' && userChoice != 'g' && userChoice != 'q')
            {
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Please input a valid choice" << endl;
                valid = false;  
            }
            else
            {
				// if the input is valid return it
                return userChoice;
            }
        }
    }
}


// this displays the users ratings for all the books they have rated (aka all the books that do not have a rating of "0")
void Library::viewRatings(string curUserName)
{
    // Book variable to keep track of rated books
	Book curBook;
	// User variable to keep track of current user when found in database
    User curUser;
	
	// int variable to count the number of books rated by the current user
    int counter(0);
    
	// for loop to find the user by comparing the string parameter to the names in the Library's user array
    for (int i = 0; i < getNumUsers(); i++)
    {
        User compUser = getUserAt(i);
        string compName = compUser.getName();
        if (curUserName == compName)
        {
            curUser = compUser;
			// once user is found in database break out of loop
            break;
        }
    }
    
	// a for loop to find the number of books the current user has actuall rated (aka that don't have a rating of "0")
    for (int i = 0; i < curUser.getNumRatings(); i++)
    {
        if (curUser.getRatingAt(i) != 0)
        {
            // count the number of rated books
			counter++;
        }
    } 
    
	// if count is "0" let the user know they haven't rated any books
    if ( counter == 0)
    {
        cout << "You have not rated any books as yet:" << endl;
    }
	// otherwise show a list of the books they rated by itirating through the current user's ratings and using the index for actual ratings to find the corresponding book authors and titles 
    else
    {
        counter = 0;
        cout << "Here are the books that you have rated:" << endl;
        for (int i = 0; i < curUser.getNumRatings(); i++)
        {
            if (curUser.getRatingAt(i) != 0)
            {
                curBook = getBookAt(i);
                cout << "Title : " << curBook.getTitle() << endl;
                cout << "Rating : " << curUser.getRatingAt(i) << endl;
                cout << "------------------------------" << endl;
                counter++;
            }
        } 
    
    }
}

// this function allow the current user to rate a book in the Library
void Library::rateBook(string curUserName)
{
    // clear passed cin input
	cin.clear();
    cin.ignore(100, '\n');
	
	// boolean variable to keep track if a book was found
    bool found = false;
	
	// string variable to keep track of user input
    string bookToRate, userInput;
	
	// create a user object for the current user
    User curUser;
	
	// int for the Library object's user array index
    int userIdx(0);
    
	// prompt user for the book they would like to rate
    cout << "Enter the name of the book that you would like to rate:" << endl;
	// get input
    std::getline(cin, bookToRate);
    
	// set userInput to actual input
    userInput = bookToRate;
	
	
	// search for the index of the current username in the Library's user array, if it is already in database
    for (int i = 0; i < getNumUsers(); i++)
    {
        User compUser = getUserAt(i);
        string compName = compUser.getName();
        if (curUserName == compName)
        {
			// if user is in the database assign the index to userIndex variable
            userIdx = i;
            curUser = compUser;
            break;
        }
    }
    
	// use a for loop to convert the input book title to lowercase so we can search database which is in lowercase
    for (int i = 0; i < bookToRate.length(); i++)
    {
        bookToRate[i] = tolower(bookToRate[i]);
    }
    
	// make int variable to iterate through books in library
    int i = 0;
    
	// while "i" is less then the total number of books in the library do the following
    while (i < getNumBooks())
    {
		// assign a comparison book variable to the current book at index "i" in the Library's books array
        Book compBook = getBookAt(i);
		
		// assign the title of the current book in the Library's books array to the curTitle variable
        string curTitle = compBook.getTitle();
		
		// if the curTitle of the compBook is the same as the title the user input do the following
        if (curTitle == bookToRate)
        {
			
            string rating;
			// prompt user for their rating of this book
            cout << "Enter your rating of the book (-5, -3, -1, 1, 3, 5):" << endl;
			// get input
            getline(cin, rating);
			
			// for the new or already existing user set the rating in their ratings array to the new rating for this book at the corresponding index
            int valid = curUser.setRatingAt(i, std::stoi(rating));
			
			if(valid == 0)
			{
				// inform user that the rating for the book they input has been updated in their ratings
            	cout << "Thank-you. The rating for the book titled " << userInput << " has been updated to " << rating << endl;
			}
			else
			{
				cout << "Sorry that rating doesn't work." << endl;
			}
			
			// set boolean variable to true so that it is noted that the book has been found
            found = true;
			
			// break out of while loop
            break;
        }
		
		// increment incrementor
        i++;
    }
    
    curUser.setNumRated(curUser.getNumRated()+1);
	
	// add user back to database with updated ratings
    setUserAt(curUser, userIdx);
    
    // for (int i = 0; i < getUserAt(userIdx).getNumRatings(); i++)
//     {
//         cout << getUserAt(userIdx).getRatingAt(i) << endl;
//     }
    
    if (found == false)
    {
        cout << "The book you requested does not exist in the database" << endl;
    }
}


// this function finds the user in the database who has the user with the most similar ratings to the current user and recommends books to the current user based on what other book the most similar user likes up to ten books
void Library::getRecommendations(string curUserName)
{
	// user variable to keep track of the current user and the user who best matches the current user
    User curUser, bestUserMatch, compUser;
	
	//  int variable that keep track of the best similarity score, the next similarity score that is found, 
    int bestSSD(0), newSSD(0), bestMatchIdx(0), counter(0), curUserIdx(0);
    
	// for loop to find the user in the Library's User array
    for (int i = 0; i < getNumUsers(); i++)
    {
        User compUser = getUserAt(i);
        string compName = compUser.getName();
        if (curUserName == compName)
        {
            curUserIdx = i;
            curUser = compUser;
			// once the user is found break out of the for loope
            break;
        }
    }
    
	// check whether the current user's index in the Library's User array if it's not set the counter that iterates through users to 1 and the first user that is compared is the first user in the Library's User array otherwise set the counter to two and compare to the second user in the Library's User array
    if (0 != curUserIdx)
    {
        compUser = getUserAt(0);
        counter = 1;
    }
    else
    {
         compUser = getUserAt(1);
         counter = 2;
    }
    
	// int to keep track of current rating that is being compared
    int idx = 0;
	// while loop to iterate through each of the ratings of each user that is being compared
    while (idx < getNumBooks())
    {
		// the total comparison score is found by totalling up the difference between each user and the current user's ratings for each book and squaring each of these differences (lower the score the better... means their is less dirrence between their ratings)
        bestSSD += pow((curUser.getRatingAt(idx) - compUser.getRatingAt(idx)), 2);
        idx++;
    }
    
	// use while loop to iterate through each user in the Library's User array and get their comparison scores compared to the current user
    while (counter < getNumUsers())
    {
        int idx(0);
        int userIdx = counter;
		
		// this is what keeps track of the current comparison score
        newSSD = 0;
		
		// this keeps track of the user that is being compared to the current user
        User compUser = getUserAt(userIdx);
        
		// this check to make sure the user that is being compared isn't the current user
		if (counter == curUserIdx)
        {
            counter++;
        }
        else
        {
			// use while loop to iterate through the ratings of the current user and the user being compared and sum up the comparison score
            while (idx < curUser.getNumRatings())
            {
                newSSD += pow((curUser.getRatingAt(idx) - compUser.getRatingAt(idx)), 2);
                idx++;
            }
			// check whether the comparison score that was found is less than the original comparison score
            if (newSSD < bestSSD)
            {
                bestSSD = newSSD;
				// if the the comparison score is lower update the index for the best matching user in the Library's User array
                bestMatchIdx = userIdx;
            }
            counter++;
        }
    }
    
    counter = 0;
	// once the while loop to find the best matching user's index is complete use the index to get the best matching user
    bestUserMatch = getUserAt(bestMatchIdx);
    
	// use for loop to iterate through all the rating by the best matching user and see if there are recommendations
    for (int i = 0; i < getNumBooks(); i++)
    {
		// first check if the current user's rating is 0 at for this book
        if (curUser.getRatingAt(i) == 0)
        {
			// if the current user's rating is 0 check if the best matching user's rating is 3 or 5
            if (bestUserMatch.getRatingAt(i) == 3 || bestUserMatch.getRatingAt(i) == 5)
            {
				// if best matching user's rating is 3 or 5 increment counter
                counter++;
            }
        }
		// if counter ever reaches 10 break out of while loop
        if (counter == 10)
        {
            break;
        }
    }
	// if counter equals 0 let the current user know there are no recommendations
    if (counter == 0)
    {
        cout << "There are no recommendations for you at present" << endl;
    }
	// if the counter is NOT 0 show the user the books for the corresponding ratings that the current user had as 0 and the best matching had as 3 or 5
    else
    {
        cout << "Here are some of the books that we think you would like" << endl;
        counter = 0;
        for (int i = 0; i < getNumBooks(); i++)
        {
            Book curBook = getBookAt(i);
            if (curUser.getRatingAt(i) == 0)
            {
                if (bestUserMatch.getRatingAt(i) == 3 || bestUserMatch.getRatingAt(i) == 5)
                {
					// use the index for the ratings that the current user had rated as 0 and the best matching had rated as 3 or 5 to find the corresponding book titles and authors
                    cout << curBook.getTitle() << " by " << curBook.getAuthor() << endl;
                    counter++;
                }
            }
			// if the counter ever reaches 10 indicating that 10 books have been recommended stop recommending books
            if (counter == 10)
            {
                break;
            }
        }
    }
}

// this terminates the program and writes the relevant data back to the text file with usernames and ratings
void Library::quit()
{
	// open the file to write to
    ofstream out_file;
    out_file.open("ratings.txt");
    
	// if the file to be written to can't be opened notify user
    if (out_file.fail())
    {
        cout << "Could not save data" << endl;
    }
    
	// string variable that will keep track of what is written to each line
    string outString;
    
	// for loop to get relevant data from each user in the Library's User array and put it in the string variable to write it on a line in the out file
    for (int i = 0; i < getNumUsers(); i++)
    {
        User curUser = getUserAt(i);
		// add username and comma to the string
        string outString = curUser.getName() + ",";
		// use a for loop to add all the ratings from this user's Ratings array to the sttring
        for (int i = 0; i < curUser.getNumRatings(); i++)
        {
            string str = to_string(curUser.getRatingAt(i));
            outString = outString + str + " ";    
        }
		// write the string to the out file
        out_file << outString << endl;
    }
    
	// close the out file
	out_file.close();
	
	// let the user know that the data was saved successfully
    cout << "Data successfully saved. Goodbye!" << endl;
}
