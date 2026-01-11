#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
                                // Temporary arrays
    int L[n1], R[n2];
                                      // Copy data to temp arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
                                   // Merge temp arrays back into arr[]
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
                                      // Copy remaining elements of L[]
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
                         // Copy remaining elements of R[]
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
                                         // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
                                        // Merge the sorted halves
        merge(arr, left, mid, right);
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
    // Example data (8 values)
    int arr[8] = {54, 33, 51, 58, 60, 22, 55, 70,};
    int n = 8;

    cout << "Array before sorting:\n";
    display(arr, n);

    // Call Merge Sort function
    mergeSort(arr, 0, n - 1);

    cout << "\nArray after Merge Sort (Ascending Order):\n";
    display(arr, n);

    return 0;
}
