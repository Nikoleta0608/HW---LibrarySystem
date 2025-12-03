#ifndef AUTHOR_H
#define AUTHOR_H

#include <string>

class Аuthor {
private:
    std::string name;
    int birthYear;

public:
    Author() : name("Neizvestno"), birthYear(1900) {}

    Author(const std::string& name, int birthYear)
        : name(name), birthYear(birthYear)
    {
        setBirthYear(birthYear);
    }

    std::string getName() const { return name; }
    int getBirthYear() const { return birthYear; }

    void setBirthYear(int y) {
        if (y < 1850 || y > 2025)
            throw "Nevalidna godina na rajdane";
        birthYear = y;
    }

    std::string to_string() const {
        return "Avtor: " + name + " (" + std::to_string(birthYear) + ")";
    }
};

#endif
