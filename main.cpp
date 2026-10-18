#include <iostream>
#include <string>

#include "library.h" //library will handle search, sort, checkout, returning and adding books
#include "book.h" //book will store info about books (title,author,genre,etc.)

void display_menu() {
	std::cout << "----------LIBRARY MENU----------" << std::endl;
	std::cout << "1 Display all books" << std::endl;
	std::cout << "2 Display available books" << std::endl;
	std::cout << "3 Display books by author" << std::endl;
	std::cout << "4 Display books published on or after a given year" << std::endl;
	std::cout << "5 Sort by page count" << std::endl;
	std::cout << "6 Display a book's details" << std::endl;
	std::cout << "7 Check out a book" << std::endl;
	std::cout << "8 Return a book" << std::endl;
	std::cout << "9 Sort books alphabetically by title" << std::endl;
	std::cout << "10 Quit" << std::endl;
	std::cout << "--------------------------------" << std::endl;
}

void print_empty_line(int num_lines = 1) { //num lines defaults to 1 if no args are provided when called
	for (int i = 0; i < num_lines; i++) {
		std::cout << std::endl;
	}
}

int get_user_menu_choice() {
	std::string input;

	while (true) {
		std::cout << "Enter your choice (Ex. 1): ";
		std::getline(std::cin, input);

		if (input.empty()) {
			std::cout << "Input cannot be empty!" << std::endl;
			continue; //continue stops while loop execution here and restarts from the beginning
		}

		int menu_choice = -1;
		try {
			menu_choice = stoi(input);
		}
		catch (const std::exception&) {
			std::cout << "Invalid input! Enter an integer (Ex. 1)" << std::endl;
			continue;
		}

		return menu_choice;
	}
}

std::string get_user_text_input(std::string prompt = "") {
	std::string input;

	while (true) {
		if (!prompt.empty()) {
			std::cout << prompt;
		}
		else {
			std::cout << "Enter your input: ";
		}
		
		std::getline(std::cin, input);

		if (input.empty()) {
			std::cout << "Input cannot be empty!" << std::endl;
			continue;
		}

		return input;
	}
}

int main() {
	int menu_choice;

	//Start loading books
	library lib;
	std::string filename = "books.csv";
	int count = lib.get_line_count(filename) - 1; //get csv line count; skip header
	
	if (!lib.read_books_from_file(filename, count)) {
		std::cout << "Failed to load books!" << std::endl;
		return -1; //end the program
	}
	std::cout << "Books loaded successfully!" << std::endl;
	print_empty_line();

	while (true) {
		display_menu();
		print_empty_line();
		menu_choice = get_user_menu_choice();

		switch (menu_choice) { //each option should probably have its own function, otherwise this switch statement will be huge
		case 1:
			std::cout << "Displaying all books..." << std::endl;
			lib.display_all_books();
			break;
		case 2:
			std::cout << "Displaying all AVAILABLE books..." << std::endl;
			lib.display_available_books();
			break;
		case 3: {
			std::string author = get_user_text_input("Enter author's name:");
			lib.display_books_by_author(author);
			break;
		}
		case 4: {
			std::string input = get_user_text_input("Enter publication year:");

			try {
				int year = std::stoi(input);
				lib.display_books_by_year(year);
			}
			catch (const std::exception&) {
				std::cout << "Invalid year!" << std::endl;

			}
			break;
		}
		case 5:
			std::cout << "Sorting by page count..." << std::endl;
			lib.sort_books_by_page_count();
			lib.display_all_books();
			break;
		case 6: {
			std::string title = get_user_text_input("Enter book title:");
			lib.display_book_by_title(title);
			break;
		}
		case 7: {
			std::string title = get_user_text_input("Enter book to check out:");

			if (lib.check_out_book(title)) {
				std::cout << "Book checked out successfully!" << std::endl;
			}
			else {
				std::cout << "Book not found or already checked out." << std::endl;
			}
			break;
		}
		case 8: {
			std::string title = get_user_text_input("Enter book to return:");

			if (lib.return_book(title)) {
				std::cout << "Book returned successfully!" << std::endl;
			}
			else {
				std::cout << "Book not found or not checked out." << std::endl;
			}
			break;
		}
		case 9:
			std::cout << "Sorting books alphabetically..." << std::endl;
			lib.sort_books_by_title();
			lib.display_all_books();
			break;

		case 10:
			std::cout << "Quitting..." << std::endl;
			return 0;
		default:
			std::cout << "Invalid menu choice!" << std::endl;
			break;
		}

		print_empty_line();
	}

	return 0;
}