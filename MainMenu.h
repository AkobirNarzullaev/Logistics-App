#ifndef MAINMENU_H
#define MAINMENU_H
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <ctype.h>
#include "SecondMainMenu.h"
#include "AboutTruck.h"

using namespace std;
void goXY(int x, int y)
{
    CursorPosition.X = x;                              // Locates column
    CursorPosition.Y = y;                              // Locates Row
    SetConsoleCursorPosition(console, CursorPosition); // Sets position for next thing to be printed
}
void mainMenu()
{
    int selection;
    do
    {
        system("CLS");
        system("COLOR 0");
        char a[] = "  ---- Logistics Transportation Menu ----";
        cout << endl << endl;
             
        for (int i = 0; i < strlen(a); i++)
        {
            Sleep(30);
            cout << a[i];
        }
        Sleep(0);
        cout << "\n                                       \n"
             << "             1. Send goods               \n"
             << "             2. Your shipping            \n"
             << "             3. Shipping Info            \n"
             << "             4. About                    \n"
             << "             5. Exit                     \n"
             << "                                         \n";
        for (int i = 0; i < 1; i++)
        {
            int x = 1;
            int y = 10;
            for (y = 3; y <= 9; y++)
            {
                goXY(x, y);
                cout << "|";
                Sleep(40);
            }
            for (x = 2; x <= 40; x++)
            {
                goXY(x, y);
                cout << "-";
                Sleep(30);
            }
            for (y = 9; y >= 3; y--)
            {
                x = 41;
                goXY(x, y);
                cout << "|";
                Sleep(40);
            }
            
            for (int i = 0; i < 1; i++)
            {
                int x = 2;
                int y = 12;
                for (x = 40; x > 2; x--)
                {
                    goXY(x, y);
                    cout << "Created by CleverStudent21";
                    Sleep(40);
                    goXY(x, y);
                    cout << "                                           ";
                    cout << "                                   ";
                }
                cout << "\n\t Created by CS21 Team" << endl << endl;
            }
            cout << "       Enter your selection : ";
            cin >> selection;
            cout << endl;
            //choices
            switch (selection)
            {
            case 1:
                secondMainMenu();
                break;

            case 2:
                readSearchFile();
                system("pause");
                break;
            case 3:
                readAllFile();
                system("pause");
                break;
            case 4:
                AboutTruck();
                 system("pause");
                break;
            case 5:
                cout << " Thank you choose us ! \n";
                exit(0);
                break;

            default:
                cout << " --- " << selection << " is not a valid menu item. --- \n";
            }
        }
    } while (selection != 5);
}
#endif