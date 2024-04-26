#include "text.hpp"

#include "ctext.hpp"
#include "utility.hpp"

using IBusko::CText;
using IBusko::Text;

Text::Text() : length(0) {
	value = new char[length + 1];
	value[0] = CText::END;
}

Text::Text(const char* const str) {
	length = IBusko::get_length(str);
	value = new char[length + 1];
	for (int i = 0; i < length; i++) {
		value[i] = str[i];
	}
	value[length] = CText::END;
}

Text::Text(const Text& x) {
	length = x.length;
	value = new char[length + 1];
	for (int i = 0; i < length; i++) {
		value[i] = x.value[i];
	}
	value[length] = CText::END;
}

Text::Text(Text&& x) {
	length = x.length;
	value = x.value;
	x.value = nullptr;
}

Text::~Text() {
	length = 0;
	delete [] value;
	value = nullptr;
}

Text& Text::operator = (const char* const str) {
	length = IBusko::get_length(str);
	
	delete [] value;
	value = new char[length + 1];
	for (int i = 0; i < length; i++) {
		value[i] = str[i];
	}
	value[length] = CText::END;
	
	return *this;
}

Text& Text::operator = (const Text& x) {
	if (this == &x) return *this;
	
	length = x.length;
	
	delete [] value;
	value = new char[length + 1];
	for (int i = 0; i < length; i++) {
		value[i] = x.value[i];
	}
	value[length] = CText::END;

	return *this;
}

Text& Text::operator = (Text&& x) {
	delete [] value;
	length = x.length;
	value = x.value;
	x.value = nullptr;
	
	return *this;
}

namespace IBusko {
	std::ostream& operator << (std::ostream& os, const Text& x) {
		os << x.value;
		return os;
	}
}
