#include <iostream>
using namespace std;

int partition(int A[], int l, int h)
{
    int V = A[l];
    int P = l + 1;
    int Q = h;

    while (P <= Q)
    {
        while (P <= h && A[P] <= V)
        {
            P = P + 1;
        }

        while (A[Q] > V)
        {
            Q = Q - 1;
        }

        if (P < Q)
        {
            swap(A[P], A[Q]);
        }
    }

    swap(A[l], A[Q]);

    return Q;
}

void QuickSort(int A[], int l, int h)
{
    if (l < h)
    {
        int p = partition(A, l, h);

        QuickSort(A, l, p - 1);

        QuickSort(A, p + 1, h);
    }
}

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int A[n];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    QuickSort(A, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }

    return 0;
}