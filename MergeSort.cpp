#include <iostream>
using namespace std;

void Merge(int A[], int l, int m, int h)
{
    int n1 = m - l + 1;
    int n2 = h - m;

    int L[n1 + 2];
    int R[n2 + 2];


    for (int i = 1; i <= n1; i++)
        L[i] = A[l + i - 1];


    for (int j = 1; j <= n2; j++)
        R[j] = A[m + j];

    L[n1 + 1] = 99999;
    R[n2 + 1] = 99999;

    int i = 1;
    int j = 1;

    for (int k = l; k <= h; k++)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
    }
}

void MergeSort(int A[], int l, int h)
{
    if (l < h)
    {
        int m = (l + h) / 2;

        MergeSort(A, l, m);
        MergeSort(A, m + 1, h);
        Merge(A, l, m, h);
    }
}

int main()
{
    int n;

    cout << "Enter array size: ";
    cin >> n;

    int A[n];
    cout << "Enter " << n << " elements: ";

    for (int i = 0; i < n; i++)
        cin >> A[i];

    MergeSort(A, 0, n - 1);

    cout << "Sorted Array: ";

    for (int i = 0; i < n; i++)
        cout << A[i] << " ";

    return 0;
}