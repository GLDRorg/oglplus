#  Copyright 2010-2013 Matus Chochlik. Distributed under the Boost
#  Software License, Version 1.0. (See accompanying file
#  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#
cmake_minimum_required(VERSION 2.8)

function(add_examples EXAMPLE_PATTERN PARENT_TARGET COMMON_LIBS)

	file(GLOB EXAMPLES "${CMAKE_CURRENT_SOURCE_DIR}/${EXAMPLE_PATTERN}.cpp")

	foreach(EXAMPLE_PATH ${EXAMPLES})
		get_filename_component(EXAMPLE_NAME "${EXAMPLE_PATH}" NAME_WE)
		set(TARGET_NAME "${EXAMPLE_NAME}")

		set(EXAMPLE_CAN_BE_BUILT true)
		require_all_dependencies(${EXAMPLE_NAME} EXAMPLE_CAN_BE_BUILT)

		if(EXAMPLE_CAN_BE_BUILT)
			add_executable(${TARGET_NAME} EXCLUDE_FROM_ALL ${EXAMPLE_PATH})
			target_link_libraries(${TARGET_NAME} ${COMMON_LIBS})
			add_all_dependencies(${TARGET_NAME})
			add_dependencies("${PARENT_TARGET}" ${TARGET_NAME})
		endif()
	endforeach()
endfunction(add_examples)

if(EGL_FOUND)
	include_directories(${EGL_INCLUDE_DIRS})

	set(EXAMPLE_LIBS ${EGL_LIBRARIES})

	add_custom_target(eglplus-examples ALL)

	add_examples("[0-9][0-9][0-9]*" eglplus-examples "${EXAMPLE_LIBS}")
endif(EGL_FOUND)
