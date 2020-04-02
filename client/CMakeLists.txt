cmake_minimum_required(VERSION 3.8)

project(ispclient)

include(FindPkgConfig)
pkg_check_modules (GLIB REQUIRED IMPORTED_TARGET glib-2.0)
pkg_check_modules (DBUS REQUIRED IMPORTED_TARGET dbus-1)
pkg_check_modules (JSON-C REQUIRED IMPORTED_TARGET json-c)

include_directories(
		${PROJECT_SOURCE_DIR}/./
		${PROJECT_SOURCE_DIR}/../interface
		/home/qe/1109/external/rv1109_rkaiq/uAPI
		/home/qe/1109/external/rv1109_rkaiq/algos
		/home/qe/1109/external/rv1109_rkaiq/common
		/home/qe/1109/external/rv1109_rkaiq/xcore
		/home/qe/1109/external/rv1109_rkaiq/iq_parser
		/home/qe/1109/external/isp2-ipc/common
		
	)

link_directories(
	${PROJECT_SOURCE_DIR}/./lib
	${PROJECT_SOURCE_DIR}/../libs
	)

aux_source_directory(./ SRCS)
aux_source_directory(./impl SRCS)

add_library(${PROJECT_NAME}
	${SRCS})

target_link_libraries(${PROJECT_NAME}
	PkgConfig::GLIB
	PkgConfig::DBUS
	PkgConfig::JSON-C
	gdbus
	pthread
	rkaiq
	)

install(TARGETS ${PROJECT_NAME}
	    LIBRARY DESTINATION  lib
	   )
install(FILES dbusconfig/ispclient.conf
	DESTINATION share/dbus-1/system.d)
