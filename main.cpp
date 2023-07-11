#include <iostream>
#include "Array.cpp"
#include "LinkedList.cpp"
#include "Stack.cpp"
#include "Queue.cpp"
#include "Tree.cpp"

int main()
{
    int option;
    while (true)
    {
        system("cls");
        std::cout << "Data Structures and Algorithms\n"
                     "Abdul Rahman Ahmad\n"
                     "BSCS-3A(Morning-Sping 23)\n\n"
//                     "Assignment#02\n\n" 
                     "Select the Desired Data Structure\n"
                     "1)Array\n"
                     "2)Linked List\n"
                     "3)Stack\n"
                     "4)Queue\n"
                     "5)Tree\n"
                     "6)Exiting\t";
        std::cin >> option;
        switch (option)
        {

        case 1:
        {
            Array array;
        }
        break;
        case 2:
        {
            LinkedList();
        }
        break;
        case 3:
        {
            Stack();
        }
        break;
        case 4:
        {
            Queue();
        }
        break;
        case 5:
        {
            Tree tree;
        }
        break;
        case 6:
        {
            exit(0);
        }
        break;
        default:
            std::cout << "Invalid Selection\n";
            system("pause");
        }
    }
    return 0;
}
