#include <iostream>

class AVL
{
    struct Node_AVL
    {
        int info, height;
        Node_AVL *Left, *Right;
    };
    Node_AVL *Root;
    int item, choice, count;

public:
    AVL()
    {
        Root = NULL;

        while (1)
        {
            system("cls");
            std::cout << "(In AVL Tree Menu)\n"
                         "Press\n"
                         "1)Traversal\n"
                         "2)Insertion in AVL\n"
                         "3)Deletion in AVL\n"
                         "4)Searching\n"
                         "5)Return to Main Menu\t";
            std::cin >> choice;
            switch (choice)
            {
            case 1:
            {
                Traversal();
            }
            break;
            case 2:
            {
                std::cout << "Enter the item you want to Insert\t";
                std::cin >> item;
                Root = Insert_AVL(Root, item);
            }
            break;
            case 3:
            {
                std::cout << "Enter the item you want to Delete\t";
                std::cin >> item;
                Root = Delete_AVL(Root, item);
            }
            break;
            case 4:
            {
                Searching();
            }
            break;
            case 5:
            {
                return;
            }
            break;
            default:
            {
                std::cout << "Invalid Choice\n";
                system("pause");
            }
            break;
            }
        }
    }

    // Traverse
    void Traversal()
    {
        if (Root == NULL)
        {
            std::cout << "Empty Tree\n";
            system("pause");
            return;
        }
        while (1)
        {
            system("cls");
            std::cout << "(In AVL Tree Traversal Menu)\n"
                         "Press\n"
                         "1)PreOrder Traversal\n"
                         "2)InOrder Traversal\n"
                         "3)PostOrder Traversal\n"
                         "4)Return to Tree Menu\t";
            std::cin >> choice;
            switch (choice)
            {
            case 1:
            {
                std::cout << "Tree values are:\n";
                PreOrder_Trav(Root);
                system("pause");
            }
            break;
            case 2:
            {
                std::cout << "Tree values are:\n";
                InOrder_Trav(Root);
                system("pause");
            }
            break;
            case 3:
            {
                std::cout << "Tree values are:\n";
                PostOrder_Trav(Root);
                system("pause");
            }
            break;
            case 4:
            {
                return;
            }
            break;
            default:
            {
                std::cout << "Invalid Choice\n";
                system("pause");
            }
            break;
            }
        }
    }

    // PreOrder Traversal
    void PreOrder_Trav(Node_AVL *ptr)
    {
        std::cout << "[" << ptr->info << "]\t";

        if (ptr->Left != NULL)
        {
            PreOrder_Trav(ptr->Left);
        }

        if (ptr->Right != NULL)
        {
            PreOrder_Trav(ptr->Right);
        }
    }

    // InOrder Traversal
    void InOrder_Trav(Node_AVL *ptr)
    {
        if (ptr->Left != NULL)
        {
            InOrder_Trav(ptr->Left);
        }

        std::cout << "[" << ptr->info << "]\t";

        if (ptr->Right != NULL)
        {
            InOrder_Trav(ptr->Right);
        }
    }

    // PostOrder Traversal
    void PostOrder_Trav(Node_AVL *ptr)
    {
        if (ptr->Left != NULL)
        {
            PostOrder_Trav(ptr->Left);
        }

        if (ptr->Right != NULL)
        {
            PostOrder_Trav(ptr->Right);
        }

        std::cout << "[" << ptr->info << "]\t";
    }

    // Get Height
    int getHeight(Node_AVL *ptr)
    {
        if (ptr == NULL)
        {
            return 0;
        }
        else
        {
            return ptr->height;
        }
    }

    // Balance Factor
    int getBalanceFactor(Node_AVL *ptr)
    {
        if (ptr == NULL)
        {
            return 0;
        }
        return getHeight(ptr->Left) - getHeight(ptr->Right);
    }

    // LL Rotation
    Node_AVL *LL_Rotate(Node_AVL *ptr)
    {
        Node_AVL *ptr1 = ptr->Left;
        ptr->Left = ptr1->Right;
        ptr1->Right = ptr;

        ptr->height = std::max(getHeight(ptr->Left), getHeight(ptr->Right)) + 1;
        ptr1->height = std::max(getHeight(ptr1->Left), getHeight(ptr1->Right)) + 1;

        return ptr1;
    }

    // RR Rotation
    Node_AVL *RR_Rotate(Node_AVL *ptr)
    {
        Node_AVL *ptr1 = ptr->Right;
        ptr->Right = ptr1->Left;
        ptr1->Left = ptr;

        ptr->height = std::max(getHeight(ptr->Left), getHeight(ptr->Right)) + 1;
        ptr1->height = std::max(getHeight(ptr1->Left), getHeight(ptr1->Right)) + 1;

        return ptr1;
    }

    // LR Rotation
    Node_AVL *LR_Rotate(Node_AVL *ptr)
    {
        ptr->Left = RR_Rotate(ptr->Left);
        ptr = LL_Rotate(ptr);
        return ptr;
    }

    // RL Rotation
    Node_AVL *RL_Rotate(Node_AVL *ptr)
    {
        ptr->Right = LL_Rotate(ptr->Right);
        ptr = RR_Rotate(ptr);
        return ptr;
    }

