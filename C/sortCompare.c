# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
clock_t bTime, qTime, iTime, sTime, mTime;
int bComp, qComp, iComp, sComp, mComp;

void createArray(int m[], int size);
int checkSort(int m[], int size);
int comp (const void * elem1, const void * elem2);
void swap(int *xp, int *yp);
void bubbleSort(int arr[], int n);
int partition (int arr[], int low, int high);
void quickSort(int arr[], int low, int high);
void insertionSort(int arr[], int n);
void selectionSort(int arr[], int n);
void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[],int l,int r);
void printResults(int size);

#define MAX 100
#define MAX_SIZE 10000
int main ()
{
    int m[MAX_SIZE], size = 1000;
    printResults(100);
    printResults(1000);
    printResults(10000);



    return 0;
}
void createArray(int m[], int size)
{
    srand (time(NULL));
    for(int i=0; i<size; ++i)
    {
        m[i] = rand() % MAX;
    }
}
int checkSort(int m[], int size)
{
    int m2[MAX_SIZE];
    memcpy(m2, m, sizeof(int) * size);
    qsort(m2, size, sizeof(int), comp);
    int ans = memcmp(m, m2, sizeof(int) * size);
    if(ans == 0)
        return 1;
    return 0;
}
int comp (const void * elem1, const void * elem2)
{
    int f = *((int*)elem1);
    int s = *((int*)elem2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubbleSort(int arr[], int n)
{
   bTime = clock();
   for (int i = 0; i < n-1; i++)
       for (int j = 0; j < n-i-1; j++)
       {
           bComp++;
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
       }
   //clock_t after = clock();
   bTime = clock() - bTime;
}
int partition (int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        qComp++;
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
    qTime = clock();
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
    qTime = clock() - qTime;
}
void insertionSort(int arr[], int n)
{
    iTime = clock();
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > key)
        {
            iComp++;
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    iTime = clock() - iTime;
}
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    sTime = clock();
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
        {
            sComp++;
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
    sTime = clock() - sTime;
}
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r]

    // Initial index of first subarray
    int i = 0;

    // Initial index of second subarray
    int j = 0;

    // Initial index of merged subarray
    int k = l;

    while (i < n1 && j < n2) {
            mComp++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of
    // L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// l is for left index and r is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int arr[],int l,int r){

    mTime = clock();
    if(l>=r){
        return;//returns recursively
    }
    int m = (l+r-1)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
    mTime = clock() - mTime;
}
void printResults(int size)
{
    int m[size];
    printf("For arrays of size %d\n", size);
    createArray(m, size);
    printf("Function     Comparisons     Time     Correct   \n");
    bubbleSort(m, size);
    printf("Bubble Sort    %8d     %5f s       %d\n", bComp, ((double)bTime)/CLOCKS_PER_SEC, checkSort(m, size));
    createArray(m, size);
    quickSort(m, 0, size-1);
    printf("Quick Sort     %8d     %5f s       %d\n", qComp, ((double)qTime)/CLOCKS_PER_SEC, checkSort(m, size));
    createArray(m, size);
    insertionSort(m, size);
    printf("Insertion Sort %8d     %5f s       %d\n", iComp, ((double)iTime)/CLOCKS_PER_SEC, checkSort(m, size));
    createArray(m, size);
    selectionSort(m, size);
    printf("Selection Sort %8d     %5f s       %d\n", sComp, ((double)sTime)/CLOCKS_PER_SEC, checkSort(m, size));
    createArray(m, size);
    mergeSort(m, 0, size-1);
    printf("Merge Sort     %8d     %5f s       %d\n", mComp, ((double)mTime)/CLOCKS_PER_SEC, checkSort(m, size));
}
