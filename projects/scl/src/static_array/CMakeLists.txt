target_sources(${SCL_LIB} 
	PRIVATE
		static_array.cpp
	PUBLIC
		static_array.hpp
)

target_include_directories(${SCL_LIB} PUBLIC
	${PROJECT_SOURCE_DIR}/src/static_array
)
