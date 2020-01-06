#include "Sort.h"

// Tìm min rồi dồn về đầu
void SelectionSort(int a[], int n) {

    // Quét từ đầu đến cuối mảng
    for (int i = 0; i < n-1; i++) {

        // Gán min bằng phần tử thứ i
        int minIdx = i;
        int minVal = a[i];
        // [ min1,min2....a[i]=min.........a[j] ]

        // Quét từ i + 1 đến cuối mảng
        for (int j = i + 1; j < n; j++) {
            // a[i].......a[j]...

            // Tìm min
            if (a[j] < minVal) {
                minIdx = j;
                minVal = a[j];
            }
            // [ min1,min2....a[i]......min..... ]
        }

        // Swap min và a[i]
        a[minIdx] = a[i];
        a[i] = minVal;
        // [ min1,min2....min......a[i]..... ]

        // Tăng i rồi tiếp tục tìm min để dồn về
    }
}


// Lấy từng phần tử chèn vào mảng đứng trước nó theo thứ tự
void InsertionSort(int a[], int n) {

    // Quét từ phần tử thứ 2 đến hết mảng
    for (int i = 1; i < n; i++) {
        int cur = a[i];
        int j = i - 1;

        // Quét từ j về trước
        while (j >= 0 && a[j] > cur) {

            // Dịch các phần tử đã quét lớn hơn cur lên 1 vị trí (đè lên a[i])
            a[j + 1] = a[j];

            j--;
        }
        // [ ...a[j]=N,L1,L2,L3,....cur ]
        // [ ...a[j]=N,L1,L1,L2,....Ln ]

        // Chèn cur vào ngay sau phần tử nhỏ hơn nó
        a[j + 1] = cur;
        // [ ...a[j]=N,cur,L1,L2,....Ln ]
    }

    // Tăng i lên rồi tiếp tục lùi về để chèn
}

int BinarySearch(int a[], int item, int low, int high)
{ 
    if (high <= low) {
        return (item > a[low]) ? (low + 1) : low;
    }
  
    int mid = (low + high) / 2; 
  
    if (item == a[mid]) {
        return mid + 1;
    }
  
    if (item > a[mid]) {
        return BinarySearch(a, item, mid+1, high); 
    }

    return BinarySearch(a, item, low, mid-1); 
} 
  
// Function to sort an array a[] of size 'n'
void BinaryInsertionSort(int a[], int n) 
{ 
    int i, loc, j, k, selected; 
  
    for (i = 1; i < n; ++i) {
        j = i - 1;
        selected = a[i];
  
        // find location where selected sould be inseretd 
        loc = BinarySearch(a, selected, 0, j); 
  
        // Move all elements after location to create space 
        while (j >= loc) {
            a[j+1] = a[j]; 
            j--; 
        } 

        a[j+1] = selected; 
    } 
} 


// Sắp xếp 2 phần tử kề nhau theo thứ thứ tự từ cuối mảng đến đầu mảng 
void BubbleSort(int a[], int n) {

    // Quét từ phần tử thứ 2 đến hết mảng
    for (int i = 1; i < n; i++) {

        // Quét từ phần tử cuối ngược về phẩn tử thứ i, đẩy min về a[i-1]
        for (int j = n - 1; j >= i; j--) {

            // Swap nếu 2 phần tử ngược thứ tự
            if (a[j] < a[j - 1]) {
                std::swap(a[j], a[j - 1]);
            }
        }
        // [ min1, min2,...a[i]=min.... ]

        // Tăng i lê rồi tiếp tục lùi về sắp xếp
    }
}

void ShakerSort(int a[], int n)
{
    int Left = 0;
    int Right = n - 1;
    int k = 0;
    while (Left < Right) {
        for (int i = Left; i < Right; i++) {
            if (a[i] > a[i + 1]) {
                std::swap(a[i], a[i + 1]);
                k = i;
            }
        }
        Right = k;
        for (int i = Right; i > Left; i--) {
            if (a[i] < a[i - 1]) {
                std::swap(a[i], a[i - 1]);
                k = i;
            }
        }
        Left = k;
    }
}

