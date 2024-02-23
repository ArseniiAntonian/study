#include <iostream>
#include <vector>
#include "radix_sort.hpp"
using namespace std;

int main() {
    int n;
    cin >> n;
	vector<int> arr;

    for(int i = 0; i < n; i++) cin >> arr[i];

	RadixSort::radixsort(arr);
	for(int x : arr) cout << x << " ";
}
