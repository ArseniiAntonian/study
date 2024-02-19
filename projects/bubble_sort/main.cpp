#include <iostream>
#include <vector>

void sort_by_bubble(std::vector<int> &arr);

int main() {
    std::vector<int> arr = {1, 8, 2, 5, 3, 11};
    std::cout << "Массив до сортировки:";
    for (int i = 0; i < arr.size(); i++) {
        std::cout << ' ' << arr[i];
    }
    std::cout << std::endl;
    
    sort_by_bubble(arr);

    std::cout << "Массив после сортировки:";
    for (int i = 0; i < arr.size(); i++) {
        std::cout << ' ' << arr[i];
    }
    std::cout << std::endl;

    std::system("PAUSE");
    return 0;
}

void sort_by_bubble(std::vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int x = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = x;
            }
        }
    }
}
