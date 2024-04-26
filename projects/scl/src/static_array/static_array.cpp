#include "static_array.hpp"

#include <algorithm>
#include <stdexcept>

using IBusko::StaticArray;

template <typename T, int size>
StaticArray<T, size>::StaticArray(const T* beg, const T* end) {
	if (end - beg > size) {
		throw std::out_of_range("Выход за пределы массива.");
	}
	int i = 0;
	while (beg != end) {
		arr[i] = *beg++;
		i++;
	}
	while (i < size) {
		arr[i] = {};
		i++;
	}
}

template <typename T, int size>
StaticArray<T, size>::StaticArray(std::initializer_list<T> arr) {
	if (arr.size() > size) {
		throw std::out_of_range("Выход за пределы массива.");
	}
	
	std::copy(arr.begin(), arr.end(), this->arr);
	
	if (arr.size() < size) {
		for (int i = arr.size(); i < size; i++) {
			this->arr[i] = {};
		}
	}
}
