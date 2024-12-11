#ifndef _PICKUPLOCATION_H
#define _PICKUPLOCATION_H
#include <iostream>
#include <string>

class Location {
private:
    std::string name;
    std::string address;
    std::string city;
    std::string postalCode;

public:
    Location();
    Location(const std::string& addr, const std::string& cty, const std::string& pc);
    Location(const std::string& addr); 
    std::string getAddress() const; 
    std::string getCity() const; 
    std::string getPostalCode() const; 
    std::string getFullAddress() const; 

    void setAddress(const std::string& address); 
    void setCity(const std::string& city); 
    void setPostalCode(const std::string& postalCode); 

    friend std::ostream& operator<<(std::ostream& os, const Location& loc) {
        os << loc.name;
        return os;
};

};

#endif