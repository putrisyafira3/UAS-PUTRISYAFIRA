#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Struktur untuk menyimpan data pesanan
struct Order {
    int id;
    string pickup;
    string destination;
    string time;
};

// Fungsi merge untuk penggabungan dua sub-array
void merge(vector<Order>& orders, int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid;
    vector<Order> L(n1), R(n2);
    
    for (int i = 0; i < n1; i++) L[i] = orders[left + i];
    for (int j = 0; j < n2; j++) R[j] = orders[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].time <= R[j].time)
            orders[k++] = L[i++];
        else
            orders[k++] = R[j++];
    }

    while (i < n1) orders[k++] = L[i++];
    while (j < n2) orders[k++] = R[j++];
}

// Fungsi merge sort
void mergeSort(vector<Order>& orders, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(orders, left, mid);
        mergeSort(orders, mid + 1, right);
        merge(orders, left, mid, right);
    }
}

int main() {
    // Nama dan NIM
    cout << "Nama: Putri Syafira" << endl;
    cout << "NIM: 241011400916" << endl;

    // Data pesanan transportasi
    vector<Order> orders = {
        {1, "A", "B", "2025-01-05 09:00:00"},
        {2, "C", "D", "2025-01-05 08:30:00"},
        {3, "E", "F", "2025-01-05 09:00:00"},
        {4, "G", "H", "2025-01-05 08:45:00"}
    };

    // Mengurutkan data berdasarkan waktu pemesanan
    mergeSort(orders, 0, orders.size() - 1);

    // Output hasil sorting
    cout << "\nData pesanan setelah diurutkan:" << endl;
    for (const auto& order : orders) {
        cout << "ID: " << order.id << ", Pickup: " << order.pickup 
             << ", Destination: " << order.destination 
             << ", Time: " << order.time << endl;
    }

    return 0;
}
