#include <iostream>

#include "bubble_sort.hpp"

int main() {
    std::vector<int> arr = {1, 8, 2, 5, 3, 11};
    std::cout << "Массив до сортировки:";
    for (int i = 0; i < arr.size(); i++) {
        std::cout << ' ' << arr[i];
    }
    std::cout << std::endl;
    
    BubbleSort::sort(arr);

    std::cout << "Массив после сортировки:";
    for (int i = 0; i < arr.size(); i++) {
        std::cout << ' ' << arr[i];
    }
    std::cout << std::endl;

    std::system("PAUSE");
    return 0;
}
