#include<iostream>

// Stack on Array
class Stack_Array
{
public:
    int size, item;
    const int lb = 0;
    int Top = (lb - 1);
    int *S;
    Stack_Array()
    {
        system("cls");
        std::cout << "Enter size of Stack\t";
        std::cin >> size;
        S = new int[size];
        Choices();
    }
    void Choices()
    {
        int choice;
        while (1)
        {
            system("cls");
            std::cout <<"(Stack on Array Menu)\n"
                     "Enter your choice\n"
                    "1) Press 1 for Traverse\n"
                    "2) Press 2 for Push\n"
                    "3) Press 3 for Pop\n"
                    "4) Press 4 for Returning to Stack Menu\t";
            std::cin >> choice;
            switch (choice)
            {
            case 1:
            {
                Traverse();
            }
            break;
            case 2:
            {
                Push();
            }
            break;
            case 3:
            {
                Pop();
            }
            break;
            case 4:
            {
                return;
            }
            break;
            default:
            {
                std::cout << "Inavlid Selection\n";
                system("pause");
            }
            }
        }
    }

    // Traverse
    void Traverse()
    {
        if (Top == lb - 1)
        {
            std::cout << "Stack is Empty\n";
            system("pause");
            return;
        }
        std::cout << "Stack is:\n";
        for (int i = Top; i >= lb; i--)
        {
            std::cout << "[" << S[i] << "]\t";
        }
        system("pause");
    }

    // Push
    void Push()
    {
        if (Top == (size + lb - 1))
        {
            std::cout << "Stack is Already full\n";
            system("pause");
            return;
        }
        std::cout << "Enter the item you want to insert\t";
        std::cin >> item;
        Top++;
        S[Top] = item;
    }

    // Pop
    void Pop()
    {
        if (Top == (lb - 1))
        {
            std::cout << "Stack is Empty\n";
                 system("pause");
            return;
        }
        item = S[Top];
        Top--;
        std::cout << "Deleted vaue is: [" << item << "]\n";
        system("pause");
    }
};