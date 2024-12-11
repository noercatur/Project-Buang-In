#ifndef _DRIVER_H
#define _DRIVER_H
#include <string>
#include "PickupLocation.h"

class Driver {
private: 
    std::string name;
    std::string vehicle;
    std::string status;
    Location destination;
public: 
    Driver(const std::string& name, const std::string& vehicle, const std::string& status);

    std::string getName() const;
    std::string getVehicle() const;
    std::string getStatus() const;

    void setStatus(const std::string& newStatus);
    void setDestination(const Location& location);
    Location getDestination() const;

};

#endif