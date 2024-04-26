target_sources(${SCL_LIB} 
	PRIVATE
		text.cpp
		utility.cpp
	PUBLIC
		ctext.hpp
		text.hpp
		utility.hpp
)

target_include_directories(${SCL_LIB} PUBLIC
	${PROJECT_SOURCE_DIR}/src/text
)