    // Insertion in AVL
    Node_AVL *Insert_AVL(Node_AVL *Root, int item)
    {
        if (Root == NULL)
        {
            Node_AVL *Node = new Node_AVL();
            Node->info = item;
            Node->Left = NULL;
            Node->Right = NULL;
            Node->height = 1;
            return Node;
        }
        if ((Root->info) > item)
        {
            Root->Left = Insert_AVL(Root->Left, item);
        }
        else
        {
            if ((Root->info) < item)
            {
                Root->Right = Insert_AVL(Root->Right, item);
            }
            else
            {
                std::cout << "Item already exist\n";
                system("pause");
            }
        }

        Root->height = 1 + std::max(getHeight(Root->Left), getHeight(Root->Right));
        //        int BF = getBalanceFactor(Root);

        if ((getBalanceFactor(Root) == 2) && (getBalanceFactor(Root->Left) == 1))
        {
            Root = LL_Rotate(Root);
        }
        else if ((getBalanceFactor(Root) == -2) && (getBalanceFactor(Root->Right) == -1))
        {
            Root = RR_Rotate(Root);
        }
        else if (((getBalanceFactor(Root) == 2) && (getBalanceFactor(Root->Left) == -1)))
        {
            Root = LR_Rotate(Root);
        }
        else if ((getBalanceFactor(Root) == -2) && (getBalanceFactor(Root->Right) == 1))
        {
            Root = RL_Rotate(Root);
        }
        return Root;
    }

    // InOrder Successor
    Node_AVL *InOrderSuccessor(Node_AVL *Root)
    {
        Node_AVL *ptr = Root->Right;
        while (ptr->Left != NULL)
        {
            ptr = ptr->Left;
        }
        return ptr;
    }

    // Deletion in AVL
    Node_AVL *Delete_AVL(Node_AVL *Root, int item)
    {
        if (Root == NULL)
        {
            std::cout << "Item not Found\n";
            system("pause");
            return Root;
        }
        if (Root->Left == NULL && Root->Right == NULL)
        {
            delete (Root);
            return NULL;
        }
        if (item < Root->info)
        {
            Root->Left = Delete_AVL(Root->Left, item);
        }
        else if (item > Root->info)
        {
            Root->Right = Delete_AVL(Root->Right, item);
        }
        else
        {
            Node_AVL *ptr;
            ptr = InOrderSuccessor(Root);
            Root->info = ptr->info;
            Root->Right = Delete_AVL(Root->Right, ptr->info);
        }

        Root->height = 1 + std::max(getHeight(Root->Left), getHeight(Root->Right));

        if (getBalanceFactor(Root) == 2 && getBalanceFactor(Root->Left) == 1)
        {
            Root = LL_Rotate(Root);
        }
        else if (getBalanceFactor(Root) == 2 && getBalanceFactor(Root->Left) == -1)
        {
            Root = LR_Rotate(Root);
        }
        else if (getBalanceFactor(Root) == 2 && getBalanceFactor(Root->Left) == 0)
        {
            Root = LL_Rotate(Root);
        }
        else if (getBalanceFactor(Root) == -2 && getBalanceFactor(Root->Right) == -1)
        {
            Root = RR_Rotate(Root);
        }
        else if (getBalanceFactor(Root) == -2 && getBalanceFactor(Root->Right) == 1)
        {
            Root = RL_Rotate(Root);
        }
        else if (getBalanceFactor(Root) == -2 && getBalanceFactor(Root->Right) == 0)
        {
            Root = RR_Rotate(Root);
        }
        return Root;
    }

    // Searching
    void Searching()
    {
        if (Root == NULL)
        {
            std::cout << "Empty Tree\n";
            system("pause");
            return;
        }
        while (1)
        {
            system("cls");
            std::cout << "(In AVL Tree Searching Menu)\n"
                         "Press\n"
                         "1)Search Minimum\n"
                         "2)Search Maximum\n"
                         "3)Search By Item\n"
                         "4)Return to AVL Tree Menu\t";
            std::cin >> choice;
            switch (choice)
            {
            case 1:
            {
                Search_Min();
                system("pause");
            }
            break;
            case 2:
            {
                Search_Max();
                system("pause");
            }
            break;
            case 3:
            {
                std::cout << "Enter Item you want to search\t";
                std::cin >> item;
                count = 0;
                Search_Item(Root);
                if (count == 0)
                {
                    std::cout << "Item not Found\n";
                }
                else
                {
                    std::cout << "Item Found\n";
                }
                system("pause");
            }
            break;
            case 4:
            {
                return;
            }
            break;
            default:
            {
                std::cout << "Invalid Choice\n";
                system("pause");
            }
            break;
            }
        }
    }

    // Search Miminum
    void Search_Min()
    {
        Node_AVL *ptr = Root;

        while (ptr->Left != NULL)
        {
            ptr = ptr->Left;
        }
        std::cout << "Mininmum Value is\t" << ptr->info << std::endl;
    }

    // Maximum Value
    void Search_Max()
    {
        Node_AVL *ptr = Root;

        while (ptr->Right != NULL)
        {
            ptr = ptr->Right;
        }
        std::cout << "Mininmum Value is\t" << ptr->info << std::endl;
    }

    // Search by Value
    void Search_Item(Node_AVL *ptr)
    {
        if (ptr->info == item)
        {
            count++;
        }
        if (ptr->Left != NULL)
        {
            Search_Item(ptr->Left);
        }
        if (ptr->Right != NULL)
        {
            Search_Item(ptr->Right);
        }
    }

    ~AVL()
    {
        delete Root;
    }
};
