#include <iostream>

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

void get_user_menu_choice() {

}

int main() {
	display_menu();

	return 0;
}