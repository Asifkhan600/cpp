#include <iostream>
using namespace std;

// Heapify function to maintain heap property
void heapify(int arr[], int n, int i) {
    int largest = i;      
    int left = 2*i + 1;  
    int right = 2*i + 2; 

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    // Step 1: Build max heap
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Step 2: Extract elements one by one
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);  // Move root to end
        heapify(arr, i, 0);   // Heapify reduced heap
    }
}

int main() {
    int arr[] = {4, 10, 3, 5, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Original array: ";
    for (int x : arr) cout << x << " ";

    heapSort(arr, n);

    cout << "\nSorted array: ";
    for (int x : arr) cout << x << " ";

    return 0;
}
