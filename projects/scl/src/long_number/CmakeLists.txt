target_sources(scl_lib 
	PRIVATE
		long_number.cpp
	PUBLIC
		long_number.hpp
)

target_include_directories(scl_lib PUBLIC
	"${PROJECT_SOURCE_DIR}/src/long_number"
)