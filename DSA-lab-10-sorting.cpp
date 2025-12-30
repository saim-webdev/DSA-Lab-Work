#include <iostream>
using namespace std;
void bubbleSort(int arr[], int n)
{
    int temp;

    // Outer loop for number of passes
    for (int i = 0; i < n - 1; i++)
    {
        // Inner loop for comparisons
        for (int j = 0; j < n - i - 1; j++)
        {
            // Compare adjacent salaries
            if (arr[j] > arr[j + 1])
            {
                // Swap if in wrong order
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
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
    int salaries[10] = {45000, 30000, 55000, 28000, 60000,
                        42000, 35000, 50000, 32000, 48000};

    int n = 10;

    cout << "Employee Salaries Before Sorting:\n";
    display(salaries, n);

    // Sorting salaries using Bubble Sort
    bubbleSort(salaries, n);

    cout << "\nEmployee Salaries After Sorting (Ascending Order):\n";
    display(salaries, n);

    return 0;
}
