#pragma once
#include <string>

enum class Genre {
    Humor,
    Mystery,
    SelfHelp,
    Satire,
    Nonfiction,
    Horror,
    Fantasy,
    ScienceFiction,
    Romance,
    Cooking,
    Adventure
};

Genre genre_from_string(const std::string& genre);
std::string genre_to_string(Genre genre);

class book {
private:
    std::string title;
    std::string author;
    Genre genre;
    int page_count;
    int year_published;
    bool is_checked_out;

public:
    book();

    book(const std::string& title,
         const std::string& author,
         Genre genre,
         int page_count,
         int year_published,
         bool is_checked_out);

    std::string get_title() const;
    std::string get_author() const;
    Genre get_genre() const;
    int get_page_count() const;
    int get_year_published() const;
    bool get_is_checked_out() const;

    void set_is_checked_out(bool is_checked_out);

    void display_info() const;
};