void ShellSort(int arr[], int n) 
{ 
    // Start with a big gap, then reduce the gap 
    for (int gap = n/2; gap > 0; gap /= 2) {
        // Do a gapped insertion sort for this gap size. 
        // The first gap elements a[0..gap-1] are already in gapped order 
        // keep adding one more element until the entire array is
        // gap sorted
        for (int i = gap; i < n; i++) {
            // add a[i] to the elements that have been gap sorted 
            // save a[i] in temp and make a hole at position i
            int temp = arr[i]; 
  
            // shift earlier gap-sorted elements up until the correct  
            // location for a[i] is found 
            int j;             
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap]; 
            }
              
            //  put temp (the original a[i]) in its correct location 
            arr[j] = temp; 
        }
    } 
}

// Xây dựng Heap (lá cha luôn lớn hơn các lá con)
void Heapify(int arr[], int n, int i) {
    //       i (iMax)
    //      / \
    //   2i+1  2i+2

    // Giả sử iMax là root;
    int iMax = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    // Tìm iMax
    if (left < n && arr[left] > arr[iMax]) {
        iMax = left;
    }
    if (right < n && arr[right] > arr[iMax]) {
        iMax = right;
    }

    // Nếu iMax khác root
    if (iMax != i) {
        std::swap(arr[i], arr[iMax]);

        // Gọi Heapify để xuống xây dựng các nhánh sâu hơn với root=iMax
        Heapify(arr, n, iMax);
    }
}

// Xây dựng Heap, Tách lá và lặp lại với mảng con
void HeapSort(int arr[], int n) {

    // Xây dựng Heap từ nửa mảng đầu
    for (int root = (n - 1) / 2; root >= 0; root--) {
        Heapify(arr, n, root);
    }

    // Tách từng lá lớn nhất ra khỏi heap
    for (int i=n-1; i>=0; i--) {

        // Dời về cuối mảng
        std::swap(arr[0], arr[i]);

        // Gọi lại hàm Heapify cho mảng đã tách các lá max
        Heapify(arr, i, 0);
    }
}

// Gộp 2 mảng đã sắp xếp vào mảng thứ ba 
void MergeArray(int a[], int na, int b[], int nb, int c[]) {
    int nc = na + nb;
    int ia = 0;
    int ib = 0;
    int i = 0;

    while (true) {

        // Phần tử mảng nào nhỏ hơn thì gán vào c[i] và tăng vị trí đang xét trong mảng đó lên 1
        c[i++] = (a[ia] < b[ib]) ? a[ia++] : b[ib++];
        
        // Nếu 1 trong 2 mảng đã xét hết, thì copy toàn bộ mảng còn lại vào mảng c và kết thúc
        if (ia == na) {
            std::copy(b+ib, b+nb, c+i);
            return;
        }
        else if (ib == nb) {
            std::copy(a+ia, a+na, c+i);
            return;
        }
    }
}

// Chia mảng làm đôi đến khi còn 1 phần tử, sau đó gộp ngược lại
void MergeSort(int a[], int n)
{
    if (n > 1) {

        // Chia mảng thành 2 mảng con
        int mid = n / 2;
        int *a1 = new int [mid];
        int *a2 = new int [n-mid];
        std::copy(a, a+mid, a1);
        std::copy(a+mid, a+n, a2);

        // Gọi đệ quy lại cho đến khi mảng con chỉ chứa 1 phần tử
        MergeSort(a1, mid);
        MergeSort(a2, n - mid);

        // Gộp các mảng đã sắp xếp vào lại a
        MergeArray(a1, mid, a2, n - mid, a);

        // Xóa đi các mảng con đã cấp phát
        delete[] a1;
        delete[] a2;
    }
}

