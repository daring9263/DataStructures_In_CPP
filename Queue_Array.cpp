#include <iostream>

// Queue Array
class Queue_Array
{
public:
    int choice, F, R, item, size;
    const int lb = 0;
    int *Q;
    int *CQ;
    Queue_Array()
    {
        Choices();
    }
    void Choices()
    {
        while (1)
        {
            system("cls");
            std::cout << "(Queue on Array)\n"
                         "Select your Choice\n"
                         "1) Press 1 for Simple Queue\n"
                         "2) Press 2 for Circular Queue\n"
                         "3) Press 3 for Returning to Queue Menu\t";
            std::cin >> choice;
            switch (choice)
            {
            case 1:
            {
                LinearQ();
            }
            break;
            case 2:
            {
                CircularQ();
            }
            break;
            case 3:
            {
                return;
            }
            break;
            default:
            {
                std::cout << "Invalid Selection\n";
                system("pause");
            }
            }
        }
    }

    // Linear Q
    void LinearQ()
    {
        system("cls");
        std::cout << "Enter size of you Queue\n";
        std::cin >> size;
        Q = new int[size];
        F = lb - 1;
        R = lb - 1;
        while (1)
        {
            system("cls");
            std::cout << "(Simple Queue on Array Menu)\n"
                         "Select your Opeartion\n"
                         "1)Press 1 for Insertion\n"
                         "2)Press 2 for Deletion\n"
                         "3)Press 3 for Display\n"
                         "4)Press 4 for Returning to Queue_Array menu\t";
            std::cin >> choice;
            switch (choice)
            {
            case 1:
                InsertionLQ();
                break;
            case 2:
                DeletionLQ();
                break;
            case 3:
                DisplayLQ();
                break;
            case 4:
                return;
                break;
            default:
                std::cout << "Invalid Selection\n";
                system("pause");
                break;
            }
        }
    }

    // Insertion Linear
    void InsertionLQ()
    {
        if (R == (size + lb - 1))
        {
            std::cout << "Queue is Full\n";
            system("pause");
            return;
        }
        if (R == (lb - 1))
        {
            R = lb;
            F = lb;
        }
        else
        {
            R++;
        }
        std::cout << "Enter the value you want to insert\t";
        std::cin >> item;
        Q[R] = item;
    }

    // Deletion Linear
    void DeletionLQ()
    {
        if (F == lb - 1)
        {
            std::cout << "Queue is Empty\n";
            system("pause");
            return;
        }
        item = Q[F];
        if (F == R)
        {
            F = lb - 1;
            R = lb - 1;
        }
        else
        {
            F++;
        }
        std::cout << item << " has been Deleted from Queue\n";
        system("pause");
    }

    // Display Linear
    void DisplayLQ()
    {
        if (F == lb - 1)
        {
            std::cout << "Queue is Empty\n";
            system("pause");
            return;
        }
        std::cout << "Queue is\n";
        for (int i = F; i <= R; i++)
        {
            std::cout << "[" << Q[i] << "]\t";
        }
        system("pause");
    }

    // Circular Quee
    void CircularQ()
    {
        system("cls");
        std::cout << "Enter size of you Queue\n";
        std::cin >> size;
        CQ = new int[size];
        F = lb - 1;
        R = lb - 1;
        while (1)
        {
            system("cls");
            std::cout << "(Circular Queue on Array Menu)\n"
                         "Select your Opeartion\n"
                         "1)Press 1 for Insertion\n"
                         "2)Press 2 for Deletion\n"
                         "3)Press 3 for Display\n"
                         "4)Press 4 for Returning to Queue_Array menu\t";
            std::cin >> choice;
            switch (choice)
            {
            case 1:
                InsertCQ();
                break;
            case 2:
                DeleteCQ();
                break;
            case 3:
                DisplayCQ();
                break;
            case 4:
                return;
                break;
            default:
                std::cout << "Invalid Selection\n";
                system("pause");
                break;
            }
        }
    }

    // Insert Circular
    void InsertCQ()
    {
        if (R == (F - 1) || ((R == (size + lb - 1)) && (F == lb)))
        {
            std::cout << "Queue is Full\n";
            system("pause");
            return;
        }
        if (R == (lb - 1))
        {
            R = lb;
            F = lb;
        }
        else
        {
            if (R == (size + lb - 1))
            {
                R = lb;
            }
            else
            {
                R++;
            }
        }
        std::cout << "Enter the value you want to insert\t";
        std::cin >> item;
        CQ[R] = item;
    }

    // Delete Circular
    void DeleteCQ()
    {
        if (F == lb - 1)
        {
            std::cout << "Queue is Empty\n";
            system("pause");
            return;
        }
        item = CQ[F];
        if (F == R)
        {
            F = lb - 1;
            R = lb - 1;
        }
        else
        {
            if (F == (size + lb - 1))
            {
                F = lb;
            }
            else
            {
                F++;
            }
        }
        std::cout << item << " has been Deleted from Queue\n";
        system("pause");
    }

    // Display Circular
    void DisplayCQ()
    {
        if (F == lb - 1)
        {
            std::cout << "Queue is Empty\n";
            system("pause");
            return;
        }
        std::cout << "Queue is\n";
        if (F <= R)
        {
            for (int i = F; i <= R; i++)
            {
                std::cout << "[" << CQ[i] << "]\t";
            }
        }
        else
        {
            for (int i = lb; i <= R; i++)
            {
                std::cout << "[" << CQ[i] << "]\t";
            }
            for (int i = F; i <= (size + lb - 1); i++)
            {
                std::cout << "[" << CQ[i] << "]\t";
            }
        }
        system("pause");
    }
};