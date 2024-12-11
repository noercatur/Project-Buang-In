#include "Driver.h"

Driver::Driver(const std::string& name, const std::string& vehicle, const std::string& status)
  : name(name), vehicle(vehicle), status("idle"){}

std::string Driver::getName() const{
    return name; }
std::string Driver::getVehicle() const{
    return vehicle; }
std::string Driver::getStatus() const{
    return status; }

void Driver::setStatus (const std::string& newStatus) {
    if (newStatus == "Driver kami sedang di jalan!" || newStatus == "Driver kami telah mengambil sampahmu!"){
        status = newStatus;
    } else { status = "invalid status" ;}

}

void Driver::setDestination(const Location& location){
    destination = location; }
Location Driver::getDestination() const {
    return destination; }

