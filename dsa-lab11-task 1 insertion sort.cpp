#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    int key, j;

    for (int i = 1; i < n; i++)
    {
        key = arr[i];   // element to be inserted
        j = i - 1;
                                             // Move elements greater than key one position ahead
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }                                // Insert key at correct position
        arr[j + 1] = key;
    }
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[10] = {45, 30, 55, 28, 60, 42, 35, 50, 32, 48};
    int n = 10;

    cout << "Array before sorting:\n";
    display(arr, n);
    
    insertionSort(arr, n);

    cout << "\nArray after Insertion Sort (Ascending Order):\n";
    display(arr, n);

    return 0;
}
