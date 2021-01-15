cmake_minimum_required(VERSION 3.4)
project(KeyFinder VERSION 2.2.4)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

option(BUILD_SHARED_LIBS "Build dynamic library" ON)

add_library(keyfinder
  src/audiodata.cpp
  src/chromagram.cpp
  src/chromatransform.cpp
  src/chromatransformfactory.cpp
  src/fftadapter.cpp
  src/keyclassifier.cpp
  src/keyfinder.cpp
  src/lowpassfilter.cpp
  src/lowpassfilterfactory.cpp
  src/spectrumanalyser.cpp
  src/temporalwindowfactory.cpp
  src/toneprofiles.cpp
  src/windowfunctions.cpp
  src/workspace.cpp
  src/constants.cpp
)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
find_package(FFTW3 REQUIRED)
target_link_libraries(keyfinder PUBLIC FFTW3::fftw3)

target_include_directories(keyfinder PUBLIC
   $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
   $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

set_target_properties(keyfinder PROPERTIES
  WINDOWS_EXPORT_ALL_SYMBOLS TRUE
)

#
# Installation
#
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

# Library
install(TARGETS keyfinder
  EXPORT KeyFinderTargets
  ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
  LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
  RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
  INCLUDES DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
)

# Headers
install(FILES
  src/audiodata.h
  src/chromagram.h
  src/chromatransform.h
  src/chromatransformfactory.h
  src/fftadapter.h
  src/keyclassifier.h
  src/keyfinder.h
  src/lowpassfilter.h
  src/lowpassfilterfactory.h
  src/spectrumanalyser.h
  src/temporalwindowfactory.h
  src/toneprofiles.h
  src/windowfunctions.h
  src/workspace.h
  src/constants.h
  src/exception.h
  src/binode.h
  DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/keyfinder")

# pkgconfig
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/libkeyfinder.pc.cmake
  ${CMAKE_CURRENT_BINARY_DIR}/libkeyfinder.pc @ONLY)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/libkeyfinder.pc DESTINATION "${CMAKE_INSTALL_LIBDIR}/pkgconfig")

# CMake config
set(KEYFINDER_INSTALL_CMAKEDIR "lib/cmake/KeyFinder")
install(
  EXPORT KeyFinderTargets
  FILE KeyFinderTargets.cmake
  NAMESPACE KeyFinder::
  DESTINATION "${KEYFINDER_INSTALL_CMAKEDIR}"
)
configure_package_config_file(KeyFinderConfig.cmake.in
  "${CMAKE_CURRENT_BINARY_DIR}/KeyFinderConfig.cmake"
  INSTALL_DESTINATION "${KEYFINDER_INSTALL_CMAKEDIR}"
)
write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/KeyFinderConfigVersion.cmake"
  VERSION "${CMAKE_PROJECT_VERSION}"
  COMPATIBILITY SameMajorVersion
)
install(
  FILES
    "${CMAKE_CURRENT_BINARY_DIR}/KeyFinderConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/KeyFinderConfigVersion.cmake"
  DESTINATION "${KEYFINDER_INSTALL_CMAKEDIR}"
)

#
# Tests
#
include(CTest)
if(BUILD_TESTING)
  add_subdirectory(tests)
endif()
