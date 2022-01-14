#ifndef SECONDMAINMENU_H
#define SECONDMAINMENU_H
#include "RegistrationForm.h"
#include "AboutTruck.h"

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;
void gotoXY(int x, int y)
{
    CursorPosition.X = x;                              // Locates column
    CursorPosition.Y = y;                              // Locates Row
    SetConsoleCursorPosition(console, CursorPosition); // Sets position for next thing to be printed
}
void secondMainMenu()
{
    int option;
    do
    {
        system("cls");
        system("COLOR 0");
        char a[] = "  ------------ Logistics Transportation ------------";
        int size;
        size = strlen(a);  //strlen returns the length of given string
        cout << endl
             << endl
             << endl;
        for (int i = 0; i < size; i++)
        {
            Sleep(25);
            cout << a[i];
        }
        int c = 1;
        cout << endl
             << endl;
        Sleep(0);
        cout << "\t         Choose Truck Options\n";
        cout << "\t                                " << endl
             << "\t               1.Standart       " << endl
             << "\t               2.Reliable       " << endl
             << "\t               3.Premium        " << endl
             << "\t               4.About          " << endl
             << "\t               5.Main Menu      " << endl    
             << "\t               6.Exit           " << endl;             
        for (int i = 0; i < 1; i++)
        {
            int x = 1;
            int y = 10;
            for (y = 4; y < 14; y++)
            {
                gotoXY(x, y);
                cout << "|";
                Sleep(40);
            }
            y = 14;
            for (x = 2; x < 52; x++)
            {
                gotoXY(x, y);
                cout << "-";
                Sleep(20);
            }
            for (y = 13; y >= 4; y--)
            {
                gotoXY(x, y);
                cout << "|";
                Sleep(40);
            }
            cout << endl;
            cout << "\n\n\n\n\n\n\n\n\n\n\n     \t\tChoose option : ";
            std::cin >> option;
            switch (option)
            {
            case 1:
            case 2:
            case 3:
                writeFile();
                system("pause");
                break;
            case 4:
                AboutTruck();
                system("pause");
                break;
            case 6: 
                exit(0);
                break;
            default:
                option = 5;
                break;
            }
        }
    }while (option != 5);
}
#endif