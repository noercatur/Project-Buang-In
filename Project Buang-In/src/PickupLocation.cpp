#include "PickupLocation.h"

Location::Location() : address(""), city(""), postalCode("") {} 

Location::Location(const std::string& addr, const std::string& cty, const std::string& pc)
    : address(addr), city(cty), postalCode(pc) {}

Location::Location(const std::string& addr) : address(addr), city(""), postalCode("") {}

std::string Location::getAddress() const {
    return address; 
}

std::string Location::getCity() const {
    return city; 
}

std::string Location::getPostalCode() const { 
    return postalCode;
}

std::string Location::getFullAddress() const { 
    return address + ", " + city + ", " + postalCode;
}

void Location::setAddress(const std::string& address) { 
    this->address = address;
}

void Location::setCity(const std::string& city) { 
    this->city = city;
}

void Location::setPostalCode(const std::string& postalCode) { 
    this->postalCode = postalCode;
}