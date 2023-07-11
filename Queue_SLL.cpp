#include<iostream>

class Queue_SLL
{
public:
    struct Node_SLL
    {
    public:
        int info;
        Node_SLL *next;
    };
    Node_SLL *F, *R;
    int choice, item;

    Queue_SLL()
    {
        while (1)
        {
            system("cls");
            std::cout << "(Queue on SLL)\n"
                         "Press\n"
                         "1)Simple Queue\n"
                         "2)Circular Queue\n"
                         "3)Return to Queue menu\t";
            std::cin >> choice;
            switch (choice)
            {
            case 1:
            {
                SimpleQueue_DLL();
            }
            break;
            case 2:
            {
                CircularQueue_DLL();
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

    // Simple Queue
    void SimpleQueue_DLL()
    {
        F = NULL, R = NULL;
        while (1)
        {
            system("cls");
            std::cout << "(Simple Queue on SLL)\n"
                         "Press\n"
                         "1)Insert\n"
                         "2)Delete\n"
                         "3)Display\n"
                         "4)Return\t";
            std::cin >> choice;
            switch (choice)
            {
            case 1:
            {
                Enqueue_SLL();
            }
            break;
            case 2:
            {
                Dequeue_SLL();
            }
            break;
            case 3:
            {
                Display_Simple_Queue();
            }
            break;
            case 4:
            {
                return;
            }
            break;

            default:
            {
                std::cout << "Invalid Selection\n";
                system("pause");
            }
            break;
            }
        }
    }

    // Enqueue SLL
    void Enqueue_SLL()
    {
        Node_SLL *ptr = new Node_SLL();
        std::cout << "Enter the value you want to insert\t";
        std::cin >> item;
        ptr->info = item;
        ptr->next = NULL;
        if (R == NULL)
        {
            F = ptr;
            R = ptr;
        }
        else
        {
            R->next = ptr;
            R = ptr;
        }
    }

    // Dequeue SLL
    void Dequeue_SLL()
    {
        if (F == NULL)
        {
            std::cout << ("Queue is Empty\n");
            system("pause");
            return;
        }
        Node_SLL *ptr = F;
        if (F->next == NULL)
        {
            F = NULL;
            R = NULL;
        }
        else
        {
            F = F->next;
        }
        delete (ptr);
    }

    // Display Simple Queue
    void Display_Simple_Queue()
    {
        if (F == NULL)
        {
            std::cout << "Linked List is Empty\n";
            system("pause");
            return;
        }
        Node_SLL *ptr = F;
        std::cout << "List is:\n";
        while (ptr != R)
        {
            std::cout << "[" << ptr->info << "]\t";
            ptr = ptr->next;
        }
        std::cout << "[" << ptr->info << "]\t";
        system("pause");
    }

    // Circular Queue
    void CircularQueue_DLL()
    {
        F = NULL, R = NULL;
        while (1)
        {
            system("cls");
            std::cout << "(Circular Queue on SLL)\n"
                         "Press\n"
                         "1)Insert\n"
                         "2)Delete\n"
                         "3)Display\n"
                         "4)Return\t";
            std::cin >> choice;
            switch (choice)
            {
            case 1:
            {
                Enqueue_Circular_SLL();
            }
            break;
            case 2:
            {
                Dequeue_Circular_SLL();
            }
            break;
            case 3:
            {
                Display_Circular_Queue();
            }
            break;
            case 4:
            {
                return;
            }
            break;

            default:
            {
                std::cout << "Invalid Selection\n";
                system("pause");
            }
            break;
            }
        }
    }

    // Enqueue Circulr SLL
    void Enqueue_Circular_SLL()
    {
        Node_SLL *ptr = new Node_SLL();
        std::cout << "Enter the value you want to insert\t";
        std::cin >> item;
        ptr->info = item;
        if (R == NULL)
        {
            F = ptr;
            R = ptr;
            R->next = F;
        }
        else{
            ptr->next = F;
            R->next= ptr;
            R=ptr;
        }
    }

    // Dequeue Circular SLL
    void Dequeue_Circular_SLL()
    {
        if (F == NULL)
        {
            std::cout << "Queue is Empty\n";
            system("pause");
            return;
        }
        Node_SLL *ptr = F;
        if (F == R)
        {
            F = NULL;
            R = NULL;
        }
        else
        {
            F = F->next;
            R->next = F;
        }
        delete (ptr);
    }

    // Display Circular Queue
    void Display_Circular_Queue()
    {
        if (F == NULL)
        {
            std::cout << "Linked List is Empty\n";
            system("pause");
            return;
        }
        Node_SLL *ptr = F;
        std::cout << "List is:\n";
        while (ptr != R)
        {
            std::cout << "[" << ptr->info << "]\t";
            ptr = ptr->next;
        }
        std::cout << "[" << ptr->info << "]\t";
        system("pause");
    }
};