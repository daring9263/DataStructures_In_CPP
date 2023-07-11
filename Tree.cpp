#include <iostream>
#include "AVL.cpp"
#include "Heap_Tree.cpp"

class Tree
{
public:
    struct Node_Tree
    {
    public:
        int info;
        Node_Tree *Left, *Right;
    };
    Node_Tree *Root = NULL;
    int choice, item, count;
    Tree()
    {   
        while (1)
        {
            system("cls");
            std::cout << "(In Tree Menu)\n"
                         "Press\n"
                         "1)Simple Tree\n"
                         "2)Binary Search Tree\n"
                         "3)AVL Tree\n"
                         "4)Binary Heap\n"
                         "5)Return to Main Menu\t";
            std::cin >> choice;
            switch (choice)
            {
            case 1:
            {
                SimpleTree();
            }
            break;
            case 2:
            {
                BST();
            }
            break;
            case 3:
            {
                AVL avl;
            }
            break;
            case 4:
            {
                Heap heap;
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
    
    
    //Simple Tree
	void SimpleTree()
	{
		while(1)
		{
			system("cls");
			std::cout << "(In Simple Tree Menu)\n"
                         "Press\n"
                         "1)Traversal\n"
                         "2)Creation of Tree\n"
                         "3)Searching\n"
                         "4)Return to Main Menu\t";
            std::cin>>choice;
             switch (choice)
            {
            case 1:
            {
                Traversal();
            }
            break;
            case 2:
            {
                CreationOfTree();
            }
            break;
            case 3:
            {
				Simple_Searching();
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
            std::cout << "(In Tree Traversal Menu)\n"
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
    void PreOrder_Trav(Node_Tree *ptr)
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
    void InOrder_Trav(Node_Tree *ptr)
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
    void PostOrder_Trav(Node_Tree *ptr)
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

    // Creation of Tree
    void CreationOfTree()
    {
        // Node_Tree *newNode = new Node_Tree();
        Root = new Node_Tree();
        Create_subTree(Root);
    }

    // Creation of Sub Tree
    void Create_subTree(Node_Tree *newNode)
    {
        std::cout << "Enter the value you want to insert at Current Node\t";
        std::cin >> item;
        newNode->info = item;
        bool op_left, op_right;

        std::cout << "Do you want Left Child of Node with value " << newNode->info << " (1 for Yes and 0 for No)?\t";
        std::cin >> op_left;
        if (op_left == true)
        {
            newNode->Left = new Node_Tree();
            Create_subTree(newNode->Left);
        }
        else
        {
            newNode->Left = NULL;
        }

        std::cout << "Do you want Right Child of Node with value " << newNode->info << " (1 for Yes and 0 for No)?\t";
        std::cin >> op_right;
        if (op_right == true)
        {
            newNode->Right = new Node_Tree();
            Create_subTree(newNode->Right);
        }
        else
        {
            newNode->Right = NULL;
        }
        return;
    }


	//Searching
	void Simple_Searching()
	{
		if(Root == NULL)
		{
			std::cout<<"Empty Tree\n";
			system("pause");
			return;
		}
		while(1)
		{
			std::cout<<"(In Simple Tree Search Menu)\n"
						"Press\n"
						"1)Single Search\n"
						"2)MultiSearch\n"
						"3)Return\t";
			std::cin>> choice;
			switch(choice)
			{
				case 1:
				{
					std::cout<<"Enter Item to Search\n";
					std::cin>>item;
					count = 0;
					Search_Simple(Root , item);
					if(count == 0)
					{
						std::cout<<"Item not Found\n";	
					}
					else
					{
						std::cout<<"Item Found\n";	
					}
					system("pause");	
				}
				break;
				case 2:
				{
					std::cout<<"Enter Item to Search\n";
					std::cin>>item;
					count = 0;
					Search_Simple(Root , item);
					if(count == 0)
					{
						std::cout<<"Item not Found\n";	
					}
					else
					{
						std::cout<<item<<" found "<<count<<" times\n";	
					}
					system("pause");
				}
				break;
				case 3:
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
	
	
	//Search Method
	void Search_Simple(Node_Tree *ptr, int item)
	{
		if(ptr->info == item)
		{
			count++;	
		}
		if(ptr-> Left != NULL)
		{
			Search_Simple(ptr->Left , item);
		}
		if(ptr->Right != NULL)
		{
			Search_Simple(ptr->Right , item);
		}	
	}
	
	
	
	//BST Method
	void BST()
	{
		while(1)
		{
			system("cls");
			std::cout<<"(In BST Menu)\n"
						"Press\n"
						"1)Traversal\n"
						"2)Insertion\n"
						"3)Deletion\n"
						"4)Searching\n"
						"5)Return\t";
			std::cin>>choice;
			switch(choice)
			{
				case 1:
				{
					Traversal();
				}
				break;
				case 2:
				{
					std::cout << "Enter the item to Insert: \t";
	                std::cin >> item;
	                Root = Insert_BST(Root, item);	
				}
				break;
				case 3:
				{
					std::cout << "Enter the item to Delete: \t";
	                std::cin >> item;
	                Root = Delete_BST(Root, item);
				}
				break;
				case 4:
				{
					Searching_BST();
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
	
    // Insertion in BST
    Node_Tree *Insert_BST(Node_Tree *Root, int item)
    {
        if (Root == NULL)
        {
            Node_Tree *Node = new Node_Tree();
            Node->info = item;
            Node->Left = NULL;
            Node->Right = NULL;
            return Node;
        }
        if ((Root->info) > item)
        {
            Root->Left = Insert_BST(Root->Left, item);
        }
        else
        {
            if ((Root->info) < item)
            {
                Root->Right = Insert_BST(Root->Right, item);
            }
            else
            {
                std::cout << "Item already exist\n";
                system("pause");
            }
        }
        return Root;
    }
    
    
    // InOrder Successor
    Node_Tree *InOrderSuccessor(Node_Tree *Root)
    {
        Node_Tree *ptr = Root->Right;
        while (ptr->Left != NULL)
        {
            ptr = ptr->Left;
        }
        return ptr;
    }
    
    
    //Deletion in BST
    Node_Tree *Delete_BST(Node_Tree *Root, int item)
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
            Root->Left = Delete_BST(Root->Left, item);
        }
        else if (item > Root->info)
        {
            Root->Right = Delete_BST(Root->Right, item);
        }
        else
        {
            Node_Tree *ptr;
            ptr = InOrderSuccessor(Root);
            Root->info = ptr->info;
            Root->Right = Delete_BST(Root->Right, ptr->info);
        }
	}			
    
     // Searching in BST
    void Searching_BST()
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
        Node_Tree *ptr = Root;

        while (ptr->Left != NULL)
        {
            ptr = ptr->Left;
        }
        std::cout << "Mininmum Value is\t" << ptr->info << std::endl;
    }

    // Maximum Value
    void Search_Max()
    {
        Node_Tree *ptr = Root;

        while (ptr->Right != NULL)
        {
            ptr = ptr->Right;
        }
        std::cout << "Mininmum Value is\t" << ptr->info << std::endl;
    }

    // Search by Value
    void Search_Item(Node_Tree *ptr)
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
};
