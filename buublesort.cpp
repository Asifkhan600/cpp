#include <iostream>
using namespace std;

int main() {
    int arr[] = {4, 3, 2, 1};   // Example array
    int n = 4;
    int comparisons = 0, swaps = 0;

    // Bubble Sort
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            comparisons++;  // count comparison
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swaps++;   // count swap
            }
        }
    }

    // Output sorted array
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    // Output counts
    cout << "\nComparisons = " << comparisons;
    cout << "\nSwaps = " << swaps;

    return 0;
}
