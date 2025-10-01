#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Kadane's Algorithm - Find maximum sum contiguous subarray
pair<int, vector<int>> kadaneMaxSubarray(const vector<int>& arr) {
    if (arr.empty()) return {0, {}};
    
    int max_ending_here = arr[0];
    int max_so_far = arr[0];
    int start = 0, end = 0;
    int temp_start = 0;
    
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > max_ending_here + arr[i]) {
            max_ending_here = arr[i];
            temp_start = i;
        } else {
            max_ending_here = max_ending_here + arr[i];
        }
        
        if (max_ending_here > max_so_far) {
            max_so_far = max_ending_here;
            start = temp_start;
            end = i;
        }
    }
    
    // Extract the subarray
    vector<int> subarray(arr.begin() + start, arr.begin() + end + 1);
    
    return {max_so_far, subarray};
}

// Modified Kadane's to handle all negative numbers
pair<int, vector<int>> kadaneAllNegative(const vector<int>& arr) {
    if (arr.empty()) return {0, {}};
    
    int max_so_far = arr[0];
    int curr_max = arr[0];
    int start = 0, end = 0;
    int temp_start = 0;
    
    for (int i = 1; i < arr.size(); i++) {
        if (curr_max < 0) {
            curr_max = arr[i];
            temp_start = i;
        } else {
            curr_max += arr[i];
        }
        
        if (curr_max > max_so_far) {
            max_so_far = curr_max;
            start = temp_start;
            end = i;
        }
    }
    
    vector<int> subarray(arr.begin() + start, arr.begin() + end + 1);
    return {max_so_far, subarray};
}

// Simple version that returns only the maximum sum
int kadaneMaxSum(const vector<int>& arr) {
    int max_so_far = INT_MIN;
    int max_ending_here = 0;
    
    for (int i = 0; i < arr.size(); i++) {
        max_ending_here = max_ending_here + arr[i];
        
        if (max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
        }
        
        if (max_ending_here < 0) {
            max_ending_here = 0;
        }
    }
    return max_so_far;
}

// Print the result
void printResult(const pair<int, vector<int>>& result) {
    cout << "Maximum sum: " << result.first << endl;
    cout << "Subarray: [";
    for (int i = 0; i < result.second.size(); i++) {
        cout << result.second[i];
        if (i < result.second.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    // Test case 1: Mixed positive and negative numbers
    vector<int> arr1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Array 1: [-2, 1, -3, 4, -1, 2, 1, -5, 4]" << endl;
    auto result1 = kadaneMaxSubarray(arr1);
    printResult(result1);
    cout << "Simple max sum: " << kadaneMaxSum(arr1) << endl;
    cout << endl;
    
    // Test case 2: All positive numbers
    vector<int> arr2 = {1, 2, 3, 4, 5};
    cout << "Array 2: [1, 2, 3, 4, 5]" << endl;
    auto result2 = kadaneMaxSubarray(arr2);
    printResult(result2);
    cout << "Simple max sum: " << kadaneMaxSum(arr2) << endl;
    cout << endl;
    
    // Test case 3: All negative numbers
    vector<int> arr3 = {-5, -2, -8, -1, -3};
    cout << "Array 3: [-5, -2, -8, -1, -3]" << endl;
    auto result3 = kadaneAllNegative(arr3);
    printResult(result3);
    cout << "Simple max sum: " << kadaneMaxSum(arr3) << endl;
    cout << endl;
    
    // Test case 4: Single element
    vector<int> arr4 = {5};
    cout << "Array 4: [5]" << endl;
    auto result4 = kadaneMaxSubarray(arr4);
    printResult(result4);
    cout << "Simple max sum: " << kadaneMaxSum(arr4) << endl;
    
    return 0;
}