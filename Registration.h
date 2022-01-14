#ifndef REGISTRATION_H
#define REGISTRATION_H
//Libraries
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <ctype.h>
using namespace std;

class Registration   //Registration Class Diagram
{
private:        //Data members of Registration Class
    string name;
    string surename;
    string fathername;
    string login;
    string phone_number;
    string type_of_product;
    string where_from;
    string where_to;
    double mass_of_product;
    string refrigirator;
    double priceDis;
    double priceMass;
    double priceRef;
    double totalPrice;
public:
    // name
    void setName(string name)
    {
        this->name = name;
    }
    string getName()
    {
        return name;
    }
    // surename
    void setSureName(string surename)
    {
        this->surename = surename;
    }
    string getSureName()
    {
        return surename;
    }
    // father name
    void setFatherName(string fathername)
    {
        this->fathername = fathername;
    }
    string getFatherName()
    {
        return fathername;
    }
    // login
    void setLogin(string login)
    {
        this->login = login;
    }
    string getLogin()
    {
        return login;
    }
    // Phone number
    void setPhone_number(string phone_number)
    {
        this->phone_number = phone_number;
    }
    string getPhohe_number()
    {
        return phone_number;
    }
    // Type of poduct
    void setType_of_poduct(string type_of_product)
    {
        this->type_of_product = type_of_product;
    }
    string getType_of_poduct()
    {
        return type_of_product;
    }
    // Where From
    void setWhere_from(string where_from)
    {
        this->where_from = where_from;
    }
    string getWhere_from()
    {
        return where_from;
    }
    // Where To
    void setWhere_to(string where_to)
    {
        this->where_to = where_to;
    }
    string getWhere_to()
    {
        return where_to;
    }
    // Mass of Product
    void setMass_of_poduct(double mass_of_product)
    {
        this->mass_of_product = mass_of_product;
    }
    double getMass_of_poduct()
    {
        return mass_of_product;
    }
    // Refrigirator
    void setRefrigirator(string refrigirator)
    {
        this->refrigirator = refrigirator;
    }
    string getRefrigirator()
    {
        return refrigirator;
    }
    // Money for Distance 
    void setMoneyDistance(double priceDis)
    {
        this->priceDis = priceDis;
    }
    double getMoneyDistance()
    {
        return priceDis;
    }
    // Money for Mass
    void setMoneyMass(double priceMass)
    {
        this->priceMass = priceMass;
    }
    double getMoneyMass()
    {
        return priceMass;
    }
    // Money for Refrigerator
    void setMoneyRef(double priceRef)
    {
        this->priceRef = priceRef;
    }
    double getMoneyRef()
    {
        return priceRef;
    }
    // Total price 
    void setTotalPrice(double totalPrice)
    {
        this->totalPrice = totalPrice;
    }
    double getTotalPrice()
    {
        return totalPrice;
    }
};
#endif
