#include "book.h"
#include <iostream>
#include <stdexcept>

Genre genre_from_string(const std::string& genre) {
    if (genre == "Humor") return Genre::Humor;
    if (genre == "Mystery") return Genre::Mystery;
    if (genre == "Self-Help") return Genre::SelfHelp;
    if (genre == "Satire") return Genre::Satire;
    if (genre == "Nonfiction") return Genre::Nonfiction;
    if (genre == "Horror") return Genre::Horror;
    if (genre == "Fantasy") return Genre::Fantasy;
    if (genre == "Science Fiction") return Genre::ScienceFiction;
    if (genre == "Romance") return Genre::Romance;
    if (genre == "Cooking") return Genre::Cooking;
    if (genre == "Adventure") return Genre::Adventure;

    throw std::invalid_argument("Unknown book genre: " + genre);
}

std::string genre_to_string(Genre genre) {
    switch (genre) {
    case Genre::Humor: return "Humor";
    case Genre::Mystery: return "Mystery";
    case Genre::SelfHelp: return "Self-Help";
    case Genre::Satire: return "Satire";
    case Genre::Nonfiction: return "Nonfiction";
    case Genre::Horror: return "Horror";
    case Genre::Fantasy: return "Fantasy";
    case Genre::ScienceFiction: return "Science Fiction";
    case Genre::Romance: return "Romance";
    case Genre::Cooking: return "Cooking";
    case Genre::Adventure: return "Adventure";
    }

    throw std::invalid_argument("Invalid genre value");
}

book::book() {
    title = "EMPTY_TITLE";
    author = "EMPTY_AUTHOR";
    genre = Genre::Humor;
    page_count = -1;
    year_published = -1;
    is_checked_out = false;
}

book::book(const std::string& title,
           const std::string& author,
           Genre genre,
           int page_count,
           int year_published,
           bool is_checked_out) {
    if (title.empty()) {
        throw std::invalid_argument("Title cannot be empty!");
    }

    if (author.empty()) {
        throw std::invalid_argument("Author cannot be empty!");
    }

    if (page_count < 1) {
        throw std::invalid_argument("Page count must be at least 1!");
    }

    if (year_published <= 0 || year_published > 2026) {
        throw std::invalid_argument("Invalid publication year!");
    }

    this->title = title;
    this->author = author;
    this->genre = genre;
    this->page_count = page_count;
    this->year_published = year_published;
    this->is_checked_out = is_checked_out;
}

std::string book::get_title() const {
    return title;
}

std::string book::get_author() const {
    return author;
}

Genre book::get_genre() const {
    return genre;
}

int book::get_page_count() const {
    return page_count;
}

int book::get_year_published() const {
    return year_published;
}

bool book::get_is_checked_out() const {
    return is_checked_out;
}

void book::set_is_checked_out(bool is_checked_out) {
    this->is_checked_out = is_checked_out;
}

void book::display_info() const {
    std::cout << "----------BOOK DETAILS----------" << std::endl
        << "Title:          " << title << std::endl
        << "Author:         " << author << std::endl
        << "Genre:          " << genre_to_string(genre) << std::endl
        << "Page Count:     " << page_count << std::endl
        << "Year Published: " << year_published << std::endl
        << "Status:         "
        << (is_checked_out ? "CHECKED OUT" : "AVAILABLE") << std::endl
        << "----------------------------------" << std::endl;
}
