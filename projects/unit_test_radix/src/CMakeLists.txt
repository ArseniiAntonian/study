target_sources(radix_sort_lib 
	PRIVATE
		radix_sort.cpp
	PUBLIC
		radix_sort.hpp
)

target_include_directories(radix_sort_lib PUBLIC
	"${PROJECT_SOURCE_DIR}/src"
)
