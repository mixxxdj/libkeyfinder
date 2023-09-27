# Change log

## 2.2.8
  * Update tests to Catch3
  * Bump minimum CMake version to 3.5 to avoid deprecation warning

## 2.2.7
  * Fix pkgconfig file when CMAKE_INSTALL_{INCLUDE,LIB}DIR are absolute paths

## 2.2.6
  * Install CMake package config to CMAKE_INSTALL_LIBDIR
  * Install FindFFTW3.cmake module
  * Fix fftw3 missing from Requires.private in pkgconfig file

## 2.2.5
  * Set version for .so library and setup version symlinks

## 2.2.4

  * Rename repository from libKeyFinder to libkeyfinder
  * Support building Windows DLL
  * Add Windows to GitHub Actions CI
  * Add CMake target export files
  * Use catch2 for tests
  * Add CTest support with standard BUILD_TESTING CMake option
  * Add example program and build it on CI
  * Add Doxygen documentation and deploy to https://mixxxdj.github.io/libkeyfinder/

## 2.2.3

  * Maintenance transferred to [Mixxx DJ Software](https://mixxx.org/) team
  * Fix CMake build
  * Use GitHub Actions for CI on Ubuntu and macOS

## 2.2.2

  * Add CMake build system support

## 2.2.1

  * update tests and downsampling shortcut
