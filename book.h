#pragma once
#include <string>

class book {
private:
	std::string title;
	std::string author;
	std::string genre;
	int page_count;
	int year_published;
	bool is_checked_out;
public:
	book();
	book(const std::string& title, const std::string& author, const std::string& genre, int page_count, int year_published, bool is_checked_out);

	//Getters
	std::string get_title() const;
	std::string get_author() const;
	std::string get_genre() const;
	int get_page_count() const;
	int get_year_published() const;
	bool get_is_checked_out() const;

	//Setters
	void set_is_checked_out(bool is_checked_out);
	
	//Utility
	void display_info() const;
};