#include "Member.h"
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>

Member::Member() : statusSubscription(false), subscriptionStart(0), durasiSubscription(0){}

bool Member::getstatusSubscription() const{
    return statusSubscription; }

std::string Member::getstartSubscriptionDate() const{
    if (!statusSubscription) return "Anda tidak berlangganan.";

    char buffer[20];
    struct tm* timeinfo = localtime (&subscriptionStart);
    strftime(buffer, sizeof(buffer), "%d-%m-%y", timeinfo);
    return std::string(buffer);
}

int Member::getsisaHariSubscription() const{
    if (!statusSubscription) return 0;

    time_t now = time(nullptr);
    double detikBerlalu = difftime(now, subscriptionStart);
    int hariBerlalu = static_cast<int>(detikBerlalu / (60 * 60 * 24));
    int sisahariSubscription = durasiSubscription - hariBerlalu;

    return (sisahariSubscription > 0) ? sisahariSubscription: 0;
}

void Member::startSubscription(int durasiHari){
    statusSubscription = true;
    subscriptionStart = time(nullptr);
    durasiSubscription = durasiHari;
}

void Member::cancelSubscription() {
    statusSubscription = false;
    subscriptionStart = 0;
    durasiSubscription = 0;
}
 