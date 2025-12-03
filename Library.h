#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <string>
#include "Book.h"
#include "Member.h"
#include "Loan.h"

class Library {
private:
    std::vector<Book> books;
    std::vector<Member> members;
    std::vector<Loan> loans;

public:
    void addBook(const Book& b) { books.push_back(b); }

    void addMember(const Member& m) { members.push_back(m); }

    bool hasBook(const std::string& isbn) const {
        for (const auto& b : books)
            if (b.getIsbn() == isbn) return true;
        return false;
    }

    bool isBookAvailable(const std::string& isbn) const {
        for (const auto& ln : loans)
            if (ln.getIsbn() == isbn && !ln.isReturned())
                return false;
        return true;
    }

    bool loanBook(const std::string& isbn, const std::string& memberId,
                  const std::string& start, const std::string& due)
    {
        if (!hasBook(isbn)) return false;
        if (!isBookAvailable(isbn)) return false;

        bool memberExists = false;
        for (const auto& m : members)
            if (m.getMemberId() == memberId)
                memberExists = true;

        if (!memberExists) return false;

        loans.emplace_back(isbn, memberId, start, due);
        return true;
    }

    bool returnBook(const std::string& isbn, const std::string& memberId) {
        for (auto& ln : loans)
            if (ln.getIsbn() == isbn && ln.getMemberId() == memberId && !ln.isReturned()) {
                ln.markReturned();
                return true;
            }
        return false;
    }

    std::vector<Book> findByAuthor(const std::string& authorName) const {
        std::vector<Book> result;
        for (const auto& b : books)
            if (b.getAuthor().getName().find(authorName) != std::string::npos)
                result.push_back(b);
        return result;
    }

    std::string to_string() const {
        int active = 0;
        for (const auto& ln : loans)
            if (!ln.isReturned()) active++;

        return "Biblioteka: " + std::to_string(books.size()) + " knigi, " +
               std::to_string(members.size()) + " chlenove, " +
               std::to_string(active) + " active loans.";
    }
};

#endif
