/*Experiment No:10= Implement the Heap/Shell sort algorithm implemented in Java demonstrating heap/shell data
structure with modularity of programming language
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Heap Sort Module
namespace HeapSort {
void heapify(vector<int>& arr, int n, int i) {
int largest = i;
int left = 2 * i + 1;
int right = 2 * i + 2;
if (left < n && arr[left] > arr[largest]) {
largest = left;
}
if (right < n && arr[right] > arr[largest]) {
largest = right;
}
if (largest != i) {
swap(arr[i], arr[largest]);
heapify(arr, n, largest);
}
}
void sort(vector<int>& arr) {
int n = arr.size();
for (int i = n / 2 - 1; i >= 0; i--) {
heapify(arr, n, i);
}
for (int i = n - 1; i > 0; i--) {
swap(arr[0], arr[i]);
heapify(arr, i, 0);
}
}
}
// Shell Sort Module
namespace ShellSort {
void sort(vector<int>& arr) {
int n = arr.size();
for (int gap = n / 2; gap > 0; gap /= 2) {
for (int i = gap; i < n; i++) {
int temp = arr[i];
int j;
for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
arr[j] = arr[j - gap];
}
arr[j] = temp;
}
}
}
}
// Utility Module
namespace Utility {
void printArray(const vector<int>& arr) {
for (int val : arr) {
cout << val << " ";
}
cout << endl;
}
}
int main() {
vector<int> arr1 = {12, 11, 13, 5, 6, 7};
vector<int> arr2 = {64, 34, 25, 12, 22, 11, 90};
cout << "Original Array for Heap Sort: ";
Utility::printArray(arr1);
HeapSort::sort(arr1);
cout << "Sorted Array (Heap Sort): ";
Utility::printArray(arr1);
cout << "\nOriginal Array for Shell Sort: ";
Utility::printArray(arr2);
ShellSort::sort(arr2);
cout << "Sorted Array (Shell Sort): ";
Utility::printArray(arr2);
return 0;
}