int Partition(int arr[], int low, int high) {
    int pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than or 
        // equal to pivot
        if (arr[j] <= pivot) {
            i++;    // increment index of smaller element
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
} 
  
// Generates Random Pivot, swaps pivot with 
// end element and calls the partition function 
// In Hoare partition the low element is selected 
// as first pivot 
int Partition_r(int arr[], int low, int high) 
{ 
    // Generate a random number in between 
    // low .. high 
    srand(time(NULL)); 
    int random = low + rand() % (high - low); 
  
    // Swap A[random] with A[low] 
    std::swap(arr[random], arr[high]);
  
    return Partition(arr, low, high); 
}

// Tìm pi trong mảng, sau đó đệ quy tìm tiếp trong 2 mảng con của nó đến khi theo thứ tự
void QuickSort(int a[], int left, int right)
{
    while (left < right-1) {
        
        // Tìm pi: [ left,N....N, pi ,L....L,right ]
        int pi = Partition_r(a, left, right);
  
        // Phần bên nào nhỏ hơn thì lặp lại phần bên đó
        // Và xử lí phần còn lại lặp đi lặp lại
        if (pi - left < right - pi) {
            QuickSort(a, left, pi - 1);
            left = pi + 1;
        }
        else {
            QuickSort(a, pi + 1, right);
            right = pi - 1;
        }
    }
}

void CountingSort(int a[], int n)
{
    int *output = new int [n]; // The output will have sorted a array
    int max = a[0];
    int min = a[0];
 
    int i;
    for (i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i]; // Maximum value in array
        }
        else if (a[i] < min) {
            min = a[i]; // Minimum value in array
        }
    }
 
    int k = max - min + 1; // Size of count array
 
    int *count_array = new int [k]; // Create a count_array to store count of each individual a value

    for (int i = 0; i < k; ++i) {
        count_array[i] = 0;
    }
 
    for (i = 0; i < n; i++) {
        count_array[a[i] - min]++; // Store count of each individual a value
    }
 
    /* Change count_array so that count_array now contains actual
     position of a values in output array */
    for (i = 1; i < k; i++) {
        count_array[i] += count_array[i - 1];
    }
 
    // Populate output array using count_array and a array
    for(i = 0; i < n; i++) {
        output[--count_array[a[i] - min]] = a[i];
    }

    std::copy(output, output + n, a);
    delete[] output;
}

// Tìm số chữ số lớn nhất của các phần tử có trong mảng
int DigitOfMax(int a[], int n) {
    
    // Tìm max
    int max = a[0];
    for (int i = 1; i < n; ++i) {
        if (max < a[i]) {
            max = a[i];
        }
    }
    
    // Tìm số chữ số của max
    int digits = 1;
    while ((max /= 10) > 0) {
        ++digits;
    }
    return digits;
}

// Tìm chữ số thứ k từ phải sang của số num
int Digit(int num, int k) {
    num = num / pow(10, k-1);
    return num % 10;
}

// Sắp xếp mảng theo chữ số thứ k theo Sắp xếp đếm 
void Sort(int a[], int n, int k) {

    // Tạo mảng f gồm 10 phần tử đại diện cho số lượng các số có chữ số thứ k bằng vị trí phần tử mảng
    int f[10] = {0};
    for (int i = 0; i < n; i++) {
        f[Digit(a[i], k)]++;
    }
    // f = [2,1,4....]

    // Cộng dồng mảng f, thì f trở thành mảng đại diện vị trí các phần tử đã sắp xếp (distribution counting)
    for (int i = 1; i < 10; i++) {
        f[i] += f[i - 1];
    }
    // f = [2,3,7,...]

    // Tạo mảng b chứa các phần tử mảng a sẽ được sắp xếp
    int *b = new int [n];

    // Quét từ cuối mảng đến đầu mảng a và chuyển dần vào mảng b
    for (int i = n - 1; i >= 0; i--) {
        int j = Digit(a[i], k);

        // Do f[j] là vị trí các phần tử, mảng b tính từ 0 nên đầu tiên giảm f[j] đi 1
        // Sau khi gán, giảm f[j] đi 1 để chuyển đến phần tử khác có cùng chữ số thứ k do [ ....j,j,j=b[f[j]],j+1,  .... ]
        b[--f[j]] = a[i];
    }

    // Chuyển mảng b vào mảng a và giải phóng bộ nhớ
    std::copy(b, b+n, a);
    delete[] b;
}

