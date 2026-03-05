#include <iostream>

using namespace std;

// O(n)
int linearSearch(int* arr, int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}

// O(log n)
int binarySearch(int* arr, int n, int target) {
    int lo = 0;
    int hi = n - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2; // Sesuai instruksi
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}

// O(n)
int* generateSortedArray(int n) {
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = i * 2; // {0, 2, 4, ..., 2(n-1)}
    }
    return arr;
}

void demoSearch(int n) {
    int* arr = generateSortedArray(n);
    int midIdx = n / 2;
    int targetExist = arr[midIdx];
    int targetNotExist = -1;

    cout << "Testing size n = " << n << endl;
    cout << "Search Exist (" << targetExist << "): Linear Index=" << linearSearch(arr, n, targetExist) 
         << ", Binary Index=" << binarySearch(arr, n, targetExist) << endl;
    cout << "Search Not Exist (" << targetNotExist << "): Linear Index=" << linearSearch(arr, n, targetNotExist) 
         << ", Binary Index=" << binarySearch(arr, n, targetNotExist) << endl;
    cout << "-----------------------------------" << endl;

    delete[] arr; // Membersihkan heap memori
}

int main() {
    int sizes[] = {10, 100, 1000};
    for (int i = 0; i < 3; i++) {
        demoSearch(sizes[i]);
    }
    return 0;
}
