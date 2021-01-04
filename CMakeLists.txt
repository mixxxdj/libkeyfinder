cmake_minimum_required(VERSION 3.0)
project(libkeyfinder)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

option(BUILD_SHARED_LIBS "Build dynamic library" OFF)
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
target_include_directories(keyfinder PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

#
# Installation
#
include(GNUInstallDirs)
install(TARGETS keyfinder
  ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
  LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
  RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
)

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

set(LIBKEYFINDER_VERSION 2.2.3)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/libKeyFinder.pc.cmake
  ${CMAKE_CURRENT_BINARY_DIR}/libKeyFinder.pc @ONLY)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/libKeyFinder.pc DESTINATION "${CMAKE_INSTALL_LIBDIR}/pkgconfig")

#
# Tests
#
include(CTest)
if(BUILD_TESTING)
  add_subdirectory(tests)
  add_test(NAME KeyFinder COMMAND $<TARGET_FILE:keyfinder-tests>)
endif()
