#include "radix_sort.hpp"
using namespace std;

int getMax(vector<int> &arr) {

    int n = arr.size();
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countSort(vector<int> &arr, int exp) {

    int n = arr.size();
    int output[n];
    int i, count[10] = { 0 };

    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void RadixSort::sort(vector<int> &arr) {
    int m = getMax(arr);

    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, exp);
}