#include <iostream>
using namespace std;
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];  // pivot element
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;   // pivot position
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
                                            // Sort elements before and after partition
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
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
    int arr[11] = {54, 60, 57, 22, 65, 47, 32, 55, 35, 41, 13};
    int n = 11;

    cout << "Array before sorting:\n";
    display(arr, n);

    quickSort(arr, 0, n - 1);

    cout << "\nArray after Quick Sort (Ascending Order):\n";
    display(arr, n);

    return 0;
}
