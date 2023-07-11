#include <iostream>
#include "Queue_Array.cpp"
#include "Queue_SLL.cpp"
#include "Queue_DLL.cpp"

void Queue_LL()
{
    int choice;
    while (1)
    {
        system("cls");
        std::cout << "(Queue On Linked List)\n"
                     "Press\n"
                     "1)Queue on SLL\n"
                     "2)Queue on DLL\n"
                     "3)Return\t";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
        {
            Queue_SLL qSLL;
        }
        break;
        case 2:
        {
            Queue_DLL qDLL;
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

// Queue
void Queue()
{
    int que;
    while (1)
    {
        system("cls");
        std::cout << "(Queue Menu)\n"
                     "Select\n"
                     "1)Queue on Array\n"
                     "2)Queue on Linked list\n"
                     "3)Return to main menu\t";
        std::cin >> que;
        switch (que)
        {
        case 1:
        {
            Queue_Array qA;
        }
        break;
        case 2:
        {
            Queue_LL();
        }
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
