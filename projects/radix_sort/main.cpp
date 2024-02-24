#include <iostream>
#include "radix_sort.hpp"
using namespace std;

int main() {
    int n;
    cin >> n;
	vector<int> a(n);

    for(int i = 0; i < n; i++) cin >> a[i];
	RadixSort::sort(a);
    for(int i = 0; i < n; i++) cout << a[i] << " ";
}
