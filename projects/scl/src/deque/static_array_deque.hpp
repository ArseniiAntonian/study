#pragma once

namespace IBusko {
	template<typename T, std::size_t n>
	class StaticArrayDeque {
		private:
			T arr[n];
			std::size_t head_index = -1;
		public:
			StaticArrayDeque() noexcept {};
			StaticArrayDeque(const StaticArrayDeque&) = delete;
			StaticArrayDeque& operator = (const StaticArrayDeque&) = delete;
			~StaticArrayDeque() noexcept;
			
			bool empty() const noexcept;
			void pop_back();
			void pop_front();
			void push_back(const T& value);
			void push_front(const T& value);
			std::size_t size() const noexcept;
			T back() const noexcept;
			T front() const noexcept;
	};
}
