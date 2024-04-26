#pragma once

namespace IBusko {
	template<typename T>
	class ListStack {
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
			ListStack() noexcept {};
			ListStack(const ListStack&) = delete;
			ListStack& operator = (const ListStack&) = delete;
			~ListStack() noexcept;
			
			bool empty() const noexcept;
			void pop() noexcept;
			void push(const T& value) noexcept;
			std::size_t size() const noexcept;
			T top() const noexcept;
	};
}
