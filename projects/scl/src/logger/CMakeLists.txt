target_sources(${SCL_LIB} 
	PRIVATE
		logger.cpp
	PUBLIC
		logger.hpp
)

target_include_directories(${SCL_LIB} PUBLIC
	${PROJECT_SOURCE_DIR}/src/logger
)
