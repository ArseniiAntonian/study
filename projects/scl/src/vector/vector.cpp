#include "vector.hpp"

using IBusko::Vector;

template<typename T>
Vector<T>::Vector() noexcept {
    _size = 0;
    capacity = 10;
}

template<typename T>
Vector<T>::~Vector() noexcept {
    delete[] arr;
}

template<typename T>
void Vector<T>::push_back(const T &value) noexcept {
    if(_size == 0){
        arr = new T[capacity];
        arr[_size] = value;
        _size++;

    }
    else if(_size % capacity == 0){
        T* arr1 = new T[_size + capacity];
        for(int i = 0; i < _size; i++){
            arr1[i] = arr[i];
        }
        arr1[_size] = value;
        arr = arr1;
        arr1 = nullptr;
        _size++;

    }
    else{
        arr[_size] = value;
        _size++;
    }

}
template<typename T>
void Vector<T>::print() const noexcept {
    for(int i = 0; i < _size; i++)
        std::cout << arr[i] << " ";
}

template<typename T>
bool Vector<T>::insert(const int position, const T& value) {
    if (position<=0 || position> _size){
        return false;
    }
    T* arr1 = new T[_size + capacity];
    if (position==1){
        arr1[0] = value;
        for (int i = 0; i < _size;i++){
            arr1[i+1] = arr[i];
        }
    }
    else {
        for (int i = 0; i < position-1; i++) {
            arr1[i] = arr[i];
        }
        arr1[position-1] = value;
        for (int i = position; i < _size; i++) {
            arr1[i] = arr[i];
        }
    }
    arr = arr1;
    arr1 = nullptr;
    return true;
}
template<typename T>
bool Vector<T>::has_item(const T& value)const noexcept{
    for (int i = 0; i< _size; i++){
        if (arr[i] == value) return true;
    }
    return false;
}

template<typename T>
bool Vector<T>::remove_first(const T& value){
    int ind  = -1;
    for (int i = 0; i< _size; i++){
        if (arr[i] == value){
            ind = i;
            break;
        }
    }
    if (ind==-1) return false;
    _size-=1;
    T* arr1 = new T[ _size];
    for (int i = 0; i< ind; i++){

        arr1[i] = arr[i];
    }
    for (int i = ind +1; i< _size; i++){
        arr1[i-1] = arr[i];
    }
    arr = arr1;
    arr1 = nullptr;
    return true;
}
template<typename T>
std::size_t Vector<T>::size() const noexcept{
    return _size;
}
