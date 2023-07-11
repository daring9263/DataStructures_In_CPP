#include <iostream>

// Array
class Array
{
public:
    int size, k, item, n = 0;
    const int lb = 0;
    int *A;
    Array()
    {
        system("cls");
        std::cout << "Enter the size of array\t";
        std::cin >> size;
        A = new int[size];
        Choices();
    }

    // Choices:
    void Choices()
    {
        int choice;
        while (1)
        {
            system("cls");
            std::cout << "(Array Menu)\n"
                         "Select your Choice:\n"
                         "1)Traverse\n"
                         "2)Insertion\n"
                         "3)Deletion\n"
                         "4)Searching\n"
                         "5)Sorting\n"
                         "6)Merging\n"
                         "7)Back to Main Menu\t";
            std::cin >> choice;
            switch (choice)
            {
            case 1:
                Traverse();
                break;
            case 2:
                Insertion();
                break;
            case 3:
                Deletion();
                break;
            case 4:
                Searching();
                break;
            case 5:
                Sorting();
                break;
            case 6:
                Merging();
                break;
            case 7:
                return;
            default:
                std::cout << "Invalid Selection\n";
                system("pause");
            }
        }
    }

    // Traverse:
    void Traverse()
    {
        if (n == 0)
        {
            std::cout << "Array is empty\n";
            system("pause");
            return;
        }
        std::cout << "Your Array is:\n";
        for (int i = lb; i <= (n + lb - 1); i++)
        {
            std::cout << "[" << A[i] << "]\t";
        }
        system("pause");
    }

    // Insertion:
    void Insertion()
    {
        if (n == size)
        {
            std::cout << "Array is already Full\n";
            system("pause");
            return;
        }
        std::cout << "Enter the value you want to insert:\t";
        std::cin >> item;
        std::cout << "Enter the position in which you want to insert the element:\t";
        std::cin >> k;
        if ((k < lb) || (k > (n + lb)))
        {
            std::cout << "Inavalid Position\n";
            system("pause");
            return;
        }
        else
        {
            for (int i = (n + lb - 1); i >= k; i--)
            {
                A[i + 1] = A[i];
            }
            A[k] = item;
            n++;
        }
    }

    // Deletion:
    void Deletion()
    {
        if (n == 0)
        {
            std::cout << "Array is Empty\n";
            system("pause");
            return;
        }
        std::cout << "Enter the position of value you want to delete\t";
        std::cin >> k;
        if ((k < lb) || (k > (n + lb - 1)))
        {
            std::cout << "You have chosen invalid postion\n";
            system("pause");
            return;
        }
        else
        {
            item = A[k];
            for (int i = (k + 1); i <= (n + lb - 1); i++)
            {
                A[i - 1] = A[i];
            }
            n--;
        }
    }

    // Searching:
    void Searching()
    {
        if (n == 0)
        {
            std::cout << "You have nothing to search as array is empty\n";
            system("pause");
            return;
        }
        int search;
        while (1)
        {
            system("cls");
            std::cout << "(Array Searching Menu)\n"
                         "Press\n"
                         "1)Single Search\n"
                         "2)MultiSearch\n"
                         "3)Return\t";
            std::cin >> search;
            switch (search)
            {
            case 1:
                SingleSearch();
                break;
            case 2:
                Multisearch();
                break;
            case 3:
                return;
                break;
            default:
                std::cout << "Invalid search type\n";
                system("pause");
            }
        }
    }

