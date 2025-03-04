
#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

int qselect(int arr[], int low, int high, int key) {
    if (low <= high) {
        int pivotIndex = partition(arr, low, high);

        if (pivotIndex == key) {
            return arr[pivotIndex];
        } else if (pivotIndex < key) {
            return qselect(arr, pivotIndex + 1, high, key);
        } else {
            return qselect(arr, low, pivotIndex - 1, key);
        }
    }
    return -1;  .
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int *arr = new int[size];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int key;
    cout << "Enter the key (1-based index for kth largest): ";
    cin >> key;
    key = size - key;  // Convert to 0-based index

    int result = qselect(arr, 0, size - 1, key);

    cout << "The " << (size - key) << "th largest element is: " << result << endl;

    delete[] arr;  // Clean up dynamically allocated memory
    return 0;
}
