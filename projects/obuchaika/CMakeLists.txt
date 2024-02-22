project(obuchaika)

set(HEADERS 
	menu.hpp
	menu_functions.hpp
	menu_items.hpp
)

set(SOURCES 
	main.cpp
	menu_functions.cpp
	menu_items.cpp
)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})
