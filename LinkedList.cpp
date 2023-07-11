#include <iostream>
#include "SLL.cpp"
#include "DLL.cpp"

// Linked List
void LinkedList()
{
    int ll;
    while (true)
    {
        system("cls");
        std::cout << "(Linked List Menu)\n"
                     "Choose Linked List\n"
                     "1)Single Linked List\n"
                     "2)Double Linked list\n"
                     "3)Return to main menu\t";
        std::cin >> ll;
        switch (ll)
        {
        case 1:
        {
            SingleLinkedList sll;
        }
        break;
        case 2:
        {
            DoubleLinkedList dll;
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