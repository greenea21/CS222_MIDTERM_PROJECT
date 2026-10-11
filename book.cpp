#include "book.h"
#include <string>
#include <iostream>

book::book() {
	title = "EMPTY_TITLE";
	author = "EMPTY_AUTHOR";
	genre = "EMPTY_GENRE";
	page_count = -1;
	year_published = -1;
	is_checked_out = false;
}

book::book(const std::string& title, const std::string& author, const std::string& genre, int page_count, int year_published, bool is_checked_out) {
	if (title.empty()) {
		throw std::exception("Title cannot be empty!");
	}
	this->title = title;

	if (author.empty()) {
		throw std::exception("Author cannot be empty!");
	}
	this->author = author;

	if (genre.empty()) {
		throw std::exception("Genre cannot be empty!");
	}
	this->genre = genre;

	if (page_count < 1) {
		throw std::exception("Page count cannot be less than 1!");
	}
	this->page_count = page_count;

	if (year_published <= 0 || year_published > 2026) { //hardcoded year is a bad idea but nobody is going to use this program
		throw std::exception("Invalid publication year!");
	}
	this->year_published = year_published;

	this->is_checked_out = is_checked_out;
}

std::string book::get_title() const {
	return title;
}

std::string book::get_author() const {
	return author;
}

std::string book::get_genre() const {
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
		<< "Genre:          " << genre << std::endl
		<< "Page Count:     " << page_count << std::endl
		<< "Year Published: " << year_published << std::endl
		<< "Status:         "
		<< (is_checked_out ? "CHECKED OUT" : "AVAILABLE") << std::endl //value of is_checked_out is evaluated; if true it returns the first string (checked out), if false it returns the second.
		<< "----------------------------------" << std::endl;
}