#pragma once

#include <initializer_list>
		
namespace IBusko {
	template <typename T, int size> 
	class StaticArray {
		private:
			T arr[size];
		public:
			StaticArray(const T* beg, const T* end);
			StaticArray(std::initializer_list<T> arr);
			
			T& operator [] (const int i) { return arr[i]; }
			
			int get_size() const noexcept { return size; }
	};
}
