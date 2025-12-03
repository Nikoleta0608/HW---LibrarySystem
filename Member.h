#ifndef MEMBER_H
#define MEMBER_H

#include <string>

class Member {
private:
    std::string name;
    std::string memberId;
    int yearJoined;

public:
    Member() : name("Neizvestno"), memberId("Nqma"), yearJoined(2000) {}

    Member(const std::string& name, const std::string& memberId, int yearJoined)
        : name(name), memberId(memberId), yearJoined(yearJoined)
    {
        if (memberId.empty()) throw "Nevaliden member ID";
    }

    std::string getName() const { return name; }
    std::string getMemberId() const { return memberId; }
    int getYearJoined() const { return yearJoined; }

    std::string to_string() const {
        return "Chlen: " + name + " (" + memberId + ")";
    }
};

#endif
