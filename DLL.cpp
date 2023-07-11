#include <iostream>

// Double Linked List
class DoubleLinkedList
{
public:
    struct Node_DLL
    {
    public:
        int info;
        Node_DLL *next, *prev;
    };
    int choices, item, sitem;
    Node_DLL *start = NULL;
    Node_DLL *ptr = start;
    DoubleLinkedList()
    {
        while (1)
        {
            system("cls");
            std::cout << "(Double Linked List Menu)\n"
                         "Press 1 for Traverse\n"
                         "Press 2 for Searching\n"
                         "Press 3 for Insertion\n"
                         "Press 4 for Deletion\n"
                         "Press 5 for Return to Linked List Menu\t";
            std::cin >> choices;
            switch (choices)
            {
            case 1:
            {
                Traverse();
            }
            break;
            case 2:
            {
                Searching();
            }
            break;
            case 3:
            {
                Insertion();
            }
            break;
            case 4:
            {
                Deletion();
            }
            break;
            case 5:
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

    // Traverse
    void Traverse()
    {
        if (start == NULL)
        {
            std::cout << "List is Empty\n";
            system("pause");
            return;
        }
        while (true)
        {
            system("cls");
            std::cout << "(Traversal in DLL)\n"
                         "Press\n"
                         "1 Traverse in Forward\n"
                         "2 Traverse in Backward\n"
                         "3 for return";
            std::cin >> choices;
            switch (choices)
            {
            case 1:
            {
                Trav_Forward();
            }
            break;
            case 2:
            {
                Trav_Backward();
            }
            break;
            case 3:
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

    // Traverse in Forward
    void Trav_Forward()
    {
        ptr = start;
        std::cout << "List is\n";
        while (ptr != NULL)
        {
            std::cout << "[" << ptr->info << "]\t";
            ptr = ptr->next;
        }
        system("pause");
    }

    // Traverse in Backward
    void Trav_Backward()
    {
        ptr = start;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        std::cout << "List is\n";
        while (ptr != NULL)
        {
            std::cout << "[" << ptr->info << "]\t";
            ptr = ptr->prev;
        }
        system("pause");
    }

    // Searching
    void Searching()
    {
        system("cls");
        std::cout << "(Searching in DLL)\n"
                     "Select desired option\n"
                     "1)Single Search\n"
                     "2)Multisearch\t";
        std::cin >> choices;
        switch (choices)
        {
        case 1:
            SingleSearch_DLL();
            break;
        case 2:
            MultiSearch_DLL();
            break;
        default:
            std::cout << "Invalid Selection\n";
            system("pause");
            break;
        }
    }

    // Single Search
    void SingleSearch_DLL()
    {
        std::cout << "Enter the value that you want to seach\t";
        std::cin >> sitem;
        Node_DLL *ptr = start;
        while (ptr != NULL)
        {
            if (ptr->info == sitem)
            {
                std::cout << "Item Found\n";
                ptr = NULL;
                delete (ptr);
                return;
            }
            ptr = ptr->next;
        }
        std::cout << "Item not Found\n";
        system("pause");
        ptr = NULL;
        delete (ptr);
    }

    // Multiseach
    void MultiSearch_DLL()
    {
        std::cout << "Enter the value that you want to seach\t";
        std::cin >> sitem;
        Node_DLL *ptr = start;
        int count = 0;
        while (ptr != NULL)
        {
            if (ptr->info == sitem)
            {
                count++;
            }
            ptr = ptr->next;
        }
        if (count == 0)
        {
            std::cout << "Item not Found\n";
        }
        else
        {
            std::cout << sitem << " found " << count << " times\n";
        }
        system("pause");
        ptr = NULL;
        delete (ptr);
    }

    // Insertion
    void Insertion()
    {
        while (1)
        {
            system("cls");
            std::cout << "(Insertion in DLL)\n"
                         "Press\n"
                         "1 for Insertion at first\n"
                         "2 for Insertion at Last\n"
                         "3 for Insertion at Middle\n"
                         "4 for return\t";
            std::cin >> choices;
            switch (choices)
            {
            case 1:
            {
                Insert_AtFirst();
            }
            break;
            case 2:
            {
                Insert_Last_DLL();
            }
            break;
            case 3:
            {
                Insert_Middle_DLL();
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

    // Insertion at First
    void Insert_AtFirst()
    {
        std::cout << "Enter value you want to insert\t";
        std::cin >> item;
        Node_DLL *ptr = new Node_DLL();
        ptr->prev = NULL;
        ptr->info = item;
        ptr->next = start;
        if (start == NULL)
        {
            start = ptr;
            return;
        }
        start->prev = ptr;
        start = ptr;
    }

    // Insertion At Last
    void Insert_Last_DLL()
    {
        std::cout << "Enter value you want to insert\t";
        std::cin >> item;
        Node_DLL *ptr = new Node_DLL();
        ptr->info = item;
        ptr->next = NULL;
        if (start == NULL)
        {
            ptr->prev = NULL;
            start = ptr;
        }
        else
        {
            Node_DLL *ptr1 = start;
            while (ptr1->next != NULL)
            {
                ptr1 = ptr1->next;
            }
            ptr1->next = ptr;
            ptr->prev = ptr1;
        }
    }

    // Insertion in Middle
    void Insert_Middle_DLL()
    {
        system("cls");
        std::cout << "(Insertion in Middle in DLL)\n"
                     "Press\n"
                     "1 for Insertion by refrence of given Node_DLL\n"
                     "2 for Insertion by reference of exactly middle Node_DLL\t";
        std::cin >> choices;
        switch (choices)
        {
        case 1:
        {
            Insert_Mid_Given_Node_DLL();
        }
        break;
        case 2:
        {
            Insert_Exactly_Mid();
        }
        break;
        default:
            std::cout << "Invalid Selection\n";
            system("pause");
            break;
        }
    }

    // Insert by Given Node_DLL
    void Insert_Mid_Given_Node_DLL()
    {
        if (start == NULL)
        {
            std::cout << "List is Empty\n";
            system("pause");
            return;
        }
        system("cls");
        std::cout << "(Insert by Ref of Given in DLL)\n"
                     "Press\n"
                     "1 for Insert Before Given Node_DLL\n"
                     "2 for Insert After Given Node_DLL\t";
        std::cin >> choices;
        switch (choices)
        {
        case 1:
        {
            Inset_Before_Node_DLL();
        }
        break;
        case 2:
        {
            Insert_After_Node_DLL();
        }
        break;
        default:
            std::cout << "Invalid Selection\n";
            system("pause");
            break;
        }
    }

    // Insert before Given Node_DLL
    void Inset_Before_Node_DLL()
    {
        std::cout << "Enter the item Before which you want to insert a Node_DLL\t";
        std::cin >> sitem;
        if (start->info == sitem)
        {
            std::cout << "Enter value you want to insert\t";
            std::cin >> item;
            Node_DLL *ptr = new Node_DLL();
            ptr->info = item;
            ptr->prev = NULL;
            ptr->next = start;
            start->prev = ptr;
            start = ptr;
            return;
        }
        Node_DLL *ptr1 = start;
        while ((ptr1 != NULL) && (ptr1->info != sitem))
        {
            ptr1 = ptr1->next;
        }
        if (ptr1 == NULL)
        {
            std::cout << "Item not found\n";
            system("pause");
            return;
        }
        std::cout << "Enter value you want to insert\t";
        std::cin >> item;
        Node_DLL *ptr = new Node_DLL();
        ptr->info = item;
        ptr->prev = ptr1->prev;
        ptr->prev->next = ptr;
        ptr1->prev = ptr;
        ptr->next = ptr1;
    }

    // Insert After Given Node_DLL
    void Insert_After_Node_DLL()
    {
        std::cout << "Enter the item After which you want to insert a Node_DLL\t";
        std::cin >> sitem;
        Node_DLL *ptr1 = start;
        while ((ptr1 != NULL) && (ptr1->info != sitem))
        {
            ptr1 = ptr1->next;
        }
        if (ptr1 == NULL)
        {
            std::cout << "Item not found\n";
            system("pause");
            return;
        }
        std::cout << "Enter value you want to insert\t";
        std::cin >> item;
        Node_DLL *ptr = new Node_DLL();
        ptr->info = item;
        ptr->prev = ptr1;
        ptr->next = ptr1->next;
        if (ptr1->next != NULL)
        {
            ptr1->next->prev = ptr;
        }
        ptr1->next = ptr;
    }

    // Insertion by Refrence of Exactly Middle Node_DLL
    void Insert_Exactly_Mid()
    {
        system("cls");
        std::cout << "(Insert Exact Mid in DLL)\n"
                     "Press\n"
                     "1 for Insert Before Middle Node_DLL\n"
                     "2 for Insert After Middle Node_DLL\t";
        std::cin >> choices;
        switch (choices)
        {
        case 1:
        {
            Insert_Before_Exact_Mid();
        }
        break;
        case 2:
        {
            Insert_After_Exact_Mid();
        }
        break;
        default:
            std::cout << "Invalid Selection\n";
            system("pause");
            break;
        }
    }

    // Insert Before Exactly Middle
    void Insert_Before_Exact_Mid()
    {
        Node_DLL *ptr = new Node_DLL();
        std::cout << "Enter value you want to insert\t";
        std::cin >> item;
        ptr->info = item;
        if ((start == NULL) || (start->next == NULL))
        {
            ptr->next = start;
            ptr->prev = NULL;
            if (start != NULL)
            {
                start->prev = ptr;
            }
            start = ptr;
            return;
        }
        int count = 0;
        Node_DLL *ptr1 = start;
        while (ptr1 != NULL)
        {
            count++;
            ptr1 = ptr1->next;
        }
        int mid = (count / 2) + 1;
        ptr1 = start;
        for (int i = 0; i < mid - 2; i++)
        {
            ptr1 = ptr1->next;
        }
        ptr->next = ptr1->next;
        ptr->prev = ptr1;
        ptr1->next->prev = ptr;
        ptr1->next = ptr;
    }

    // Insert After Exactly Middle
    void Insert_After_Exact_Mid()
    {
        Node_DLL *ptr = new Node_DLL();
        std::cout << "Enter value you want to insert\t";
        std::cin >> item;
        ptr->info = item;
        if (start == NULL)
        {
            ptr->prev = NULL;
            ptr->next = NULL;
            start = ptr;
            return;
        }
        int count = 0;
        Node_DLL *ptr1 = start;
        while (ptr1 != NULL)
        {
            count++;
            ptr1 = ptr1->next;
        }
        int mid = (count / 2) + 1;
        ptr1 = start;
        for (int i = 0; i < mid - 1; i++)
        {
            ptr1 = ptr1->next;
        }
        ptr->prev = ptr1;
        if ((count == 1) || (count == 2))
        {
            ptr->next = NULL;
            ptr1->next = ptr;
            return;
        }
        ptr->next = ptr1->next;
        ptr1->next->prev = ptr;
        ptr1->next = ptr;
    }

    // Deletion
    void Deletion()
    {
        if (start == NULL)
        {
            std::cout << "Linked List is Empty\n";
            system("pause");
            return;
        }
        while (1)
        {
            system("cls");
            std::cout << "(Deletion in DLL)\n"
                         "Press\n"
                         "1 for Deleteion at First\n"
                         "2 for Deleteion at Last\n"
                         "3 for Deleteion at Middle\n"
                         "4 for Return\t";
            std::cin >> choices;
            if ((choices <= 3) && (start == NULL))
            {
                std::cout << "Linked List is Empty\n";
                system("pause");
                return;
            }
            switch (choices)
            {
            case 1:
            {
                Deletion_First_DLL();
            }
            break;
            case 2:
            {
                Deleion_Last_DLL();
            }
            break;
            case 3:
            {
                Deletion_Middle();
            }
            break;
            case 4:
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

    // Deletion at First
    void Deletion_First_DLL()
    {
        Node_DLL *ptr = start;
        start = start->next;
        if (start != NULL)
        {
            start->prev = NULL;
        }
        delete (ptr);
    }

    // Deletion at Last
    void Deleion_Last_DLL()
    {
        if (start->next == NULL)
        {
            Node_DLL *ptr = start;
            start = NULL;
            delete (ptr);
            return;
        }
        Node_DLL *ptr = start;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->prev->next = NULL;
        delete (ptr);
    }

    // Deletion of Middle
    void Deletion_Middle()
    {
        system("cls");
        std::cout << "(Deletion in Mid in DLL)\n"
                     "Press\n"
                     "1 for deletion of Given Item\n"
                     "2 for deletion of Exact Middle\t";
        std::cin >> choices;
        switch (choices)
        {
        case 1:
        {
            Deletion_Mid_Item_DLL();
        }
        break;
        case 2:
        {
            Deletion_Exact_Middle_DLL();
        }
        break;
        default:
            std::cout << "Invalid Selection\n";
            system("pause");
            break;
        }
    }

    // Deletion by given Item
    void Deletion_Mid_Item_DLL()
    {
        std::cout << "Enter value you want to delete\t";
        std::cin >> sitem;
        if (start->info == sitem)
        {
            Node_DLL *ptr = start;
            start = start->next;
            if (start != NULL)
            {
                start->prev = NULL;
            }
            delete (ptr);
            return;
        }
        Node_DLL *ptr = start;
        while ((ptr != NULL) && (ptr->info != sitem))
        {
            ptr = ptr->next;
        }
        if (ptr == NULL)
        {
            std::cout << "Item not Found\n";
            system("pause");
            return;
        }
        Node_DLL *ptr1 = ptr;
        ptr->prev->next = ptr->next;
        if (ptr->next != NULL)
        {
            ptr->next->prev = ptr->prev;
        }
        delete (ptr1);
    }

    // Deletion of Exact Middle
    void Deletion_Exact_Middle_DLL()
    {
        if (start->next == NULL)
        {
            Node_DLL *ptr = start;
            start = NULL;
            delete (ptr);
            return;
        }
        int count = 0;
        Node_DLL *ptr = start;
        while (ptr != NULL)
        {
            count++;
            ptr = ptr->next;
        }
        int mid = (count / 2) + 1;
        ptr = start;
        for (int i = 0; i < (mid - 1); i++)
        {
            ptr = ptr->next;
        }
        Node_DLL *ptr1 = ptr->prev;
        if (ptr->next != NULL)
        {
            ptr1->next = ptr->next;
            ptr->next->prev = ptr1;
        }
        else
        {
            ptr1->next = NULL;
        }
        delete (ptr);
    }
};