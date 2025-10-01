#include <iostream>
using namespace std;

int main() {
    int arr[] = {5, 3, 4, 1, 2};  
    int n = 5;

    cout << "Original Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n\n";

    // Selection Sort
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;  // assume current element is the smallest

        // find the smallest element in remaining array
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;  // update index of smallest element
            }
        }

        // swap smallest element with current element
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;

        // print array after each pass
        cout << "Pass " << i + 1 << ": ";
        for (int k = 0; k < n; k++) cout << arr[k] << " ";
        cout << "\n";
    }

    cout << "\nSorted Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    
    return 0;
}
