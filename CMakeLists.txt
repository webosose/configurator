# Copyright (c) 2007-2024 LG Electronics, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 2.8.7)

project(configurator CXX)

include(webOS/webOS)
webos_modules_init(1 0 0 QUALIFIER RC2)
webos_component(3 0 0)

webos_add_compiler_flags(ALL "-DMOJ_LINUX" --std=c++0x)

include_directories(src)

include(FindPkgConfig)

pkg_check_modules(GLIB2 REQUIRED glib-2.0)
include_directories(${GLIB2_INCLUDE_DIRS})
webos_add_compiler_flags(ALL ${GLIB2_CFLAGS})

pkg_check_modules(LUNASERVICE REQUIRED luna-service2)
include_directories(${LUNASERVICE_INCLUDE_DIRS})
webos_add_compiler_flags(ALL ${LUNASERVICE_CFLAGS})

# -- check for openssl
pkg_check_modules(OPENSSL REQUIRED openssl)
webos_add_compiler_flags(ALL ${OPENSSL_CFLAGS})

pkg_check_modules(DB8 REQUIRED db8>=3)
include_directories(${DB8_INCLUDE_DIRS})
webos_add_compiler_flags(ALL ${DB8_CFLAGS_OTHER})

if (NOT DEFINED USE_PMLOG OR USE_PMLOG)
    # -- check for pmLogLib
    pkg_check_modules(PMLOG REQUIRED PmLogLib>=3)
    include_directories(${PMLOG_INCLUDE_DIRS})
    webos_add_compiler_flags(ALL ${PMLOG_CFLAGS_OTHER} -DUSE_PMLOG)
endif()

if (EXTENSION_STARFISH)
    add_definitions(-DEXTENSION_STARFISH)
endif()

if(NO_FIRST_USE)
    add_definitions(-DNO_FIRST_USE)
    message(STATUS "FIRST_USE is not defined")
endif()

find_library(PTHREAD pthread REQUIRED)

file(GLOB SOURCE_FILES src/*.cpp)
add_executable(configurator ${SOURCE_FILES} )

target_link_libraries(configurator
                    -L.
                    ${DB8_LDFLAGS}
                    ${GLIB2_LDFLAGS}
                    ${LUNASERVICE_LDFLAGS}
		    ${OPENSSL_LDFLAGS}
                    ${PTHREAD}
                    ${PMLOG_LDFLAGS}
                   )

webos_configure_header_files(src)
webos_build_daemon(NAME configurator LAUNCH files/launch)
webos_build_system_bus_files()
