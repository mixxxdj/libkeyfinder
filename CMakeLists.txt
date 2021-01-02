cmake_minimum_required(VERSION 3.0)
project(libkeyfinder)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(BUILD_STATIC_LIBS)
  message(STATUS "Building libKeyFinder as a static library")
  add_library(keyfinder STATIC
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
else()
  message(STATUS "Building libKeyFinder as a dynamic library")
  add_library(keyfinder SHARED
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
endif()

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
find_package(FFTW REQUIRED)
target_link_libraries(keyfinder PUBLIC FFTW::FFTW)
target_include_directories(keyfinder PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

include(GNUInstallDirs)
install(TARGETS keyfinder DESTINATION "${CMAKE_INSTALL_LIBDIR}")
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

add_subdirectory(tests)
