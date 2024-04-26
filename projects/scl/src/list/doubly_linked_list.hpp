#pragma once

#include <cstddef>

namespace AAntonian {
	template <typename T> 
	class DoublyLinkedList {
		private:
			class Node {
				public:
					T value;
					Node* prev = nullptr;
					Node* next = nullptr;
					
					Node(const T& value) : value(value) {}
						
					Node(const Node&) = delete;
					Node& operator = (const Node&) = delete;
			};
			Node* begin = nullptr;
			Node* end = nullptr;
		public:
			DoublyLinkedList() noexcept {};
			DoublyLinkedList(const DoublyLinkedList&) = delete;
			DoublyLinkedList& operator = (const DoublyLinkedList&) = delete;
			~DoublyLinkedList() noexcept;
			
			void push_back(const T& value) noexcept;
			bool has_item(const T& value) const noexcept;
			void print() const noexcept;
			bool remove_first(const T& value) noexcept;
			std::size_t size() const noexcept;
	};
}
