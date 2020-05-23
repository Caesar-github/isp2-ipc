cmake_minimum_required(VERSION 3.8)

project(ispserver)

include(FindPkgConfig)
pkg_check_modules (GLIB REQUIRED IMPORTED_TARGET glib-2.0)
pkg_check_modules (DBUS REQUIRED IMPORTED_TARGET dbus-1)
pkg_check_modules (JSON-C REQUIRED IMPORTED_TARGET json-c)
message("=================================")
message("$PROJECT_SOURCE_DIR")

include_directories(
	${PROJECT_SOURCE_DIR}/./
        ${PROJECT_SOURCE_DIR}/../interface/
        ${PROJECT_SOURCE_DIR}/../common/
        ${CMAKE_SYSROOT}/usr/include/rkaiq/uAPI/
        ${CMAKE_SYSROOT}/usr/include/rkaiq/algos
        ${CMAKE_SYSROOT}/usr/include/rkaiq/common
        ${CMAKE_SYSROOT}/usr/include/rkaiq/xcore
        ${CMAKE_SYSROOT}/usr/include/rkaiq/iq_parser
        ${PROJECT_SOURCE_DIR}/../../CallFunIpc
	)


aux_source_directory(./ SRCS)
aux_source_directory(./impl SRCS)

add_executable(${PROJECT_NAME}
	${SRCS})

if(DEFINED CONFIG_OEM)
   add_definitions(-DCONFIG_OEM=${CONFIG_OEM})
endif()

target_link_libraries(${PROJECT_NAME}
        PkgConfig::GLIB
        PkgConfig::DBUS
        PkgConfig::JSON-C
        gdbus
        pthread
        CallFunIpc
        rkaiq
        )

install(TARGETS ${PROJECT_NAME}
	RUNTIME DESTINATION bin)
install(FILES dbusconfig/ispserver.conf
	DESTINATION share/dbus-1/system.d)
