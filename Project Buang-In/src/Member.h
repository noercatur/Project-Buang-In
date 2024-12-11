#ifndef _MEMBER_H
#define _MEMBER_H

#include <string>
#include <ctime>

class Member{
private :
    bool statusSubscription;
    time_t subscriptionStart;
    int durasiSubscription;

public :
    Member();

    bool getstatusSubscription() const;
    std::string getstartSubscriptionDate() const;
    int getsisaHariSubscription() const;

    void startSubscription (int durasiHari);
    void cancelSubscription ();
};

#endif