#ifndef BOOK_H
#define BOOK_H

#include <string>
#include "Author.h"

class Book {
private:
    std::string title;
    Author author;
    int year;
    double price;
    std::string isbn;

public:
    static int totalBooks;

    Book()
        : title("Neizvestno"), author(), year(1900), price(0.0), isbn("NEIZVESTNO")
    {
        totalBooks++;
    }

    Book(const std::string& title, const Author& author, int year,
         double price, const std::string& isbn)
        : title(title), author(author), year(year), price(price), isbn(isbn)
    {
        if (year < 1500 || year > 2025) throw "Nevalidna godina";
        if (price < 0) throw "Nevalidna cena";
        if (isbn.empty()) throw "Nevaliden ISBN";
        totalBooks++;
    }

    Book(const Book&) = default;
    Book(Book&&) noexcept = default;
    Book& operator=(const Book&) = default;
    Book& operator=(Book&&) noexcept = default;
    ~Book() = default;

    std::string getTitle() const { return title; }
    Author getAuthor() const { return author; }
    int getYear() const { return year; }
    double getPrice() const { return price; }
    std::string getIsbn() const { return isbn; }

    void setPrice(double p) {
        if (p < 0) throw "Nevalidna cena";
        price = p;
    }

    std::string to_string() const {
        return "Kniga: " + title + " | " + author.getName() + " | " +
               std::to_string(year) + " | " + isbn;
    }

    static int getTotalBooks() { return totalBooks; }
};

int Book::totalBooks = 0;

#endif