// Sắp xếp mảng theo chữ số thứ 1 đến chữ số lớn nhất
void CountingRadixSort(int a[], int n) {

    // Tìm chữ số lớn nhất của các số trong mảng
    int d = DigitOfMax(a, n);

    // Tiến hành sắp xếp mảng theo chữ số thứ k, đi từ LSD
    for (int k = 1; k <= d; k++) Sort(a, n, k);
}

void showArr(int a[], int n) {
    for (std::size_t i = 0; i < n-1; ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << a[n-1] << "\n";
}

long RunSort(int a[], int n, int type, bool show) {

    if (show) {
        std::cout << "Type: " << type << ", Size: " << n;
        std::cout << "\nBefore:\n";
        showArr(a, n);
    }

    // Get starting timepoint
    auto start = std::chrono::high_resolution_clock::now(); 

    // Call the function
    if (type == 0) {
        SelectionSort(a, n);
    } else if (type == 1) {
        InsertionSort(a, n);
    } else if (type == 2) {
        BinaryInsertionSort(a, n);
    } else if (type == 3) {
        BubbleSort(a, n);
    } else if (type == 4) {
        ShakerSort(a, n);
    } else if (type == 5) {
        ShellSort(a, n);
    } else if (type == 6) {
        HeapSort(a, n);
    } else if (type == 7) {
        MergeSort(a, n);
    } else if (type == 8) {
        QuickSort(a, 0, n-1);
    } else if (type == 9) {
        CountingSort(a, n);
    } else if (type == 10) {
        CountingRadixSort(a, n);
    }
    else  {
        FlashSort(a, n);
    }

    // Get ending timepoint
    auto stop = std::chrono::high_resolution_clock::now(); 

    // Get duration. Substart timepoints to  
    // get durarion. To cast it to proper unit 
    // use duration cast method 
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

    if (show) {
        std::cout << "\nAfter:\n";
        showArr(a, n);
    }
    
    return duration.count();
}
 
//The flashsort algorithm is attributed to Karl-Dietrich Neubert
//The translation to C++ is provided by Clint Jed Casper
//
//sorts an array in place in O(n) time using 20% of the
//memory used by the array for storing intermediate,
//temporary computations
void FlashSort(int a[], int n) {
    if (n == 0) return;

    //20% of the number of elements or 0.2n classes will
    //be used to distribute the input data set into
    //there must be at least 2 classes (hence the addition)
    int m = (int)((0.2 * n) + 2);

    //-------CLASS FORMATION-------

    //O(n)
    //compute the max and min values of the input data
    int min, max, maxIndex;
    min = max = a[0];
    maxIndex = 0;

    for (int i = 1; i < n - 1; i += 2) {
        int small;
        int big;
        int bigIndex;

        //which is bigger A(i) or A(i+1)
        if (a[i] < a[i + 1]) {
            small = a[i];
            big = a[i + 1];
            bigIndex = i + 1;
        }
        else {
            big = a[i];
            bigIndex = i;
            small = a[i + 1];
        }

        if (big > max) {
            max = big;
            maxIndex = bigIndex;
        }

        if (small < min) {
            min = small;
        }
    }

    //do the last element
    if (a[n - 1] < min) {
        min = a[n - 1];
    }
    else if (a[n - 1] > max) {
        max = a[n - 1];
        maxIndex = n - 1;
    }

    if (max == min) {
        //all the elements are the same
        return;
    }

    //dynamically allocate the storage for L
    //note that L is in the range 1...m (hence
    //the extra 1)
    int* L = new int[m + 1];
    
    //O(m)
    //initialize L to contain all zeros (L[0] is unused)
    for(int t = 1; t <= m; t++) {
        L[t] = 0;
    }

    //O(n)
    //use the function K(A(i)) = 1 + INT((m-1)(A(i)-Amin)/(Amax-Amin))
    //to classify each A(i) into a number from 1...m
    //(note that this is mainly just a percentage calculation)
    //and then store a count of each distinct class K in L(K)
    //For instance, if there are 22 A(i) values that fall into class
    //K == 5 then the count in L(5) would be 22

    //IMPORTANT: note that the class K == m only has elements equal to Amax

    //precomputed constant
    double c = (m - 1.0) / (max - min);
    int K;
    for (int h = 0; h < n; h++) {
        //classify the A(i) value
        K = ((int)((a[h] - min) * c)) + 1;

        //assert: K is in the range 1...m

        //add one to the count for this class
        L[K] += 1;
    }

    //O(m)
    //sum over each L(i) such that each L(i) contains
    //the number of A(i) values that are in the ith
    //class or lower (see counting sort for more details)
    for (K = 2; K <= m; K++) {
        L[K] = L[K] + L[K - 1];
    }

    //-------PERMUTATION-------

    //swap the max value with the first value in the a
    std::swap(a[maxIndex], a[0]);

    //Except when being iterated upwards,
    //j always points to the first A(i) that starts
    //a new class boundary && that class hasn't yet
    //had all of its elements moved inside its borders;

    //This is called a cycle leader since you know 
    //that you can begin permuting again here. You know
    //this because it is the lowest index of the class
    //and as such A(j) must be out of place or else all
    //the elements of this class have already been placed
    //within the borders of the this class (which means
    //j wouldn't be pointing to this A(i) in the first place)
    int j = 0;
    
    //K is the class of an A(i) value. It is always in the range 1..m
    K = m;

    //the number of elements that have been moved
    //into their correct class
    int numMoves = 0;

    //O(n)
    //permute elements into their correct class; each
    //time the class that j is pointing to fills up
    //then iterate j to the next cycle leader
    //
    //do not use the n - 1 optimization because that last element
    //will not have its count decreased (this causes trouble with
    //determining the correct classSize in the last step)
    while (numMoves < n) {
        //if j does not point to the begining of a class
        //that has at least 1 element still needing to be
        //moved to within the borders of the class then iterate
        //j upward until such a class is found (such a class
        //must exist). In other words, find the next cycle leader
        while (j >= L[K]) {
            j++;
            //classify the A(j) value
            K = ((int)((a[j] - min) * c)) + 1;
        }

        //evicted always holds the value of an element whose location
        //in the a is free to be written into //aka FLASH
        int evicted = a[j];

        //while j continues to meet the condition that it is
        //pointing to the start of a class that has at least one
        //element still outside its borders (the class isn't full)
        while (j < L[K]) {
            //compute the class of the evicted value
            K = ((int)((evicted - min) * c)) + 1;

            //get a location that is inside the evicted
            //element's class boundaries
            int location = --L[K];

            //swap the value currently residing at the new
            //location with the evicted value
            std::swap(a[location], evicted);

            //another element was moved
            numMoves++;
        }
    }

    //-------RECURSION or STRAIGHT INSERTION-------

    //if the classes do not have the A(i) values uniformly distributed
    //into each of them then insertion sort will not produce O(n) results;

    //look for classes that have too many elements; ideally each class
    //(except the topmost or K == m class) should have about n/m elements;
    //look for classes that exceed n/m elements by some threshold AND have
    //more than some minimum number of elements to flashsort recursively

    //if the class has 25% more elements than it should
    int threshold = (int)(1.25 * ((n / m) + 1));
    const int minElements = 30;
    
    //for each class decide whether to insertion sort its members
    //or recursively flashsort its members;
    //skip the K == m class because it is already sorted
    //since all of the elements have the same value
    for (K = m - 1; K >= 1; K--) {
        //determine the number of elments in the Kth class
        int classSize = L[K + 1] - L[K];

        //if the class size is larger than expected but not
        //so small that insertion sort could make quick work
        //of it then...
        if (classSize > threshold && classSize > minElements) {
            //...attempt to flashsort the class. This will work 
            //well if the elements inside the class are uniformly
            //distributed throughout the class otherwise it will 
            //perform badly, O(n^2) worst case, since we will have 
            //performed another classification and permutation step
            //and not succeeded in making the problem significantly
            //smaller for the next level of recursion. However,
            //progress is assured since at each level the elements
            //with the maximum value will get sorted.
            FlashSort(&a[L[K]], classSize);
        }
        else { //perform insertion sort on the class
            if (classSize > 1) {
                InsertionSort(&a[L[K]], classSize);
            }
        }
    }

    delete[] L;
}