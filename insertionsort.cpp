#include <iostream>
using namespace std;

int main() {
    int arr[] = {5, 3, 4, 1, 2}; 
    int n = 5;

    cout << "Original Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n\n";

    // Insertion Sort
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Shift larger elements to the right
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Insert key in correct position
        arr[j + 1] = key;

        // Print array after each pass
        cout << "Pass " << i << ": ";
        for (int k = 0; k < n; k++) cout << arr[k] << " ";
        cout << "\n";
    }

    // Final result
    cout << "\nSorted Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";

    return 0;
}
