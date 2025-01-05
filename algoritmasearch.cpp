#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Fungsi binary search dengan tambahan untuk menghitung jumlah langkah
int binarySearch(const vector<int>& arr, int target, int& steps) {
    int left = 0, right = arr.size() - 1;
    steps = 0;
    
    while (left <= right) {
        steps++;
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    cout << "Nama : Putri Syafira" << endl;
    cout << "NIM : 241011400916" << endl;

    vector<int> data = {34, 7, 23, 32, 5, 62};
    sort(data.begin(), data.end()); // Binary search membutuhkan array terurut
    int target, steps;

    cout << "Data: ";
    for (int num : data) cout << num << " ";
    cout << "\nMasukkan angka yang dicari: ";
    cin >> target;

    int result = binarySearch(data, target, steps);
    if (result != -1)
        cout << "Angka ditemukan di indeks " << result << " setelah " << steps << " langkah.\n";
    else
        cout << "Angka tidak ditemukan setelah " << steps << " langkah.\n";

    return 0;
}
