#include "doubly_linked_list.hpp"
#include <iostream>

using AAntonian::DoublyLinkedList;

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() noexcept {
    Node* node;
    while(begin != end){
        if(end == nullptr) break;
        node = end;
        end = node->prev;
        delete node;
    }
    delete begin;
}

template <typename T>
void DoublyLinkedList<T>::push_back(const T& value) noexcept{
    Node* node = new Node(value);
    node->prev = end;
    if(end != nullptr){
        end->next = node;
    }else{
        begin = node;
    }
    end = node;
}

template <typename T>
void DoublyLinkedList<T>::print() const noexcept {
    Node *ptr = begin;
    while(ptr != end){
        std::cout << ptr->value << "\n";
        ptr = ptr->next;
    }
    std::cout << end->value << "\n";
}

template <typename T>
bool DoublyLinkedList<T>::remove_first(const T& value) noexcept{
    Node* node = begin;
    if (begin == nullptr)
        return false;
    if (begin->value == value){
        begin = node->next;
        delete node;
        return true;
    }
    while(true){
        if (node == end){
            if (end->value == value){
                end = node->prev;
                delete node;
                return true;
            } else{
                return false;
            }
        }
        if(node->value == value){
            Node* left = node->prev;
            Node* right = node->next;
            right->prev = left;
            left->next = right;
            delete node;
            return true;
        }
        node = node->next;
    }
}

template <typename T>
bool DoublyLinkedList<T>::has_item(const T& value) const noexcept{
    Node* node = begin;
    while(true){
        if (node == end && node->value != value)
            return false;
        if (node->value == value)
            return true;
        node = node->next;
    }
}

template <typename T>
size_t DoublyLinkedList<T>::size() const noexcept{
    if (begin == nullptr)
        return 0;
    Node* node = begin;
    size_t count = 0;
    while(true){
        count++;
        if (node == end)
            return count;
        node = node->next;
    }
}
