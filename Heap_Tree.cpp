#include <iostream>
#include<queue>
class Heap
{
public:
	int quee[100];
    int F, R, choice, item;

    Heap()
    {
        while (1)
        {
            system("cls");
            std::cout << "(In Heap Menu)\n"
                    "Press\n"
                    "1)Max Heap\n"
                    "2)Min Heap\n"
                    "3)Return\t";
            std::cin >> choice;
            switch (choice)
            {
            case 1:
            {
                MaxHeap();
            }
            break;
            case 2:
            {
                MinHeap();
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

    // Max Heap Menu
    void MaxHeap()
    {
        F = R = -1;
        while (1)
        {
            system("cls");
            std::cout << "(In Max Heap Menu)\n"
                    "Press\n"
                    "1)Traversal\n"
                    "2)Insertion\n"
                    "3)Deletion\n"
                    "4)Return\t";
            std::cin >> choice;
            switch (choice)
            {
            case 1:
            {
                Trav_Heap();
            }
            break;
            case 2:
            {
                std::cout << "Enter item to insert\n";
                std::cin >> item;
                Insert_MaxHeap(item);
            }
            break;
            case 3:
            {
                Delete_Max();
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

    // Min Heap Menu
    void MinHeap()
    {
        F = R = -1;
        while (1)
        {
            system("cls");
            std::cout << "(In Min Heap Menu)\n"
                    "Press\n"
                    "1)Traversal\n"
                    "2)Insertion\n"
                    "3)Deletion\n"
                    "4)Return\t";
            std::cin >> choice;
            switch (choice)
            {
            case 1:
            {
                Trav_Heap();
            }
            break;
            case 2:
            {
                std::cout << "Enter item to insert\n";
                std::cin >> item;
                Insert_MinHeap(item);
            }
            break;
            case 3:
            {
            	Delete_Min();
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

    //Insert in Max Heap
    void Insert_MaxHeap(int item)
    {
        if (F == -1)
        {
            F = R = 0;
        }
        else
        {
            R++;
        }
        quee[R] = item;

        int index = R;

        while (index > 0)
        {
            int parent = (index - 1) / 2;

            if (quee[index] > quee[parent])
            {
                std::swap(quee[index], quee[parent]);
                index = parent;
            }
            else
            {
            	break;
			}
        }
    }
    
    
    // Deletionn in Max Heap
    void Delete_Max()
    {
        if (F == -1)
        {
            std::cout << "Empty Heap\n";
            system("pause");
        }
        else
        {
            std::swap(quee[F], quee[R]);
            R--;
            
            int index = F;
            while (true)
            {
                int LeftChild = (2 * index) + 1;
                int RightChild = (2 * index) + 2;
                
                int largest = index;

                if (LeftChild <= R && quee[largest] < quee[LeftChild])
                {
                    largest = LeftChild;
                }
                if (RightChild <= R && quee[largest] < quee[RightChild])
                {
                    largest = RightChild;
                }
                
                if(largest == index)
                {
                	break;
				}
				
				std::swap(quee[largest], quee[index]);
				index = largest;
            }
        }
    }

    // Insert in Min Heap
    void Insert_MinHeap(int item)
    {
        if (F == -1)
        {
            F = R = 0;
        }
        else
        {
            R++;
        }
        quee[R] = item;

        int index = R;

        while (index > 0)
        {
            int parent = (index - 1) / 2;

            if (quee[index] < quee[parent])
            {
                std::swap(quee[index], quee[parent]);
                index = parent;
            }
        }
    }
    
    
    // Deletionn in Min Heap
    void Delete_Min()
    {
        if (F == -1)
        {
            std::cout << "Empty Heap\n";
            system("pause");
        }
        else
        {
            std::swap(quee[F], quee[R]);
            R--;
            
            int index = F;
            while (true)
            {
                int LeftChild = (2 * index) + 1;
                int RightChild = (2 * index) + 2;
                
                int smallest = index;

                if (LeftChild <= R && quee[smallest] > quee[LeftChild])
                {
                    smallest = LeftChild;
                }
                if (RightChild <= R && quee[smallest] > quee[RightChild])
                {
                    smallest = RightChild;
                }
                
                if(smallest == index)
                {
                	break;
				}
				
				std::swap(quee[smallest], quee[index]);
				index = smallest;
            }
        }
    }

    // Display Method for Both
    void Trav_Heap()
    {
        if (F == -1)
        {
            std::cout << "Heap is Empty\n";
        }
        else
        {
            std::cout << "Heap is:\n";
            for (int i = F; i <= R; i++)
            {
                std::cout << "[" << quee[i] << "]\t";
            }
        }
        system("pause");
    }
    
    
    
//     void BFS_Trav()
//     {
//     	if (F == -1)
// 	    {
// 	        cout << "Heap is Empty\n";
// 	        return;
// 	    }
	    
//     	queue<int> pqmax;
    	
//     	pqmax.push(quee[F]);
    	
//     	while(!pqmax.empty())
//     	{
// //    		int value = pqmax.top();
// //    		pqmax.pop();
// //    		std::cout<<"\t"<<value<<"\t";
// //    		
// //    		while(!pqmax.empty())
// //    		{
// //    			for(int i=F; i<= R; i++)
// //    			{
// //    				int left = 2*i + 1;
// //	    			int right = 2*i + 2;
// //	    			
// //	    			if(left <= R)
// //	    			{
// //	    				pqmax.push(quee[left]);
// //					}
// //					
// //					if(right <= R)
// //					{
// //						pqmax.push(quee[right]);
// //					}	
// //				}	
// //			}
			
// 		        int current = pqmax.front();
// 		        pqmax.pop();
// 		        cout << "[" << current << "]\t";
				
// 				for(int i=F; i<= R; i++)
// 				{
// 			        int leftChild = 2 * F + 1;
// 			        int rightChild = 2 * F + 2;
			
// 			        if (leftChild <= R)
// 			            pqmax.push(leftChild);
			
// 			        if (rightChild <= R)
// 			            pqmax.push(rightChild);
// 				}
		    
// 		}
// 	}
};
