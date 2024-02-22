target_sources(bubble_sort_mf 
	PRIVATE
		bubble_sort.cpp
		bubble_sort.hpp
)

target_include_directories(bubble_sort_mf PRIVATE
	"${PROJECT_SOURCE_DIR}/sortings"
)
