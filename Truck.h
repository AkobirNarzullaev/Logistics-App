#ifndef TRUCK_H
#define TRUCK_H
#include "Registration.h"
using namespace std;

class Truck
{
protected:   //Data members
    double mass;
    double distance;
    bool refrigirator = false;
public:
    Truck(double mass, double distance, bool refrigirator) //Parametric Constructor
    {
        this->mass = mass;
        this->distance = distance;
        this->refrigirator = refrigirator;
    }
      //Pure virtual functions
    virtual double getMoneyForDistance() = 0;
    virtual double getMonerForMass() = 0;
    virtual double getMoneyForRefrigirator() = 0;
    virtual double getTotalPrice() = 0;
};

//Derived Standart class inheriting from Base Truck class
class Standart : public Truck 
{
public:
    Standart(double mass, double distanc, bool refrigirator) : Truck(mass, distanc, refrigirator) {}
    double getMoneyForDistance() override
    {
        return distance * 0.25;
    }
    double getMonerForMass() override
    {
        return mass * 20;
    }
    double getMoneyForRefrigirator() override
    {
        if (refrigirator == true)
        {
            return 20;
        }
        else if (refrigirator == false)
            return 0;
    }
    double getTotalPrice()
    {
        return getMoneyForDistance() + getMonerForMass() + getMoneyForRefrigirator();
    }
};

//Derived Reliable class inheriting from Base Truck class
class Reliable : public Truck
{
public:
    Reliable(double mass, double distanc, bool refrigirator) : Truck(mass, distanc, refrigirator) {}
    double getMoneyForDistance() override
    {
        return distance * 0.35;
    }
    double getMonerForMass() override
    {
        return mass * 30;
    }
    double getMoneyForRefrigirator() override
    {
        if (refrigirator == true)
        {
            return 30;
        }
        else if (refrigirator == false)
            return 0;
    }
    double getTotalPrice()
    {
        return getMoneyForDistance() + getMonerForMass() + getMoneyForRefrigirator();
    }
};

//Derived Premium class inheriting from Base Truck class
class Premium : public Truck
{
public:
    Premium(double mass, double distanc, bool refrigirator) : Truck(mass, distanc, refrigirator) {}
    double getMoneyForDistance() override
    {
        return distance * 0.45;
    }
    double getMonerForMass() override
    {
        return mass * 40;
    }
    double getMoneyForRefrigirator() override
    {
        if (refrigirator == true)
        {
            return 40;
        }
        else if (refrigirator == false)
            return 0;
    }
    double getTotalPrice()
    {
        return getMoneyForDistance() + getMonerForMass() + getMoneyForRefrigirator();
    }
};
#endif