#include <iostream>
#include "radix_sort.hpp"
using namespace std;

int main() {
    int n;
    cin >> n;
	int arr[n];

    for(int i = 0; i < n; i++) cin >> arr[i];

	radixsort(arr, n);
	for(int x : arr) cout << x << " ";
}
