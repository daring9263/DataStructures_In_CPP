#include <iostream>
#include "Stack_SLL.cpp"
#include "Stack_DLL.cpp"
#include "Stack_Array.cpp"

void Stack_LL()
{
    int choice;
    while (1)
    {
        system("cls");
        std::cout << "(Stack On Linked List)\n"
                     "Press\n"
                     "1)Stack on SLL\n"
                     "2)Stack on DLL\n"
                     "3)Return\t";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
        {
            Stack_SLL sSLL;
        }
        break;
        case 2:
        {
            Stack_DLL sDLL;
        }
        break;
        case 3:
        {
            return;
        }
        break;
        default:
            std::cout << "Invalid Selection\n";
            system("pause");
            break;
        }
    }
}

// Stack
void Stack()
{
    int st;
    while (1)
    {
        system("cls");
        std::cout << "(Stack Menu)\n"
                     "Select\n"
                     "1)Stack on Array\n"
                     "2)Stack on Linked list\n"
                     "3)Return to main menu\t";
        std::cin >> st;
        switch (st)
        {
        case 1:
        {
            Stack_Array stackA;
        }
        break;
        case 2:
            Stack_LL();
            break;
        case 3:
            return;
            break;
        default:
            std::cout << "Invalid Selection\n";
            system("pause");
        }
    }
}