#pragma once

#include <iostream>

namespace IBusko {
	class Text final {
		private:
			char* value;
			int length;
		public:
			Text();
			Text(const char* const str);
			Text(const Text& x);
			Text(Text&& x);
			~Text();

			Text& operator = (const char* const str);
			Text& operator = (const Text& x);
			Text& operator = (Text&& x);
			
			int get_length() const { return length; }
			const char* get_str() const { return value; }
			
			friend std::ostream& operator << (std::ostream& os, const Text& x);
	};
}
