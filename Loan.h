#ifndef LOAN_H
#define LOAN_H

#include <string>

class Loan {
private:
    std::string isbn;
    std::string memberId;
    std::string startDate;
    std::string dueDate;
    bool returned;

public:
    Loan(const std::string& isbn, const std::string& memberId,
         const std::string& start, const std::string& due)
        : isbn(isbn), memberId(memberId), startDate(start), dueDate(due), returned(false)
    {
        if (due < start) throw "Nevalidni dati";
    }

    std::string getIsbn() const { return isbn; }
    std::string getMemberId() const { return memberId; }
    bool isReturned() const { return returned; }

    void markReturned() { returned = true; }

    bool isOverdue(const std::string& today) const {
        return !returned && today > dueDate;
    }

    std::string to_string() const {
        return "Zaem: " + isbn + " -> " + memberId + " [" +
               startDate + " - " + dueDate + "] " +
               (returned ? "returned" : "active");
    }
};

#endif