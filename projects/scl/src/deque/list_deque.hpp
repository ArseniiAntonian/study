#pragma once

namespace IBusko {
	template<typename T>
	class ListDeque {
		private:
			class Node {
				public:
					T value;
					Node* next = nullptr;
					
					Node(const T& value) : value(value) {}
						
					Node(const Node&) = delete;
					Node& operator = (const Node&) = delete;
			}
			Node* begin = nullptr;
			Node* end = nullptr;
		public:
			ListDeque() noexcept {};
			ListDeque(const ListDeque&) = delete;
			ListDeque& operator = (const ListDeque&) = delete;
			~ListDeque() noexcept;
			
			bool empty() const noexcept;
			void pop_back() noexcept;
			void pop_front() noexcept;
			void push_back(const T& value) noexcept;
			void push_front(const T& value) noexcept;
			std::size_t size() const noexcept;
			T back() const noexcept;
			T front() const noexcept;
	};
}
