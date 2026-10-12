#pragma once
#include <string>
#include <vector>
#include "book.h"

class library {
private:
	std::vector<book> books; //contains book objects (basically a built-in dynamic array)
public:
	//Load books from file
	int get_line_count(const std::string& path);
	bool read_books_from_file(const std::string& filename, int count); //returns true if books were loaded, false if they were not. also loads books into the vector
															//will have to handle malicious input for MVP 6 and 7 (six seveeeeeen)
															//If file is missing, reject file and return false
															//If any data is bad/missing, reject file and return false
															//probably should just end the program if bad data is contained in csv

	//Menu display
	void display_all_books() const;
	void display_available_books() const;
	void display_books_by_author(const std::string& author) const;
	void display_books_by_year(int year) const;
	void display_book_by_title(const std::string& title) const;

	//Sort
	void sort_books_by_page_count(); //built in sort function (std::sort) for stretch goal 6

	//Checkout and return; will return true if successfully checked in/out; false if otherwise
	bool check_out_book(const std::string& title);
	bool return_book(const std::string& title);

	//Stretch goal stuff
	void sort_books_by_title();
	void donate_book(const book& new_book); //add a new book object to the book vector; user will input the details/info
};