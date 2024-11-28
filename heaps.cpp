#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function prototypes
void insertHeap(vector<int>& heap, int value);
void deleteRoot(vector<int>& heap);
void heapify(vector<int>& arr, int n, int i);
void buildMaxHeap(vector<int>& arr);
void convertToMinHeap(vector<int>& heap);
void printHeap(const vector<int>& heap);

int main() {
    cout << "### Space Expedition Heap Quest ###\n";

    // Task 1: Insert elements into a Max-Heap
    vector<int> maxHeap;
    vector<int> elements = {50, 70, 30, 90, 60};
    cout << "\nTask 1: Fleet Assembly (Insertion into Max-Heap)\n";
    for (int value : elements) {
        insertHeap(maxHeap, value);
        cout << "Adding spacecraft with energy " << value << " to the Max-Heap: ";
        printHeap(maxHeap);
    }

    // Task 2: Delete root from Max-Heap
    cout << "\nTask 2: Critical Mission Deployment (Deleting Root)\n";
    cout << "Initial Fleet: ";
    printHeap(maxHeap);
    deleteRoot(maxHeap);
    cout << "Fleet after deploying the highest-energy spacecraft: ";
    printHeap(maxHeap);

    // Task 3: Heapify an array into a Max-Heap
    cout << "\nTask 3: Fleet Optimization (Heapify Operation)\n";
    vector<int> unsortedArray = {40, 10, 20, 50, 30, 60};
    cout << "Unsorted fleet: ";
    printHeap(unsortedArray);
    buildMaxHeap(unsortedArray);
    cout << "Heapified fleet: ";
    printHeap(unsortedArray);

    // Task 4: Convert Max-Heap to Min-Heap
    cout << "\nTask 4 (Bonus): Energy Redistribution (Convert to Min-Heap)\n";
    cout << "Fleet in Max-Heap order: ";
    printHeap(maxHeap);
    convertToMinHeap(maxHeap);
    cout << "Fleet converted to Min-Heap order: ";
    printHeap(maxHeap);

    return 0;
}

// Insert into Max-Heap
void insertHeap(vector<int>& heap, int value) {
    heap.push_back(value);
    int i = heap.size() - 1;
    while (i > 0 && heap[i] > heap[(i - 1) / 2]) {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Delete the root of the Max-Heap
void deleteRoot(vector<int>& heap) {
    if (heap.empty()) return;
    heap[0] = heap.back();
    heap.pop_back();
    heapify(heap, heap.size(), 0);
}

// Heapify a subtree rooted at index i
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Build a Max-Heap from an array
void buildMaxHeap(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

// Convert Max-Heap to Min-Heap
void convertToMinHeap(vector<int>& heap) {
    sort(heap.begin(), heap.end());
}

// Print the heap
void printHeap(const vector<int>& heap) {
    cout << "[";
    for (size_t i = 0; i < heap.size(); ++i) {
        cout << heap[i];
        if (i < heap.size() - 1) cout << ", ";
    }
    cout << "]\n";
}

