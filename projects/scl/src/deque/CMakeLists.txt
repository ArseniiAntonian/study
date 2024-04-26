target_sources(${SCL_LIB} 
	PRIVATE
		
	PUBLIC
		list_deque.hpp
		static_array_deque.hpp
		vector_deque.hpp
)

target_include_directories(${SCL_LIB} PUBLIC
	${PROJECT_SOURCE_DIR}/src/deque
)
