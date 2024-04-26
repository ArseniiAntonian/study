#include "utility.hpp"

#include <cstddef>

#include "ctext.hpp"

namespace IBusko {
	int get_length(const char* const str) {
		if (str == nullptr) return 0;

		int lenght = 0;
		while (str[lenght] != CText::END) {
			lenght++;
		}
		
		return lenght;
	}
}
