#include <iostream>
using namespace std;

int BinarySearch(int arr[], int low, int high, int key)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;

        else if (key < arr[mid])
            high = mid - 1;

        else
            low = mid + 1;
    }

    return -1;
}

int main()
{
    int n, key;

    cout << "Enter Number of Elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter Sorted Array Elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter Search Key: ";
    cin >> key;

    int position = BinarySearch(arr, 0, n - 1, key);

    if (position != -1)
        cout << "Element Found at Position: " << position + 1;
    else
        cout << "Element Not Found";

    return 0;
}