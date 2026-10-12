#include "library.h"
#include <iostream>
#include <fstream>

int library::get_line_count(const std::string& path)
{
    std::ifstream file;
    file.open(path);

    int count = 0;

    if (file.is_open()) {
        std::string current_line;

        while (std::getline(file, current_line)) {
            count++;
        }

        file.close();
    }

    return count;
}

bool library::read_books_from_file(const std::string& filename, int count) {
    std::ifstream file;

    file.open(filename);

    if (!file.is_open()) {
        std::cout << "Error opening file!" << std::endl;
        return false;
    }

    //Begin file parsing
    std::string current_line;
    if (!std::getline(file, current_line) || current_line.empty() || count <= 0) {
        std::cout << "CSV file is empty or invalid!" << std::endl;
        return false;
    }
    
    for (int i = 0; i < count; i++) {
        //Title
        if (!std::getline(file, current_line, ',')) {
            std::cout << "Error reading title in CSV file!" << std::endl;
            return false;
        }
        std::string title = current_line;

        //Author
        if (!std::getline(file, current_line, ',')) {
            std::cout << "Error reading author in CSV file!" << std::endl;
            return false;
        }
        std::string author = current_line;

        //Genre
        if (!std::getline(file, current_line, ',')) {
            std::cout << "Error reading genre in CSV file!" << std::endl;
            return false;
        }
        std::string genre = current_line;

        //Page count
        if (!std::getline(file, current_line, ',')) {
            std::cout << "Error reading page count in CSV!" << std::endl;
            return false;
        }
        int page_count = 0;
        try {
            page_count = stoi(current_line);
        }
        catch (const std::exception&) {
            std::cout << "Invalid page count in CSV!" << std::endl;
            return false;
        }

        //Year published
        if (!std::getline(file, current_line, ',')) {
            std::cout << "Error reading published year in CSV!" << std::endl;
            return false;
        }
        int year_published = 0;
        try {
            year_published = stoi(current_line);
        }
        catch (const std::exception&) {
            std::cout << "Invalid published year in CSV!" << std::endl;
            return false;
        }

        //Checkout status
        if (!std::getline(file, current_line)) {
            std::cout << "Error reading checkout status in CSV!" << std::endl;
            return false;
        }
        int checkout_status = 0;
        try {
            checkout_status = std::stoi(current_line);
        }
        catch (const std::exception&) {
            std::cout << "Invalid checkout status in CSV!" << std::endl;
            return false;
        }

        if (checkout_status != 1 && checkout_status != 0) {
            std::cout << "Checkout status must be a 1 or 0 in CSV!" << std::endl;
            return false;
        }

        //Load current line's info into a book object inside of the books vector
        try {
            books.push_back(book(title, author, genre, page_count, year_published, checkout_status)); //compiler will autoconvert checkout_status int to a bool (we already validated it is 1 or 0)
        }
        catch (const std::exception&) {
            std::cout << "Invalid book data!" << std::endl;
            return false;
        }
    }

    file.close();
    return true;
}

void library::display_all_books() const {
    //range-based for loop (don't have to deal with indexes or passing length)
    for (const book& current_book : books) { //for each const book (reference) current book in books vector...
        current_book.display_info();
    }
}