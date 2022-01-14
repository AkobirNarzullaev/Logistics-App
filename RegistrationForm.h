#ifndef REGISTRATIONFORM_H
#define REGISTRATIONFORM_H
#include "Truck.h" //Implementing Truck header file
#include <algorithm>
using namespace std;
#define LINE "________________________________________"
Registration r;  //Defining Registration class a "r"
fstream reg; //Defining fstream input/output stream as a "reg"
string name, surename, fathername, login, type_of_product, refrigirator, where_from, where_to;
string phone_number;
double mass_of_product;
double checkPlace(string, string);
bool String_numCheck(string);
void writeFile()
{
   system("CLS"); //clears the screen
   reg.open("RegistrationForm", ios::app | ios::out | ios::binary);  //Opening RegistrationForm
   cout << "\n\n\t  --- Please fill Registration Form --- " << endl;
   cout << "\n Enter Name : ";
   cin >> name;
   r.setName(name);  //accessing Registration function and storing value
   cout << "\n\t\t\t\t Enter Surname : ";
   cin >> surename;
   r.setSureName(surename);
   cout << "\n Enter Fathername : ";
   cin >> fathername;
   r.setFatherName(fathername);
   cout << "\n\t\t\t\t Enter password : ";
   cin >> login;
   r.setLogin(login);
   do //Checks the whether it's number or string
   {
     cout << "\n Enter phone number : ";
   cin >> phone_number;
   if(String_numCheck(phone_number))
   {
      r.setPhone_number(phone_number);
   }
   else
   {
      cout<<endl<<endl<<"\t\t"<<phone_number<<" is not a Number! Input number!!!"<<endl;
   } 
   }while(String_numCheck(phone_number)==false);
   
   cout << "\n\t\t\t\t Enter type of Product : ";
   cin >> type_of_product;
   r.setType_of_poduct(type_of_product);
   cout << "\n Enter Where From : ";
   cin >> where_from;
   r.setWhere_from(where_from);
   cout << "\n\t\t\t\t Enter Where To : ";
   cin >> where_to;
   r.setWhere_to(where_to);
   cout << "\n Enter mass of Product : ";
   cin >> mass_of_product;
   r.setMass_of_poduct(mass_of_product);
   cout << "\n\t\t\t\t Enter want to Refrigerator (Yes or No): ";
   cin >> refrigirator;
   r.setRefrigirator(refrigirator);
   bool yes;
   if (refrigirator == "Yes" || refrigirator == "yes")
      yes = true;
   else
      yes = false;
   if (mass_of_product < 7)
   {
      Standart standart(mass_of_product, checkPlace(where_from, where_to), yes);
      r.setMoneyMass(standart.getMonerForMass());
      r.setMoneyDistance(standart.getMoneyForDistance());
      r.setMoneyRef(standart.getMoneyForRefrigirator());
      r.setTotalPrice(standart.getTotalPrice());
   }
   else if (mass_of_product >= 7 && mass_of_product < 12)
   {
      Reliable reliable(mass_of_product, 120, yes);
      r.setMoneyMass(reliable.getMonerForMass());
      r.setMoneyDistance(reliable.getMoneyForDistance());
      r.setMoneyRef(reliable.getMoneyForRefrigirator());
      r.setTotalPrice(reliable.getTotalPrice());
   }
   else if (mass_of_product >= 12)
   {
      Premium premium(mass_of_product, 120, yes);
      r.setMoneyMass(premium.getMonerForMass());
      r.setMoneyDistance(premium.getMoneyForDistance());
      r.setMoneyRef(premium.getMoneyForRefrigirator());
      r.setTotalPrice(premium.getTotalPrice());
   }
   
   reg.write((char *)&r, sizeof(Registration));
   reg.close();
   system("CLS");
   cout << "\n\n\n\n\t\t\t Your Shipping is Successfully Registered.\t"
       << "Find Additional Informations on <<Your Shippping>> page \n\n\n" << endl;
}
void readAllFile()
{
   system("CLS");
   reg.open("RegistrationForm", ios::binary | ios::in);
   while (reg.read((char *)&r, sizeof(Registration)))
   {
      cout << "      --- Details of " << r.getName() << " ---" << endl
           << endl;
      cout << " Name               : " << r.getName() << endl
           << " Surename           : " << r.getSureName() << endl
           << " Fathername         : " << r.getFatherName() << endl
           << " Phone number       : " << r.getPhohe_number() << endl
           << " Type of product    : " << r.getType_of_poduct() << endl
           << " Where from         : " << r.getWhere_from() << endl
           << " Where to           : " << r.getWhere_to() << endl
           << " Mass of Product    : " << r.getMass_of_poduct() << endl
           << " Refrigerator       : " << r.getRefrigirator() << endl
           << " Distance price     : " << r.getMoneyDistance() << endl
           << " Mass price         : " << r.getMoneyMass() << endl
           << " Refrigerator price : " << r.getMoneyRef() << endl
           << " Total price        : " << r.getTotalPrice() << endl
           << endl;
      cout << LINE << endl
           << endl;
   }
   reg.close();
}
void readSearchFile()
{
   system("CLS");
   bool found = false;
   cout << "          --- Search ----         " << endl
        << endl;
   cout << " Enter Login    : ";
   cin >> name;
   cout << " Enter Password : ";
   cin >> login;
   reg.open("RegistrationForm", ios::binary | ios::in);
   while (reg.read((char *)&r, sizeof(Registration)))
   {
      if (r.getName() == name && r.getLogin() == login)
      {
         cout << endl
              << endl;
         cout << "     --- Details of " << r.getName() << " ---" << endl
              << endl;
         cout << " Name               : " << r.getName() << endl
              << " Surename           : " << r.getSureName() << endl
              << " Fathername         : " << r.getFatherName() << endl
              << " Phone number       : " << r.getPhohe_number() << endl
              << " Type of product    : " << r.getType_of_poduct() << endl
              << " Where from         : " << r.getWhere_from() << endl
              << " Where to           : " << r.getWhere_to() << endl
              << " Mass of Product    : " << r.getMass_of_poduct() << endl
              << " Refrigerator       : " << r.getRefrigirator() << endl
              << " Distance price     : " << r.getMoneyDistance() << endl
              << " Mass price         : " << r.getMoneyMass() << endl
              << " Refrigerator price : " << r.getRefrigirator() << endl
              << " Total price        : " << r.getTotalPrice() << endl
              << endl;
         found = true;
      }
   }
   if (found = false)
      cout << " --- Wrong name or login code !!! --- " << endl;
   reg.close();
}

double checkPlace(string from, string to)
{
   string plus;
   bool found = false;
   for_each(from.begin(), from.end(), [](char &c) {
      c = tolower(c);
   });
   for_each(to.begin(), to.end(), [](char &c) {
      c = tolower(c);
   });
   string a[12] = {"andijan", "namangan", "fergana", "tashkent", "syrdarya", "jizzakh", "samarkand", "bukhara", "kashkadarya", "surkhandarya", "navoiy", "kharezm"};
   for (int i = 0; i < 12; i++)
   {
      if(a[i] == from && a[i] == to)
      {
         plus = from + to;
         found = true;
      }
   }
   if (found == false)
   {
      cout << "Not found Data ! " << endl;
      return 0;
   }
   string distance;
   ifstream out;
   out.open(plus + "txt");
   getline(out, distance); //Getline holds the line to Input another values
   string::size_type sz;
   double real_distance = std::stod (distance,&sz);
   out.close(); 
   return real_distance;
}
bool String_numCheck(string str) //string or number checker 
{
    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false)
            return false;
    return true;
}
#endif