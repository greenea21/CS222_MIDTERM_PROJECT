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
    void library::display_available_books() const {
        bool found = false;

        for (const book& current_book : books) {
            if (!current_book.get_is_checked_out()) {
                current_book.display_info();
                found = true;
            }
        }

        if (!found) {
            std::cout << "No available books found." << std::endl;
        }
    }
    void library::display_books_by_author(const std::string& author) const {
        bool found = false;

        for (const book& current_book : books) {
            if (current_book.get_author() == author) {
                current_book.display_info();
                found = true;
            }
        }

        if (!found) {
            std::cout << "No books found by that author." << std::endl;
        }
    }
    void library::display_books_by_year(int year) const {
        bool found = false;

        for (const book& current_book : books) {
            if (current_book.get_year_published() >= year) {
                current_book.display_info();
                found = true;
            }
        }

        if (!found) {
            std::cout << "No books found for that year." << std::endl;
        }
    }
    void library::sort_books_by_page_count() {
        for (int i = 0; i < books.size() - 1; i++) {
            int min_index = i;

            for (int j = i + 1; j < books.size(); j++) {
                if (books[j].get_page_count() < books[min_index].get_page_count()) {
                    min_index = j;
                }
            }

            book temp = books[i];
            books[i] = books[min_index];
            books[min_index] = temp;
        }
    }
    void library::display_book_by_title(const std::string& title) const {
        bool found = false;

        for (const book& current_book : books) {
            if (current_book.get_title() == title) {
                current_book.display_info();
                found = true;
            }
        }

        if (!found) {
            std::cout << "No book found with that title." << std::endl;
        }
    }
    bool library::check_out_book(const std::string& title) {
        for (book& current_book : books) {
            if (current_book.get_title() == title) {
                if (current_book.get_is_checked_out()) {
                    return false;
                }

                current_book.set_is_checked_out(true);
                return true;
            }
        }

        return false;
    }
    bool library::return_book(const std::string& title) {
        for (book& current_book : books) {
            if (current_book.get_title() == title) {
                if (!current_book.get_is_checked_out()) {
                    return false;
                }

                current_book.set_is_checked_out(false);
                return true;
            }
        }

        return false;
    }
    void library::sort_books_by_title() {
        if (books.size() < 2) {
            return;
        }

        for (int i = 0; i < static_cast<int>(books.size()) - 1; i++) {
            int min_index = i;

            for (int j = i + 1; j < static_cast<int>(books.size()); j++) {
                if (books[j].get_title() < books[min_index].get_title()) {
                    min_index = j;
                }
            }

            book temp = books[i];
            books[i] = books[min_index];
            books[min_index] = temp;
        }
    }

