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
	std::cout << "9 Quit" << std::endl;
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
			std::cout << prompt << std::endl;
		}
		std::cout << "Enter your input: ";
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

	while (true) {
		display_menu();
		print_empty_line();
		menu_choice = get_user_menu_choice();

		switch (menu_choice) { //each option should probably have its own function, otherwise this switch statement will be huge
		case 1:
			std::cout << "Displaying all books..." << std::endl;
			break;
		case 2:
			std::cout << "Displaying all AVAILABLE books..." << std::endl;
			break;
		case 3:
			std::cout << "Displaying books by author..." << std::endl; //could eventually add author's name in the display here
			break;
		case 4:
			std::cout << "Displaying books on or after the given year..." << std::endl; //same as above but print year
			break;
		case 5:
			std::cout << "Sorting by page count..." << std::endl;
			break;
		case 6:
			std::cout << "Displaying details..." << std::endl;
			break;
		case 7:
			std::cout << "Checkout book menu..." << std::endl;
			break;
		case 8:
			std::cout << "Return book menu..." << std::endl;
			break;
		case 9:
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