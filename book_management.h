#ifndef BOOK_MANAGEMENT_GUARD__H 
#define BOOK_MANAGEMENT_GUARD__H

#include <stdio.h>

/*You can extend the structs (Book and BookList) defined in this head file;
  However, you may not change the function prototypes. 
  You are also free to add additional head files and data structures as needed. 
*/

typedef struct _Book {
	    unsigned int id; //Book ID
		char *title; //book title
		char *authors; //comma separated list of authors
		unsigned int year; // year of publication
		unsigned int copies; //number of copies the library has
		struct _Book* next; //pointer to the next book element
}Book;

typedef struct _BookList {
	 Book* list; // pointer to a list of struct Book.
	 unsigned int length; // number of elements in the (Book*) List 
}BookList;


//saves the database of books in the specified file
//returns 0 if books were stored correctly, or an error code otherwise
int store_books(FILE *file);

//loads the database of books from the specified file
//the file must have been generated by a previous call to store_books()
//returns 0 if books were loaded correctly, or an error code otherwise
int load_books(FILE *file);

//adds a book to the ones available to the library
//returns 0 if the book could be added, or an error code otherwise
int add_book(Book book);

//removes a book from the library
//returns 0 if the book could be successfully removed, or an error code otherwise.
int remove_book(Book book);

//finds books with a given id
Book* find_book_by_id(unsigned int id);

//finds books with a given title.
//returns a BookList structure, where the field "list" is a list of books, or null if no book with the 
//provided title can be found. The length of the list is also recorded in the returned structure, with 0 in case
//list is the NULL pointer.
BookList find_book_by_title (const char *title);

//finds books with the given authors.
//returns a Booklist structure, where the field "list" is a newly allocated list of books, or null if no book with the 
//provided title can be found. The length of the list is also recorded in the returned structure, with 0 in case
//list is the NULL pointer.
BookList find_book_by_author (const char *author);

//finds books published in the given year.
//returns a Booklist structure, where the field "list" is a list of books, or null if no book with the 
//provided title can be found. The length of the list is also recorded in the returned structure, with 0 in case
//list is the NULL pointer.
BookList find_book_by_year (unsigned int year);


//-----------------------------------------------------------------------------------

typedef struct user
{
    char *name;
    char *password;
    struct user *next;
}user;

//saves the database of readers in the specified file
void store_readers(FILE *file);

//open the file and read the information
void load_users(FILE *file);

//traverse list to find whether the new reader exists
int compare(struct user *head, char *target, int order);

//Borrow a book
void BorrowBook();

//Return a book
void ReturnBook();

//---------------------------------------------------------------------------------------

//desplay the menu
void main_menu();

//menu for librarian
void menu_librarian();

//menu for reader
void menu_reader(user*u);

//Register an account
void Register();

//Log in
void Login();

//Search books
void SearchBooks();

//Display all books
void Display();

//-------------------------------------------------------------------------------------------------
//run all methords
void run();

#endif