    // SinlgeSearch:
    void SingleSearch()
    {
        std::cout << "Enter the value which you want to searh for\t";
        std::cin >> item;
        int searchtype;
        std::cout << "(Array Single Search Menu)\n"
                     "Choose your operation\n"
                     "1)Linear Search\n"
                     "2)Binary Search\t";
        std::cin >> searchtype;
        switch (searchtype)
        {
        case 1:
        {
            for (int i = lb; i <= (n + lb - 1); i++)
            {
                if (A[i] == item)
                {
                    std::cout << item << " Found\n";
                    system("pause");
                    return;
                }
            }
            std::cout << item << " not Found\n";
            system("pause");
        }
        break;
        case 2:
        {
            QuickSort();
            int low = lb;
            int high = (n + lb - 1);
            int mid;
            while (low <= high)
            {
                mid = (low + high) / 2;
                if (A[mid] == item)
                {
                    std::cout << item << " found\n";
                    system("pause");
                    return;
                }
                else if (A[mid] > item)
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            std::cout << item << " not found\n";
            system("pause");
        }
        break;
        default:
            std::cout << "Invalid Selection\n";
            system("pause");
        }
    }

    // MultiSearch:
    void Multisearch()
    {
        std::cout << "Enter the value which you want to searh for\t";
        std::cin >> item;
        int count = 0, searchtype;
        std::cout << "(Array Multi Search Menu)\n"
                     "Choose your operation\n"
                     "1)Linear Search\n"
                     "2)Binary Search\t";
        std::cin >> searchtype;
        switch (searchtype)
        {
        case 1:
        {
            for (int i = lb; i <= (n + lb - 1); i++)
            {
                if (A[i] == item)
                {
                    count += 1;
                }
            }
            if (count == 0)
            {
                std::cout << item << " not found\n";
                system("pause");
                return;
            }
            else
            {
                std::cout << item << " found " << count << " times\n";
                system("pause");
            }
        }
        break;
        case 2:
        {
            QuickSort();
            int low = lb;
            int high = (n + lb - 1);
            int mid;
            while (low <= high)
            {
                mid = (low + high) / 2;
                if (A[mid] == item)
                {
                    count++;
                    int i = mid - 1;
                    while ((i >= lb) && (A[i] == item))
                    {
                        count++;
                        i--;
                    }
                    i = mid + 1;
                    while ((i < (n + lb)) && (A[i] == item))
                    {
                        count++;
                        i++;
                    }
                    std::cout << item << " found " << count << " times\n";
                    system("pause");
                    return;
                }
                else if (A[mid] > item)
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            std::cout << "Item not found\n";
            system("pause");
        }
        break;
        default:
            std::cout << "Invalid Selection\n";
            system("pause");
        }
    }

    // Sorting
    void Sorting()
    {
        if (n == 0)
        {
            std::cout << "You have nothing to sort as array is empty\n";
            return;
        }
        int sorttype;
        system("cls");
        std::cout << "(Array Sorting Menu)\n"
                     "Press\n"
                     "1 for Bubble Sort\n"
                     "2 for Selection Sort\n"
                     "3 for Insertion Sort\n"
                     "4 for Shell Sort\n"
                     "5 for Merge Sort\n"
                     "6 for Quick Sort\t";
        std::cin >> sorttype;
        switch (sorttype)
        {
        case 1:
        {
            BubbleSort();
        }
        break;
        case 2:
        {
            SelectionSort();
        }
        break;
        case 3:
        {
            InsertionSort();
        }
        break;
        case 4:
        {
            ShellSort();
        }
        break;
        case 5:
        {
            MergeSort();
        }
        break;
        case 6:
        {
            QuickSort();
            std::cout << "Array has been Ascendingly Sorted by Quick Sort\n";
            system("pause");
        }
        break;
        default:
            std::cout << "Invalid Selection\n";
            system("pause");
        }
    }

    // BubbleSorting
    void BubbleSort()
    {
        std::cout << "Press 1 for Ascending Sorting\n"
                     "Press 2 for Descending Sorting\t";
        int bubblesorttype;
        std::cin >> bubblesorttype;
        int last = (n + lb - 1);
        switch (bubblesorttype)
        {
        case 1:
        {
            while (last > 0)
            {
                for (int i = lb; i <= (last - 1); i++)
                {
                    if (A[i] > A[i + 1])
                    {
                        std::swap(A[i], A[i + 1]);
                    }
                }
                last--;
            }
            std::cout << "Your array has been sorted Ascendingly by Bubble Sort\n";
            system("pause");
        }
        break;
        case 2:
        {
            while (last > 0)
            {
                for (int i = lb; i <= (last - 1); i++)
                {
                    if (A[i] < A[i + 1])
                    {
                        std::swap(A[i], A[i + 1]);
                    }
                }
                last--;
            }
            std::cout << "Your array has been sorted Descendingly by Bubble Sort\n";
            system("pause");
        }
        break;
        default:
            std::cout << "Invalid Selection\n";
            system("pause");
        }
    }

    // Selection Sort
    void SelectionSort()
    {
        int selectionsorttype;
        std::cout << "Enter 1 for Ascending Sort\n"
                     "Enter 2 for Descending Sort\t";
        std::cin >> selectionsorttype;
        int first = lb;
        switch (selectionsorttype)
        {
        case 1:
        {
            while (first < (n + lb - 1))
            {
                int min = first;
                for (int j = (first + 1); j <= (n + lb - 1); j++)
                {
                    if (A[min] > A[j])
                    {
                        min = j;
                    }
                }
                std::swap(A[min], A[first]);
                first++;
            }
            std::cout << "Your array has been sorted Ascendingly by Selection Sort\n";
            system("pause");
        }
        break;
        case 2:
        {
            while (first < (n + lb - 1))
            {
                int max = first;
                for (int j = (first + 1); j <= (n + lb - 1); j++)
                {
                    if (A[max] < A[j])
                    {
                        max = j;
                    }
                }
                std::swap(A[max], A[first]);
                first++;
            }
            std::cout << "Your array has been sorted Descendingly by Selection Sort\n";
            system("pause");
        }
        break;
        default:
        {
            std::cout << "Invalid Selection\n";
            system("pause");
        }
        }
    }

    // Insertion Sort
    void InsertionSort()
    {
        int insertionsorttype;
        std::cout << "Enter 1 for Ascending Sort\n"
                     "Enter 2 for Descending Sort\t";
        std::cin >> insertionsorttype;
        switch (insertionsorttype)
        {
        case 1:
        {
            for (int last = (lb + 1); last <= (n + lb - 1); last++)
            {
                int min = A[last];
                int i = last - 1;
                while ((i >= lb) && (A[i] > min))
                {
                    A[i + 1] = A[i];
                    i--;
                }
                A[i + 1] = min;
            }
            std::cout << "Your array has been sorted Ascendingly by Insertion Sort\n";
            system("pause");
        }
        break;
        case 2:
        {
            for (int last = (lb + 1); last <= (n + lb - 1); last++)
            {
                int max = A[last];
                int i = last - 1;
                while ((i >= lb) && (A[i] < max))
                {
                    A[i + 1] = A[i];
                    i--;
                }
                A[i + 1] = max;
            }
            std::cout << "Your array has been sorted Descendingly by Insertion Sort\n";
            system("pause");
        }
        break;
        default:
        {
            std::cout << "Invalid Position\n";
            system("pause");
        }
        }
    }

    // Shell Sort
    void ShellSort()
    {
        int shellsorttype;
        std::cout << "Enter 1 for Ascending Sort\n"
                     "Enter 2 for Descending Sort\t";
        std::cin >> shellsorttype;
        int gap = n / 2;
        switch (shellsorttype)
        {
        case 1:
        {
            while (gap != 0)
            {
                for (int last = (lb + gap); last <= (n + lb - 1); last++)
                {
                    int min = A[last];
                    int i = last - gap;
                    while ((i >= lb) && (A[i] > min))
                    {
                        A[i + gap] = A[i];
                        i = i - gap;
                    }
                    A[i + gap] = min;
                }
                gap = gap / 2;
            }
            std::cout << "Your array has been sorted Ascendingly by Shell Sort\n";
            system("pause");
        }
        break;
        case 2:
        {
            while (gap != 0)
            {
                for (int last = (lb + gap); last <= (n + lb - 1); last++)
                {
                    int max = A[last];
                    int i = last - gap;
                    while ((i >= lb) && (A[i] < max))
                    {
                        A[i + gap] = A[i];
                        i = i - gap;
                    }
                    A[i + gap] = max;
                }
                gap = gap / 2;
            }
            std::cout << "Your array has been sorted Descendingly by Shell Sort\n";
            system("pause");
        }
        break;
        default:
        {
            std::cout << "Invalid Position\n";
            system("pause");
        }
        }
    }

    // Merge Sort
    void Merge(int low, int mid, int high)
    {
        int nl = (mid - low + 1);
        int nr = high - mid;
        k = lb;
        int Left[nl];
        int Right[nr];
        for (int i = low; i <= mid; i++)
        {
            Left[k] = A[i];
            k++;
        }
        k = lb;
        for (int i = (mid + 1); i <= high; i++)
        {
            Right[k] = A[i];
            k++;
        }
        int ptra, ptrl, ptrr;
        ptrl = ptrr = lb;
        ptra = low;

        while ((ptrl <= (nl + lb - 1)) && (ptrr <= (nr + lb - 1)))
        {
            if (Left[ptrl] < Right[ptrr])
            {
                A[ptra] = Left[ptrl];
                ptrl++;
            }
            else
            {
                A[ptra] = Right[ptrr];
                ptrr++;
            }
            ptra++;
        }
        if (ptrl > (nl + lb - 1))
        {
            for (int i = ptrr; i <= (nr + lb - 1); i++)
            {
                A[ptra] = Right[i];
                ptra++;
            }
        }
        else
        {
            for (int i = ptrl; i <= (nl + lb - 1); i++)
            {
                A[ptra] = Left[i];
                ptra++;
            }
        }
    }

    void MergeSort_sub(int low, int high)
    {
        if (low < high)
        {
            int mid = (low + high) / 2;
            MergeSort_sub(low, mid);
            MergeSort_sub((mid + 1), high);
            Merge(low, mid, high);
        }
    }

    void MergeSort()
    {
        int low = lb;
        int high = (n + lb - 1);
        MergeSort_sub(low, high);
        std::cout << "Array has been Ascendingly Sorted by Merge Sort\n";
        system("pause");
    }

    // Quick Sort
    int Partition(int low, int high)
    {
        int pivot = A[high];
        int i = low - 1;
        for (int j = low; j < high; j++)
        {
            if (A[j] <= pivot)
            {
                i++;
                std::swap(A[i], A[j]);
            }
        }
        std::swap(A[i + 1], A[high]);
        return (i + 1);
    }

    // QuickSOrt Sub
    void QuickSort_sub(int low, int high)
    {
        if (low < high)
        {
            int index = Partition(low, high);
            QuickSort_sub(low, (index - 1));
            QuickSort_sub((index + 1), high);
        }
    }

    void QuickSort()
    {
        int low = lb;
        int high = (n + lb - 1);
        QuickSort_sub(low, high);
    }

    // Merging
    void Merging()
    {
        int na, nb;
        std::cout << "Enter size of first Array\t";
        std::cin >> na;
        int Aa[na];
        std::cout << "Enter values in your first Array\n"
                     "Values must be in Ascending Order\t";
        for (int i = lb; i < na; i++)
        {
            std::cin >> Aa[i];
        }
        std::cout << "Enter size of second Array\t";
        std::cin >> nb;
        int B[nb];
        std::cout << "Enter values in your second Array\n"
                     "Values must be in Ascending Order\t";
        for (int i = lb; i < nb; i++)
        {
            std::cin >> B[i];
        }
        int nc = na + nb;
        int C[nc];
        int ptra, ptrb, ptrc;
        ptra = ptrb = ptrc = lb;

        while ((ptra <= (na + lb - 1)) && (ptrb <= (nb + lb - 1)))
        {
            if (Aa[ptra] < B[ptrb])
            {
                C[ptrc] = Aa[ptra];
                ptra++;
            }
            else
            {
                C[ptrc] = B[ptrb];
                ptrb++;
            }
            ptrc++;
        }
        if (ptra > (na + lb - 1))
        {
            for (int i = ptrb; i <= (nb + lb - 1); i++)
            {
                C[ptrc] = B[i];
                ptrc++;
            }
        }
        else
        {
            for (int i = ptra; i <= (na + lb - 1); i++)
            {
                C[ptrc] = Aa[i];
                ptrc++;
            }
        }
        std::cout << "Your fisrt Array is:\n";
        for (int i = lb; i < na; i++)
        {
            std::cout << "[" << Aa[i] << "]\t";
        }
        std::cout << "\nYour second Array is:\n";
        for (int i = lb; i < nb; i++)
        {
            std::cout << "[" << B[i] << "]\t";
        }
        std::cout << "\nYour New Array(Merged Array) is:\n";
        for (int i = lb; i < nc; i++)
        {
            std::cout << "[" << C[i] << "]\t";
        }
        system("pause");
    }
};