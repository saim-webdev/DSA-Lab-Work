#include <iostream>
using namespace std;
void selectionSort(int arr[], int n)
{
    int minIndex, temp;
                                           // Loop for each position in the array
    for (int i = 0; i < n - 1; i++)
    {
        minIndex = i;
                                             // Find the smallest element in remaining array
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
                                       // Swap smallest element with current position
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
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
	int arr[10] = {34, 30, 56, 28, 68, 40, 36, 10, 32, 43};
    int n = 10;

    cout << "Array before sorting:\n";
    display(arr, n);

  
    selectionSort(arr, n);

    cout << "\nArray after Selection Sort (Ascending Order):\n";
    display(arr, n);

    return 0;
}
