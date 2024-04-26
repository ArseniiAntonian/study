target_sources(${SCL_LIB} 
	PRIVATE
		
	PUBLIC
		vector.hpp
		vector.cpp
)

target_include_directories(${SCL_LIB} PUBLIC
	${PROJECT_SOURCE_DIR}/src/vector
)
