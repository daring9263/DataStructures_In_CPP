#include <iostream>

class Stack_DLL
{
public:
    struct Node_DLL
    {
    public:
        int info;
        Node_DLL *next, *prev;
    };
    int choice, item;
    Node_DLL *Top = NULL;

    Stack_DLL()
    {
        while (1)
        {
            system("cls");
            std::cout << "(Stack on DLL)\n"
                         "Press\n"
                         "1 for Push\n"
                         "2 for Pop\n"
                         "3 for Traverse\n"
                         "4 for Return \t";
            std::cin >> choice;
            switch (choice)
            {
            case 1:
            {
                PUSH_DLL();
            }
            break;
            case 2:
            {
                POP_DLL();
            }
            break;
            case 3:
            {
                Traverse_DLL_Stack();
            }
            break;
            case 4:
            {
                return;
            }
            break;
            default:
                std::cout << "Invalid Choice\n";
                system("pause");
                break;
            }
        }
    }

    // Push in DLL
    void PUSH_DLL()
    {
        Node_DLL *ptr = new Node_DLL();
        std::cout << "Enter the value you want to Insert\t";
        std::cin >> item;
        ptr->info = item;
        ptr->next = Top;
        ptr->prev = NULL;
        if (Top != NULL)
        {
            Top->prev=ptr;
        }
        Top = ptr;
    }

    // POP in DLL
    void POP_DLL()
    {
        if (Top == NULL)
        {
            std::cout << "Stack Already Empty, Deletion not Possible\n";
            system("pause");
            return;
        }
        Node_DLL *ptr = Top;
        Top = Top->next;
        if (Top != NULL)
        {
            Top->prev=NULL;
        }
        delete (ptr);
    }

    // Traverse
    void Traverse_DLL_Stack()
    {
        if (Top == NULL)
        {
            std::cout << "Stack is Empty\n";
            system("pause");
            return;
        }
        Node_DLL *ptr = Top;
        std::cout << "List is\n"; 
        while (ptr != NULL)
        {
            std::cout << "[" << ptr->info << "]\t";
            ptr = ptr->next;
        }
        system("pause");
    }
};